/*
 * CType2CommandHandler.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#include "header/CResetCaseHandler.h"

CResetCaseHandler::CResetCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu) {
	// TODO Auto-generated constructor stub

}

CResetCaseHandler::~CResetCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CResetCaseHandler::getCommandType() {
	return resetCase;
}

void CResetCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];
	pCmdRecever = new CCmdResetCaseReceiver(_value["CMDINDEX"].asInt(), _value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
