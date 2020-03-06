//----------------------------------------------------------------
// Netscape6 Mozilla �Ή� hokow.js
// Arranged by ���X��
// �z�z�y�[�W: http://www.geocities.co.jp/SiliconValley-Bay/2566/

// Macintosh��IE�Ή� hakow.js�i���돔���Q�P�j
// v1.1
// Arranged by Logue
// �z�z�T�C�g�Fhttp://logue.be/
//----------------------------------------------------------------

// �ݒ�l
function initialize() {
    adminName = 'admin';
    email = 'your&#64;name.com';
    homepage = 'http://example.co.jp/';

    // �\������n�}�̑傫��
    normalSize = 11;
    largeSize = 23;
    printMode = 0; // 0��normal

    normalHalf = Math.floor(normalSize / 2);
    largeHalf = Math.floor(largeSize / 2);

    // �C���[�W�̒u���Ă���f�B���N�g��
    imgDir = './images/';

    // ��x�ɕ\�����鏇��
    printOrder = 5;

    // �����̒P��
    unitMoney = '���~';

    // �H���̒P��
    unitFood = '00�g��';

    // �l���̒P��
    unitPop = '00�l';

    // �ʐς̒P��
    unitArea = '00����';

    // �؂̒P��
    unitTree = '00�{';

    // ���͒��R�}���h�̔w�i�F
    changeCommandBG = '#DDDDFF';

    // �R�}���h
    comlist = 
	[
	 [1,'���n',5],
	 [62,'�H���A�o',-100],
	 [2,'�n�ς�',100],
	 [3,'���߂���',150],
	 [4,'�@��',200],
	 [5,'����',0],
	 [6,'�̓y�g��',100],
	 [21,'�A��',50],
	 [22,'�_�ꐮ��',20],
	 [23,'�H�ꌚ��',100],
	 [24,'�̌@�ꐮ��',300],
	 [25,'�~�T�C����n����',300],
	 [26,'�h�q�{�݌���',800],
	 [27,'�C���n����',8000],
	 [28,'�L�O�茚��',9999],
	 [29,'�n���{�e�ݒu',1],
	 [41,'�~�T�C������',20],
	 [42,'PP�~�T�C������',50],
	 [43,'���n�j��e����',100],
	 [44,'�e���~�T�C������',150],
	 [45,'���b�h��',3000],
	 [61,'�����J��',0],
	 [63,'��������',100],
	 [64,'�H������',-100],
	 [65,'�U�v����',1000],
	 [67,'���_�ύX',1000],
	 [66,'���̕���',0]
	 ];

    // ���b�̖��O
    monsterName =
	[
	 '���J���̂�',     // 0(�l��)
	 '���̂�',         // 1
	 '�T���W��',       // 2
	 '���b�h���̂�',   // 3
	 '�_�[�N���̂�',   // 4
	 '���̂�S�[�X�g', // 5
	 '�N�W��',         // 6
	 '�L���O���̂�'    // 7
	 ];

    // ���b�̉摜
    monsterImage =
	[
	 'monster7.gif',
	 'monster0.gif',
	 'monster5.gif',
	 'monster1.gif',
	 'monster2.gif',
	 'monster8.gif',
	 'monster6.gif',
	 'monster3.gif'
	 ];

    // �o���l
    baseExp = [20, 60, 120, 200];
    sBaseExp = [50, 200];

    // ���b�̉摜(�d����)
    monsterImage2 = ['','','monster4.gif','','','','monster4.gif',''];

    // ���b�̍d������
    // 0:�d�����Ȃ� 1:��^�[�� 2:�����^�[��
    monsterHard = [0,0,1,0,0,0,2,0];

    // �܂̖��O
    prizeName = 
	[
	 '100�^�[���t',
	 '300�^�[���t',
	 '1000�^�[���t',
	 '�ɉh��',
	 '���ɉh��',
	 '���ɔɉh��',
	 '�Г��',
	 '���Г��',
	 '���ɍГ��',
	 '���a��',
	 '�����a��',
	 '���ɕ��a��'
	 ];

    // �܂̉摜
    prizeImage = 
	[
	 'prize0.gif',
	 'prize10.gif',
	 'prize11.gif',
	 'prize1.gif',
	 'prize2.gif',
	 'prize3.gif',
	 'prize7.gif',
	 'prize8.gif',
	 'prize9.gif',
	 'prize4.gif',
	 'prize5.gif',
	 'prize6.gif'
	 ];

    // �L�O��̖��O
    monumentName =
	[
	 '���m���X',
	 '���a�̓�',
	 '�푈�̔�'
	 ];

    // �w�b�_
    header =
	'<A HREF="http://web.archive.org/web/20070707102159/t.pos.to/hako/">���돔���X�N���v�g�z�z��</A>�^' +
	'<A href="https://github.com/logue/hako21">������</a><HR>'
        + '<SPAN class="title">' + titleName + '</SPAN><HR>';

    // �t�b�^
    footer = 
	'<HR><P align=center>�Ǘ���:' + adminName + '(<A HREF="mailto:' +email + '">' + email + '</A>)' +
	'<BR>�f����(<A HREF="' + bbs + '">' + bbs + '</A>)' + 
	'<BR>�z�[���y�[�W(<A HREF="' + homepage + '">' + homepage + '</A>)' +
	'<BR>���돔���̃y�[�W(<A HREF="http://web.archive.org/web/20070707102159/t.pos.to' + '/hako">http://t.pos.to/hako/' +
    '</A>)<BR>';

    // �u�߂�v�����N
    backLink = big('<A HREF="' + cgiURL + '?cname=' + cname + '">�g�b�v�֖߂�</A>');

    // �t�H�[���w�b�_
    formHeader = '<FORM action="' + cgiURL + '" method="POST"><input type=hidden name="cname" value="' + cname + '">';
}

// �t�H���g�̐ݒ�
function tagHeader(s) {
    return '<SPAN class="header">' + s + '</SPAN>';
}

// �G���[���b�Z�[�W
function errorMes(s) {
    return '<SPAN class="error">' + s + '</SPAN>';
}

// �ł�������
function big(s) {
    return '<big>' + s + '</big>';
}

// �{�^��
function tagButton(s) {
    return '<SPAN class="button">' + s + '</SPAN>';
}

// �ԍ�
function tagNumber(s) {
    return '<SPAN class="number">' + s + '</SPAN>';
}

// �R�}���h�̖��O
function tagComName(s) {
    return '<SPAN class="command">' + s + '</SPAN>';
}

// ���̖��O
function tagName(s) {
    return '<SPAN class="island_name">' + s + '</SPAN>';
}

// ���̖��O(�O���[)
function tagName2(s) {
    return '<SPAN class="island_name_g">' + s + '</SPAN>';
}

// �ЊQ
function tagDis(s) {
    return '<SPAN class="destory">' + s + '</SPAN>';
}

// �Z���̑���
// ���ʕ\���o��
function cellTitle(s) {
    return '<TH BGCOLOR="#ffccff" class="pink"><NOBR>' + s + '</NOBR></TH>';
}

// ���ʕ\����
function cellNumber(s) {
    return '<TD BGCOLOR="#ffcccc" class="red" ROWSPAN=2 ALIGN=center><NOBR>' + tagNumber(s) + '</NOBR></TD>';
}

// ���ʕ\����
function cellName(s) {
    return '<TD BGCOLOR="#ccffff" class="water" ROWSPAN=2 ALIGN=center><NOBR>' + s + '</NOBR></TD>';
}

// ���ʕ\�����
function cellInfo(s) {
    return '<TD BGCOLOR="#ccffcc" class="green" ALIGN=right><NOBR>' + s + '</NOBR></TD>';
}

// ���ʕ\�R�����g��
function cellComment(s) {
    return '<TD BGCOLOR="#ffffcc" class="yellow" COLSPAN=8><NOBR>' + s + '</NOBR></TD>';
}

function help(s){
	return 'title="' + s + '" onmouseout="window.status=\'\'" onmouseover="window.status=\'' + s + '\'; return true;" ';
}

// ���C�����[�`��
function main() {
	// ������
	window.status='���΂炭���҂��������c�B';
	initialize();
	var str = header;

    // ���[�h�ŕ���
    if(mainMode == 'owner') {
	// ���僂�[�h
	str += ownerMain();
    } else if(mainMode == 'map') {
	// �ό��҃��[�h
	str += tagHeader('<BR>���돔���Q�P���I�ւ悤�����c�B<BR><BR>') + backLink;
	str += sightMain();
    } else if(mainMode == 'mente') {
	// �����e�i���X���[�h
	str += menteMain();
    } else if(mainMode == 'top') {
	// �g�b�v���j���[���[�h
	str += topMain();
    } else {
	// �G���[���b�Z�[�W(�G���[����Ȃ��̂�����)
	window.status='�g�b�v�ɖ߂���N���b�N���ĉ������B';
	if(mainMode == 'errorNewIsland') {
	    str += errorMes('���𔭌����܂����I�I');

	} else if(mainMode == 'errorIslandFull') {
	    str += errorMes('���̐����ő吔�ł��B�o�^�ł��܂���B');

	} else if(mainMode == 'errorNoName') {
	    str += errorMes('���̖��O�����͂���Ă��܂���B');

	} else if(mainMode == 'errorBadName') {
	    str += errorMes(',"?()<>\$�Ƃ������Ă���A�u�Y�ꋎ��ꂽ���v�Ƃ��������ςȖ��O�͂�߂܂��傤��`'); // "

	    } else if(mainMode == 'errorDupName') {
		str += errorMes('���̓��Ȃ���ɔ�������Ă��܂���B');

	    } else if(mainMode == 'errorNoPassword') {
		str += errorMes('�p�X���[�h�����͂���Ă��܂���B');

	    } else if(mainMode == 'errorWrongPassword') {
		str += errorMes('�p�X���[�h���Ⴂ�܂��B');

	    } else if(mainMode == 'errorNotEnoughArea') {
		str += errorMes('���̕ӂɂ͓��͂Ȃ��悤�ł��E�E�E�B');

	    } else if(mainMode == 'errorNotEnoughMoney') {
		str += errorMes('�������s�����Ă��܂��E�E�E�B');

	    } else if(mainMode == 'errorNotChange') {
		str += errorMes('�ύX�͂���܂���ł����B');

	    } else if(mainMode == 'errorMaxMoney') {
		str += errorMes('�����A�H�����ő�l�ɂ��܂����B');

	    } else if(mainMode == 'errorChange') {
		str += errorMes('�ύX���܂����B');

	    }

	// '�g�b�v�֖߂�'�����N
	str += backLink;

	}

	// �t�b�^���o���ďI��
	if (check == 1){
		document.all('mainBody').innerHTML = str + footer;
	}else if (check == 2){
		with (document.layers["mainBody"].document){
			write("<HTML><BODY><DIV align='center'>",str,footer,"</DIV></BODY></HTML>"); 
			close();
		}
	}else if (check == 3){
		document.getElementById('mainBody').innerHTML = str + footer;
	}
}

// �g�b�v�y�[�W
function topMain() {
    var str = '';
    if(debugMode == 1) {
	str = formHeader + '<INPUT TYPE="submit" NAME="TurnMode" VALUE="�^�[����i�߂�"></FORM>';
    }
    str +=
	tagHeader('<BR>�^�[���F' + cturn + '�^' + eturn + '<BR><BR>') + '<HR>' + 
	formHeader + tagHeader('�����̓���') + islandList() +
	'�p�X���[�h<INPUT TYPE="password" NAME="Password" VALUE="' + dpass + '" SIZE=32 MAXLENGTH=32>' +
	'<INPUT TYPE="submit" VALUE="�J�����ɍs��" NAME="OwnerMode"></FORM>' +

	tagHeader('<HR><BR>�ό��A���T��<BR><BR>') + formHeader + 
	'<INPUT TYPE="submit" VALUE="�ό��^���T���ɍs��" NAME="MapMode"></FORM>' + 

	tagHeader('<HR><BR>�����A�p�X���[�h�̕ύX<BR><BR>') + 
	'<P>(�����̕ύX��500���~�A�p�X���[�h�ύX�͖���)</P>' + formHeader + 
	'<TABLE>' + 
	' <TR>' +
	'  <TD>���̓���</TD>' +
	'  <TD>' + islandList() + '</TD>' +
	' </TR>' +
	' <TR>' +
	'  <TD>�V���������i�ύX����ꍇ�̂݁j</TD>' +
	'  <TD><INPUT TYPE="text" NAME="IslandName" SIZE=32 MAXLENGTH=32>��</TD>' +
	' </TR>' + 
	' <TR>' +
	'  <TD>���p�X���[�h�i�K�{�j</TD>' + 
	'  <TD><INPUT TYPE="password" NAME="Password" VALUE="' + dpass + '" SIZE=32 MAXLENGTH=32></TD>' +
	' </TR>' +
	' <TR>' +
	'  <TD>�V�p�X���[�h�i�ύX����ꍇ�̂݁j</TD>' + 
	'  <TD><INPUT TYPE="password" NAME="Password3" SIZE=32 MAXLENGTH=32></TD>' + 
	' </TR>' +
	' <TR>' +
	'  <TD>�m�F�p�p�X���[�h</TD>' +
	'  <TD><INPUT TYPE="password" NAME="Password2" SIZE=32 MAXLENGTH=32></TD>' + 
	' </TR>' +
	' <TR>' +
	'  <TD></TD>' +
	'  <TD><INPUT TYPE="submit" VALUE="�ύX����" NAME="RenameMode"></TD>' +
	' </TR>' + 
	'</TABLE></FORM>' +
	'<HR>'  + formHeader + 
	'�p�X���[�h<INPUT TYPE="password" NAME="Password" SIZE=32 MAXLENGTH=32>' +
	'<INPUT TYPE="submit" VALUE="�Ǘ��҃��[�h��" NAME="MenteMode">' +
	'</FORM>';
    return str;
}

// ���僂�[�h
function ownerMain() {
    window.status='�`�撆�ł��c�B';
    var island = getIslandByID(currentID);
    var name = island[0];
    currentX = island[2];
    currentY = island[3];

    // �\��R�}���h�Z�b�g
    currentPlanD();

    var str = tagHeader('<BR>' + name + '���J���v��<BR><BR>') + backLink;

    str += orderPrint(getNumberByID(currentID) + 1, 1);

    str += '<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=1><TR><TD ID ="map" class="water">' + 
	mapPrint(currentX,currentY) + 
	'</TD><TD align=center class="green">' +
	' <SPAN class="plan">�v��ԍ�</SPAN>' + planNumList() +
	' <HR><SPAN class="plan">�J���v��</SPAN><BR>' + commandList() +
	' <HR><SPAN class="plan">���W</SPAN>' + pointList(currentX, currentY) +
	' <HR><SPAN class="plan">�Ώۂ̓�</SPAN><BR>' + islandList() +
	' <HR><SPAN class="plan">����</SPAN>' + amountList() + '<HR>' +
	' <A HREF="JavaScript:comIn(0);" ' + help('�v���}�����܂��B') + '>' + tagButton('�}��') + '</A>�@' +
	' <A HREF="JavaScript:comIn(1);" ' + help('�v����㏑�����܂��B') + '>' + tagButton('�㏑') + '</A>�@' +
	' <A HREF="JavaScript:comIn(2);" ' + help('�v����폜���܂��B') + '>' + tagButton('�폜') + '</A>' +
	    formHeader +
	' <INPUT NAME="CommandList" TYPE="hidden" ID="commandtext" VALUE="' + currentPlanD() +'">' +
	' <B>�p�X���[�h</B><BR><INPUT TYPE=password VALUE="' + dpass +'"NAME="Password">' +
	' <INPUT NAME="CommandMode" TYPE="hidden">' +
	' <HR><INPUT VALUE="�v�摗�M" TYPE="submit"></FORM>' +
	'</TD><TD ID="planarea" class="red">';

    str += currentPlan() + '</TD></TR></TABLE>';

    // ���ʕ���
    currentOrder = 1;
    str += '<BR><DIV ID="order">' + orderPrint(1, 0) + '</DIV><BR><BR>';

    // �R�����g���̓{�b�N�X
    str += tagHeader('<BR>�R�����g�X�V<BR><BR>') + formHeader +
	'<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=1 class="gray">' + 
	' <TR>' +
	'  <TD nowrap>�R�����g�F<INPUT TYPE=text NAME=Message SIZE=70>' +
	'  �p�X���[�h�F<INPUT TYPE=password NAME=Password VALUE="' + dpass + '" size=10>' +
	'  <INPUT TYPE=submit VALUE="�R�����g�X�V" NAME=MesMode' + currentID + '></nobr></TD>' +
	' </TR>' +
	'</TABLE></FORM>';


    // ���O����
    str += tagHeader('<BR>�ŋ߂̏o����<BR><BR>') + 
	'<BR><DIV ID="log">' + logPrint(currentID) + '</DIV><BR><BR>' + hisPrint();

    window.status='';
    return str;
}

// �ό��҃��[�h
function sightMain() {
    window.status='���돔���Q�P���I�ւ悤�����I';
    // �n�}����
    currentX = Math.floor(worldSize / 2);
    currentY = Math.floor(worldSize / 2);
    if(infoData.length > 0) {
	currentX = infoData[0][2];
	currentY = infoData[0][3];
    }
    var str =
	'<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=1><TR><TD ID ="map" class="water">' +
	    mapPrint(currentX,currentY) +
		'</TD><TD class="cell_plan">';

    // �����ő吔�łȂ��ꍇ
    str += tagHeader('<H2>����T��</H2>');
    str += formHeader + '�ǂ�Ȗ��O������\��H<BR>' + 
	'<INPUT TYPE="text" NAME="IslandName" SIZE=32 MAXLENGTH=32>��<BR>' +
	'�p�X���[�h�́H<BR>' + 
	'<INPUT TYPE="password" VALUE="' + dpass + ' "NAME="Password" SIZE=32 MAXLENGTH=32><BR>' +
	'�O�̂��߃p�X���[�h���������<BR>' + 
	'<INPUT TYPE="password" NAME="Password2" SIZE=32 MAXLENGTH=32><BR>' + pointList(currentX, currentY);
    if(infoData.length < maxNumber) {
	str += '�t�߂�<INPUT TYPE="submit" VALUE="�T���ɍs��" NAME="NewIslandMode"></FORM>';
    } else {
	str += '<BR><B>���̐����ő吔�ł��B<BR>���ݓo�^�ł��܂���B</B></FORM>';
    }

    str += '</TD></TR></TABLE>';

    // ���ʕ���
    currentOrder = 1;
    str += '<BR><DIV ID="order">' + orderPrint(1, 0) + '</DIV><BR><BR>';

    // ���O����
    str += tagHeader('<BR>�ŋ߂̏o����<BR><BR>') + 
	'<BR><DIV ID="log">' + logPrint(0) + '</DIV><BR><BR>' + hisPrint();
    return str;
}

// �����e���[�h
function menteMain() {
    var str = '<H1>�Ǘ��҃��[�h</H1>' + backLink + '<HR>' + formHeader +
	'�p�X���[�h�F<INPUT TYPE="password" NAME="Password" SIZE=32 MAXLENGTH=32>';
    if(currentData[0] == 0) {
	str +=
	    '<HR>�����f�[�^�͂���܂���<BR><INPUT TYPE="submit" VALUE="�V�K�f�[�^�����" NAME="MakeData">';
    } else {
	str += '<HR><H3>�����f�[�^</H3>';
	str += menteData(currentData);
	str += '<BR><INPUT TYPE="submit" VALUE="�o�b�N�A�b�v" NAME="BackUp">';
	str += '<INPUT TYPE="submit" VALUE="���̃f�[�^���폜" NAME="Delete">';
	str += '<BR>�ŏI�X�V�b����<INPUT TYPE="text" NAME="Second" VALUE="' + currentData[1] + '" SIZE=32 MAXLENGTH=32>' +
	'<INPUT TYPE="submit" VALUE="�ɕύX����" NAME="ChangeTime">';
    }

    var i;
    for(i = 0; i < backUpMax; i++) {
	if(backData[i][0] != 0) {
	    str += '<HR><H3>�o�b�N�A�b�v' + i + '</H3>';
	    str += menteData(backData[i]);
	    str += '<BR><INPUT TYPE="submit" VALUE="���̃f�[�^��������" NAME="Activate' + i + '">';
	    str += '<INPUT TYPE="submit" VALUE="���̃f�[�^���폜" NAME="Delete' + i + '">';
	}
    }

    return str + '</FORM>';
}

// �e�f�[�^�\��
function menteData(d) {
    var str = '�m' + d[0] + '�^�[���n�ŏI�X�V' + d[1] + '�b�i';
    var dDate = new Date(d[1] * 1000);
    str += dDate.toLocaleString() + '�j';
    return str;
}

// �n�}�\��
function mapPrint(sx, sy) {
    window.status = '�}�b�v�f�R�[�h���c�B�i0�������j';
    var x, y, tx, ty, str;

    var printSize;
    var halfSize;
    var il, is;
    if(printMode == 0) {
	printSize = normalSize;
	halfSize = normalHalf;
	il = 32;
	is = 16;
    } else {
	printSize = largeSize;
	halfSize = largeHalf;
	il = 16;
	is = 8;
    }

    tx = sx - halfSize;
    ty = sy - halfSize;
    if(tx < 0) { tx = 0; }
    if(ty < 0) { ty = 0; }
    if(tx >= (worldSize - printSize)) { tx = (worldSize - printSize); }
    if(ty >= (worldSize - printSize)) { ty = (worldSize - printSize); }

    str = '<B>�i' + currentX + ',' + currentY + '�j�n�_�t��</B> �\���̈�i' +
	tx + ',' + ty + '�j�`�i' + (tx + printSize - 1) + ',' +
	    (ty + printSize - 1) + '�j';
    str += '<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=1><TR><TD class="blue"><nobr>';
    window.status = '';
    for(y = ty; y < (ty + printSize); y++) {
	if((y % 2) == 0) {
	    str += 
	    '<IMG WIDTH=' + is + ' HEIGHT=' + il + ' SRC="' + imgDir + 'black.gif" border=0>';
	}
	for(x = tx; x < (tx + printSize); x++) {
	    var land = mapPoint(x, y);
	    var kind = land[0];  // �n�`�̎��
	    var param = land[1]; // �p�����[�^
	    var owner = land[2]; // ������
	    var name = '�����n��';
	    if(owner != 0) {
		name = getIsland(owner)[0] + '��';
	    }
	    var altString = name + '(' + x + ',' + y + ')\n';
	    var imageFile = '';
	    switch(kind) {
	    case 0:
		if(param == 0) {
		    altString += '�C';
		    imageFile = 'land0.gif';
		} else if(param == 1){
		    altString += '�C�i�󐣁j';
		    imageFile = 'land14.gif';
		} else {
		    altString += '�C����c';
		    imageFile = 'land16.gif';
		}
		break;

	    case 1:
		altString += '�r�n';
		if(param == 0) {
		    imageFile = 'land1.gif';
		} else {
		    imageFile = 'land13.gif';
		}
		break;

	    case 2:
		if(param == 0) {
		    altString += '���n';
		    imageFile = 'land2.gif';
		} else {
		    if(param < 30) {
			altString += '��';
			imageFile = 'land3.gif';
		    } else if(param < 100) {
			altString += '��';
			imageFile = 'land4.gif';
		    } else {
			altString += '�s�s';
			imageFile = 'land5.gif';
		    }
		    altString += '�i' + param + unitPop + '�j'
		    }
		break;

	    case 3:
		altString += '�X';
		imageFile = 'land6.gif';
		if(param != 0) {
		    altString += '�i' + param + unitTree + '�j';
		}
		break;

	    case 4:
		altString += '�_��i' + param + '0' + unitPop + '�K�́j';
		imageFile = 'land7.gif';
		break;

	    case 5:
		altString += '�H��i' + param + '0' + unitPop + '�K�́j';
		imageFile = 'land8.gif';
		break;

	    case 6:
		altString += '�~�T�C����n�i���x��' +
		    expToLevel(baseExp, param) + '�^�o���l' + param + '�j';
		imageFile = 'land9.gif';
		break;

	    case 7:
		if(param == 0) {
		    altString += '�h�q�{��';
		} else {
		    altString += '�n���{�e';
		}
		imageFile = 'land10.gif';
		break;

	    case 8:
		if(param == 0) {
		    altString += '�R';
		    imageFile = 'land11.gif';
		} else {
		    altString += '�R�i�̌@��' + param + '0' + unitPop + '�K�́j';
		    imageFile = 'land15.gif';
		}

		break;

	    case 9:
		{
		    var k = Math.floor(param / 20);
		    var h = Math.floor(param % 20);
		    if(((monsterHard[k] == 1) && ((cturn % 2) == 1)) ||
		       ((monsterHard[k] == 2) && ((cturn % 2) == 0))) {
			altString += '���b' + monsterName[k] + '�i�̗�' + h + '�F�d�����j';
			imageFile = monsterImage2[k];
		    } else {
			altString += '���b' + monsterName[k] + '�i�̗�' + h + '�j';
			imageFile = monsterImage[k];
		    }
		}
		break;

	    case 10:
		altString += '�C���n(���x��' +
		    expToLevel(sBaseExp, param) + '�^�o���l' + param + ')';
		imageFile = 'land12.gif';
		break;

	    case 11:
		altString += monumentName[param];
		imageFile = 'monument0.gif';
		break;
	    }

	    if(mainMode == 'owner') {
		var i;
		for(i = 0; i < commandMax; i++) {
		    var c = comData[i];
		    if(c[0] < 40) {
			if((x == c[2]) && (y == c[3])) {
			    var cn = commandObj(c[0]);
			    altString += '\n[' + (i + 1) + ']' + cn[1];
			}
		    }
		}
	    }
	    var alt2;
	    alt2 = altString.replace(/[\n]/g,"");
	    str += 
		'<a href="javascript:pointMove(' + x + ',' + y + ');" title="' + alt2 + '" ' +
		'ondblclick="mapMove(' + x + ',' + y + ')"  onclick="return true;" ' +
		'onmouseover="window.status=\'' + alt2 + '\'; return true;" onmouseout="window.status=\'\'">' +
		'<IMG WIDTH=' + il + ' HEIGHT=' + il + ' SRC="'+ imgDir + imageFile + '" ALT ="' + altString + '" border=0></a>';
	}
	if((y % 2) == 1) {
	    str += '<IMG WIDTH=' + is + ' HEIGHT=' + il + ' SRC="' + imgDir + 'black.gif">';
	}
	str += '</NOBR><BR>';
	window.status = '�}�b�v�f�R�[�h���c�B�i' + Math.ceil(y/(ty + printSize)*100) + '�������j';

    }
    str += '</TD></TR></TABLE>';
    str += '�_�u���N���b�N�����ꏊ�����S�ɂȂ�܂��B<BR>';
    str += '<DIV align=left><A HREF="JavaScript:changePMode();" ' + 
    help('�}�b�v���g��^�k���\�����܂��B�}�V�����\�ɂ���Ă͎��Ԃ�������܂��B') +
    '>�\�����[�h�؂�ւ�</A>';
	window.status = '';
    return str;
}

// �\�����[�h�؂�ւ�
function changePMode() {
    printMode = 1 - printMode;
    mapMove(currentX, currentY);
}

// ���ʕ\��
function orderPrint(number, mode) {
    var i;
    var l = infoData.length;
    var str = '';
    var po;
    if(mode == 0) {
	po = printOrder;
    } else {
	po = 1;
    }
    if((number > 1) && (mode == 0)){
	str += '<A HREF="JavaScript:orderMove(-' + printOrder + ');" ' + help('��ʃ����N��\��') + '>����ʁ�</A>';
    } else {
	str += '<BR>';
    }
    str +=
	'<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=1><TR>' +
        cellTitle('����') +
	cellTitle('���̖��O</A>') +
	cellTitle('�l��') + cellTitle('�ʒu') +
	cellTitle('�ʐ�') +
	cellTitle('����') + cellTitle('�H��') + cellTitle('�_��') +
	cellTitle('�H��') + cellTitle('�̌@��') + '</TR>';
    for(i = number; (i < (number + po)) && (i <= l); i++){
	var island = getIsland(i);
	var money = island[8];
	if((island[1] != currentID) || (mainMode != 'owner')){
	    if(money < 500) {
		money = '����500' + unitMoney + '����';
	    } else {
		money = '����' + money + unitMoney;
	    }
	} else {
	    money = money + unitMoney;
	}
	var farm;
	if(island[12] == 0) {
	    farm = '�ۗL����';
	} else {
	    farm = island[12] + '000�l�K��';
	}

	var factory;
	if(island[13] == 0) {
	    factory = '�ۗL����';
	} else {
	    factory = island[13] + '000�l�K��';
	}

	var mountain;
	if(island[14] == 0) {
	    mountain = '�ۗL����';
	} else {
	    mountain = island[14] + '000�l�K��';
	}

	var name = island[0] + '��';
	if(island[6] > 0) {
	    name = tagName2(name + '(' + island[6] + ')');
	} else  {
	    name = tagName(name);
	}

	var prize = island[4];
	var prizeStr = '';
	var j;
	var k = 1;
	for(j = 0; j < prizeName.length; j++) {
	    if(k & prize) {
		prizeStr += ' <IMG SRC="'+ imgDir + prizeImage[j] + '" ALT="' + prizeName[j] + '" WIDTH=16 HEIGHT=16>';
	    }
	    k = k * 2;
	}

	var monster = island[5];
	var last = -1;
	var monAlt = '';
	k = 1;
	for(j = 0; j < monsterName.length; j++) {
	    if(k & monster) {
		last = j;
		monAlt += monsterName[j];
	    }
	    if(j != monsterName.length - 1) {
		monAlt += "\n";
	    }
	    k = k * 2;
	}
	if(last != -1) {
		prizeStr += ' <IMG SRC="'+ imgDir + monsterImage[last] + '" ALT="' + monAlt + '" WIDTH=16 HEIGHT=16>';
	}

	str += '<TR>' + cellNumber(i) +
	    cellName(
		     '<A STYLE="text-decoration:none" ' +
		     'HREF="javascript:mapMove(' + island[2] + ',' + island[3] + ');logRewrite(' + island[1] + ');"' + 
		     help('�N���b�N����ƁA' + island[0] + '��(' + island[2] + ',' + island[3] + ')�ɔ�т܂�') + '>' +
		     name + '</A><BR><NOBR>' + prizeStr + '</NOBR>' ) +
		     cellInfo(island[10] + unitPop) + 
		     cellInfo('(' + island[2] + ',' + island[3] + ')') +
		     cellInfo(island[11] + unitArea) + cellInfo(money) + 
		     cellInfo(island[9] + unitFood) + cellInfo(farm) +
		     cellInfo(factory) +
		     cellInfo(mountain) + '</TR><TR>' + cellComment('<B>�R�����g�F</B>' + island[7]) + '<TR>';
    }
    str += '</TABLE>';
    if(((number + po) <= l) && (mode == 0)) {
	str += '<A HREF="JavaScript:orderMove(' + printOrder + ');" ' + help('���ʃ����N��\��') + '>�����ʁ�</A>';
    } else {
	str += '<BR>';
    }
    return str;
}

// ���ʕ\�̏㉺
function orderMove(d) {
    currentOrder += d;
    var l = infoData.length;
    if(currentOrder < 1) {
	currentOrder = 1;
    } else if(currentOrder > l) {
	currentOrder = l;
    }
    currentOrder -= (currentOrder % printOrder - 1);

	if (check == 1){
		document.all('order').innerHTML = orderPrint(currentOrder, 0);
	}else if (check == 2){
		with(document.layers["order"].document){
			write("<HTML><BODY><DIV align='center'>",orderPrint(currentOrder, 0),"</DIV></BODY></HTML>"); 
			close();
		}
	}else if (check == 3){
		document.getElementById('order').innerHTML = orderPrint(currentOrder, 0);
	}
}

// �ړ�
function mapMove(x, y) {
    if(x < 0) { x = 0; }
    if(y < 0) { y = 0; }
    if(x >= worldSize) { x = worldSize - 1; }
    if(y >= worldSize) { y = worldSize - 1; }
    currentX = x;
    currentY = y;
    var str = mapPrint(x,y);
	if (check == 1){
		document.all('map').innerHTML = str;
	}else if (check == 2){
		with(document.layers["map"].document){
			write("<HTML><BODY><DIV align='center'>",str,"</DIV></BODY></HTML>"); 
			close();
		}
	}else if (check == 3){
		document.getElementById('map').innerHTML = str;
	}
    pointMove(currentX, currentY);
}

// ���W�����ړ�
function pointMove(x, y) {
    if(x < 0) { x = 0; }
    if(y < 0) { y = 0; }
    if(x >= worldSize) { x = worldSize - 1; }
    if(y >= worldSize) { y = worldSize - 1; }
	if (check == 1){
		document.all('pointX').options[x].selected = true;
		document.all('pointY').options[y].selected = true;
	}else if (check == 2){
		document.layers["pointX"].document.options[x].selected = true;
		document.layers["pointY"].document.options[y].selected = true;
	}else if (check == 3){
		document.getElementById('pointX').options[x].selected = true;
		document.getElementById('pointY').options[y].selected = true;
	}
}

// �R�}���h����
function comIn(mode) {
	// �����o��
	if (check == 1){
		var planNum = document.all('planNum').value;
		var command = document.all('command').value;
		var x = document.all('pointX').value;
		var y = document.all('pointY').value;
		var island = document.all('island').value;
		var amount = document.all('amount').value;
	}else if (check == 2){
		var planNum = document.layers["planNum"].value;
		var command = document.layers["command"].value;
		var x = document.layers["pointX"].value;
		var y = document.layers["pointY"].value;
		var island = document.layers["island"].value;
		var amount = document.layers["amount"].value;
	}else if (check == 3){
		var planNum = document.getElementById('planNum').value;
		var command = document.getElementById('command').value;
		var x = document.getElementById('pointX').value;
		var y = document.getElementById('pointY').value;
		var island = document.getElementById('island').value;
		var amount = document.getElementById('amount').value;
	}
	var i;

	if(mode == 0) {
		// �}�����[�h
		// �ԍ��ȍ~�����ւ��炷
		for(i = commandMax - 1; i > planNum; i--) {
			comData[i] = comData[i - 1];
		}
	}

	if(mode != 2) {
		// �폜�ȊO
		comData[planNum] = [command, island, x, y, amount];
		if(planNum < (commandMax - 1)) {
			numberSet(1 + Math.floor(planNum));
		}
	} else {
		// �폜
		for(i = Math.floor(planNum); i < (commandMax - 1); i++) {
			comData[i] = comData[i + 1];
		}
		comData[commandMax - 1] = [61,0,0,0,0];
	}

	// �f�[�^�ɔ��f
	if (check == 1){
		document.all('commandtext').value = currentPlanD();
		document.all('planarea').innerHTML = currentPlan();
		document.all('planarea').bgColor = changeCommandBG;
	}else if (check == 2){
		document.layers["commandtext"].value = currentPlanD();
		with (document.layers["planarea"].document){ 
			write("<HTML><BODY><DIV align='center'>",currentPlan(),"</DIV></BODY></HTML>"); 
			close();
		}
		document.layers["planarea"].bgColor = changeCommandBG;
	}else if (check == 3){
		document.getElementById('commandtext').value = currentPlanD();
		document.getElementById('planarea').innerHTML = currentPlan();
		document.getElementById('planarea').bgColor = changeCommandBG;
	}
}

// �n�`1�}�X�����o��
function mapPoint(x, y) {
    var s = mapData[y].substr(x * 5, 5);
    var s1 = hex(s.substr(0,1));
    var s2 = hex(s.substr(1,2));
    var s3 = hex(s.substr(3,2));
    return [s1, s2, s3];
}

// �������16�i����
function hex(s) {
    var l = s.length;
    var i;
    var v = 0;
    for(i = 0; i < l; i++) {
	v = v * 16;
	var c = s.charCodeAt(i);
	if(c <= 57/* '9' */) {
	    c -= 48/* '0' */;
	} else {
	    c += 10 - 97/* 'a' */;
	}
	v += c;
    }
    return v;
}

// ���͍ς݂̌v��(hidden��value�p)
function currentPlanD() {
    var str = currentID + ' ';
    var i;
    for(i = 0; i < commandMax; i++) {
	var c = comData[i];
	str += c[0] + ' ' + c[1] + ' ' + c[2] + ' ' + c[3] + ' ' + c[4] + ' ';
    }    
    return str;
}

// ���͍ς݂̌v��(�\���p)
function currentPlan() {
    var str = '';
    var i;
    for(i = 0; i < commandMax; i++) {
	var c = comData[i];
	var kind = c[0];
	var cc = commandObj(kind);
	var name = tagComName(cc[1]);
	var tname;
	var target = getIslandByID(c[1]);
	tname = target[0];
	tname = tagName(tname + '��');
	var x = c[2];
	var y = c[3];
	var amount = c[4];
	var point = tagName("�i" + x + "�C" + y + "�j");

	// ��ނŕ���
	var tstr;
	if((kind == 61) ||
	   (kind == 65) ||
	   (kind == 66)) {
	    // ���O�����n
	    tstr = name;
	} else if((kind == 41) ||
		  (kind == 42) ||
		  (kind == 43) ||
		  (kind == 44)) {
	    // �~�T�C��
	    tstr = point + '��' + name;
	    if(amount == 0) {
		tstr += '(������)';
	    } else {
		tstr += '(' + amount + '��)';
	    }
	} else if(kind == 45) {
	    // �^�[�Q�b�g�t�L
	    tstr = tname + '��' + name;
	} else if(kind == 63) {
	    // �����t�L
	    if(amount == 0) { amount = 1; } 
	    tstr = tname + '��' + name + amount + '00' + unitMoney;
	} else if(kind == 64) {
	    if(amount == 0) { amount = 1; } 
	    // �H���A���蓇�t�L
	    tstr = tname + '��' + name + amount + '00' + unitFood;
	} else if(kind == 62) {
	    if(amount == 0) { amount = 1; } 
	    // �H���t�L
	    tstr = name + amount + '00' + unitFood;
	} else if(kind == 4) {
	    // �@��
	    tstr = point + '��' + name;
	    if(amount != 0) {
		tstr += '(�\�Z' + (amount * 200) + unitMoney + ')';
	    }
	} else if(kind == 67) {
	    // ���W�t�L(����)
	    tstr = point + '��' + name;
	} else  if((kind == 22) || (kind == 23) || (kind == 24)) {
	    // ���W�A�񐔕t�L
	    if(amount != 0) {
		tstr = point + '��' + name + '(' + amount + '��)';
	    } else {
		tstr = point + '��' + name;
	    }
	} else {
	    // ���W�t�L
	    tstr = point + '��' + name;
	}
	var dum0 = '';
	if(i < 9) {
	    dum0 = '0';
	}
	str +=
	    '<A STYLE="text-decoration:none;color:000" HREF="JavaScript:numberSet(' + i + ');" ' +
	    help('�N���b�N����Ƃ��̌v��ԍ����I������܂��B') + '><NOBR>' +
		tagNumber(dum0 + (i + 1)) + ':' +
		    tstr + '</NOBR></A><BR>';
    }
    return str;
}

// �v��ԍ��_�C�A���O���Z�b�g
function numberSet(x) {
	if (check == 1){
		document.all('planNum').options[x].selected = true;
	}else if (check == 2){
		document.layers["planNum"].options[x].selected = true;
	}else if (check == 3){
		document.getElementById('planNum').options[x].selected = true;
	}
}

// �v��̎��->�v��I�u�W�F�N�g
function commandObj(k) {
    var i;
    for(i = 0; i < comlist.length; i++) {
	var c = comlist[i];
	if(k == c[0]) {
	    return c;
	}
    }
    return commandObj(61)/* �����J�� */;
}

// �v��ԍ��{�b�N�X
function planNumList() {
    var str = '<SELECT NAME="PlanNum" ID= "planNum">'
	var i;
    for(i = 0; i < commandMax; i++) {
	str += '<OPTION VALUE=' + i + '>' + (i + 1);
    }
    str += '</SELECT>'
	return str;
}

// ���ʗp���X�g�{�b�N�X�̒��g
function amountList() {
    var str = '<SELECT NAME="Amount" ID="amount">';
    var i;
    for(i = 0; i < 100; i++) {
	str += '<OPTION VALUE=' + i + '>' + i;
    }
    str += '</SELECT>'
	return str;
}

// �R�}���h�p���X�g�{�b�N�X�̒��g
function commandList(x, y) {
    var str = '<SELECT NAME="Command" ID="command">';
    var i;
    for(i = 0; i < comlist.length; i++) {
	var c = comlist[i];
	var v = c[2];
	str += '<OPTION VALUE=' + c[0] + '>' + c[1];
	if(v == 0) {
	    str += '�i�����j';
	} else if(v < 0) {
	    str += '�i' + (-v) + unitFood +'�j';
	} else {
	    str += '�i' + v + unitMoney +'�j';
	}
    }
    str += '</SELECT>';
    return str;
}

// ���W�I��p���X�g�{�b�N�X�̒��g
function pointList(x, y) {
    var str = '(<SELECT NAME="PointX" ID="pointX">';
    str += pointListSub(x);
    str += '</SELECT>,<SELECT NAME="PointY" ID="pointY">';
    str += pointListSub(y);
    str += '</SELECT>)';
    return str;
}

function pointListSub(num) {
    var str = '';
    var i;
    for(i = 0; i < worldSize; i++) {
	if(i == num) {
	    str += '<OPTION VALUE=' + i + ' SELECTED>' + i;
	} else {
	    str += '<OPTION VALUE=' + i + '>' + i;
	}
    }
    return str;
}

// ���W�I��p���X�g�{�b�N�X�̒��g
function islandList(x, y) {
    var l = infoData.length;
    var str = '<SELECT NAME="Island" ID="island">';
    for(i = 0; i < l; i++) {
	var island = infoData[i];
	var name = island[0];
	var id = island[1];
	if(did == id) {
	    str += '<OPTION VALUE=' + id + ' SELECTED>' + name + '��';
	} else {
	    str += '<OPTION VALUE=' + id + '>' + name + '��';
	}
    }
    str += '</SELECT>';
    return str;
}

// �ԍ����瓇�z����擾
function getIsland(num) {
    return infoData[num - 1];
}

// ID���瓇�z����擾
function getIslandByID(id) {
    var l = infoData.length;
    var i;
    for(i = 0; i < l; i++) {
	if(infoData[i][1] == id) {
	    return infoData[i];
	}
    }
    return ['�Y�ꋎ��ꂽ',id,0,0,0,0,0,'',0,0,0,0,0,0,0];
}


// ID���瓇�ԍ����擾
function getNumberByID(id) {
    var l = infoData.length;
    var i;
    for(i = 0; i < l; i++) {
	if(infoData[i][1] == id) {
	    return i;
	}
    }
    return 0;
}

// ���O�����Ȃ���
function logRewrite(id) {
	if (check == 1){
		document.all('log').innerHTML = logPrint(id);
	}else if (check == 2){
		with (document.layers["log"].document){ 
			write("<HTML><BODY><DIV align='center'>",logPrint(id),"</DIV></BODY></HTML>"); 
			close();
		}
	}else if (check == 3){
		document.getElementById('log').innerHTML = logPrint(id);
	}
}


// ���O�\��
function logPrint(id) {
    var str = '<A STYLE="text-decoration:none" HREF="JavaScript:logRewrite(0);" ' + help('�S���̃��O��\�����܂�') + 
    '><B>���O�\��</B></A><BR><BR>';
    var i, j;
    var len1 = logData.length;
    if((id == 0) && (len1 > 2)){
	len1 = 2;
    }
    for(i = 0; i < len1; i++) {
	var l = logData[i];
	var len2 = l.length;
	for(j = len2 - 1; j >= 0; j--) {
	    var ll = l[j];
	    if(ll.length != 8) {
		continue;
	    }
	    var kind = ll[0];
	    var mIsland = ll[1];
	    var sIsland = ll[2];
	    var cKind = ll[3];
	    var x = ll[4];
	    var y = ll[5];
	    var land = ll[6];
	    var amount = ll[7];
	    if((id == 0) ||
	       (mIsland == -1) ||
	       (id == mIsland) ||
	       (id == sIsland)) {
		str += logMessage(kind, mIsland, sIsland, cKind,
				  x, y, land, amount, cturn - i);
	    }
	}
    }
    return str;
}

// �e���O�̕\��
function logMessage(kind, mIsland, sIsland, cKind, x, y, land, amount, turn) {
    var name1 = tagName('�����n��');
    var name2 = tagName('�����n��');
    if(mIsland) {
	var i1 = getIslandByID(mIsland);
	name1 = tagName(i1[0] + '��');
    }
    if(sIsland) {
	var i2 = getIslandByID(sIsland);
	name2 = tagName(i2[0] + '��');
    }
    var c = commandObj(cKind);
    var cName = tagComName(c[1]);

    var lName = '<B>' + landName(land) + '</B>';
    var point;
    if(x != -999) {
	point = '<A STYLE="text-decoration:none" HREF="JavaScript:mapMove(' + x + ',' + y + ');" ' +
	 + help('�N���b�N�����(' + x + ',' + y + ')�n�_�ɔ�т܂��B') + '>' + tagName('(' + x + ',' + y + ')') + '</A>';
    } else {
	point = tagName('(?,?)');
    }

    var str = '<NOBR>' + tagNumber(turn + '�^�[���F');
    switch(kind) {
    case 100: // �����s��
	str += name1 + '�ŗ\�肳��Ă���' + cName +
	    '�́A<B>�����s��</B>�̂��ߒ��~����܂����B';
	break;

    case 101: // �H���s��
	str += name1 + '�ŗ\�肳��Ă���' + cName +
	    '�́A<B>�H���s��</B>�̂��ߒ��~����܂����B';
	break;

    case 102: // �����̓y�n����Ȃ�
	str += name1 + '�ŗ\�肳��Ă���' + cName + '�́A�\��n��' + point +
	    '��<B>�̗L�n�łȂ�</B>���ߒ��~����܂����B';
	break;

    case 103: // ���n�̎�ނ�����
	str += name1 + '�ŗ\�肳��Ă���' + cName + '�́A�\��n��' + point +
	    '��' + lName + '���������ߒ��~����܂����B';
	break;

    case 104: // ���͂ɗ̗L�n���Ȃ�
	str += name1 + '�ŗ\�肳��Ă���' + cName + '�́A�\��n��' + point +
	    '���ӂ�<B>�̗L�n������</B>���ߒ��~����܂����B';
	break;

    case 105: // ���łɎ����̓y�n
	str += name1 + '�ŗ\�肳��Ă���' + cName + '�́A�\��n��' + point +
	    '��<B>���ɗ̗L�n�ł���</B>���ߒ��~����܂����B';
	break;

    case 106: // ���l�̓y�n
	str += name1 + '�ŗ\�肳��Ă���' + cName + '�́A�\��n��' + point +
	    '��<B>�����̗̗L�n�ł���</B>���ߒ��~����܂����B';
	break;

    case 107: // ����̓����Ȃ�
	str += name1 + '�ŗ\�肳��Ă���' + cName +
	    '�́A<B>����̓������ɑ��݂��Ȃ�</B>���ߒ��~����܂����B';
	break;

    case 108: // ���n�̎�ނ�����
	str += name1 + '�ŗ\�肳��Ă���' + cName + '�́A�\��n��' + point +
	    '��<B>�C�^���s�ւȂ���</B>�ɒ��~����܂����B';
	break;

    case 200: // �s���� + ���W
	str += name1 + '��' + point + '��' + cName + '���s���܂����B';
	break;

    case 201: // ���c����
	str += name1 + '��' + point + '�ŗ\�Z' + amount + unitMoney + '��' +
	    cName + '���s���A<B>���c���@�蓖�Ă܂����B</B>';
	break;

    case 202: // ���c�����Ȃ炸
	str += name1 + '��' + point + '�ŗ\�Z' + amount + unitMoney + '��' +
	    cName + '���s���܂������A<B>���c�͌�����܂���ł����B</B>';
	break;

    case 203: // �N�����u�N��
	str += name1 + point + '��' + lName + '��<B>�N�����u���N��</B>����܂����B';
	break;

    case 204: // ������Ȃ����E�E�E
	str += '������Ȃ����A' + name1 + '��<B>�X</B>���������悤�ł��B';
	break;

    case 205: // �~�T�C�����ˎw��
	str += name1 + '��' + point + '�n�_�ւ�' + cName + '�𔭗߂��܂����B';
	break;

    case 206: // ���b�h��
	str += name1 + '��<B>�l�����b������</B>�A' + name2 + '�֔h�����܂����B';
	break;

    case 207: // ��������
	str += name1 + '���A' + name2 + '��' + amount + unitMoney + '��' +
	    cName + '���s���܂����B';
	break;

    case 208: // �H������
	str += name1 + '���A' + name2 + '��' + amount + unitFood + '��' +
	    cName + '���s���܂����B';
	break;

    case 209: // �H���A�o
	str += name1 + '��' + amount + unitFood + '��' +
	    cName + '���s���܂����B';
	break;

    case 210: // �s��������
	str += name1 + '��' + cName + '���s���܂����B';
	break;

    case 211: // ������
	str += name1 + '��' + amount + unitMoney + '����<B>������</B>�����@����܂����B';
	break;

    case 212: // ���c����
	str += name1 + point + '��' + lName + '��' + amount + unitMoney + '�̎���������܂����B';
	break;

    case 213: // ���c�͊�
	str += name1 + point + '��' + lName + '��<B>�͊�</B>�����͗l�B';
	break;

    case 214: // �̓y�̕ω�
	str += name1 + point + '��' + lName + '�́A' + name2 + '�̗̒n�ƂȂ�܂����B';
	break;

    case 400: // �H���s��
	str += name1 + '��<B>�H�����s�����Ă��܂��B</B>';
	break;

    case 401: // �΍�
	str += name1 + point + '��' + lName + '��' + tagDis('�΍�') + '������</B>�B��т��r�n�Ɖ����܂����B';
	break;

    case 402: // �L���Q�Ő��v
	str += name1 + point + '��' + lName + '�͐��v���܂����B';
	break;

    case 403: // �L���Q�ōr�n
	str += name1 + point + '��' + lName + '�͏�����т܂����B';
	break;

    case 404: // �h�q�{�ݎ���
	str += name1 + point + '�ɂ���' + lName + '��<B>�������u���쓮�I�I</B>';
	break;

    case 405: // �C�ꂪ�[���Ȃ�
	str += name1 + point + '�̊C�ꂪ�������܂����B';
	break;

    case 406: // ���b����
	str += name1 + point + '�ɋ���' + lName + '�������o�����͗l�I�I';
	break;

    case 407: // ���b��Q
	str += name1 + point + '��' + lName + '�����ݍr�炳��܂����B';
	break;

    case 408: // �L�O�蔭��
	str += name1 + point + '��' + lName + '���A�����ƂƂ��ɔ�ї����܂����B</B>';
	break;

    case 409: // �L�O�蒅�e
	str += point + '��<B>�����ƂĂ��Ȃ�����</B>�����������͗l�ł��B</B>';
	break;

    case 410: // �n�k�ōr�n
	str += name1 + point + '��' + lName + '�͕��󂵂܂����B';
	break;

    case 411: // �n�k����
	str += tagDis('�n�k�����I�I') + '�k���n��' + point + '�n�_�I�I';
	break;

    case 412: // �Ôg����
	str += point + '�t�߂�' + tagDis('�Ôg') + '�̔�Q���o�Ă��܂��B';
	break;

    case 413: // �䕗����
	str += point + '�t�߂�' + tagDis('�䕗') + '���P���܂���';
	break;

    case 414: // ��΂����
	str += name1 + point + '��' + lName + '�͔��ł����܂����B';
	break;

    case 415: // �����Q
	str += point + '�t�߂�' + tagDis('�����Q') + '���P�����܂����B';
	break;

    case 416: // 覐Η���������
	str += name1 + point + '��' + lName + '��' + tagDis('覐�') + '���������܂����B';
	break;

    case 417: // �C��P����
	str += name1 + point + '��' + lName + '��' + tagDis('覐�') + '�������A�C�ꂪ�P���܂����B';
	break;

    case 418: // �C�̑���
	str += name1 + point + '��' + tagDis('覐�') + '�������A' + lName + '�͊C�̑����Ə����܂����B';
	break;

    case 419: // ���v
	str += name1 + point + '��' + tagDis('覐�') + '�������A' + lName + '�͐��v���܂����B';
	break;

    case 420: // ����覐�
	str += point + '��' + tagDis('����覐�') + '�������I�I';
	break;

    case 421: // ����
	str += point + '��' + tagDis('�ΎR����') + '�A<B>�R</B>���ł��܂����B';
	break;

    case 422: // �C�ꂪ���N
	str += name1 + point + '�̊C�ꂪ���N�A' + lName + '�ɂȂ�܂����B';
	break;

    case 423: // �ΎR�D
	str += name1 + point + '��' + lName + '�Ɍ������ėn�◬������A��т�<B>�r�n</B>�Ɖ����܂����B';
	break;

    case 424: // ���b
	str += name1 + point + '��' + lName + '��' + tagDis('���b') + '���o���B��т����ݍr�炳��܂����B';
	break;

    case 425: // �
	str += name1 + '�ɂǂ�����Ƃ��Ȃ�' + amount + unitPop + '��<B>�</B>���Y�����܂����B' + name1 + '�͉����󂯓��ꂽ�悤�ł��B';
	break;

    case 426: // �\��
	str += name1 + point + '��' + lName + '�́A�H�������߂�Z����' + tagDis('�\��') + '�ɂ��j�󂳂�܂����B';
	break;

    case 500: // �~�T�C�����������̈�O
	str += name1 + '��' + cName + '���s���܂������A<B>�̈�O�̊C</B>�ɗ������͗l�ł��B';
	break;

    case 501: // �ʏ�~�T�C���A�d�����̉��b�Ƀq�b�g
	str += name1 + '��' + cName + '���s���A' + name2 + point + '��' +
	    lName + '�ɖ����B�������d����Ԃ������ߌ��ʂ�����܂���ł����B';
	break;

    case 502: // �ʏ�~�T�C���A���b�Ƀq�b�g
	str += name1 + '��' + cName + '���s���A' + name2 + point + '��' +
	    lName + '�ɖ����B' + lName + '�͋ꂵ�����ə��K���܂����B';
	break;

    case 503: // �ʏ�~�T�C���A���b�Ƀq�b�g�A�|���B
	str += name1 + '��' + cName + '���s���A' + name2 + point + '��' +
	    lName + '�ɖ����B' + lName + '�͗͐s���A�|��܂����B';
	break;

    case 504: // ���b�̎c�[�������
	str += lName + '�̎c�[�ɂ́A' + amount + unitMoney +
	    '�̒l���t���܂����B';
	break;

    case 505: // �~�T�C���A�C���ɗ����Č��ʂȂ�
	str += name1 + '��' + cName + '���s���܂������A' + name2 + point + '��' +
	    lName + '�ɗ����܂����B';
	break;

    case 506: // �~�T�C�����e�B�C�ɂȂ�B
	str += name1 + '��' + cName + '���s���A' + name2 + point + '��' +
	    lName + '�ɒ��e�A' + lName + '�͊C�̑����Ə����܂����B';
	break;

    case 507: // �~�T�C�����e�B�r�n�ɂȂ�B
	str += name1 + '��' + cName + '���s���A' + name2 + point + '��' +
	    lName + '�ɒ��e�A��т��r�n�Ɖ����܂����B';
	break;

    case 508: // �~�T�C�����e�B�[���Ȃ�B
	str += name1 + '��' + cName + '���s���A' + name2 + point + '��' +
	    lName + '�ɒ��e�A�C�ꂪ�������܂����B';
	break;

    case 509: // �~�T�C�����e�B�󐣂ɂȂ�B
	str += name1 + '��' + cName + '���s���A' + name2 + point + '��' +
	    lName + '�ɒ��e�A��т����v���܂����B';
	break;

    case 510: // �h�q�{�݂Ŗh��
	str += name1 + '��' + cName + '���s���܂������A' + name2 + point +
	    '�̏��ŋ󒆔��j����܂����B';
	break;

    case 600: // ���
	str += name1 + '��<B>' + prizeName[amount] + '</B>����܂��܂����B';
	break;

    default:
        str += '���O�ԍ�' + kind + '�͒�`����Ă��܂���B';
	break;
    }
    return str + '</NOBR><BR>';
}

// �������O
function hisPrint() {
    // �������O����
    var str = tagHeader('<BR>�����̋L�^<BR><BR>');
    var i;
    for(i = hisData.length - 1; i >= 0; i--) {
	var l = hisData[i];
	if(l.length != 4) {
	    continue;
	}
	var turn = l[0];
	str += '<NOBR>' + tagNumber(turn + '�^�[��:');
	var kind = l[1];
	var name = tagName(l[2] + '��');
	var name2 = tagName(l[3] + '��');
	switch(kind) {
	case 0: // ����
	    str += name + '�����������B';
	    break;

	case 1: // ����
	    str += name + '����������A�Y�ꋎ����B';
	    break;

	case 2: // ���l��
	    str += name + '����l�����Ȃ��Ȃ�A�Y�ꋎ����B';
	    break;

	case 3: // ���O�ύX
	    str += name + '�A���̖��O��' + name2 + '�ɕύX����B';
	    break;
	}
	str += '</NOBR><BR>';
    }

    return str;
}

// �o���l���烌�x���Z�o
function expToLevel(elist, point) {
    var i;
    var level = 1;
    for(i = 0; i < elist.length; i++) {
	if(point >= elist[i]) {
	    level++;
	}
    }
    return level;
}

// ���n�̖��O
function landName(land) {
    switch(land) {
    case 0: return '�C';
	case 1: return '��';
	case 2: return '�C����c';
	case 10: return '�r�n';
	case 20: return '���n';
	case 21: return '��';
	case 22: return '��';
	case 23: return '�s�s';
	case 30: return '�X';
	case 40: return '�_��';
	case 50: return '�H��';
	case 60: return '�~�T�C����n';
	case 70: return '�h�q�{��';
	case 71: return '�n���{�e';
	case 80: return '�R';
	case 100: return '�C���n';
	default:
	    if(land < 300) {
		// ���b
		return '���b' + monsterName[land - 200];
	    } else {
		// �L�O��
		return monumentName[land - 300];
	    }
	}
}
