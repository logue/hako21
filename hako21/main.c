#include "main.h"

int main() {
    // ����������
    srandom(time(0));

    // cgi����
    if(HakoIO::cgiInput() == 0) {
	exit(0); // �u�s�����́v
    }

    // �ݒ�ǂݍ���
    HakoIO::readConfigFile();

    // �w�b�_�o��
    Template::header();

    // �N�b�L�[���e�̔��f
    HakoIO::cookieInput();
    
    // ���ǂ݂���
    Util::lock();
    HakoIO::readInfoFile();

    switch(Value::mainMode) {
    case MODE_MENTENANCE:
    case MODE_MENTENANCE_MAKEDATA:
    case MODE_MENTENANCE_DELETE:
    case MODE_MENTENANCE_BACKUP:
    case MODE_MENTENANCE_TIME:
    case MODE_MENTENANCE_ACTIVATE:
	// �����e�n�Ȃ�^�[���͐i�܂Ȃ�
	break;
    default:
	// ���Ԃ��o���Ă���΃^�[���i�s
	if((Info::turn != 0) && (Info::totalNumber != 0) &&
	   (Info::turn < Value::endTurn)){
	    if((Info::lastTime + Value::unitTime) < time(0)) {
		Value::mainMode = MODE_TURN;
	    }
	}
    }

    // ���ʏ��o��
    Info::commonOut();

    // ���[�h����
    switch(Value::mainMode) {

    case MODE_MAP_OWNER:
	// �J�����[�h
	if(Util::passCheck()) {
	    Owner::main(0);
	}
	break;

    case MODE_MAP_COMMAND:
	// �J�����[�h(�R�}���h����)
	Owner::main(1); // �����Ńp�X���[�h�`�F�b�N
	break;

    case MODE_MAP:
	// �ό��҃��[�h
	Sight::common();
	break;

    case MODE_NEW:
	// ���o�^���[�h
	NewIsland::main();
	break;

    case MODE_TURN:
	// �^�[���i�s���[�h
	if(Info::totalNumber > 0) {
	    Info::lastTime += Value::unitTime;
	    Turn::main();

	    // ���ʏ��ďo��
	    Info::commonOut();
	}

	// �g�b�v�y�[�W�s��
	TopPage::main();
	break;

    case MODE_MESSAGE:
	// �R�����g���̓��[�h
	Owner::main(2);
	break;

    case MODE_RENAME:
	// ���O�ύX���[�h
	Rename::main();
	break;

    case MODE_MENTENANCE:
	// �����e���[�h
	if(Util::passCheck() >= 2) {
	    Mentenance::common();
	}
	break;

    case MODE_MENTENANCE_MAKEDATA:
	// �����e���[�h�A�V�K�f�[�^�쐬
	if(Util::passCheck() >= 2) {
	    Mentenance::makeData();
	}
	break;

    case MODE_MENTENANCE_DELETE:
	// �����e���[�h�A�f�[�^�폜
	if(Util::passCheck() >= 2) {
	    Mentenance::deleteData();
	}
	break;

    case MODE_MENTENANCE_TIME:
	// �����e���[�h�A���ԕύX
	if(Util::passCheck() >= 2) {
	    Mentenance::changeTime();
	}
	break;

    case MODE_MENTENANCE_BACKUP:
	// �����e���[�h�A�f�[�^�폜
	if(Util::passCheck() >= 2) {
	    Mentenance::backUpData();
	}
	break;

    case MODE_MENTENANCE_ACTIVATE:
	// �����e���[�h�A�f�[�^������
	if(Util::passCheck() >= 2) {
	    Mentenance::activateData();
	}
	break;

    default:
	// ���̑��̏ꍇ�̓g�b�v�y�[�W
	TopPage::main();
	break;
    }

    // �t�b�^�o��
    Template::footer();
    return 0;
}
