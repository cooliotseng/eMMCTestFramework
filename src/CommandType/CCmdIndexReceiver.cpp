/*
 * CCmdType1Receiver.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#include "header/CCmdIndexReceiver.h"

CCmdIndexReceiver::CCmdIndexReceiver(int Index,int CmdArg,std::string _FileName) {
	mCmdIndex = Index;
	mCmdArg	= CmdArg;
	mFileName = _FileName;
}

CCmdIndexReceiver::~CCmdIndexReceiver() {
}

Json::Value CCmdIndexReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	FILE *pp;

	stringstream streamIndex, streamArg;

	//myTest on debugfs
	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTest","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	streamIndex  << setfill('0') << setw(10) << mCmdIndex;
	streamArg    << setfill('0') << setw(10) << mCmdArg;

	mCmdIndexString.assign("0000000050#");							//cmdIndex

	//e.g. SWITCH to partition 0 (Default partition)
	mCmdIndexString.append(streamIndex.str());					// 00050#00006
	mCmdIndexString.append("#").append(streamArg.str());		// 00048#00006#00000
	mCmdIndexString.append(" > ");								// 00048#00006#00000 >


	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	pclose(pp);

	ArgArray[0]= mCmdArg;

	value["CMDINDEX"] = mCmdIndex;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;


	return value;
}
