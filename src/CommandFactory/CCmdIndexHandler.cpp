/*
 * CType1CommandHandler.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#include "./header/CCmdIndexHandler.h"

CCmdIndexHandler::CCmdIndexHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)
{
	// TODO Auto-generated constructor stub

}

CCmdIndexHandler::~CCmdIndexHandler() {
	// TODO Auto-generated destructor stub
}

int CCmdIndexHandler::getCommandType() {
	// TODO Auto-generated destructor stub
	return cmdIndex;
}

void CCmdIndexHandler::genCommand(Json::Value _value) {
	// TODO Auto-generated destructor stub
	const Json::Value ArgArray = _value["Argument"];
	pCmdRecever = new CCmdIndexReceiver(_value["CMDINDEX"].asInt(),ArgArray[0].asInt(),_value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
