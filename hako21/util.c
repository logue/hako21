#include"util.h"

int Util::lockFd = 0;

// ���O�̐��������`�F�b�N
int Util::badNameCheck(char *name) {
    if((strcmp(Value::islandName, "�Y�ꋎ��ꂽ") == 0) ||
       charCheck(Value::islandName, ' ') ||
       charCheck(Value::islandName, '"') ||
       charCheck(Value::islandName, ',') ||
       charCheck(Value::islandName, '?') ||
       charCheck(Value::islandName, '(') ||
       charCheck(Value::islandName, ')') ||
       charCheck(Value::islandName, '<') ||
       charCheck(Value::islandName, '>') ||
       charCheck(Value::islandName, '$')) {
	return 1;
    }
    return 0;
}

// ���̕������܂ނ��ǂ����`�F�b�N
int Util::charCheck(char *str, char c) {
    char *ptr = str;
    while(*ptr != 0) {
	if(c == *ptr) {
	    return 1;
	}
	ptr++;
    }
    return 0;
}

// ���̖��O�����łɎg���Ă��邩�`�F�b�N
int Util::dupCheck(char *name) {
    for(int i = 0; i < Info::totalNumber; i++) {
	if(strcmp(name, Info::islands[i].name) == 0) {
	    return 1;
	}
    }
    return 0;
}

// �������16�i����
int Util::hex(char *s) {
    char *ptr = s;
    int v = 0;
    while(*ptr != 0) {
	v = v * 16;
	char c = *ptr;
	if(c <= '9') {
	    c -= '0';
	} else {
	    c += 10 - 'a';
	}
	v += c;
	ptr++;
    }
    return v;
}

// ����(0 -> n-1)
int Util::dice(int n) {
    return random() % n;
}

// n byte�ȉ��ɐ؂�l�߂�
void Util::cutColumn(char *s, int n) {
    unsigned char *ptr = (unsigned char *)s;
    int count = 0;
    while(*ptr != 0) {
	if(((*ptr >= 0x81) && (*ptr <= 0x9f)) ||
	   ((*ptr >= 0xe0) && (*ptr <= 0xfc))) {
	    // ����2byte����
	    if(count < (n - 1)) {
		count += 2;
		ptr += 2;
	    } else {
		*ptr = 0;
		break;
	    }
	} else {
	    // ����1byte����
	    if(count < n) {
		if((*ptr < ' ') || (*ptr == '<') || (*ptr == '>') ||
		   (*ptr == '\\') || (*ptr == '\'') || (*ptr == '"')) {
		  *ptr = ' '; // ��΂��ȕ������J�b�g
		}
		count ++;
		ptr ++;
	    } else {
		*ptr = 0;
		break;
	    }
	}
    }
}

// �p�X���[�h�`�F�b�N
int Util::passCheck() {
    if(strcmp(Value::password, Value::masterPassword) == 0) {
	return 2;
    }

    if(strcmp(Value::password, Value::specialPassword) == 0) {
	return 3;
    }

    Island *island = Info::getIslandByID(Value::id);

    if(island != 0) {
	if(strcmp(Value::password, island->password) == 0) {
	    return 1;
	}
    }

    // ���s
    Util::unlock();
    HakoIO::out("mainMode = 'errorWrongPassword';");
    return 0;
}

// ���b�N
void Util::lock() {
#ifndef LOCAL
    lockFd = open(Value::dirName, O_RDWR);
    if(flock(lockFd, LOCK_EX)) {
	// ����
	return;
    } else {
	// ���s
	exit(0);
    }
#endif
}

// �A�����b�N
void Util::unlock() {
#ifndef LOCAL
    flock(lockFd, LOCK_UN);
    close(lockFd);
#endif
}
