/*
 * CType2CommandHandler.h
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#ifndef CTESTCASEHANDLER_H_
#define CTESTCASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdTestCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CTestCaseHandler: public CHandler {
public:
	CTestCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CTestCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* CTYPE2COMMANDHANDLER_H_ */
