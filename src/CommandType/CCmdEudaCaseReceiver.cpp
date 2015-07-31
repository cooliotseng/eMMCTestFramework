/*
 * CCmdTypeC_Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdEudaCaseReceiver.h"

CCmdEudaCaseReceiver::CCmdEudaCaseReceiver(int _Cmdname, unsigned int _StartAddr, int _SizeMult, int _EnhancedAttr, std::string _FileName) {
	mCmdname = _Cmdname;
	mStartAddr = _StartAddr;
	mSizeMult = _SizeMult;
	mEnhancedAttr = _EnhancedAttr;
	mFileName = _FileName;
}

CCmdEudaCaseReceiver::~CCmdEudaCaseReceiver() {
}

Json::Value CCmdEudaCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	FILE *pp;

	stringstream streamIndex, streamAddr, streamSize, streamAttr;

	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTest","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	streamIndex  << setfill('0') << setw(10) << mCmdname;
	streamAddr   << setfill('0') << setw(10) << mStartAddr;
	streamSize   << setfill('0') << setw(10) << mSizeMult;
	streamAttr   << setfill('0') << setw(10) << mEnhancedAttr;

	mCmdIndexString.assign("0000000056#");

	mCmdIndexString.append(streamIndex.str());					// 0000000056#0000000000
	mCmdIndexString.append("#").append(streamAddr.str());		// 0000000056#0000000000:0000000000
	mCmdIndexString.append("#").append(streamSize.str());		// 00055#00000#00000#00016
	mCmdIndexString.append("#").append(streamAttr.str());		// 00055#00000#00000#00016#00001
	mCmdIndexString.append(" > ");								// 00055#00000#00000#00016 >

	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	pclose(pp);

	ArgArray[0]= mStartAddr;
	ArgArray[1]= mSizeMult;
	ArgArray[2]= mEnhancedAttr;

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
