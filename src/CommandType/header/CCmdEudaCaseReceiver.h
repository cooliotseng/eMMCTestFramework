/*
 * CCmdTypeCReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

//#ifndef COMMANDTYPE_CCMDEUDACASERECEIVER_H_
//#define COMMANDTYPE_CCMDEUDACASERECEIVER_H_

#include "IReceiver.h"

class CCmdEudaCaseReceiver: public IReceiver {
private:
	int mCmdname;
	unsigned int mStartAddr;
	int mSizeMult;
	int mEnhancedAttr;
	std::string mFileName;
public:
	CCmdEudaCaseReceiver(int, unsigned int, int, int, std::string);
	virtual ~CCmdEudaCaseReceiver();
	Json::Value Action();
};

//#endif /* COMMANDTYPE_CCMDERASECASERECEIVER_H_ */
