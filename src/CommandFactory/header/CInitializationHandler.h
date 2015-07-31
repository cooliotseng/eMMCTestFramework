/*
 * CType2CommandHandler.h
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#ifndef CINITIALIZATIONHANDLER_H_
#define CINITIALIZATIONHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdInitializationReceiver.h"
#include "../../header/CConcreteCommand.h"

class CInitializationHandler: public CHandler {
public:
	CInitializationHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CInitializationHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* CTYPE2COMMANDHANDLER_H_ */
