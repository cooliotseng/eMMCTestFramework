/*
 * CCmdTypeC_Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdGppCaseReceiver.h"

CCmdGppCaseReceiver::CCmdGppCaseReceiver(int _Cmdname,int _SizeMult,int _EnhancedAttr,std::string _FileName) {
	mCmdname = _Cmdname;
	mSizeMult = _SizeMult;
	mEnhancedAttr = _EnhancedAttr;
	mFileName = _FileName;
}

/*
 * 	int mSizeMult;
	int mEnhancedAttribute;
 * */

CCmdGppCaseReceiver::~CCmdGppCaseReceiver() {
}

Json::Value CCmdGppCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	FILE *pp;

	stringstream streamIndex, streamSize, streamAttr;

	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTest","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	streamIndex  << setfill('0') << setw(10) << mCmdname;
	streamSize   << setfill('0') << setw(10) << mSizeMult;
	streamAttr << setfill('0') << setw(10) << mEnhancedAttr;

	mCmdIndexString.assign("0000000055#");

	mCmdIndexString.append(streamIndex.str());					// 0000000055#0000000143 (Trick: Use cmdIndex)
	mCmdIndexString.append("#").append(streamSize.str());		// 0000000055#0000000143#0000000000
	mCmdIndexString.append("#").append(streamAttr.str());		// 00055#00143#00000#00016
	mCmdIndexString.append(" > ");								// 00055#00143#00000#00016 >

	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	pclose(pp);

	ArgArray[0]= mSizeMult;
	ArgArray[1]= mEnhancedAttr;

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
