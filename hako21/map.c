#include "map.h"
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