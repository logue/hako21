#include"new_island.h"

void NewIsland::main() {
    // �f�[�^�ǂݍ���
    HakoIO::readMapFile();

    // ���������ς��łȂ����`�F�b�N
    if(Info::totalNumber >= Value::maxNumber) {
	Util::unlock();
	HakoIO::out("mainMode = 'errorIslandFull';");
	return;
    }

    // ���O�����邩�`�F�b�N
    if(strcmp(Value::islandName, "") == 0) {
	Util::unlock();
	HakoIO::out("mainMode = 'errorNoName';");
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

    // password�̑��ݔ���
    if(strcmp(Value::password, "") == 0) {
	Util::unlock();
	HakoIO::out("mainMode = 'errorNoPassword';");
	return;
    }

    // �m�F�p�p�X���[�h
    if(strcmp(Value::password, Value::password2)) {
	// password�ԈႢ
	Util::unlock();
	HakoIO::out("mainMode = 'errorWrongPassword';");
	return;
    }

    // �y�n���󂢂Ă��邩�̃`�F�b�N
    int sx = Value::pointX;
    int sy = Value::pointY;
    if(Map::countNeutral(sx, sy, 0, 91) != 91) {
	// 5�w�b�N�X���ɒ����ȊO�̒n�`����
	// �ꏊ���Ȃ�
	Util::unlock();
	HakoIO::out("mainMode = 'errorNotEnoughArea';");
	return;
    }

    // �������鎖�Ɍ���
    // ���ԍ����擾
    int id = Info::nextID;
    Info::nextID++;

    // ���̐��𑝂₷
    Info::totalNumber++;
    int number = Info::totalNumber;

    // ���I�u�W�F�N�g�̎擾
    Island *island = &(Info::islands[number - 1]);
    strcpy(island->name, Value::islandName);
    island->id = id;
    island->centerX = sx;
    island->centerY = sy;
    island->prize = 0;
    island->monster = 0;
    island->absent = Value::initialAbsent;
    strcpy(island->comment, "(���o�^)");
    strcpy(island->password, Value::password);
    island->money = Value::initialMoney;
    island->food = Value::initialFood;

    // �n�`�쐬
    // 5hex�����C�ɏ�����
    for(int i = 19; i < 91; i++) {
	Land *land = Map::getAround(sx, sy, i);
	if(land == 0) {
	    continue;
	}
	land->kind = Land::Sea;
	land->param = Land::SeaDeep;
	land->owner = 0;
    }

    // 2hex�͈͂��r�n�ɏ�����
    for(int i = 0; i < 19; i++) {
	Land *land = Map::getAround(sx, sy, i);
	if(land == 0) {
	    continue;
	}
	land->kind = Land::Waste;
	land->param = Land::WasteNormal;
	land->owner = number;
    }

    // 4Hex���ɗ��n�𑝐B
    for(int i = 0; i < 100; i++) {
	// �����_�����W
	Point p = Map::getPoint(sx, sy, Util::dice(61));
	if(p.x == -1) {
	    continue;
	}
	if(Map::countAround(p, Land::Sea, 1, 7) < 6){
	    // ����ɗ��n������ꍇ
	    Land *land = Map::getLand(p);
	    int kind = land->kind;
	    if(kind == Land::Waste) {
		// �r�n�͕��n�ɂ���
		land->kind = Land::Town;
		land->param = 0;
	    } else if(land->kind == Land::Sea) {
		if(land->param == Land::SeaShoal) {
		    // �󐣂͍r�n�ɂ���
		    land->kind = Land::Waste;
		    land->param = Land::WasteNormal;
		    land->owner = number;
		} else {
		    // �C�Ȃ�󐣂ɂ���
		    land->param = Land::SeaShoal;
		}
	    }
	}
    }

    // �X�����
    int count = 0;
    while(count < 3) {
	// �����_�����W
	Land *land = Map::getAround(sx, sy, Util::dice(19));
	if(land == 0) {
	    continue;
	}

	// ���������łɐX�łȂ���΁A�X�����
	if(land->kind != Land::Forest) {
	    land->kind = Land::Forest;
	    land->param = 5; // ��500�{
	    count++;
	}
    }

    // �������
    count = 0;
    while(count < 2) {
	// �����_�����W
	Land *land = Map::getAround(sx, sy, Util::dice(19));
	if(land == 0) {
	    continue;
	}

	// �������X�����łȂ���΁A�������
	if((land->kind != Land::Forest) &&
	   ((land->kind != Land::Town) ||
	    (land->param == 0))) {
	    land->kind = Land::Town;
	    land->param = 5; // �l��500�l
	    count++;
	}
    }

    // �R�����
    count = 0;
    while(count < 1) {
	// �����_�����W
	Land *land = Map::getAround(sx, sy, Util::dice(19));
	if(land == 0) {
	    continue;
	}

	// �������X�����łȂ���΁A�R�����
	if((land->kind != Land::Forest) &&
	   ((land->kind != Land::Town) ||
	    (land->param == 0))) {
	    land->kind = Land::Mountain;
	    land->param = 0; // �̌@��͂Ȃ�
	    count++;
	}
    }

    // ��n�����
    count = 0;
    while(count < 1) {
	// �����_�����W
	Land *land = Map::getAround(sx, sy, Util::dice(19));
	if(land == 0) {
	    continue;
	}

	// �������X�������R�łȂ���΁A��n�����
	if((land->kind != Land::Forest) &&
	   (land->kind != Land::Mountain) &&
	   ((land->kind != Land::Town) ||
	    (land->param == 0))) {
	    land->kind = Land::Base;
	    land->param = 0; // �o���n0
	    count++;
	}
    }

    // �R�}���h�쐬
    Command::initialize();

    // �v�f����
    Map::estimate();

    // �������O��������
    HakoIO::hisOutput(0, island->name);

    // �f�[�^��������
    HakoIO::writeComFile(id);
    HakoIO::writeInfoFile();
    HakoIO::writeMapFile();

    Util::unlock();

    Info::jsOut(0);
    HakoIO::out("mainMode = 'errorNewIsland';");
//    Sight::common();
}
