/*
 * CCmdWriteCaseReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDSINGLEFILEDISKCASERECEIVER_H_
#define COMMANDTYPE_CCMDSINGLEFILEDISKCASERECEIVER_H_

#include "IReceiver.h"

class CCmdSingleFileDiskCaseReceiver: public IReceiver {
private:
	int mCmdname;;
	std::string mIofilename;
	std::string mFileName;
public:
	CCmdSingleFileDiskCaseReceiver(int ,std::string ,std::string);
	virtual ~CCmdSingleFileDiskCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDSINGLEFILECASERECEIVER_H_ */
