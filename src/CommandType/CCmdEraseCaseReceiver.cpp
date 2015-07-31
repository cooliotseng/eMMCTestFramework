/*
 * CCmdTypeC_Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdEraseCaseReceiver.h"

CCmdEraseCaseReceiver::CCmdEraseCaseReceiver(int _Cmdname,int _StartAdd,int _BlkLength,std::string _FileName) {
	mCmdname = _Cmdname;
	mStartAdd = _StartAdd;
	mBlkLength = _BlkLength;
	mFileName = _FileName;
}

CCmdEraseCaseReceiver::~CCmdEraseCaseReceiver() {
}

Json::Value CCmdEraseCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	FILE *pp;

	stringstream streamIndex, streamAddr, streamLength;

	sleep(1);

	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTest","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	streamIndex  << setfill('0') << setw(10) << mCmdname;
	streamAddr   << setfill('0') << setw(10) << mStartAdd;
	streamLength << setfill('0') << setw(10) << mBlkLength;


	if (mCmdname == ERASE) {
		mCmdIndexString.assign("0000000048#");
	} else if (mCmdname == TRIM) {
		mCmdIndexString.assign("0000000064#");
	} else if (mCmdname == DISCARD) {
		mCmdIndexString.assign("0000000085#");
	}

	mCmdIndexString.append(streamIndex.str());					// 00048#00000 (cmdIndex don't care)
	mCmdIndexString.append("#").append(streamAddr.str());		// 00048#00000#00000
	mCmdIndexString.append("#").append(streamLength.str());		// 00048#00000#00000#00016


	mCmdIndexString.append(" > ");								// 00048#00000#00000#00016#testLOL >

	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	pclose(pp);

	ArgArray[0]= mStartAdd;
	ArgArray[1]= mBlkLength;

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
