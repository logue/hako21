#include"rename.h"

void Rename::main() {
    // �p�X���[�h�`�F�b�N
    int mode = Util::passCheck();
    if(mode == 0) {
	return;
    }

    // ���̎擾
    Island *island = Info::getIslandByID(Value::id);

    if(island == 0) {
	TopPage::main();
	return;
    }

    // �ύX�t���O
    int flag = 0;

    // ���O������ꍇ�́A���O��ύX
    if(strcmp(Value::islandName, "") != 0) {
	if(island->money < 500) {
	    Util::unlock();
	    HakoIO::out("mainMode = 'errorNotEnoughMoney';");
	    return;
	}

	// ���O���������`�F�b�N
	if(Util::badNameCheck(Value::islandName)) {
	    Util::unlock();
	    HakoIO::out("mainMode = 'errorBadName';");
	    return;
	}

	// ���O�̏d���`�F�b�N
	if(Util::dupCheck(Value::islandName)) {
	    Util::unlock();
	    HakoIO::out("mainMode = 'errorDupName';");
	    return;
	}

	// �ύX
	// �������O��������
	HakoIO::hisOutput(3, island->name,  Value::islandName);

	strcpy(island->name, Value::islandName);
	island->money -= 500;
	flag = 1;
    }


    // �ύX�p�p�X���[�h������ꍇ�́A�p�X���[�h��ύX
    if(strcmp(Value::password3, "") != 0) {

	// �m�F�p�p�X���[�h
	if(strcmp(Value::password3, Value::password2)) {
	    // password�ԈႢ
	    Util::unlock();
	    HakoIO::out("mainMode = 'errorWrongPassword';");
	    return;
	}

	// �ύX
	strcpy(island->password, Value::password3);
	flag = 1;
    }

    if(flag == 0) {
	if(mode == 3) {
	    // �����A�H������
	    island->money = 9999;
	    island->food = 9999;
	    HakoIO::writeInfoFile();
	    HakoIO::out("mainMode = 'errorMaxMoney';");
	} else {
	    // �ύX���Ȃ��������b�Z�[�W
	    HakoIO::out("mainMode = 'errorNotChange';");
	}
    } else {
	// �ύX���O
	HakoIO::out("mainMode = 'errorChange';");
	HakoIO::writeInfoFile();
    }

    Util::unlock();
    return;
}
