/*
 * CCmdTypeC_Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdBufferLengthCaseReceiver.h"

CCmdBufferLengthCaseReceiver::CCmdBufferLengthCaseReceiver(int _Cmdname,int _BufferLength, std::string _FileName) {
	mCmdname = _Cmdname;
	mBufferLength = _BufferLength;
	mFileName = _FileName;
}

CCmdBufferLengthCaseReceiver::~CCmdBufferLengthCaseReceiver() {
}

Json::Value CCmdBufferLengthCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	FILE *pp;

	stringstream streamIndex, streamBufferLength;

	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTest","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	streamIndex  << setfill('0') << setw(10) << mCmdname;
	streamBufferLength   << setfill('0') << setw(10) << mBufferLength;

	mCmdIndexString.assign("0000000066#");
	mCmdIndexString.append(streamIndex.str());							// 00067#00000 		(cmdIndex don't care)
	mCmdIndexString.append("#").append(streamBufferLength.str());		// 00067#00000#00004

	mCmdIndexString.append(" > ");										// 00067#00000#00004  >

	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	pclose(pp);

	ArgArray[0]= mBufferLength;

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
