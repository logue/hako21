#include"turn.h"

// �^�[���������s��
int *Turn::order;
int *Turn::orderX;
int *Turn::orderY;

// �^�[���i�s
void Turn::main() {
    // �^�[���i�s
    Info::turn++;

    // �n�}�ǂݍ���
    HakoIO::readMapFile();

    // ��������̗p��
    makeOrder();
    makeOrderXY();

    // ���O�t�@�C�����炷
    HakoIO::logSlide();

    // ���O�t�@�C���J��
    HakoIO::logOpen();

    // �C�ۓx�v�Z�A�̓y�̊���
    for(int x = -4; x < Value::worldSize + 4; x++) {
	for(int y = -4; y < Value::worldSize + 4; y++) {
	    Map::calcSea(x, y);
	}
    }

    int world2 = Value::worldSize * Value::worldSize;
    for(int i = 0; i < world2; i++) {
	    Map::infLand(orderX[i], orderY[i]);
    }

    // �����A����t�F�C�Y
    for(int i = 0; i < Info::totalNumber; i++) {
	Island *island = Info::getIsland(i + 1);
	island->clear2();
	island->order = i + 1;
	island->income();

	// ���l�����L�^
	island->prePop = island->pop;
    }
    
    // �R�}���h�t�F�C�Y
    for(int i = 0; i < Info::totalNumber; i++) {
	Island *island = Info::getIsland(order[i]);
	HakoIO::readComFile(island->id);
	Command::exec(island, order[i]);
	HakoIO::writeComFile(island->id);
    }
    
    // �e�w�b�N�X�����t�F�C�Y
    for(int i = 0; i < world2; i++) {
	Map::process(orderX[i],orderY[i]);
    }

    // �R�}���h�t�F�C�Y
    for(int i = 0; i < Info::totalNumber; i++) {
	Island *island = Info::getIsland(order[i]);
	Map::getBoatPeople(island);
    }

    // �S�̍ЊQ�t�F�C�Y
    Map::globalDisaster();

    // �p�����[�^�Z�o
    Map::estimate();

    // ���Ŕ���
    int *dFlag = new int[Info::totalNumber + 1];
    dFlag[0] = 0;
    int newTotal = Info::totalNumber;
    for(int i = 0; i < Info::totalNumber; i++) {
	Island *island = Info::getIsland(order[i]);
	dFlag[order[i]] = 0;
	// �H���؂�̂�
	if(island->food > 9999) {
	    int r = island->food - 9999;
	    island->food = 9999;
	    island->money += r / 10;
	}

	// �����؂�̂�
	if(island->money > 9999) {
	    island->money = 9999;
	}

	if(island->command == Com::Giveup) {
	    // �����ŏ���
	    HakoIO::hisOutput(1, island->name);
	    island->pop = 0;
	    dFlag[order[i]] = 1;
	} else if(island->pop <= 0) {
	    // �l�������ď���
	    HakoIO::hisOutput(2, island->name);
	    dFlag[order[i]] = 1;
	}
	if(dFlag[order[i]] == 1) {
	    // ������1���炷
	    newTotal--;

	    // �R�}���h�t�@�C������
	    sprintf(HakoIO::buffer, "%s/command%d.cgi",
		    Value::dirName, island->id);
	    unlink(HakoIO::buffer);
	} else {
    	    // �����Ȃ������ꍇ�A��ܔ���
	    island->getPrize(order[i]);
	}
    }
    
    if(newTotal != Info::totalNumber) {
	// 1���ȏ�������ꍇ
	// �����������A�n�}�������
	Map::deleteIslands(dFlag);
    }
    delete(dFlag);

    // �l���ɂ��\�[�g
    int *newOrder = new int[Info::totalNumber];
    Info::sortIslands(newOrder);
    Info::totalNumber = newTotal;

    // �y�n�̎�����X�V
    Map::changeOwner(newOrder);
    delete(newOrder);

    // ���O�t�@�C������
    HakoIO::logClose();

    // �n�}��������
    HakoIO::writeMapFile();

    // ��񏑂�����
    HakoIO::writeInfoFile();

    // �������O�؂�l��
    HakoIO::hisCut();

    // �o�b�N�A�b�v
    if((Info::turn % Value::backUpTurn) == 0) {
	Mentenance::slideBack();
    }
}

// 1�`�����܂ł̐��������Âo�Ă��鐔������
void Turn::makeOrder() {
    int n = Info::totalNumber;

    // �����l
    if(n == 0) {
	order = 0;
    } else {
	order = new int[n];
    }
    for(int i = 0; i < n; i++) {
	order[i] = i + 1;
    }

    // �V���b�t��
    for (int i = (n - 1); i >= 0; i--) {
	int j = Util::dice(i + 1);
	if(i != j) {
	    SWAP(order[i], order[j]);
	}
    }
}

// ���W�̎��s���������
void Turn::makeOrderXY() {
    int n = Value::worldSize * Value::worldSize;

    // �����l
    orderX = new int[n];
    orderY = new int[n];
    int i = 0;
    for(int y = 0; y < Value::worldSize; y++) {
	for(int x = 0; x < Value::worldSize; x++) {
	    orderX[i] = x;
	    orderY[i] = y;
	    i++;
	}
    }

    // �V���b�t��
    for (int i = (n - 1); i >= 0; i--) {
	int j = Util::dice(i + 1);
	if(i != j) {
	    SWAP(orderX[i], orderX[j]);
	    SWAP(orderY[i], orderY[j]);
	}
    }
}

// ���O�o�͂̃G�C���A�X
void Turn::log(int kind, int secret, int mIsland, int sIsland,
	      int cKind, int x, int y, int land, int amount) {
    HakoIO::logOutput(kind, secret, mIsland, sIsland,
		      cKind, x, y, land, amount);
}
