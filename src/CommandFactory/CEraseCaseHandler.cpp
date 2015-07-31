/*
 * CType4CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CEraseCaseHandler.h"

CEraseCaseHandler::CEraseCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CEraseCaseHandler::~CEraseCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CEraseCaseHandler::getCommandType() {
	// TODO Auto-generated destructor stub
	return eraseCase;
}

void CEraseCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdEraseCaseReceiver (_value["CMDINDEX"].asInt(),ArgArray[0].asInt(),ArgArray[1].asInt(),_value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
