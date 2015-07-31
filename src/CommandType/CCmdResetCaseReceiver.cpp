/*
 * CCmdType3Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdResetCaseReceiver.h"

CCmdResetCaseReceiver::CCmdResetCaseReceiver(int _Cmdname, std::string _FileName) {
	mCmdname = _Cmdname;
	mFileName = _FileName;
}

CCmdResetCaseReceiver::~CCmdResetCaseReceiver() {
}

Json::Value CCmdResetCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;

	sleep(1);
	system("sudo modprobe -r sdhci_acpi");
	sleep(1);
	system("sudo modprobe sdhci_acpi");
	sleep(1);
	system("sudo rmmod mmc_block");


	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
