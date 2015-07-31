/*
 * CConcreteCommandAct.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#include "./header/CConcreteCommandAct.h"

CConcreteCommandAct::CConcreteCommandAct() {
	// TODO Auto-generated constructor stub
	//mpCommandList = new vector<ICommand *>();

}

CConcreteCommandAct::~CConcreteCommandAct() {
	// TODO Auto-generated destructor stub
}

void CConcreteCommandAct::RegisterCommand(ICommand *pcmd) {
	mpCommandList.push_back(pcmd);
}

void CConcreteCommandAct::UnRegisterCommand(ICommand *pcmd) {
	mpCommandList.clear();
}

void CConcreteCommandAct::Action(){
	// TODO Auto-generated destructor stub
	std::vector<ICommand *>::iterator it = mpCommandList.begin();
	while(it != mpCommandList.end()){
		(*it)->Execute();
		++it;
	}
}
