/*
 * CCmdType3Receiver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CCmdDeviceTypeCaseReceiver.h"

CCmdDeviceTypeCaseReceiver::CCmdDeviceTypeCaseReceiver(int _Cmdname, std::string _FileName) {
	mCmdname = _Cmdname;
	mFileName = _FileName;
}

CCmdDeviceTypeCaseReceiver::~CCmdDeviceTypeCaseReceiver() {
}

Json::Value CCmdDeviceTypeCaseReceiver::Action() {
	Json::Value value;
	Json::Value ArgArray;

	//Replace 'echo' with 'printf', the printf command can put the string in text file without append newline.
	switch (mCmdname) {
		case 1000:  //High-Speed 26MHz, 1 bit data bus (SDR)
			system ("printf '00000001' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '0' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1001:  //High-Speed 26MHz, 4 bit data bus (SDR)
			system ("printf '00000001' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '1' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1002:  //High-Speed 26MHz, 8 bit data bus (SDR)
			system ("printf '00000001' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '2' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1003:  //High-Speed 52MHz, 1 bit data bus (SDR)
			system ("printf '00000011' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '0' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1004:  //High-Speed 52MHz, 4 bit data bus (SDR)
			system ("printf '00000011' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '1' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1005:  //High-Speed 52MHz, 8 bit data bus (SDR)
			system ("printf '00000011' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '2' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1006:  //High-Speed 52MHz, 4 bit data bus (DDR), 1.8V or 3V I/O
			system ("printf '00000111' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '5' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1007:  //High-Speed 52MHz, 8 bit data bus (DDR), 1.8V or 3V I/O
			system ("printf '00000111' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '6' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;


		case 1008:  //HS200, 1 bit data bus (SDR), 1.8V I/O
			system ("printf '00010111' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '0' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1009:  //HS200, 4 bit data bus (SDR), 1.8V I/O
			system ("printf '00010111' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '1' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		case 1010:  //HS200, 8 bit data bus (SDR), 1.8V I/O
			system ("printf '00010111' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '2' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
		break;

		default:
			system ("printf '00010111' > /var/www/html/emmc/statusFiles/timing_bus/timing/config");
			system ("printf '2' > /var/www/html/emmc/statusFiles/timing_bus/bus_width/config");
	}



	sleep(1);
	system("sudo modprobe -r sdhci_acpi");
	sleep(1);
	system("sudo modprobe sdhci_acpi");
	sleep(1);


	value["CMDINDEX"] = mCmdname;
	value["Argument"] = ArgArray;
	value["ReadFileName"] = mFileName;

	return value;
}
