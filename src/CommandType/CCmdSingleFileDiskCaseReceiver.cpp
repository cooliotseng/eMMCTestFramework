/*
 * CCmdRWCaseReceiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdSingleFileDiskCaseReceiver.h"

CCmdSingleFileDiskCaseReceiver::CCmdSingleFileDiskCaseReceiver(int _Cmdname,std::string _Iofilename,std::string _FileName) {
	// TODO Auto-generated constructor stub
	mCmdname = _Cmdname;
	mIofilename = _Iofilename;
	mFileName = _FileName;
}

CCmdSingleFileDiskCaseReceiver::~CCmdSingleFileDiskCaseReceiver() {
}

Json::Value CCmdSingleFileDiskCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	stringstream streamIndex,
				 timestampFile;
	time_t timestamp = time(0);

	timestampFile << timestamp;

	FILE *pp;

	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTestSingleFileDisk","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	/*
	 * leading zeros   ex: 25 > 00025
	 * */
	streamIndex  << setfill('0') << setw(10) << mCmdname;


	/*
	 *
const int RPMB_read_single_frame_data = 0;
const int RPMB_read_multiple_frame_data = 1;
	 * */

	switch (mCmdname) {
		case RPMB_read_single_frame_data:
			mCmdIndexString.assign("0000000078#");
			break;

		case RPMB_read_multiple_frame_data:
			mCmdIndexString.assign("0000000080#");
			break;

		default:
			mCmdIndexString.assign("0000000078#");
	}

	mCmdIndexString.append(streamIndex.str());				// 00075#00000
	mCmdIndexString.append("#").append(mIofilename);		// 00075#00001#/var/www/cdsdc
	mCmdIndexString.append("#").append(timestampFile.str());// // 00075#00001#/var/www/cdsdc#1575346468
	mCmdIndexString.append(" > ");

	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	pclose(pp);

	ArgArray[0]= mIofilename;
	ArgArray[1]= timestampFile.str();

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
