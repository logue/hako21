#include "sight.h"

// ���ʃ��W���[��
void Sight::common() {
    // �f�[�^�ǂݍ���
    HakoIO::readMapFile();
    Util::unlock();

    // �n�}���o��
    Map::jsOut(0);

    // �����o��
    Info::jsOut(0);

    // ���O�o��
    HakoIO::logJsOut(0);

    HakoIO::out("mainMode = 'map';");
}
