/*
 * CCmdType3Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdInitializationReceiver.h"

CCmdInitializationReceiver::CCmdInitializationReceiver(int _Cmdname, std::string _FileName) {
	mCmdname = _Cmdname;
	mFileName = _FileName;
}

CCmdInitializationReceiver::~CCmdInitializationReceiver() {
}

Json::Value CCmdInitializationReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;

	string tShellbuf;
	string mCmdIndexString;
	char Shellbuf[4096] = {};

	stringstream tempStream;
	FILE *pp;

	system ("echo 1 > ~/debugfs/mmc0/mmc0\:0001/cardInitialization");
	/*
	ifstream infile;
	char test[16];
	int fileSize, i;
	int q, r;

	infile.open("~/Pictures/456", ios::binary | ios::in);
	if (!infile) {
		return -1;
	}

	infile.seekg(0, ios::end);
	fileSize = infile.tellg();

    q = fileSize / 16;
    r = fileSize % 16;

    for (i = 0; i < q; i++) {
    	if((pp=popen("sudo find ~/debugfs/mmc0 -name cardInitialization","r")) == NULL){
    		std::cout << "Popen() error: " << std::endl;
    	}

		infile.seekg(i * 16, ios::beg);
		infile.read(test, 16);

	for (j = 0; j < 16; j++)
	    printf("%02x ", test[j]);

	cout << endl;

        mCmdIndexString.assign(test, 0, 16).append(" > ");
    	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));

    	system(tShellbuf.c_str());
    	pclose(pp);
    }


	if((pp=popen("sudo find ~/debugfs/mmc0 -name cardInitialization","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}
    infile.seekg (q * 16, ios::beg);
    infile.read (test, r);
    mCmdIndexString.assign(test, 0, r - 1).append(" > ");
    tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));;
    system(tShellbuf.c_str());
    pclose(pp);

*/
    //    	system("echo 6 >> /var/www/html/emmc/statusFiles/show.log");
	/*
	tempStream << mCmdname;
	mCmdIndexString.assign(tempStream.str()).append(" > ");
	tShellbuf.assign("echo ").append(mCmdIndexString).append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());
	*/



	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;


	return value;
}
