/*
 * CType3CommandHandler.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef CWRITECASEHANDLER_H_
#define CWRITECASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdWriteCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CWriteCaseHandler: public CHandler {
public:
	CWriteCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CWriteCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* CTYPE3COMMANDHANDLER_H_ */
