/*
 * CType4CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CReadCaseHandler.h"

CReadCaseHandler::CReadCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CReadCaseHandler::~CReadCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CReadCaseHandler::getCommandType() {
	return readCase;
}

void CReadCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdReadCaseReceiver (_value["CMDINDEX"].asInt(),ArgArray[0].asInt(),ArgArray[1].asInt(),_value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
