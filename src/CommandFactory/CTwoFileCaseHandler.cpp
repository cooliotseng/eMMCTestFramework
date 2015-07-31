/*
 * CType3CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CTwoFileCaseHandler.h"

CTwoFileCaseHandler::CTwoFileCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CTwoFileCaseHandler::~CTwoFileCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CTwoFileCaseHandler::getCommandType() {
	// TODO Auto-generated destructor stub
	return twoFileCase;
}

void CTwoFileCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdTwoFileCaseReceiver(_value["CMDINDEX"].asInt(), ArgArray[0].asCString(), ArgArray[1].asCString(), _value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
