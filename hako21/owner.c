#include "owner.h"

int Owner::parsePoint;

// ���ʃ��W���[��
void Owner::main(int mode) {
    // �R�}���h���̓��[�h�Ȃ瓇ID���擾
    if(mode == 1) {
	parsePoint = 0;
	Value::id = parseNumber();
    }

    // �p�X���[�h�`�F�b�N
    if(Util::passCheck() == 0) {
	return;
    }

    // ���̎擾
    Island *island = Info::getIslandByID(Value::id);

    if(island == 0) {
	TopPage::main();
	return;
    }
    int id = island->id;

    // �n�}�A�R�}���h�ǂ݂���
    HakoIO::readMapFile();
    HakoIO::readComFile(id);

    if(mode == 1) {
	// �R�}���h���̓��[�h�Ȃ���͏����A��������
	parseCommand();
	HakoIO::writeComFile(id);
    } else if(mode == 2) {
	// �R�����g���[�h�Ȃ珑������
	strcpy(island->comment, Value::message);
	HakoIO::writeInfoFile();
    }
    Util::unlock();

    // �n�}���o��
    Map::jsOut(Info::getOrderByID(id));

    // �����o��
    Info::jsOut(id);

    // �R�}���h���o��
    Command::jsOut();

    // ���O�o��
    HakoIO::logJsOut(id);

    // �o��
    sprintf(HakoIO::buffer, "currentID = %d;", id);
    HakoIO::out(HakoIO::buffer);
    HakoIO::out("mainMode = 'owner';");
}

// commandList���琮����ǂ�
int Owner::parseNumber() {
    char *ptr = Value::commandList + parsePoint;
    char *ptr2 = HakoIO::buffer;
    while((*ptr != ' ') && (*ptr != 0)){
	*ptr2 = *ptr;
	ptr ++;
	ptr2 ++;
	parsePoint++;
    }
    *ptr2 = 0;
    parsePoint++;
    return atoi(HakoIO::buffer);
}

void Owner::parseCommand() {
    for(int i = 0; i < Value::commandMax; i++) {
	Com *c = (Command::coms + i);
	c->kind = parseNumber();
	c->target = parseNumber();
	c->x = parseNumber();
	c->y = parseNumber();
	c->amount = parseNumber();
    }
}
