/*
 * CCmdRWCaseReceiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdWriteCaseReceiver.h"

CCmdWriteCaseReceiver::CCmdWriteCaseReceiver(int _Cmdname,int _StartAdd,int _BlkLength,std::string _Iofilename,std::string _FileName) {
	// TODO Auto-generated constructor stub
	mCmdname = _Cmdname;
	mStartAdd = _StartAdd;
	mBlkLength = _BlkLength;
	mIofilename = _Iofilename;
	mFileName = _FileName;
}

CCmdWriteCaseReceiver::~CCmdWriteCaseReceiver() {
}

Json::Value CCmdWriteCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	stringstream streamIndex, streamAddr, streamLength;

	FILE *pp;

	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTest","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	/*
	 * leading zeros   ex: 25 > 00025
	 * */
	streamIndex  << setfill('0') << setw(10) << mCmdname;
	streamAddr   << setfill('0') << setw(10) << mStartAdd;
	streamLength << setfill('0') << setw(10) << mBlkLength;

	switch (mCmdname) {
		case openEnd:
			mCmdIndexString.assign("0000000047#");
			break;

		case preDefined_non_reliable:
			mCmdIndexString.assign("0000000059#");
			break;

		case preDefined_reliable:
			mCmdIndexString.assign("0000000072#");
			break;

	}

	mCmdIndexString.append(streamIndex.str());				// 00047#00000
	mCmdIndexString.append("#").append(streamAddr.str());	// 00047#00000#00000
	mCmdIndexString.append("#").append(streamLength.str()); // 00047#00000#00000#00001
	mCmdIndexString.append("#").append(mIofilename);		// 00047#00000#00000#00001#/var/www/cdsdc
	mCmdIndexString.append(" > ");

	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	pclose(pp);

	ArgArray[0]= mStartAdd;
	ArgArray[1]= mBlkLength;
	ArgArray[2]= mIofilename;

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
