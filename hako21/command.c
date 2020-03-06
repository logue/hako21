#include "command.h"

Com *Command::coms = 0;

// ��p
const int costTable[] = {
    Com::Prepare,   5,    // ���n
    Com::Prepare2,  100,  // �n�ς�
    Com::Reclaim,   150,  // ����
    Com::Destroy,   200,  // �@��
    Com::SellTree,  0,    // ����
    Com::Widen,     100,  // �̓y�g��
    Com::Plant,     50,   // �A��
    Com::Farm,      20,   // �_�ꐮ��
    Com::Factory,   100,  // �H�ꌚ��
    Com::Mountain,  300,  // �̌@�ꐮ��
    Com::Base,      300,  // �~�T�C����n����
    Com::DBase,     800,  // �h�q�{�݌���
    Com::SBase,     8000, // �C���n����
    Com::Monument,  9999, // �L�O�茚��
    Com::Haribote,  1,    // �n���{�e�ݒu
    Com::MissileNM, 20,   // �~�T�C������
    Com::MissilePP, 50,   // PP�~�T�C������
    Com::MissileLD, 100,  // ���n�j��e����
    Com::MissileIS, 150,  // �e���~�T�C������
    Com::Monster,   3000, // ���b�h��
    Com::DoNothing, 0,    // �����J��
    Com::Sell,      -100, // �H���A�o
    Com::Money,     100,  // ��������
    Com::Food,      -100, // �H������
    Com::Propaganda,1000, // �U�v����
    Com::Giveup,    0,    // ���̕���
    Com::Move,      1000, // ���_�ύX
    -1
    };

void Command::alloc() {
    coms = new Com[Value::commandMax];
}

void Command::initialize() {
    if(coms == 0) {
	Command::alloc();
    }
    for(int i = 0; i < Value::commandMax; i++) {
	coms[i].initialize();
    }
}

void Command::jsOut() {
    HakoIO::out("comData = [\n");
    for(int i = 0; i < Value::commandMax; i++) {
	coms[i].jsOut();
	if(i < (Value::commandMax - 1)) {
	    HakoIO::out(",");
	}
	HakoIO::out("\n");
    }
    HakoIO::out("];\n");
}

void Command::input(ifstream *ifs) {
    for(int i = 0; i < Value::commandMax; i++) {
	coms[i].input(ifs);
    }
}

void Command::output(ofstream *ofs) {
    for(int i = 0; i < Value::commandMax; i++) {
	coms[i].output(ofs);
    }
}

void Command::exec(Island *island, int order) {
    // 1�ڂ����o��
    Com *c = &(coms[0]);

    // ���s����
    int r = c->exec(island, order);
    if(r == 2) {
	// �񐔌���������
	// �������Ȃ�
    }  else {
	// ���炷
	for(int i = 0; i < (Value::commandMax - 1); i++) {
	    coms[i] = coms[i + 1];
	}

	// �����Ɏ����J��
	Com c2;
	c2.kind = Com::DoNothing;
	c2.target = 0;
	c2.x = 0;
	c2.y = 0;
	c2.amount = 0;
	coms[Value::commandMax - 1] = c2;

	if(r == 0) {
	    // �����R�}���h�Ȃ玟�����s
	    exec(island, order);
	}
    }
}

void Com::jsOut() {
    sprintf(HakoIO::buffer, "[%d,%d,%d,%d,%d]",kind,target,x,y,amount);
    HakoIO::out(HakoIO::buffer);
}

void Com::input(ifstream *ifs) {
    *ifs >> kind >> target >> x >> y >> amount;
}

void Com::output(ofstream *ofs) {
    *ofs << kind << " " << target << " " <<
	x << " " << y << " " << amount << "\n";
}

void Com::initialize() {
    kind = DoNothing;
    target = 0;
    x = 0;
    y = 0;
    amount = 0;
}

int Com::exec(Island *island, int order) {
    // �e��̒l
    int id = island->id;
    Land *land = Map::getLand(x, y);
    if(land == 0) {
	return 1;
    }
    int landValue = land->landValue();

    // �l�̃e�X�g(�ꉞ)
    if(x < 0) { x = 0; } 
    else if(x >=  Value::worldSize) { x = Value::worldSize - 1; }
    if(y < 0) { y = 0; } 
    else if(y >=  Value::worldSize) { x = Value::worldSize - 1; }
    if(amount < 0) { amount = 0; } 
    else if(amount >= 100) { amount = 99; }

    if(kind == DoNothing) {
	// �����J��`�F�b�N
	island->money += 10;
	island->absent++;
	if(island->absent >= Value::giveupTurn) {
	    // ��������
	    Com c;
	    c.kind = Giveup;
	    c.target = 0;
	    c.x = 0;
	    c.y = 0;
	    c.amount = 0;
	    Command::coms[0] = c;
	    return 2;
	}
	return 1;
    }
    island->absent = 0;

    // �����`�F�b�N
    int cost = getCost();
    if(cost > 0) {
	// ���̏ꍇ
	if(island->money < cost) {
	    // �����s�����O
	    log(100, 0, id, 0, kind);
	    return 0;
	}
    } else if(cost < 0) {
	// �H���̏ꍇ
	if(island->food < cost) {
	    // �H���s�����O
	    log(101, 0, id, 0, kind);
	    return 0;
	}
    }

    // ���̍��W�������̂��̂łȂ��Əo���Ȃ���̃`�F�b�N
    switch(kind) {
    case Prepare:  // ���n
    case Prepare2: // �n�ς�
    case SellTree: // ����
    case Plant: // �A��
    case Farm: // �_�ꐮ��
    case Factory: // �H�ꌚ��
    case Mountain: // �̌@�ꐮ��
    case Base: // �~�T�C����n����
    case DBase: // �h�q�{�݌���
    case Monument: // �L�O�茚��
    case Haribote: // �n���{�e�ݒu
    case Move: // ���_�ύX
	if(land->owner != order) {
	    // �����̓y�n�łȂ����O 
	    log(102, 0, id, 0, kind, x, y);
	    return 0;
	}
	break;
    default:
	break;
    }

    switch(kind) {
    case Prepare:  // ���n
    case Prepare2: // �n�ς�
	// �����̓y�n�ł��鎖�̓`�F�b�N�ς�
	// �R�A���b�A�C���n�A�C�ȊO�͐���
	if((land->kind == Land::Mountain) ||
	   (land->kind == Land::Monster) ||
	   (land->kind == Land::SBase) ||
	   (land->kind == Land::Sea)) {
	    // �y�n���s�K�����O
	    log(103, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}

	// ����
	// �R�X�g��������
	island->money -= cost;

	// ���n��
	land->kind = Land::Town;
	land->param = 0;
	
	// ���O
	log(200, 0, id, 0, kind, x, y);

	if(kind == Prepare2) {
	    // �n�ς��̓^�[���i�܂�
	    if(Util::dice(1000) < Value::disEarthquake2) {
		// �n�k����
		Map::disEarthquake(x, y);
	    }
	    return 0;
	} else {
	    if(Util::dice(1000) < Value::disMaizo) {
		// ����������
		int v = 100 + Util::dice(901);
		island->money += v;
		log(211, 0, id, 0, 0, 0, 0, 0, v);
	    }
	    return 1;
	}
	break;

    case Reclaim: // ����
	if(Map::nearLand(x, y, 1, 7, order) == 0) {
	    // ���͂Ɏ����̓y�n�A�����n���Ȃ���Ύ��s
	    // ���͂ɗ̒n���Ȃ����O
	    log(104, 0, id, 0, kind, x, y);
	    return 0;
	}
	
	if((land->kind != Land::Sea) &&
	   (land->kind != Land::SBase)) {
	    // �C�A�C���n�ȊO�́A�s�K�؂ȓy�n
	    log(103, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}

	// ����
	// �R�X�g��������
	island->money -= cost;
	
	if((land->kind == Land::Sea) &&
	   (land->param == Land::SeaShoal)) {
	    // �󐣂͍r�n�ɂ���
	    land->kind = Land::Waste;
	    land->param = Land::WasteNormal;
	    land->owner = order;

	    if((Map::countAround(x, y, Land::Sea, 1, 7) +
		Map::countAround(x, y, Land::SBase, 1, 7)) <= 3) {
		// ���͂̊C(or�C���n)�̐���3�ȉ�
		// ����炷�ׂĂ�󐣂ɂ���
		for(int i = 1; i < 7; i++) {
		    Land *l = Map::getAround(x, y, i);
		    if(l == 0) {
			continue;
		    }
		    if((l->kind == Land::Sea) ||
		       (l->kind == Land::SBase)) {
			// �󐣂ɂ���
			l->kind = Land::Sea;
			l->param = Land::SeaShoal;
			l->owner = 0;
		    }
		}
	    }

	} else {
	    // ����ȊO�͐󐣂ɂ���
	    land->kind = Land::Sea;
	    land->param = Land::SeaShoal;
	    land->owner = 0;
	}

	// ���O
	log(200, 0, id, 0, kind, x, y);
	return 1;
	break;

    case Destroy: // �@��
	if(Map::nearLand(x, y, 0, 37, order) == 0) {
	    // ����3�w�b�N�X���Ɏ����̓y�n�A�����n���Ȃ���Ύ��s
	    // ���͂ɗ̒n���Ȃ����O
	    log(104, 0, id, 0, kind, x, y);
	    return 0;
	}

	if((land->kind == Land::Monster) ||
	   (land->kind == Land::SBase)) {
	    // ���b�A�C���n�͌@��s��
	    log(103, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}

	// �Ώےn�`�ɂ���ĕ���
	if(land->kind == Land::Sea) {
	    if(land->param == Land::SeaDeep) {
		// �Ζ��@��
		// �ʂ��֌W���Ă���
		if(amount == 0) {
		    amount = 1;
		}
		int c = MIN((cost * amount), island->money);
		island->money -= c;
		int ratio = c / cost;
		if(Util::dice(100) < ratio) {
		    // ���c����
		    land->kind = Land::Sea;
		    land->param = Land::SeaOil;
		    land->owner = order;
		    log(201, 0, id, 0, kind, x, y, 0, c);
		} else {
		    // ���c�����Ȃ炸
		    log(202, 0, id, 0, kind, x, y, 0, c);
		}
		return 1;
	    } else if(land->param == Land::SeaOil) {
		// ���c�͌@��ł���
		// �y�n���s�K�����O
		log(103, 0, id, 0, kind, x, y, landValue);
		return 0;
	    }
	} else {
	    if(land->owner != order) {
		// �C�ȊO�Ŏ����̓y�n�łȂ����O 
		log(102, 0, id, 0, kind, x, y);
		return 0;
	    }
	}

	// �ʏ�̌@��
	island->money -= cost;
	if(land->kind == Land::Sea) {
	    // ��
	    land->param = Land::SeaDeep;
	} else if(land->kind == Land::Mountain) {
	    // �R
	    land->kind = Land::Waste;
	    land->param = Land::WasteNormal;
	} else {
	    // ���̑�
	    land->kind = Land::Sea;
	    land->param = Land::SeaShoal;
	    land->owner = 0;
	}

	// ���O
	log(200, 0, id, 0, kind, x, y);
	return 1;

    case SellTree: // ����
	// �����̓y�n�ł��鎖�̓`�F�b�N�ς�
	// �X�łȂ��Ǝ��s
	if(land->kind != Land::Forest) {
	    // �y�n���s�K�����O
	    log(103, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}

	// ���p�v
	island->money += Value::treeValue * land->param;

	// ���n�ɂ���
	land->kind = Land::Town;
	land->param = 0;

	// ���O
	log(200, 0, id, 0, kind, x, y);
	return 1;

    case Widen: // �̓y�g��
	if(Map::nearLand2(x, y, 1, 7, order) == 0) {
	    // ���͂Ɏ����̓y�n�A�����n���Ȃ���Ύ��s
	    // ���͂ɗ̒n���Ȃ����O
	    log(104, 0, id, 0, kind, x, y);
	    return 0;
	}

	if(land->owner == order) {
	    // ���łɎ����̓y�n
	    log(105, 0, id, 0, kind, x, y);
	    return 0;
	}

	if((land->kind != Land::Waste) &&
	   (land->owner != 0)) {
	    // ���l�̓y�n���r�n�łȂ�
	    if(land->owner == 0) {
		log(106, 0, id, 0, kind, x, y);
	    } else {
		log(106, 0, id, (Info::getIsland(land->owner))->id, kind, x, y);
	    }
	    return 0;
	}

	// ���b�A�C���n�A�C�͂���
	if((land->kind == Land::Monster) ||
	   (land->kind == Land::SBase) ||
	   (land->kind == Land::Sea)) {
	    // �y�n���s�K�����O
	    log(103, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}

	// ����
	land->owner = order;
	island->money -= cost;

	// ���O
	log(200, 0, id, 0, kind, x, y);
	return 1;

    case Plant: // �A��
	return buildCommand(island, land, id, cost, order, kind,
			    x, y, landValue,
			    Land::Forest, 5, 0, 0);
    case Farm: // �_�ꐮ��
	if(land->seaLevel < Land::SeaLevel1) {
	    // �y�n���s�K�����O
	    log(108, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}
	return buildCommand(island, land, id, cost, order, kind,
			    x, y, landValue,
			    Land::Farm, 10, 2, 50);
    case Factory: // �H�ꌚ��
	if(land->seaLevel < Land::SeaLevel2) {
	    // �y�n���s�K�����O
	    log(108, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}
	return buildCommand(island, land, id, cost, order, kind,
			    x, y, landValue,
			    Land::Factory, 30, 10, 100);

    case Base: // �~�T�C����n����
	return buildCommand(island, land, id, cost, order, kind,
			    x, y, landValue,
			    Land::Base, 0, 0, 0);

    case DBase: // �h�q�{�݌���
	return buildCommand(island, land, id, cost, order, kind,
			    x, y, landValue,
			    Land::DBase, 0, -1, 0);

    case Monument: // �L�O�茚��
	if(amount >= Value::monumentVar) {
	    amount = 0;
	}
	return buildCommand(island, land, id, cost, order, kind,
			    x, y, landValue,
			    Land::Monument, amount, -1, 0);

    case Haribote: // �n���{�e�ݒu
	return buildCommand(island, land, id, cost, order, kind,
			    x, y, landValue,
			    Land::DBase, 1, 0, 0);

    case Mountain: // �̌@�ꐮ��
	// �R�ȊO�͂���
	if(land->kind != Land::Mountain) {
	    log(103, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}

	// ����
	island->money -= cost;

	land->param += 5;
	if(land->param > 200) {
	    land->param = 200;
	}

	// �ʏ탍�O
	log(200, 0, id, 0, kind, x, y);
	if(amount > 0) {
	    amount--;
	    if(amount > 0) {
		return 2;
	    }
	}
	return 1;

    case SBase: // �C���n����
	if(Map::nearLand(x, y, 0, 37, order) == 0) {
	    // ����3�w�b�N�X���Ɏ����̓y�n�A�����n���Ȃ���Ύ��s
	    // ���͂ɗ̒n���Ȃ����O
	    log(104, 0, id, 0, kind, x, y);
	    return 0;
	}

	// �C�ȊO�͂���
	if((land->kind != Land::Sea) && (land->kind != Land::SeaDeep)) {
	    log(103, 0, id, 0, kind, x, y, landValue);
	    return 0;
	}

	// ����
	island->money -= cost;

	land->kind = Land::SBase;
	land->param = 0;
	land->owner = order;

	// �ʏ탍�O
	log(200, 1, id, 0, kind, x, y);
	log(200, 2, id, 0, kind, -999, -1);
	return 1;

    case MissileNM: // �~�T�C������
    case MissilePP: // PP�~�T�C������
    case MissileLD: // ���n�j��e����
    case MissileIS: // �e���~�T�C������
	island->tx = x;
	island->ty = y;
	island->command = kind;
	if(amount) {
	    island->amount = amount;
	} else {
	    island->amount = 1000;
	}
	log(205, 0, id, 0, kind, x, y);
	return 1;

    case Monster: // ���b�h��
	{
	    Island *ti = Info::getIslandByID(target);
	    if(ti == 0) {
		// �^�[�Q�b�g���Ȃ��Ď��s
		log(107, 0, id, 0, kind);
		return 0;
	    }

	    // ����
	    island->money -= cost;
	    ti->amonster++;
	    log(206, 0, id, ti->id, kind);
	    return 1;
	}

    case Money: // ��������
    case Food: // �H������
    case Sell: // �H���A�o
	{
	    Island *ti = 0;
	    if(kind != Sell) {
		ti = Info::getIslandByID(target);
		if(ti == 0) {
		    // �^�[�Q�b�g���Ȃ��Ď��s
		    log(107, 0, id, 0, kind);
		    return 0;
		}
	    }

	    // ����
	    if(kind == Money) {
		int c;
		c = MIN(island->money, cost * amount);
		if((c == 0) && (island->money != 0)) { c = cost; }
		island->money -= c;
		ti->money += c;
		log(207, 0, id, target, kind, 0, 0, 0, c);
	    } else {
		int c;
		c = MIN(island->food, (-cost) * amount);
		if((c == 0) && (island->food != 0)) { c = -cost; }
		island->food -= c;
		if(kind == Food) {
		    // ����
		    ti->food += c;
		    log(208, 0, id, target, kind, 0, 0, 0, c);
		} else {
		    // �A�o
		    island->money += c / 10;
		    log(209, 0, id, 0, kind, 0, 0, 0, c);
		}
	    }
	    return 0;
	}

    case Propaganda: // �U�v����
	island->money -= cost;
	island->shortage = -1;
	log(210, 0, id, 0, kind);
	return 1;

    case Giveup: // ���̕���
	island->command = Giveup;
	return 1;

    case Move: // ���_�ύX
	island->centerX = x;
	island->centerY = y;
	island->money -= cost;
	return 1;
    }

    return 0;
}

int Com::buildCommand(Island *island, Land *land, int id, int cost, int order,
		       int kind, int x, int y, int landValue,
		       int lKind, int iParam, int param, int maxparam) {
    // �s�s(���n) or �ړI�̒n�`�ȊO�͂���
    if((land->kind != Land::Town) &&
       ((param == 0 ) || (land->kind != lKind))) {
	// �y�n���s�K�����O
	log(103, 0, id, 0, kind, x, y, landValue);
	return 0;
    }

    // �n���{�e�̏�͂���
    if((land->kind == Land::DBase) && (land->param == Land::DBaseFalse)) {
	// �y�n���s�K�����O
	log(103, 0, id, 0, kind, x, y, landValue);
	return 0;
    }

    // ����
    island->money -= cost;
    if(land->kind == lKind) {
	if(param > 0) {
	    land->param += param;
	    if(land->param > maxparam) {
		land->param = maxparam;
	    }
	} else {
	    // ����or�L�O���΂�
	    land->flag = 1;

	    // �N�����u�N�����O
	    log(203, 0, id, 0, kind, x, y, landValue);
	    island->command = kind;
	    island->target = target;
	    return 1;
	}
    } else {
	// ����
	land->kind = lKind;
	land->param = iParam;
	land->owner = order;
    }

    if(kind == Base) {
	// �閧���O
	log(200, 1, id, 0, kind, x, y);
	// ������Ȃ����E�E�E
	log(204, 2, id, 0, kind);
    } else if(kind == Plant) {
	// �閧���O
	log(200, 1, id, 0, kind, x, y);
	// ������Ȃ����E�E�E
	log(204, 2, id, 0, kind);
    } else if(kind == Haribote) {
	// �閧���O
	log(200, 1, id, 0, kind, x, y);
	// �h�q�{�݂̂ӂ�
	log(200, 2, id, 0, DBase, x, y);
    } else {
	// �ʏ탍�O
	log(200, 0, id, 0, kind, x, y);
    }

    if((kind == Farm) || (kind == Factory)) {
	if(amount > 0) {
	    amount--;
	    if(amount > 0) {
		return 2;
	    }
	}
    }
    return 1;
}


// ���O�o�͂̃G�C���A�X
void Com::log(int kind, int secret, int mIsland, int sIsland,
	      int cKind, int x, int y, int land, int amount) {
    HakoIO::logOutput(kind, secret, mIsland, sIsland,
		      cKind, x, y, land, amount);
}

// �l�i
int Com::getCost() {
    return getCost(kind);
}

// �l�i
int Com::getCost(int k) {
    int i = 0;
    while(costTable[i] != -1) {
	if(k == costTable[i]) {
	    return costTable[i + 1];
	}
	i+=2;
    }
    return 0;
}
