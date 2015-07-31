/*
 * CUpdateStatus.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */
#include "./header/CUpdateStatus.h"
CUpdateStatus::CUpdateStatus(std::string _FilePath) {
	mFilePath = _FilePath;
}

CUpdateStatus::~CUpdateStatus() {
}

void CUpdateStatus::Update(Json::Value _value) {
	char Shellbuf[4096];
	std::string tString = mFilePath, dmesgLog;
    fstream file,logfile;
    FILE *pp;

    file.open(tString.append(_value["ReadFileName"].asCString()).c_str(),ios::out|ios::trunc);

    if ((pp=popen("dmesg | cut -d ']' -f 2 | grep Result | awk '{print $3}'", "r")) == NULL) {
    	std::cout << "Popen() error: " << std::endl;
	}

    if (_value["CMDINDEX"].asInt() >= 1000) {
    	_value["Response"] = "OK";
    } else {
		_value["Response"] = fgets(Shellbuf,sizeof(Shellbuf),pp);
    }

    system ("dmesg >> /var/www/html/emmc/statusFiles/myEclipseLog.log");
    system ("sudo dmesg -c >/dev/null");

    pclose(pp);

	file.write(_value.toStyledString().c_str(),_value.toStyledString().size());
	file.close();
}
