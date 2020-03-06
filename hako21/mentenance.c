#include"mentenance.h"

// ���ʕ���
void Mentenance::common() {
    HakoIO::out("mainMode = 'mente';\n");

    // �����f�[�^
    if(HakoIO::readInfoFile()) {
	// ����
	sprintf(HakoIO::buffer, "currentData = [%d, %d];\n", Info::turn,
		(unsigned int)Info::lastTime);
	HakoIO::out(HakoIO::buffer);
    } else {
	// �Ȃ�
	HakoIO::out("currentData = [0, 0];\n");
    }

    // �o�b�N�A�b�v�f�[�^
    HakoIO::out("backData = [");
    for(int i = 0; i < Value::backUpMax; i++) {
	if(HakoIO::readInfoFile(i)) {
	    sprintf(HakoIO::buffer, "[%d, %d]", Info::turn,
		    (unsigned int)Info::lastTime);
	    HakoIO::out(HakoIO::buffer);
	} else {
	    HakoIO::out("[0, 0]");
	}
	if((i + 1) < Value::backUpMax) {
	    HakoIO::out(",");
	} else {
	    HakoIO::out("];\n");
	}
    }
    Util::unlock();
}

// �V�K�f�[�^�쐬
void Mentenance::makeData() {
    // �f�B���N�g���쐬
    mkdir(Value::dirName, Value::dirMode);

    // �����������l�ɂ���
    Info::initialize();

    // �n�}���������l�ɂ���
    Map::alloc();
    Map::initialize();

    // ��������������
    HakoIO::writeInfoFile();

    // �n�}������������
    HakoIO::writeMapFile();

    common();
}

// �f�[�^�������
void Mentenance::deleteData() {
    removeData(Value::id);
    common();
}

// �f�[�^�f�B���N�g���폜
void Mentenance::removeData(int num) {
    if(num == -1) {
	strcpy(HakoIO::buffer, Value::dirName);
    } else {
	sprintf(HakoIO::buffer, "%s.bak%d", Value::dirName, num);
    }
    DIR *dp;
    dirent *de;
    dp = opendir(HakoIO::buffer);
    if(dp != 0) {
	while(1) {
	    de = readdir(dp);
	    if(de == 0) {
		break;
	    }
	    sprintf(HakoIO::buffer2, "%s/%s",
		    HakoIO::buffer, de->d_name);
	    unlink(HakoIO::buffer2);
	}
	closedir(dp);
    }
    rmdir(HakoIO::buffer);
}

// �f�[�^�̌�����
void Mentenance::activateData() {
    // �����f�[�^���폜
    removeData(-1);

    // �t�@�C�����ݒ�
    sprintf(HakoIO::buffer, "%s.bak%d", Value::dirName, Value::id);
    rename(HakoIO::buffer, Value::dirName);

    common();
}

// �f�[�^�̃o�b�N�A�b�v
void Mentenance::backUpData() {
    slideBack();
    common();
}

// �f�[�^�̃o�b�N�A�b�v(����)
void Mentenance::slideBack() {
    // �Ō�̃f�[�^���폜
    removeData(Value::backUpMax - 1);

    // ���炷
    for(int i = Value::backUpMax - 1; i > 0; i--) {
	sprintf(HakoIO::buffer, "%s.bak%d", Value::dirName, i - 1);
	sprintf(HakoIO::buffer2, "%s.bak%d", Value::dirName, i);
	rename(HakoIO::buffer, HakoIO::buffer2);
    }

    // �����f�[�^���R�s�[
    sprintf(HakoIO::buffer, "%s.bak0", Value::dirName); // �R�s�[��
    mkdir(HakoIO::buffer, Value::dirMode);

    DIR *dp;
    dirent *de;
    dp = opendir(Value::dirName);
    while(1) {
	de = readdir(dp);
	if(de == 0) {
	    break;
	}
	if(checkTail(de->d_name)) {
	    // �R�s�[���t�@�C����
	    sprintf(HakoIO::buffer2, "%s/%s",
		    Value::dirName, de->d_name);

	    // �R�s�[��t�@�C����
	    sprintf(HakoIO::buffer3, "%s/%s",
		    HakoIO::buffer, de->d_name);

	    ifstream ifs;
	    ofstream ofs;
	    ifs.open(HakoIO::buffer2);
	    ofs.open(HakoIO::buffer3);
	    while(!ifs.eof()) {
		ifs.getline(HakoIO::buffer4, 8192);
		if(HakoIO::buffer4[0] != 0) {
		    ofs << HakoIO::buffer4 << "\n";
		}
	    }
	}
    }
}

// �X�V�����ύX
void Mentenance::changeTime() {
    HakoIO::readInfoFile();
    Info::lastTime = Value::cTime;
    HakoIO::writeInfoFile();
    common();
}

// 'cgi'�ŏI��閼�O���`�F�b�N
int Mentenance::checkTail(char *name) {
    int l = strlen(name);
    if(l < 3) {
	return 0;
    }
    if((name[l - 3] == 'c') &&
       (name[l - 2] == 'g') &&
       (name[l - 1] == 'i')) {
	return 1;
    } else {
	return 0;
    }
}
