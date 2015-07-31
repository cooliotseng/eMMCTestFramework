/*
 * CCmdWriteCaseReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDWRITECASERECEIVER_H_
#define COMMANDTYPE_CCMDWRITECASERECEIVER_H_

#include "IReceiver.h"

class CCmdWriteCaseReceiver: public IReceiver {
private:
	int mCmdname;;
	int mStartAdd;
	int mBlkLength;
	std::string mIofilename;
	std::string mFileName;
public:
	CCmdWriteCaseReceiver(int ,int ,int ,std::string ,std::string);
	virtual ~CCmdWriteCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDRWCASERECEIVER_H_ */
