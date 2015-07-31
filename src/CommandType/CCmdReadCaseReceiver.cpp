/*
 * CCmdTypeC_Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdReadCaseReceiver.h"

CCmdReadCaseReceiver::CCmdReadCaseReceiver(int _Cmdname,int _StartAdd,int _BlkLength,std::string _FileName) {
	mCmdname = _Cmdname;
	mStartAdd = _StartAdd;
	mBlkLength = _BlkLength;
	mFileName = _FileName;
}

CCmdReadCaseReceiver::~CCmdReadCaseReceiver() {
}

Json::Value CCmdReadCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	FILE *pp;

	stringstream streamIndex, streamAddr, streamLength;
	stringstream timestampFile;
	time_t timestamp = time(0);

	timestampFile << timestamp;

	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTest","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	streamIndex  << setfill('0') << setw(10) << mCmdname;
	streamAddr   << setfill('0') << setw(10) << mStartAdd;
	streamLength << setfill('0') << setw(10) << mBlkLength;


	switch (mCmdname) {
		case openEnd:
			mCmdIndexString.assign("0000000046#");
			break;

		case preDefined_non_reliable:
			mCmdIndexString.assign("0000000058#");
			break;

		case preDefined_reliable:
			mCmdIndexString.assign("0000000071#");
			break;
		default:
			mCmdIndexString.assign("0000000046#");
	}

	mCmdIndexString.append(streamIndex.str());					// 00046#00000 		(cmdIndex don't care)
	mCmdIndexString.append("#").append(streamAddr.str());		// 00046#00000#00000
	mCmdIndexString.append("#").append(streamLength.str());		// 00046#00000#00000#00016
	mCmdIndexString.append("#").append(timestampFile.str());	// 00046#00000#00000#00016#testLOL
	mCmdIndexString.append(" > ");								// 00046#00000#00000#00016#testLOL >

	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	pclose(pp);

	ArgArray[0]= mStartAdd;
	ArgArray[1]= mBlkLength;
	ArgArray[2]= timestampFile.str();

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
