/*
 * CCmdRWCaseReceiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdTwoFileCaseReceiver.h"

CCmdTwoFileCaseReceiver::CCmdTwoFileCaseReceiver(int _Cmdname,std::string _Iofilename1, std::string _Iofilename2, std::string _FileName) {
	// TODO Auto-generated constructor stub
	mCmdname = _Cmdname;
	mIofilename1 = _Iofilename1;
	mIofilename2 = _Iofilename2;
	mFileName = _FileName;
}

CCmdTwoFileCaseReceiver::~CCmdTwoFileCaseReceiver() {
}

Json::Value CCmdTwoFileCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;
	char Shellbuf[4096];
	string tShellbuf;
	string mCmdIndexString;
	stringstream streamIndex;

	FILE *pp;

	if((pp=popen("sudo find /home/vli/debugfs/mmc0 -name myTestTwoFile","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	/*
	 * leading zeros   ex: 25 > 00025
	 * */
	streamIndex  << setfill('0') << setw(10) << mCmdname;


	/*
	 *
const int RPMB_write_single_frame_data = 0;
const int RPMB_write_multiple_frame_data = 1;	 * */

	switch (mCmdname) {
		case RPMB_write_single_frame_data:
			mCmdIndexString.assign("0000000077#");
			break;
		case RPMB_write_multiple_frame_data:
			mCmdIndexString.assign("0000000079#");
			break;

		default:
			mCmdIndexString.assign("0000000077#");
	}

	mCmdIndexString.append(streamIndex.str());				// 00075#00000
	mCmdIndexString.append("#").append(mIofilename1);		// 00075#00001#/var/www/cdsdc
	mCmdIndexString.append("#").append(mIofilename2);		// 00075#00001#/var/www/cdsdc
	mCmdIndexString.append(" > ");

	//echo > 0000000075#0000000000#
	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	// sudo echo 0000000075#0000000000#/home/vli/Desktop/123 > ~/debugfs/mmc0/mmc0:0001/myTestSingleFile
	//system ("echo 1 > /var/www/html/emmc/statusFiles/test");

	pclose(pp);
/*
	ArgArray[0]= mStartAdd;
	ArgArray[1]= mBlkLength;
	ArgArray[2]= mIofilename;
*/
	ArgArray[0]= mIofilename1;
	ArgArray[1]= mIofilename2;

	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
