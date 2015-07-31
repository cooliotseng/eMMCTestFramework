/*
 * CConcreteCommand.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#include "./header/CConcreteCommand.h"


CConcreteCommand::CConcreteCommand(ICommandAct *pCommandAct) {
	// TODO Auto-generated constructor stub
	this->mpCommandAct = pCommandAct;
	this->mpCommandAct->RegisterCommand(this);
	this->mpCmdRecever = NULL;
	this->mpUpdateMethod = NULL;
}
CConcreteCommand::CConcreteCommand(ICommandAct *pCommandAct,IReceiver *pCmdRecever,IUpdateStatus *pUpdateMethod){
	// TODO Auto-generated constructor stub
	this->mpCommandAct = pCommandAct;
	this->mpCommandAct->RegisterCommand(this);
	this->mpCmdRecever = pCmdRecever;
	this->mpUpdateMethod = pUpdateMethod;
}

CConcreteCommand::~CConcreteCommand() {
	// TODO Auto-generated destructor stub
}

void CConcreteCommand::Execute() {
	// TODO Auto-generated constructor stub
	Json::Value value;
	cout << "CConcreteCommand::Execute" << endl; // prints !!!Hello World!!!
	value = this->mpCmdRecever->Action();
	this->mpUpdateMethod->Update(value);
}
