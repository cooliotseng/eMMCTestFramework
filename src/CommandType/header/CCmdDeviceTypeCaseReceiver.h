/*
 * CCmdType3Receiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDDEVICETYPECASERECEIVER_H_
#define COMMANDTYPE_CCMDDEVICETYPECASERECEIVER_H_

#include "IReceiver.h"

class CCmdDeviceTypeCaseReceiver: public IReceiver {
private:
	int mCmdname;;
	std::string mFileName;
public:
	CCmdDeviceTypeCaseReceiver(int ,std::string);
	virtual ~CCmdDeviceTypeCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDTESTCASERECEIVER_H_ */
