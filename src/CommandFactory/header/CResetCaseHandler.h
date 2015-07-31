/*
 * CType2CommandHandler.h
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#ifndef CRESETCASEHANDLER_H_
#define CRESETCASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdResetCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CResetCaseHandler: public CHandler {
public:
	CResetCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CResetCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* CTYPE2COMMANDHANDLER_H_ */
