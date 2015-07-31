/*
 * CCmdRWCaseReceiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdSingleFileCaseReceiver.h"

CCmdSingleFileCaseReceiver::CCmdSingleFileCaseReceiver(int _Cmdname,std::string _Iofilename,std::string _FileName) {
	// TODO Auto-generated constructor stub
	mCmdname = _Cmdname;
	mIofilename = _Iofilename;
	mFileName = _FileName;
}

CCmdSingleFileCaseReceiver::~CCmdSingleFileCaseReceiver() {
}

Json::Value CCmdSingleFileCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	stringstream streamIndex;

	FILE *pp;

	if((pp=popen("sudo find ~/debugfs/mmc0 -name myTestSingleFile","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	/*
	 * leading zeros   ex: 25 > 00025
	 * */
	streamIndex  << setfill('0') << setw(10) << mCmdname;


	/*
	 *
const int programming_key = 0;
const int single_frame_read = 1;
const int multiple_frame_read = 2;
	 * */

	switch (mCmdname) {
		case programming_key:
			mCmdIndexString.assign("0000000075#");
			break;

		case single_frame_read:
			mCmdIndexString.assign("0000000078#");
			break;

		case multiple_frame_read:
			mCmdIndexString.assign("0000000080#");
			break;
	}

	mCmdIndexString.append(streamIndex.str());				// 00075#00000
	mCmdIndexString.append("#").append(mIofilename);		// 00075#00001#/var/www/cdsdc
	mCmdIndexString.append(" > ");

	//echo > 0000000075#0000000000#
	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	// sudo echo 0000000075#0000000000#~/Desktop/123 > ~/debugfs/mmc0/mmc0:0001/myTestSingleFile
	//system ("echo 1 > /var/www/html/emmc/statusFiles/test");

	pclose(pp);
/*
	ArgArray[0]= mStartAdd;
	ArgArray[1]= mBlkLength;
	ArgArray[2]= mIofilename;
*/
	ArgArray[0]= mIofilename;

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
