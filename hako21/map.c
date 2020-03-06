#include "map.h"Land *Map::land;// (�͈�/����hex��)�ꗗ// (0/1) (1/7) (2/19) (3/37) (4/61) (5/91) (6/127)// (7/169) (8/217) (9/271) (10/331) (11/397)const int ax[] = {0,0,1,-1,1,0,1,-1,0,1,-1,2,-2,2,-1,2,-1,0,1,-1,0,1,2,-2,2,-2,3,-3,3,-2,3,-2,2,-1,0,1,2,-2,-1,0,1,2,-2,3,-3,3,-3,4,-4,4,-3,4,-3,3,-2,3,-2,-1,0,1,2,-2,-1,0,1,2,3,-3,3,-3,4,-4,4,-4,5,-5,5,-4,5,-4,4,-3,4,-3,3,-2,-1,0,1,2,3,-3,-2,-1,0,1,2,3,-3,4,-4,4,-4,5,-5,5,-5,6,-6,6,-5,6,-5,5,-4,5,-4,4,-3,4,-3,-2,-1,0,1,2,3,-3,-2,-1,0,1,2,3,4,-4,4,-4,5,-5,5,-5,6,-6,6,-6,7,-7,7,-6,7,-6,6,-5,6,-5,5,-4,5,-4,4,-3,-2,-1,0,1,2,3,4,-4,-3,-2,-1,0,1,2,3,4,-4,5,-5,5,-5,6,-6,6,-6,7,-7,7,-7,8,-8,8,-7,8,-7,7,-6,7,-6,6,-5,6,-5,5,-4,5,-4,-3,-2,-1,0,1,2,3,4,-4,-3,-2,-1,0,1,2,3,4,5,-5,5,-5,6,-6,6,-6,7,-7,7,-7,8,-8,8,-8,9,-9,9,-8,9,-8,8,-7,8,-7,7,-6,7,-6,6,-5,6,-5,5,-4,-3,-2,-1,0,1,2,3,4,5,-5,-4,-3,-2,-1,0,1,2,3,4,5,-5,6,-6,6,-6,7,-7,7,-7,8,-8,8,-8,9,-9,9,-9,10,-10,10,-9,10,-9,9,-8,9,-8,8,-7,8,-7,7,-6,7,-6,6,-5,6,-5,-4,-3,-2,-1,0,1,2,3,4,5,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,-6,6,-6,7,-7,7,-7,8,-8,8,-8,9,-9,9,-9,10,-10,10,-10,11,-11,11,-10,11,-10,10,-9,10,-9,9,-8,9,-8,8,-7,8,-7,7,-6,7,-6,6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6};const int ay[] = {0,-1,-1,0,0,1,1,-2,-2,-2,-1,-1,0,0,1,1,2,2,2,-3,-3,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,3,3,-4,-4,-4,-4,-4,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,4,4,4,4,4,-5,-5,-5,-5,-5,-5,-4,-4,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,4,4,5,5,5,5,5,5,-6,-6,-6,-6,-6,-6,-6,-5,-5,-4,-4,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,6,6,6,6,6,-7,-7,-7,-7,-7,-7,-7,-7,-6,-6,-5,-5,-4,-4,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,7,7,7,7,7,7,-8,-8,-8,-8,-8,-8,-8,-8,-8,-7,-7,-6,-6,-5,-5,-4,-4,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,8,8,8,8,8,8,8,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-8,-8,-7,-7,-6,-6,-5,-5,-4,-4,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,9,9,9,9,9,9,9,9,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-9,-9,-8,-8,-7,-7,-6,-6,-5,-5,-4,-4,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,10,10,10,10,10,10,10,10,10,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-10,-10,-9,-9,-8,-8,-7,-7,-6,-6,-5,-5,-4,-4,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,11,11,11,11,11,11,11,11,11,11};// �̈�m��void Map::alloc() {    // �̈�m��    land = new Land[Value::worldSize * Value::worldSize];}// ������void Map::initialize() {    int size = Value::worldSize * Value::worldSize;    for(int i = 0; i < size; i++) {	land[i].initialize();    }}// �t�@�C���o��void Map::output(ofstream *ofs) {    int i = 0;    for(int y = 0; y < Value::worldSize; y++) {	for(int x = 0; x < Value::worldSize; x++) {	    land[i].output(ofs);	    i++;	}	*ofs << "\n";    }}// �t�@�C������void Map::input(ifstream *ifs) {    int i = 0;    for(int y = 0; y < Value::worldSize; y++) {	for(int x = 0; x < Value::worldSize; x++) {	    land[i].input(ifs);	    i++;	}	(*ifs).get(); // ���s�ǂݔ�΂�    }}// JavaScript�o��void Map::jsOut(int number) {    int i = 0;    HakoIO::out("mapData = [\n");    for(int y = 0; y < Value::worldSize; y++) {	HakoIO::out("\"");	for(int x = 0; x < Value::worldSize; x++) {	    land[i].jsOut(number);	    i++;	}	if(y == Value::worldSize - 1) {	    HakoIO::out("\"\n");	} else {	    HakoIO::out("\",\n");	}    }    HakoIO::out("];\n");}// ���ӂ̍��W��Ԃ�Point Map::getPoint(int sx, int sy, int d) {    Point p;    p.x = sx + ax[d];    p.y = sy + ay[d];    // �s�ɂ��ʒu����    if(((p.y % 2) == 0) && ((sy % 2) == 1)) {	p.x--;    }    if((p.x < 0) || (p.x >= Value::worldSize) ||       (p.y < 0) || (p.y >= Value::worldSize)) {	p.x = -1;	p.y = -1;    }    return p;}// �w����W��Land�̃|�C���^��Ԃ�Land *Map::getLand(int x, int y) {    if((x >= Value::worldSize) ||       (x < 0) ||       (y >= Value::worldSize) ||       (y < 0)) {	return 0;    }    return land + y * Value::worldSize + x;}// �w����W��Land�̃|�C���^��Ԃ�(���Ӕ�)Land *Map::getAround(int sx, int sy, int d) {    Point p = getPoint(sx, sy, d);    return getLand(p);}// �w����W���ӂŁA���̎�ނ̓y�n�𐔂���int Map::countAround(int sx, int sy, int kind, int from, int to, int param) {    int count = 0;    for(int i = from; i < to; i++) {	Land *land = getAround(sx, sy, i);	if(land == 0) {	    // �̈�O�͊C	    if(kind == Land::Sea) {		if((param == -1) || (param == Land::SeaDeep)) {		    count++;		}	    }	} else if(land->kind == kind){	    if((param == -1) || (param == land->param)) {		count++;	    }	}    }    return count;}// �w����W���ӂŁA���̎�ނ̓y�n�𐔂���int Map::countNeutral(int sx, int sy, int from, int to) {    int count = 0;    for(int i = from; i < to; i++) {	Land *land = getAround(sx, sy, i);	if(land == 0) {	    count++;	} else {	    if(land->owner == 0) {		count++;	    }	}    }    return count;}// �w����W���ӂŁA�����̓y�n�����n�����邩�ǂ���int Map::nearLand(int x, int y, int from, int to, int order) {    for(int i = from; i < to; i++) {	Land *land = getAround(x, y, i);	if(land != 0) {	    if(land->owner == order) {		// �C�܂��͊C���n�ȊO		if((land->kind != Land::Sea) &&		   (land->kind != Land::SBase)) {		    return 1;		}	    }	}    }    return 0;}// �w����W���ӂŁA�����̓y�n�����n���r�n�ȊO�����邩�ǂ���int Map::nearLand2(int x, int y, int from, int to, int order) {    for(int i = from; i < to; i++) {	Land *land = getAround(x, y, i);	if(land != 0) {	    if(land->owner == order) {		// �C�܂��͊C���n�܂��͍r�n�ȊO		if((land->kind != Land::Sea) &&		   (land->kind != Land::Waste) &&		   (land->kind != Land::SBase)) {		    return 1;		}	    }	}    }    return 0;}// �l�����̑��𐔂���void Map::estimate() {    int size = Value::worldSize * Value::worldSize;    // ����\����������    Info::clear();    // �S�n�`���Ȃ߂�    for(int i = 0; i < size; i++) {	land[i].estimate();    }}// �C�ۓx�v�Zvoid Map::calcSea(int x, int y) {    Land *land = getLand(x, y);    if(land != 0) {	if((land->kind != Land::Sea) &&	   (land->kind != Land::SBase)) {	    // �C�A�C���n�ȊO�͊֌W�Ȃ�	    return;	}    }    // ����4�w�b�N�X�։e����^����    for(int i = 0; i < 61; i++) {	Land *land = getAround(x, y, i);	if(land != 0) {	    land->seaLevel++;	}    }}// �̓y�̊���void Map::infLand(int x, int y) {    Land *land = getLand(x, y);    if(land == 0) {	// �̈�O�Ȃ�֌W�Ȃ�	return;    }    if((land->kind == Land::Sea) ||       (land->kind == Land::Waste) ||        (land->kind == Land::Monster) ||        (land->kind == Land::SBase) ||        (land->kind == Land::Monument)) {	// ��L�n�`�͊֌W�Ȃ�	return;    }    // �����n�т��֌W�Ȃ�    if(land->owner == 0) {	return;    }    // ����6�w�b�N�X����e�����󂯂�    int d = Util::dice(6) + 1;    Land *land2 = getAround(x, y, d);    if(land2 == 0) {	return;    }    if(land2->owner == 0) {	return;    }        // ���l�̓y�n�̏ꍇ    if(land2->owner != land->owner) {	if((land2->kind == Land::Sea) ||	   (land2->kind == Land::Waste) || 	   (land2->kind == Land::Monster) || 	   (land2->kind == Land::SBase)) {	    // ��L�n�`�͊֌W�Ȃ�	    return;	}	// ������ύX	Island *island = Info::getIsland(land->owner);	int id = island->id;	Island *island2 = Info::getIsland(land2->owner);	int id2 = island2->id;	int landValue = land->landValue();	log(214, 0, id, id2, 0, x, y, landValue);	land->owner = land2->owner;    }}// �w����W�ɂ�����w�b�N�X����void Map::process(int x, int y) {    Land *land = getLand(x, y);    Island *island = 0;    int id = 0;    if(land->owner != 0) {	island = Info::getIsland(land->owner);	id = island->id;    }    int landValue = land->landValue();    switch(land->kind) {    case Land::Sea: // �C	// ����	if(land->param == Land::SeaOil) {	    log(212, 0, id, 0, 0, x, y, landValue, 1000);	    island->money += 1000;	    // �͊�	    if(Util::dice(1000) < 40) {		log(213, 0, id, 0, 0, x, y, landValue);		land->kind = Land::Sea;		land->param = Land::SeaDeep;		land->owner = 0;	    }	}	return;    case Land::Town: // ���n�A��	// �����A�����A�΍�	if(island == 0) { return; } // �O�̂���	if((island->amonster > 0) && (land->param > 0)){
	    // �l�����b�o��
	    island->amonster--;
	    disMonster(land, x, y, 0);
	    return;
	}

	if(land->param >= 100) {
	    // �s�s�̏ꍇ�΍Д���
	    if(disFire(land, id, x, y, landValue)) {
		return;
	    }
	}

	if(island->shortage == 1) {
	    // �H���s��
	    int p = ((int)land->param) - Util::dice(30) - 1;
	    if(p < 0) {
		p = 0;
	    }
	    land->param = p;
	} else {
	    if(land->param == 0) {
		// ���n�̏ꍇ�A����������
		// �C�ۓx�ɂ���āA�������߂�
		int ratio;
		if(land->seaLevel >= Land::SeaLevel2) {
		    ratio = 20;
		} else if(land->seaLevel >= Land::SeaLevel1) {
		    ratio = 10;
		} else {
		    ratio = 5;
		}
		if(Util::dice(100) < 20) {
		    int count =
			countAround(x, y, Land::Farm, 1, 7) +
			    countAround(x, y, Land::Town, 1, 7) -
				countAround(x, y, Land::Town, 1, 7, 0);
		    if(count > 0) {
			// ������
			land->param++;
		    }
		}
	    } else {
		// �C�ۓx�ɂ���āA���E�l�A�������߂�
		int max, ratio;
		if(land->seaLevel >= Land::SeaLevel2) {
		    max = 100;
		    ratio = 3;
		} else if(land->seaLevel >= Land::SeaLevel1) {
		    max = 50;
		    ratio = 2;
		} else {
		    max = 20;
		    ratio = 1;
		}

		if(island->shortage == -1) {
		    // �U�v������
		    if(land->param < max) {
			land->param += Util::dice(10 * ratio) + 1;
			if(land->param > max) {
			    land->param = max;
			}
		    } else {
			land->param += Util::dice(ratio) + 1;
			if(land->param > 200) {
			    land->param = 200;
			}
		    }
		} else {
		    // �ʏ펞
		    if(land->param < max) {
			land->param += Util::dice(3 * ratio) + 1;
			if(land->param > max) {
			    land->param = max;
			}
		    }
		}
	    }
	}
	break;

    case Land::Forest: // �X
	// ����
	if(land->param < 200) {
	    land->param++;
	}
	break;

    case Land::Farm: // �_��
	if(island->shortage == 1) {
	    // �H���\��
	    if(disRiot(land, id, x, y, landValue)) {
		return;
	    }
	}
	break;

    case Land::Factory: // �H��
	// �΍Д���
	if(disFire(land, id, x, y, landValue)) {
	    return;
	}
	if(island->shortage == 1) {
	    // �H���\��
	    if(disRiot(land, id, x, y, landValue)) {
		return;
	    }
	}
	break;

    case Land::Base:
	if(island->shortage == 1) {
	    // �H���\��
	    if(disRiot(land, id, x, y, landValue)) {
		return;
	    }
	}

    case Land::SBase:
	{
	    int cKind = island->command;
	    int tx = island->tx;
	    int ty = island->ty;
	    int cost = Com::getCost(cKind);
	    if((cKind == Com::MissileNM) ||
	       (cKind == Com::MissilePP) ||
	       (cKind == Com::MissileLD) ||
	       (cKind == Com::MissileIS)) {
		// �~�T�C������
		// �e���~�T�C���ȊO�͋�������
		if(cKind != Com::MissileIS) {
		    if(distance(x, y, tx, ty) > Value::missileReach) {
			// �͂��Ȃ��̂Ŕ��˂��Ȃ�
			return;
		    }
		}

		// ���x���̎Z�o
		int level = land->getLevel();

		// ��������A���˗\�萔���c���Ă��Ă���茂���Â���
		while((island->money >= cost) &&
		      (island->amount > 0) &&
		      (level > 0)) {
		    // ���A�񐔂̃J�E���g
		    island->money -= cost;
		    island->amount--;
		    level--;

		    // �덷�ݒ�
		    int err;
		    if(cKind == Com::MissilePP) {
			// �o�o�~�T�C��
			err = 7;  // �덷1�w�b�N�X
		    } else {
			// ���̑�
			err = 19; // �덷2�w�b�N�X
		    }

		    // ���e�_�Z�o
		    Point p = getPoint(tx, ty, Util::dice(err));
		    if(p.x == -1) {
			// �n�}�O�ɗ�����
			log(500, 0, id, 0, cKind);
			continue;
		    }

		    // ���e�_�̗��n
		    Land *tLand = getLand(p);
		    int tKind = tLand->kind;
		    int tParam = tLand->param;
		    int tLandValue = tLand->landValue();
		    Island *tIsland = Info::getIsland(tLand->owner);
		    int tid = 0;
		    if(tIsland) {
			tid = tIsland->id;
		    }
		    
		    // �h�q����
		    if((tKind != Land::DBase) ||
		       (tParam != Land::DBaseTrue)) {
			if(countAround(p.x, p.y, Land::DBase, 1, 19,
				       Land::DBaseTrue)) {
			    // �󒆔��j
			    log(510, 0, id, tid, cKind,
				p.x, p.y);
			    continue;
			}
		    }

		    // ���j�e���ǂ����ŕ���
		    if(cKind == Com::MissileLD) {
			// ���j�e
			// ���n�̎�ނŕ���
			if(tKind == Land::Mountain) {
			    // �R
			    // �r�n�ɂȂ�
			    tLand->kind = Land::Waste;
			    tLand->param = Land::WasteMissile;
			    log(507, 0, id, tid, cKind,
				p.x, p.y, tLandValue);
			} else if(tKind == Land::SBase) {
			    // �C���n
			    // �[�C�ɂȂ�
			    tLand->kind = Land::Sea;
			    tLand->param = Land::SeaDeep;
			    tLand->owner = 0;
			    log(506, 0, id, tid, cKind,
				p.x, p.y, tLandValue);
			} else if(tKind == Land::Sea) {
			    if(tParam == Land::SeaDeep) {
				// �[�C
				// ����������
				// ��Q�Ȃ�
				log(505, 0, id, tid, cKind,
				    p.x, p.y, tLandValue);
			    } else if(tParam == Land::SeaShoal) {
				// ��
				// �[�C�ɂȂ�
				tLand->param = Land::SeaDeep;
				log(508, 0, id, tid, cKind,
				    p.x, p.y, tLandValue);
			    } else {
				// ���c
				// �[�C�ɂȂ�
				tLand->param = Land::SeaDeep;
				tLand->owner = 0;
				log(506, 0, id, tid, cKind,
				    p.x, p.y, tLandValue);
			    }
			} else {
			    // ���̑�
			    // �󐣂ɂȂ�
			    tLand->kind = Land::Sea;
			    tLand->param = Land::SeaShoal;
			    tLand->owner = 0;
			    log(509, 0, id, tid, cKind,
				p.x, p.y, tLandValue);
			}
		    } else {
			// �ʏ�e
			// ���n�̎�ނŕ���

			if(tKind == Land::Monster) {
			    // ���b
			    // �d������Ȃǂł��낢�땪��
			    Monster::fromParam(tParam);
			    if(Monster::isHard()) {
				// �d����
				// �_���[�W�Ȃ�
				log(501, 0, id, tid, cKind,
				    p.x, p.y, tLandValue);
			    } else {
				// �ʏ�̎�
				Monster::hp--;
				if(Monster::hp == 0) {
				    // �|����
				    // �r�n�ɂ���
				    tLand->kind = Land::Waste;
				    tLand->param = Land::WasteMissile;
				    log(503, 0, id, tid, cKind,
					p.x, p.y, tLandValue);
				    int value = Monster::getValue();
				    if((value != 0) &&
				       (tid != 0)) {
					// �c�[�ɒl�i����
					log(504, 0, tid, 0, cKind,
					    p.x, p.y, tLandValue, value);
					tIsland->money += value;
				    }

				    // �L���}�[�N
				    island->monster |= 1<<Monster::kind;

				    // ��n�̌o���l
				    land->param += Monster::getExp();
				    if((land->param) > 200) {
					land->param = 200;
				    }
				} else {
				    // �_���[�W�̂�
				    tLand->param = Monster::toParam();
				    log(502, 0, id, tid, cKind,
					p.x, p.y, tLandValue);
				}
			    }
			} else if((tKind == Land::Waste) ||
				  (tKind == Land::Mountain) ||
				  ((tKind == Land::Sea) && 
				   (tParam != Land::SeaOil))) {
			    // �R�A�r�n�A�C(���c�ȊO)
			    // ��Q�Ȃ�
			    log(505, 0, id, tid, cKind,
				p.x, p.y, tLandValue);
			} else if(tKind == Land::SBase) {
			    // �C���n
			    // �C�̂ӂ�
			    log(505, 0, id, 0, cKind,
				p.x, p.y, 0);
			} else if(tKind == Land::Sea) {
			    // ���c
			    // �C�ɂȂ�
			    tLand->kind = Land::Sea;
			    tLand->param = Land::SeaDeep;
			    tLand->owner = 0;
			    log(506, 0, id, tid, cKind,
				p.x, p.y, tLandValue);
			} else {
			    // ���̑�
			    // �s�s�Ȃ�o���l
			    if(tKind == Land::Town) {
				land->param += tLand->param / 20;
				if((land->param) > 200) {
				    land->param = 200;
				}
				// �e���e�łȂ���Γ�J�E���g
				if(cKind != Com::MissileIS) {
				    if(id != tid) {
					island->boatPeople += tLand->param;
				    }
				}
			    }

			    // �r�n�ɂȂ�
			    tLand->kind = Land::Waste;
			    tLand->param = Land::WasteMissile;
			    log(507, 0, id, tid, cKind,
				p.x, p.y, tLandValue);
			}
		    }

		    // ���̎��_�ł��łɊ�n�łȂ��Ȃ��Ă���΁A
		    // ���[�v�𔲂���
		    if((land->kind != Land::Base) &&
		       (land->kind != Land::SBase)) {
			break;
		    }
		}
	    }
	}
	break;

    case Land::DBase:
	if(island->shortage == 1) {
	    // �H���\��
	    if(disRiot(land, id, x, y, landValue)) {
		return;
	    }
	}

	if(land->param == Land::DBaseFalse) {
	    // �n���{�e�΍Д���
	    if(disFire(land, id, x, y, landValue)) {
		return;
	    }
	}

	// ����
	if(land->flag == 1) {
	    log(404, 0, id, 0, 0,
		x, y, landValue);
	    wideDamage(x, y);
	}
	break;

    case Land::Monster:
	// �ړ�
	Monster::fromParam(land->param);
	if(Monster::isHard()) {
	    break;
	}
	if(Monster::move > land->flag) {
	    int flag = 0;
	    for(int i = 0; i < 3; i++) {
		int r = Util::dice(6) + 1;
		Point p = getPoint(x, y, r);
		if(p.x == -1) {
		    continue;
		}
		Land *tLand = getLand(p);
		int tKind = tLand->kind;
		switch(tKind) {
		case Land::Sea:
		case Land::SBase:
		case Land::Mountain:
		case Land::Monster:
		case Land::Monument:
		    break;
		default:
		    {
			// �ړ�
			int tLandValue = tLand->landValue();
			log(406, 0, id, 0, 0,
			    x, y, landValue);
			log(407, 0, id, 0, 0,
			    p.x, p.y, tLandValue);
			// �ړ���ݒ�
			tLand->kind = land->kind;
			tLand->param = land->param;
			tLand->flag = land->flag + 1;

			// �������Ƃ�����r�n��
			land->kind = Land::Waste;
			land->param = Land::WasteNormal;
			land->flag = 0;

			flag = 1;
		    }
		    break;
		}
		if(flag == 1) {
		    break;
		}
	    }
	}
	break;

    case Land::Monument:
	// ����
	if(land->flag == 1) {
	    Island *tIsland = Info::getIslandByID(island->target);
	    log(408, 0, id, 0, 0, x, y, landValue);
	    land->kind = Land::Waste;
	    land->param = Land::WasteNormal;
	    if(tIsland != 0) {
		// ���e�_�Z�o
		Point p = getPoint(tIsland->centerX,
				   tIsland->centerY,
				   Util::dice(91));
		log(409, 0, -1, 0, 0, p.x, p.y);
		wideDamage(p.x, p.y);
	    }
	}
	break;

    default:
	break;
    }
}

// �S�̍ЊQ
void Map::globalDisaster() {
    // �n�k
    if(Util::dice(1000) < Value::disEarthquake1) {
	disEarthquake(Util::dice(Value::worldSize + 10) - 5,
		      Util::dice(Value::worldSize + 10) - 5);
    }

    // �Ôg
    if(Util::dice(1000) < Value::disTsunami) {
	disTsunami(Util::dice(Value::worldSize + 10) - 5,
		   Util::dice(Value::worldSize + 10) - 5);
    }

    // �䕗
    if(Util::dice(1000) < Value::disTyphoon) {
	disTyphoon(Util::dice(Value::worldSize + 10) - 5,
		   Util::dice(Value::worldSize + 10) - 5);
    }

    // 覐�
    if(Util::dice(1000) < Value::disMeteo) {
	disMeteo(Util::dice(Value::worldSize + 10) - 5,
		 Util::dice(Value::worldSize + 10) - 5);
    }

    // ����覐�
    if(Util::dice(1000) < Value::disHugeMeteo) {
	int x = Util::dice(Value::worldSize + 4) - 2;
	int y = Util::dice(Value::worldSize + 4) - 2;

	// ���b�Z�[�W
	log(420, 0, -1, 0, 0, x, y);
	wideDamage(x, y);
    }

    // ����
    if(Util::dice(1000) < Value::disEruption) {
	int x = Util::dice(Value::worldSize);
	int y = Util::dice(Value::worldSize);
	disEruption(x, y);
    }

    // ���b
    for(int i = 0; i < Value::disMonster; i++) {
	// ���W
	int x = Util::dice(Value::worldSize);
	int y = Util::dice(Value::worldSize);
	Land *land = getLand(x, y);
	switch(land->kind) {
	case Land::SBase:
	case Land::Sea:
	case Land::Monster:
	case Land::Monument:
	case Land::Mountain:
	    break;
	default:
	    {
		int l = 3;
		if(land->owner != 0) {
		    Island *island = Info::getIsland(land->owner);
		    int pop = island->pop;
		    if(pop < 1000) {
			break;
		    } else if(pop < 2500) {
			l = 1;
		    } else if(pop < 4000) {
			l = 2;
		    } else {
			l = 3;
		    }
		}
		disMonster(land, x, y, l);
	    }
	    break;
	}
	
    }
}



// ���b
void Map::disMonster(Land *land, int x, int y, int level) {
    int id = 0;
    int landValue = land->landValue();

    if(land->owner != 0) {
	Island *island = Info::getIsland(land->owner);
	id = island->id;
    }
    log(424, 0, id, 0, 0, x, y, landValue);

    Monster::makeMonster(level);
    land->kind = Land::Monster;
    land->param = Monster::toParam();
    return;
}

// �Ύ�
int Map::disFire(Land *land, int id, int x, int y, int landValue) {
    if(countAround(x, y, Land::Forest, 1, 7)) {
	return 0;
    }
    if(countAround(x, y, Land::Monument, 1, 7)) {
	return 0;
    }
    if(Util::dice(1000) < Value::disFire) {
	land->kind = Land::Waste;
	land->param = Land::WasteNormal;
	log(401, 0, id, 0, 0, x, y, landValue);
	return 1;
    } else {
	return 0;
    }
}

// �\��
int Map::disRiot(Land *land, int id, int x, int y, int landValue) {
    if(Util::dice(4) == 0) {
	land->kind = Land::Waste;
	land->param = Land::WasteNormal;
	log(426, 0, id, 0, 0, x, y, landValue);
	return 1;
    } else {
	return 0;
    }
}

// �n�k
void Map::disEarthquake(int x, int y) {
    // �n�k�������b�Z�[�W
    log(411, 0, -1, 0, 0, x, y);
    // 10Hex�����[�v
    for(int i = 0; i < 331; i++) {
	Point p = getPoint(x, y, i);
	if(p.x == -1) {
	    continue;
	}
	Land *land = getLand(p);
	int landValue = land->landValue();
	int kind = land->kind;
	int param = land->param;
	int id = 0;
	if(land->owner != 0) {
	    Island *island = Info::getIsland(land->owner);
	    id = island->id;
	}

	// �Ώےn�`
	if(((kind == Land::Town) && (param >= 100)) ||
	   ((kind == Land::DBase) && (param == Land::DBaseFalse)) ||
	   (kind == Land::Factory)) {
	    // 1/4�̊m���ōr�n��
	    if(Util::dice(4) == 0) {
		log(410, 0, id, 0, 0, p.x, p.y, landValue);
		land->kind = Land::Waste;
		land->param = Land::WasteNormal;
	    }
	}
    }
    return;
}

// �Ôg
void Map::disTsunami(int x, int y) {
    // �Ôg�������b�Z�[�W
    log(412, 0, -1, 0, 0, x, y);

    // 10Hex�����[�v
    for(int i = 0; i < 331; i++) {
	Point p = getPoint(x, y, i);
	if(p.x == -1) {
	    continue;
	}
	Land *land = getLand(p);
	int landValue = land->landValue();
	int kind = land->kind;
	int id = 0;
	if(land->owner != 0) {
	    Island *island = Info::getIsland(land->owner);
	    id = island->id;
	}

	// �Ώےn�`
	if((kind != Land::Sea) &&
	   (kind != Land::Waste) &&
	   (kind != Land::Forest) &&
	   (kind != Land::Mountain) &&
	   (kind != Land::Monster) &&
	   (kind != Land::SBase) &&
	   ((kind != Land::Town) || (land->param != 0))&&
	   (kind != Land::Monument)) {
	    int c =
		countAround(p.x, p.y, Land::Sea, 1, 7) + 
		countAround(p.x, p.y, Land::SBase, 1, 7);
	    if(Util::dice(12) < (c - 1)) {
		log(410, 0, id, 0, 0, p.x, p.y, landValue);
		land->kind = Land::Waste;
		land->param = Land::WasteNormal;
	    }
	}
    }
    return;
}

// �䕗
void Map::disTyphoon(int x, int y) {
    // �䕗�������b�Z�[�W
    log(413, 0, -1, 0, 0, x, y);

    // 10Hex�����[�v
    for(int i = 0; i < 331; i++) {
	Point p = getPoint(x, y, i);
	if(p.x == -1) {
	    continue;
	}
	Land *land = getLand(p);
	int landValue = land->landValue();
	int kind = land->kind;
	int id = 0;
	if(land->owner != 0) {
	    Island *island = Info::getIsland(land->owner);
	    id = island->id;
	}

	// �Ώےn�`
	if((kind == Land::Farm) ||
	   ((kind == Land::DBase) && (land->param == Land::DBaseFalse))){
	    // �X�A����ыL�O��𐔂���
	    int c =
		countAround(p.x, p.y, Land::Forest, 1, 7) + 
		countAround(p.x, p.y, Land::Monument, 1, 7);
	    if(Util::dice(12) < (6 - c)) {
		log(414, 0, id, 0, 0, p.x, p.y, landValue);
		land->kind = Land::Town;
		land->param = 0;
	    }
	}
    }
    return;
}

// �����Q
void Map::disMeteo(int x, int y) {
    // �����Q���b�Z�[�W
    log(415, 0, -1, 0, 0, x, y);

    // 10Hex�����[�v
    do {
	Point p = getPoint(x, y, Util::dice(331));
	if(p.x == -1) {
	    continue;
	}
	Land *land = getLand(p);
	int landValue = land->landValue();
	int kind = land->kind;
	int param = land->param;
	int id = 0;
	if(land->owner != 0) {
	    Island *island = Info::getIsland(land->owner);
	    id = island->id;
	}


	if((kind == Land::Sea) && (param == Land::SeaDeep)){
	    // �C(����������)
	    log(416, 0, id, 0, 0, p.x, p.y, landValue);
	} else if((kind == Land::Sea) && (param == Land::SeaShoal)) {
	    // ��(�P��)
	    log(417, 0, id, 0, 0, p.x, p.y, landValue);
	    land->param = Land::SeaDeep;
	} else if((kind == Land::Sea) || (kind == Land::SBase)) {
	    // �C���n�A���c(�C�̑���)
	    log(418, 0, id, 0, 0, p.x, p.y, landValue);
	    land->kind = Land::Sea;
	    land->param = Land::SeaDeep;
	    land->owner = 0;
	} else {
	    // ���v
	    log(419, 0, id, 0, 0, p.x, p.y, landValue);
	    land->kind = Land::Sea;
	    land->param = Land::SeaDeep;
	    land->owner = 0;
	}
    } while(Util::dice(2) == 0);
    return;
}

// ����
void Map::disEruption(int x, int y) {
    // ���S
    log(421, 0, -1, 0, 0, x, y);
    Land *land = getLand(x, y);
    land->kind = Land::Mountain;
    land->param = 0;

    // ����
    for(int i = 1; i < 7; i++) {
	Point p = getPoint(x, y, i);
	if(p.x == -1) {
	    continue;
	}

	Land *land = getLand(p);
	int landValue = land->landValue();
	int kind = land->kind;
	int param = land->param;
	int id = 0;
	if(land->owner != 0) {
	    Island *island = Info::getIsland(land->owner);
	    id = island->id;
	}

	if((kind == Land::Sea) || (kind == Land::SBase)) {
	    if((kind == Land::Sea) && (param == Land::SeaShoal)) {
		// �󐣂���r�n��
		land->kind = Land::Waste;
		land->param = Land::WasteNormal;
	    } else {
		// �C����󐣂�
		land->param = Land::SeaShoal;
	    }
	    int landValue = land->landValue();
	    log(422, 0, id, 0, 0, p.x, p.y, landValue);
	} else if(kind != Land::Mountain) {
	    // �r�n��
	    land->kind = Land::Waste;
	    land->param = Land::WasteNormal;
	    log(423, 0, id, 0, 0, p.x, p.y, landValue);
	}
    }
}

// �
void Map::getBoatPeople(Island *island) {
    island->boatTotal = 0;
    if(island->boatPeople < 2) {
	return;
    }
    int rest = island->boatPeople / 2;
    int total = 0;
    int cx = island->centerX;
    int cy = island->centerY;
    for(int i = 0; i < 91; i++) {
	Land *land = getAround(cx, cy, i);
	if(land == 0) {
	    continue;
	}
	if(land->kind == Land::Town) {
	    if(land->param > 0) {
		int r = MIN(MIN(rest, 200 - land->param), 50);
		land->param += r;
		rest -= r;
		total += r;
		if(rest == 0) {
		    break;
		}
	    }
	}
    }
    if(total > 0) {
	island->boatTotal = total;
	log(425, 0, island->id, 0, 0, 0, 0, 0, total);
    }
}

// �L���Q
void Map::wideDamage(int x, int y) {
    for(int i = 0; i < 19; i++) {
	Point p = getPoint(x, y, i);
	if(p.x == -1) {
	    continue;
	}

	Land *land = getLand(p);
	int landValue = land->landValue();
	int kind = land->kind;
	int param = land->param;
	int id = 0;
	if(land->owner != 0) {
	    Island *island = Info::getIsland(land->owner);
	    id = island->id;
	}

	if(i > 6) {
	    // �r�n��
	    switch(kind) {
	    case Land::Sea:
	    case Land::SBase:
	    case Land::Waste:
	    case Land::Mountain:
		break;
	    default:
		log(403, 0, id, 0, 0, p.x, p.y, landValue);
		land->kind = Land::Waste;
		land->param = Land::WasteNormal;
		break;
	    }
	} else {
	    // ��
	    if((kind == Land::Sea) || (kind == Land::SBase)) {
		if((param == Land::SeaOil) || (kind == Land::SBase)) {
		    // �������
		    log(403, 0, id, 0, 0, p.x, p.y, landValue);
		} else if(param == Land::SeaShoal) {
		    // ������
		    log(405, 0, id, 0, 0, p.x, p.y, landValue);
		}
		land->kind = Land::Sea;
		land->param = Land::SeaDeep;
		land->owner = 0;
	    } else {
		// ���v
		log(402, 0, id, 0, 0, p.x, p.y, landValue);
		land->kind = Land::Sea;
		land->param = Land::SeaShoal;
		land->owner = 0;
		if(i == 0) {
		    land->param = Land::SeaDeep;
		}
	    }
	}
    }
}


// �y�n�̎�����X�V
void Map::deleteIslands(int *dFlag) {
    int size = Value::worldSize * Value::worldSize;
    for(int i = 0; i < size; i++) {
	if(dFlag[land[i].owner] == 1) {
	    // �Cor�󐣂ɂ���
	    land[i].kind = Land::Sea;
	    land[i].owner = 0;
	    if(Util::dice(3) == 0) {
		land[i].param = Land::SeaDeep;
	    } else {
		land[i].param = Land::SeaShoal;
	    }
	}
    }
}

// �y�n�̎�����X�V
void Map::changeOwner(int *newOrder) {
    int size = Value::worldSize * Value::worldSize;
    for(int i = 0; i < size; i++) {
	land[i].changeOwner(newOrder);
    }
}

// ���O�o�͂̃G�C���A�X
void Map::log(int kind, int secret, int mIsland, int sIsland,
	      int cKind, int x, int y, int land, int amount) {
    HakoIO::logOutput(kind, secret, mIsland, sIsland,
		      cKind, x, y, land, amount);
}

// �����v�Z
int Map::distance(int sx, int sy, int x, int y) {
    int dx, dy;
    int ym = 0;
    if(sx < x) {
	dx = x - sx;
	if((sy % 2) == 0) {
	    ym = 1;
	}
    } else {
	dx = sx - x;
	if((sy % 2) == 1) {
	    ym = 1;
	}
    }

    if(sy < y) {
	dy = y - sy;
    } else {
	dy = sy - y;
    }
    dx -= (dy + ym) / 2;
    if(dx < 0) { dx = 0; }
    return dx + dy;
}

// �n�`������
void Land::initialize() {
    kind = Sea;
    param = SeaDeep;
    owner = 0;
}

// �n�`���t�@�C���o��
void Land::output(ofstream *ofs) {
    sprintf(HakoIO::buffer, "%x%02x%02x", kind, param, owner);
    *ofs << HakoIO::buffer;
}

// �n�`���t�@�C������
void Land::input(ifstream *ifs) {
    HakoIO::buffer[0] = ifs->get();
    HakoIO::buffer[1] = 0;
    kind = Util::hex(HakoIO::buffer);
    HakoIO::buffer[0] = ifs->get();
    HakoIO::buffer[1] = ifs->get();
    HakoIO::buffer[2] = 0;
    param = Util::hex(HakoIO::buffer);
    HakoIO::buffer[0] = ifs->get();
    HakoIO::buffer[1] = ifs->get();
    owner = Util::hex(HakoIO::buffer);

    // ���łɃt���O����������
    flag = 0;
    seaLevel = 0;
}

// �n�`��JavaScript�o��
void Land::jsOut(int number) {
    // owner�Ȃ�f�ʂ�
    if(number == owner) {
	sprintf(HakoIO::buffer, "%x%02x%02x", kind, param, owner);
    } else {
	// owner�łȂ��ꍇ
	// �n�`�̎�ނŕ���
	switch(kind) {
	case Forest:
	case Base:
	    // �X�Ɗ�n
	    sprintf(HakoIO::buffer, "%x%02x%02x", Forest, 0, owner);
	    break;

	case DBase:
	    // �h�q�{�݂ƃn���{�e
	    sprintf(HakoIO::buffer, "%x%02x%02x", DBase, DBaseTrue, owner);
	    break;

	case SBase:
	    // �C���n
	    sprintf(HakoIO::buffer, "%x%02x%02x", Sea, SeaDeep, 0);
	    break;

	default:
	    // ���̑��͑f�ʂ�
	    sprintf(HakoIO::buffer, "%x%02x%02x", kind, param, owner);
	    break;
	}
    }


    HakoIO::out(HakoIO::buffer);
}

// �l�����̑��𐔂���
void Land::estimate() {
    if(owner == 0) {
	return;
    }
    Island *island = Info::getIsland(owner);

    // �L��
    if((kind != SBase) && (kind != Sea)) {
	island->area++;
    }

    // �e�v�f
    switch(kind) {
    case Town:
	island->pop += param;
	break;

    case Farm:
	island->farm += param;
	break;

    case Factory:
	island->factory += param;
	break;

    case Mountain:
	island->mountain += param;
	break;

    default:
	break;
    }
}

int Land::landValue() {
    switch(kind) {
    case Sea:
	return kind * 10 + param;

    case  Waste:
	return kind * 10;

    case Town:
	if(param == 0) {
	    return 20;
	} else if(param < 30) {
	    return 21;
	} else if(param < 100) {
	    return 22;
	} else {
	    return 23;
	}
	
    case Forest:
    case Farm:
    case Factory:
    case Base:
    case Mountain:
    case SBase:
	return kind * 10;

    case DBase:
	return kind * 10 + param;

    case Monster:
	return 200 + (param / 20);

    case Monument:
	return 300 + param;
    default:
	return 0;
    }
}

// �y�n�̎�����X�V
void Land::changeOwner(int *newOrder) {
    if(owner == 0) { 
	return;
    }
    owner = newOrder[owner - 1];
}

// ���x�������߂�
int Land::getLevel() {
    if(kind == Base) {
	if(param < 20) {
	    return 1;
	} else if(param < 60) {
	    return 2;
	} else if(param < 120) {
	    return 3;
	} else if(param < 200) {
	    return 4;
	} else {
	    return 5;
	}
    } else if(kind == SBase) {
	if(param < 50) {
	    return 1;
	} else if(param < 200) {
	    return 2;
	} else {
	    return 3;
	}
    } else {
	return 0;
    }
}
