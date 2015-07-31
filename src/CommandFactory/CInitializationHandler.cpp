/*
 * CType2CommandHandler.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#include "header/CInitializationHandler.h"

CInitializationHandler::CInitializationHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu) {
	// TODO Auto-generated constructor stub

}

CInitializationHandler::~CInitializationHandler() {
	// TODO Auto-generated destructor stub
}

int CInitializationHandler::getCommandType() {
	return 100;
}

void CInitializationHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];
	pCmdRecever = new CCmdInitializationReceiver(_value["CMDINDEX"].asInt(), _value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
