/*
 * CType3CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CWriteCaseHandler.h"

CWriteCaseHandler::CWriteCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CWriteCaseHandler::~CWriteCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CWriteCaseHandler::getCommandType() {
	// TODO Auto-generated destructor stub
	return writeCase;
}

void CWriteCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdWriteCaseReceiver(_value["CMDINDEX"].asInt(),ArgArray[0].asInt(),ArgArray[1].asInt(),ArgArray[2].asCString(),_value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
