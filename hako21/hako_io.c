#include"hako_io.h"

ofstream *HakoIO::logofs;

// �ėp�o�b�t�@
char HakoIO::buffer[8192];
char HakoIO::buffer2[8192];
char HakoIO::buffer3[8192];
char HakoIO::buffer4[8192];

// 16�i��1�P�^(�啶������)�𐮐���
#define DECODEX(X) (((X) >= 'A') ? (X) - 'A' + 10 : (X) - '0')

// (��)
void HakoIO::out(char *s){
    cout << s;
/*    ofstream o;
    o.open("logfile", ios::app);
    o << s;
    o.close();*/
}

// �ݒ�t�@�C���ǂݍ���
void HakoIO::readConfigFile() {
    // �t�@�C�����J��
    ifstream ifs;
    ifs.open("config.cgi");

    if(ifs.fail()) {
	exit(0);
    }

    // �����N���X�ɃX�g���[����n��
    Value::input(&ifs);
    return;
}

// ���t�@�C����ǂ�
int HakoIO::readInfoFile(int number){
    // �t�@�C�����̐ݒ�
    if(number == -1) {
	// �ʏ�̃t�@�C��
	sprintf(buffer, "%s/info.cgi", Value::dirName);
    } else {
	// �o�b�N�A�b�v�t�@�C��
	sprintf(buffer, "%s.bak%d/info.cgi", Value::dirName, number);
    }
    
    // �t�@�C�����J��
    ifstream ifs;
    ifs.open(buffer);
    if(ifs.fail()) {
	return 0;
    }

    // �����N���X�ɃX�g���[����n��
    Info::input(&ifs);
    return 1;
}

// ���t�@�C��������
int HakoIO::writeInfoFile(){
    // �t�@�C�����̐ݒ�
    sprintf(buffer, "%s/info.cgi", Value::dirName);
    
    // �t�@�C�����J��
    ofstream ofs;
    ofs.open(buffer);
    if(ofs.fail()) {
	return 0;
    }

    // �����N���X�ɃX�g���[����n��
    Info::output(&ofs);

    return 1;
}

// �R�}���h�t�@�C���ǂݍ���
int HakoIO::readComFile(int id) {
    // �t�@�C�����̐ݒ�
    sprintf(buffer, "%s/command%d.cgi", Value::dirName, id);

    // �t�@�C�����J��
    ifstream ifs;
    ifs.open(buffer);
    if(ifs.fail()) {
	return 0;
    }

    // �R�}���h�N���X�ɃX�g���[����n��
    if(Command::coms == 0) {
	Command::alloc();
    }
    Command::input(&ifs);
    return 1;
}

// �R�}���h�t�@�C����������
int HakoIO::writeComFile(int id) {
    // �t�@�C�����̐ݒ�
    sprintf(buffer, "%s/command%d.cgi", Value::dirName, id);

    // �t�@�C�����J��
    ofstream ofs;
    ofs.open(buffer);
    if(ofs.fail()) {
	return 0;
    }

    // �R�}���h�N���X�ɃX�g���[����n��
    Command::output(&ofs);
    return 1;
}

// �n�}�t�@�C����ǂ�
int HakoIO::readMapFile(){
    // �t�@�C�����̐ݒ�
    sprintf(buffer, "%s/map.cgi", Value::dirName);
    
    // �t�@�C�����J��
    ifstream ifs;
    ifs.open(buffer);
    if(ifs.fail()) {
	Info::totalNumber = 0;
	return 0;
    }

    // �n�}�N���X�ɃX�g���[����n��
    Map::alloc();
    Map::input(&ifs);

    return 1;
}

// �n�}�t�@�C��������
int HakoIO::writeMapFile(){
    // �t�@�C�����̐ݒ�
    sprintf(buffer, "%s/map.cgi", Value::dirName);
    
    // �t�@�C�����J��
    ofstream ofs;
    ofs.open(buffer);
    if(ofs.fail()) {
	return 0;
    }

    // �n�}�N���X�ɃX�g���[����n��
    Map::output(&ofs);

    return 1;
}

// �N�b�L�[����(���ʂ�JavaScript�o��)
void HakoIO::cookieInput() {
    out("dpass = ''; did = 0;\n");

    char *httpcookie = getenv("HTTP_COOKIE");
    if(httpcookie == 0) {
	return;
    }
    int len = strlen(httpcookie);
    char *cookie = new char[len + 2];

    // �N�b�L�[���R�s�[
    strcpy(cookie, httpcookie);

    // ������';'������
    cookie[len] = ';';
    cookie[len + 1] = 0;

    // �t���O
    char *cookiePass = "";
    int cookieID = 0;

    // �܂킷
    char *src = cookie;
    char *name = "";
    char *cont = "";
    int mode = 0;
    while(*src != 0) {
	switch(mode) {
	case 0:
	    // ' '�łȂ���Ό��݈ʒu�𖼑O�̐擪��
	    if(*src != ' ') {
		name = src;
		mode = 1;
	    }
	    break;

	case 1:
	    // '='�̏ꍇ�̓��[�h�ύX
	    if(*src == '=') {
		*src = 0;
		mode = 2;
	    }
	    break;

	case 2:
	    // ���݈ʒu����e�̐擪��
	    cont = src;
	    mode = 3;
	    break;

	case 3:
	    // ';'�̏ꍇ�̓N�b�L�[�̉���
	    if(*src == ';') {
		*src = 0;
		mode = 0;

		// �p�X���[�h
		sprintf(buffer, "%s%sPASSWORD", Value::cgiURL,Value::configName);
		if(strcmp(buffer, name) == 0) {
		    cookiePass = cont;
		} else {
		    // ��ID
		    sprintf(buffer, "%s%sISLAND", Value::cgiURL,Value::configName);
		    if(strcmp(buffer, name) == 0) {
			cookieID = atoi(cont);
		    }
		}
	    }
	    break;
	}
	src++;
    }

    if(Value::password[0] != 0) {
	cookiePass = Value::password;
    }

    if(Value::id != 0) {
	cookieID = Value::id;
    }

    sprintf(buffer, "dpass = '%s'; did = %d;\n", cookiePass, cookieID);
    out(buffer);

    delete(cookie);
}


// CGI����
int HakoIO::cgiInput(){
    char *line;

    // POST�̒��������߂�
    char *cLen = getenv("CONTENT_LENGTH");
    if(cLen > 0) {
	// POST�̏ꍇ
	// �o�b�t�@�m��
	int len = atol(cLen);
	if(len > 8192) { return 0; } // ����܂蒷���Ƌp��
	line = new char[len + 3];
	if(line == 0) { return 0; }
	// POST��ǂ݂���
	cin.getline(line, len + 3);
    } else {
	char *g = getenv("QUERY_STRING");
	if(g == 0)  {
	    // �ǂ���ł��Ȃ��ꍇ
	    return 1;
	}
	// GET�̏ꍇ
	line = new char[strlen(g) + 3];
	strcpy(line, g);
    }


/*	    ofstream o;
	    o.open("logfile", ios::app);
	    o << line << "\n";
	    o.close();*/

    // +��%�̉��߂����A���ږ��ɕ���
    char *keyword[maxInput];
    char *content[maxInput];
    for(int i = 0; i < maxInput; i++){
	keyword[i] = 0;
	content[i] = 0;
    }
    int mode = 0;
    int count = 0;
    char *pos = line;
    char *pos2 = line;
    while(*pos != 0) {
	if(mode == 0) {
	    keyword[count] = pos2;
	    mode = 1;
	} else if(mode == 2) {
	    content[count] = pos2;
	    mode = 3;
	}
	switch(*pos) {
	case '+':
	    *pos = ' ';
	    break;

	case '%':
	    // 16�i�̉���
	    *pos2 = DECODEX(*(pos + 1)) * 16 + DECODEX(*(pos + 2));
	    pos += 2;
	    break;

	case '=':
	    // �L�[���[�h�I��
	    *pos2 = 0;
	    mode = 2;
	    break;

	case '&':
	    // �L�[���[�h�I��
	    *pos2 = 0;
	    mode = 0;
	    count++;
	    if(count >= maxInput) {
		count = 0;
	    }
	    break;

	case '\'':
	    // �s���ɂ��_�u���N�H�[�g��
	    *pos2 = '"';
	    break;

	default:
	    *pos2 = *pos;
	    break;
	}

	pos++;
	pos2++;
    }
    *pos2 = 0;
    

    // �e�L�[���[�h�̉���
    count = 0;
    while(keyword[count] != 0) {
	char *key = keyword[count];
	char *cont = content[count];

//	cout << "\n//" << key << "\n";
//	cout << "\n//" << cont << "\n";

	if(strcmp(key, "MenteMode") == 0) {
	    Value::mainMode = MODE_MENTENANCE;

	} else if(strcmp(key, "MapMode") == 0) {
	    Value::mainMode = MODE_MAP;

	} else if(strcmp(key, "OwnerMode") == 0) {
	    Value::mainMode = MODE_MAP_OWNER;

	} else if(strcmp(key, "CommandMode") == 0) {
	    Value::mainMode = MODE_MAP_COMMAND;

	} else if(strcmp(key, "NewIslandMode") == 0) {
	    Value::mainMode = MODE_NEW;

	} else if(strcmp(key, "RenameMode") == 0) {
	    Value::mainMode = MODE_RENAME;

	} else if(strcmp(key, "TurnMode") == 0) {
	    if(Value::debugMode == 1) {
		Value::mainMode = MODE_TURN;
	    }
	} else if(strncmp(key, "MesMode", 7) == 0) {
	    Value::mainMode = MODE_MESSAGE;
	    Value::id = atoi(key + 7);

	} else if(strncmp(key, "Activate", 8) == 0) {
	    Value::mainMode = MODE_MENTENANCE_ACTIVATE;
	    Value::id = atoi(key + 8);

	} else if(strcmp(key, "Second") == 0) {
	    Value::cTime = atoi(cont);

	} else if(strcmp(key, "MakeData") == 0) {
	    Value::mainMode = MODE_MENTENANCE_MAKEDATA;


	} else if(strcmp(key, "BackUp") == 0) {
	    Value::mainMode = MODE_MENTENANCE_BACKUP;

	} else if(strcmp(key, "ChangeTime") == 0) {
	    Value::mainMode = MODE_MENTENANCE_TIME;

	} else if(strncmp(key, "Delete", 6) == 0) {
	    Value::mainMode = MODE_MENTENANCE_DELETE;
	    if(strcmp(key, "Delete") == 0) {
		Value::id = -1;
	    } else {
		Value::id = atoi(key + 6);
	    }

	} else if(strcmp(key, "cname") == 0) {
	    if(cont != 0) {
		Util::cutColumn(cont, 32);
		Value::configName = cont;
	    }
	} else if(strcmp(key, "IslandName") == 0) {
	    if(cont != 0) {
		Util::cutColumn(cont, 32);
		Value::islandName = cont;
	    }

	} else if(strcmp(key, "Message") == 0) {
	    if(cont != 0) {
		Util::cutColumn(cont, 80);
		Value::message = cont;
	    }
	} else if(strcmp(key, "Password") == 0) {
	    if(cont != 0) {
		Util::cutColumn(cont, 32);
		Value::password = cont;
//		cookieOutput("PASSWORD", cont);
	    }
	} else if(strcmp(key, "Password2") == 0) {
	    if(cont != 0) {
		Util::cutColumn(cont, 32);
		Value::password2 = cont;
	    }
	} else if(strcmp(key, "Password3") == 0) {
	    if(cont != 0) {
		Util::cutColumn(cont, 32);
		Value::password3 = cont;
	    }
	} else if(strcmp(key, "PointX") == 0) {
	    Value::pointX = atoi(cont);

	} else if(strcmp(key, "PointY") == 0) {
	    Value::pointY = atoi(cont);

	} else if(strcmp(key, "Island") == 0) {
	    Value::id = atoi(cont);
//	    cookieOutput("ISLAND", cont);

	} else if(strcmp(key, "CommandList") == 0) {
	    if(cont != 0) {
		Value::commandList = cont;
	    }

	}

	count++;
    }

    return 1;
}

// �N�b�L�[�o��
void HakoIO::cookieOutput(char *name, char *cont) {
    time_t tt = time(0) + 2592000; // 30��
    tm *t = gmtime(&tt);
    char *day[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
		   "Thursday", "Friday", "Saturday"};
    char *mon[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    sprintf(buffer, 
	    "Set-Cookie: %s%s%s=%s; expires=%s, %02d-%s-%04d %02d:%02d:%02d GMT\n",
	    Value::cgiURL,Value::configName,name, cont, day[t->tm_wday], t->tm_mday,
	    mon[t->tm_mon], 1900 + t->tm_year, t->tm_hour, t->tm_min, t->tm_sec);
    out(buffer);
}

// ���O�t�@�C�����̐ݒ�
void HakoIO::setLogfileName(char *c, int num) {
     sprintf(c, "%s/logfile%d.cgi", Value::dirName, num);
}

// ���O�t�@�C���J��
void HakoIO::logOpen() {
    // �t�@�C�����̐ݒ�
    setLogfileName(buffer, 0);
    
    // �t�@�C�����J��
    logofs = new ofstream();
    logofs->open(buffer);
}

// ���O�t�@�C���J��
void HakoIO::logClose() {
    logofs->close();
    delete(logofs);
}

// ���O�t�@�C���������݊�{�֐�
// ��� * �@���t���O * ��֘A�� * ���֘A�� *
// �R�}���h�̎�� * �� *
// x���W2 * y���W2 * �n�`
void HakoIO::logOutput(int kind, int secret, int mIsland, int sIsland,
		       int cKind, int x, int y, int land, int amount) {
    (*logofs)
	<< kind << " "
	<< secret << " "
	<< mIsland << " "
	<< sIsland << " "
	<< cKind << " "
	<< x << " "
	<< y << " "
	<< land << " "
	<< amount << "\n";
}

// �������O��������
void HakoIO::hisOutput(int kind, char *name, char *name2) {
    // �������O�t�@�C�����̐ݒ�
    sprintf(buffer, "%s/loghis.cgi", Value::dirName);
    
    // �t�@�C�����J��(������͒ǉ��I�[�v��)
    ofstream ofs;
    ofs.open(buffer, ios::app);

    // �o��
    if(!ofs.fail()) {
	ofs << Info::turn << " " << kind << " " << name << " ";
	if(name2 != 0) {
	    ofs << name2;
	} else {
	    ofs << " <>";
	}
	ofs<< "\n";

	// ����
	ofs.close();
    }
}

// �������O��10�s�ɐ؂�l��
void HakoIO::hisCut() {
    char logBuf[10][80];

    // �������O�t�@�C�����̐ݒ�
    sprintf(buffer, "%s/loghis.cgi", Value::dirName);
    
    // �t�@�C�����J��
    ifstream ifs;
    ifs.open(buffer);

    // �s���𐔂���
    int num = 0;
    if(!ifs.fail()) {
	while(!ifs.eof()) {
	    ifs.getline(logBuf[0], 80);
	    num++;
	}
	ifs.close();
    }

    // 10�s�ȉ��Ȃ牽�����Ȃ�
    if(num <= 11) {
	return;
    }

    // ������x�J��
    ifs.open(buffer);

    // 10�s�c���ēǂݔ�΂�
    for(int i = 0; i < num - 11; i++) {
	ifs.getline(logBuf[0], 80);
    }

    // �Ō��10�s��ǂ�
    for(int i = 0; i < 10; i++) {
	logBuf[i][0] = 0;
	ifs.getline(logBuf[i], 80);
    }
    ifs.close();

    // out�ŊJ��
    ofstream ofs;
    ofs.open(buffer);

    // 10�s��������
    for(int i = 0; i < 10; i++) {
	ofs << logBuf[i] << "\n";
    }
    ofs.close();
}

// ���O�t�@�C�����炷
void HakoIO::logSlide() {
    setLogfileName(buffer, Value::logMax - 1);
    unlink(buffer);
    for(int i = Value::logMax - 2; i >= 0; i--) {
	setLogfileName(buffer, i);
	setLogfileName(buffer2, i + 1);
	rename(buffer, buffer2);
    }
}

// ���O�t�@�C��JavaScript�o��(�������O��)
void HakoIO::logJsOut(int id) {
    ifstream ifs;
    int kind, secret, mIsland, sIsland, cKind, x, y, land, amount, turn;
    out("logData = [");
    for(int i = 0; i < Value::logMax; i++) {
	setLogfileName(buffer, i);
	ifs.open(buffer);
	if(ifs.fail()) {
	    out("[]");
	    break;
	}
	out("[");
	while(!ifs.eof()) {
	    kind = -1;
	    ifs >> kind >> secret >> mIsland >> sIsland >> cKind
		>> x >> y >> land >> amount;
	    if(kind == -1) {
		out("[]");
		break;
	    }
	    if(((secret == 1) && (id != mIsland)) ||
	       ((secret == 2) && (id == mIsland))) {
		continue;
	    }
	    sprintf(buffer, "[%d,%d,%d,%d,%d,%d,%d,%d]",
		    kind, mIsland, sIsland, cKind, x, y, land, amount);
	    out(buffer);
	    if(!ifs.eof()) {
		out(",\n");
	    }
	}
	out("]");
	ifs.close();
	if(i < (Value::logMax - 1)) {
	    out(",");
	}
    }
    out("];");
    ifs.close();

    // �������O
    sprintf(buffer, "%s/loghis.cgi", Value::dirName);
    ifs.open(buffer);
    out("\nhisData = [");
    while(!ifs.eof()) {
	kind = -1;
	ifs >> turn >> kind >> buffer2 >> buffer3;
	if(kind == -1) {
	    out("[]");
	    break;
	}
	sprintf(buffer, "[%d, %d,\"%s\",\"%s\"]", turn, kind, buffer2, buffer3);
	out(buffer);
	if(!ifs.eof()) {
	    out(",\n");
	}
    }
    out("];");
}
