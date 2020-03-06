#include "template.h"

void Template::header() {
    if(Value::id != 0) {
	static char tmp[16];
	sprintf(tmp, "%d", Value::id);
	HakoIO::cookieOutput("ISLAND", tmp);
    }

    if(strcmp(Value::password, "") != 0) {
	HakoIO::cookieOutput("PASSWORD", Value::password);
    }

    out("Content-type: text/html\n\n"
	"<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
	"<html lang=\"ja\" dir=\"LTR\">\n"
	"<head>\n"
	"<meta http-equiv=\"content-type\" content=\"text/html;charset=Shift_JIS\">\n"
	"<meta http-equiv=\"content-language\" content=\"ja\">\n"
	"<meta http-equiv=\"content-script-type\" content=\"text/javascript\">\n"
	"<meta http-equiv=\"content-style-type\" content=\"text/css">\n"
	"<meta htto-equiv=\"pragma\" content=\"no-cache\">\n"
	"<link rel=\"stylesheet\" type=\"text/css\" href=\""
	);
    out(Value::fileDir);
    out(
	"hakow.css\" media=\"screen\">\n"
	"<script type=\"text/javascript\" src=\""
	);
    out(Value::fileDir);
    out(
	"hakow.js\"></script>\n"
	"<title>箱庭諸島２１</title>\n"
	"</head>\n<body "
	);
    out(Value::htmlBody);
    out(">\n<script type=\"text/javascript\"><!--\n"
	"check=0;\n"
	"Browser = navigator.appName;\n"
	"if(document.all){\n"
	"	check=1;\n"
	"	document.write(\"<DIV id='mainBody'></DIV>\");\n"
	"}else if(document.layers){\n"
	"	check=2;\n"
	"	document.write(\"<LAYER name='mainBody'></LAYER>\");\n"
	"}else if((document.getElementById) && navigator.appName.indexOf(\"Netscape\") > -1){\n"
	"	check=3;\n"
	"	document.write(\"<DIV id='mainBody'></DIV>\");\n"
	"}\n"
	"// --></script>\n"
	"<noscript><font color=red>このゲームは、JavaScriptがonになってないとできません。</noscript>"
	"</body>\n<script type=\"text/javascript\"><!--\n"
	);
}

void Template::footer() {
    out(
	"\n"
	"main();\n"
	"// --></script>\n"
	"</html>\n"
    );
}
