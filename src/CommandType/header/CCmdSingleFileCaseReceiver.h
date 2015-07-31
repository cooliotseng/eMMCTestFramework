/*
 * CCmdWriteCaseReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDSINGLEFILECASERECEIVER_H_
#define COMMANDTYPE_CCMDSINGLEFILECASERECEIVER_H_

#include "IReceiver.h"

class CCmdSingleFileCaseReceiver: public IReceiver {
private:
	int mCmdname;;
	std::string mIofilename;
	std::string mFileName;
public:
	CCmdSingleFileCaseReceiver(int ,std::string ,std::string);
	virtual ~CCmdSingleFileCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDSINGLEFILECASERECEIVER_H_ */
