/*
 * CHandler.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#include "./header/CHandler.h"

CHandler::CHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatus) {
	// TODO Auto-generated constructor stub
	pmUpdateStatus = _pUpdateStatus;
	pAct = _pAct;
	pCmdRecever = NULL;
	pCommand = NULL;
	pmNextHandler = NULL;
}

CHandler::~CHandler() {
	// TODO Auto-generated destructor stub
}

void CHandler::setNext(CHandler *_pNextHandler) {
	// TODO Auto-generated destructor stub
	pmNextHandler = _pNextHandler;
}

CHandler * CHandler::getHandler() {
	// TODO Auto-generated destructor stub
	return pmNextHandler;
}

IUpdateStatus * CHandler::getUpdateStatus() {
	// TODO Auto-generated destructor stub
	return pmUpdateStatus;
}
void CHandler::setUpdateStatus(CUpdateStatus * _pUpdateStatus) {
	// TODO Auto-generated destructor stub
	pmUpdateStatus = _pUpdateStatus;
}

ICommandAct * CHandler::getCommandAct() {
	// TODO Auto-generated destructor stub
	return pAct;
}
void CHandler::setCommandAct(ICommandAct * _pCommandAct) {
	// TODO Auto-generated destructor stub
	pAct = _pCommandAct;
}

IReceiver * CHandler::getReceiver() {
	// TODO Auto-generated destructor stub
	return pCmdRecever;
}
void CHandler::setReceiver(IReceiver * _pReceiver) {
	// TODO Auto-generated destructor stub
	pCmdRecever = _pReceiver;
}

ICommand * CHandler::getCommand() {
	// TODO Auto-generated destructor stub
	return pCommand;
}

void CHandler::setCommand(ICommand * _pCommand) {
	// TODO Auto-generated destructor stub
	pCommand = _pCommand;
}

void CHandler::CommandCreatHandler(Json::Value value) {
	// TODO Auto-generated destructor stub
	if(this->getCommandType() == value["CMDType"].asInt()){
	//if(this->GetCommandType() == value["CommandIndex"]){
		this->genCommand(value);
	}else{
		if(this->pmNextHandler != NULL){
			this->pmNextHandler->CommandCreatHandler(value);
		}else{

		}

	}

}


