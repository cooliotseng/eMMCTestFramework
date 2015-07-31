/*
 * CType2CommandHandler.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#include "header/CDeviceTypeCaseHandler.h"

CDeviceTypeCaseHandler::CDeviceTypeCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu) {
	// TODO Auto-generated constructor stub

}

CDeviceTypeCaseHandler::~CDeviceTypeCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CDeviceTypeCaseHandler::getCommandType() {
	return deviceTypeCase;
}

void CDeviceTypeCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];
	pCmdRecever = new CCmdDeviceTypeCaseReceiver(_value["CMDINDEX"].asInt(), _value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
