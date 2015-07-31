/*
 * CType4CommandHandler.h
 *
 *  Created on: Mar 13, 2015
 *      Author: vli
 */

#ifndef COMMANDFACTORY_CBUFFERLENGHTCASEHANDLER_H_
#define COMMANDFACTORY_CBUFFERLENGHTCASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdBufferLengthCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CBufferLengthCaseHandler: public CHandler {
public:
	CBufferLengthCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CBufferLengthCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* COMMANDFACTORY_CTYPE4COMMANDHANDLER_H_ */
