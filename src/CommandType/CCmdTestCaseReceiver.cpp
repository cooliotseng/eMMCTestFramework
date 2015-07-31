/*
 * CCmdType3Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdTestCaseReceiver.h"

CCmdTestCaseReceiver::CCmdTestCaseReceiver(int _Cmdname, std::string _FileName) {
	mCmdname = _Cmdname;
	mFileName = _FileName;
}

CCmdTestCaseReceiver::~CCmdTestCaseReceiver() {
}

Json::Value CCmdTestCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	stringstream tempStream;
	FILE *pp;

	if((pp=popen("sudo find ~/debugfs/mmc0 -name test","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	tempStream << mCmdname;
	mCmdIndexString.assign(tempStream.str()).append(" > ");
	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));

	system(tShellbuf.c_str());

	pclose(pp);

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
