/*
 * CFactory.h
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#ifndef CFACTORY_H_
#define CFACTORY_H_
#include <iostream>
#include <string>
#include <stdio.h>
#include "../../header/ICommand.h"
#include "../../header/ICommandAct.h"
#include "../../CommandType/header/IReceiver.h"
#include "../../UpdateMethod/header/IUpdateStatus.h"
#include "../../UpdateMethod/header/CUpdateStatus.h"
#include "../../header/CConcreteCommandAct.h"
#include "CHandler.h"
#include <json/json.h>
#include "CCmdIndexHandler.h"
#include "CTestCaseHandler.h"
#include "CReadCaseHandler.h"
#include "CEraseCaseHandler.h"
#include "CEudaCaseHandler.h"
#include "CGppCaseHandler.h"
#include "CResetCaseHandler.h"
#include "CInitializationHandler.h"
#include "CWriteCaseHandler.h"
#include "CBufferLengthCaseHandler.h"
#include "CDeviceTypeCaseHandler.h"
#include "CSingleFileCaseHandler.h"
#include "CTwoFileCaseHandler.h"
#include "CSingleFileDiskCaseHandler.h"

class CFactory {
protected:
	IUpdateStatus *pmUpdateStatus;
	CCmdIndexHandler *mCmdHandler1;
	CTestCaseHandler *mCmdHandler2;
	CWriteCaseHandler *mCmdHandler3;
	CReadCaseHandler *mCmdHandler4;
	CEraseCaseHandler *mCmdHandler5;
	CGppCaseHandler *mCmdHandler6;
	CEudaCaseHandler *mCmdHandler7;
	CResetCaseHandler *mCmdHandler8;
	CInitializationHandler *mCmdHandler9;
	CBufferLengthCaseHandler *mCmdHandler10;
	CDeviceTypeCaseHandler *mCmdHandler11;
	CSingleFileCaseHandler *mCmdHandler12;
	CTwoFileCaseHandler *mCmdHandler13;
	CSingleFileDiskCaseHandler *mCmdHandler14;
public:
	CFactory(CConcreteCommandAct *_pAct,string _Pathname);
	virtual ~CFactory();
	virtual void CreatCommandList(Json::Value _value)=0;
};

#endif /* CFACTORY_H_ */
