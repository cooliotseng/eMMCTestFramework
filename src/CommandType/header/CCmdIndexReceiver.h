/*
 * CCmdTypeCmdIndexReceiver.h
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#ifndef CCMDINDEXRECEIVER_H_
#define CCMDINDEXRECEIVER_H_

#include "IReceiver.h"
using namespace std;

class CCmdIndexReceiver: public IReceiver {
private:
	int mCmdIndex;
	int mCmdArg;
	std::string mFileName;
public:
	CCmdIndexReceiver(int ,int,std::string);
	virtual ~CCmdIndexReceiver();
	Json::Value Action();
};

#endif /* CCMDINDEXRECEIVER_H_ */
