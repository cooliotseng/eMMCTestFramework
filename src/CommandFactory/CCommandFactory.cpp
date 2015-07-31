/*
 * CCommandFactory.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#include "./header/CCommandFactory.h"

CCommandFactory::CCommandFactory(CConcreteCommandAct *_pAct,string _Pathname): CFactory(_pAct,_Pathname){
	// TODO Auto-generated constructor stub


}

CCommandFactory::~CCommandFactory() {
	// TODO Auto-generated destructor stub
}

void CCommandFactory::CreatCommandList(Json::Value _value){
	// TODO Auto-generated constructor stub
	const Json::Value ComdArray = _value["CMD"];
			 for(unsigned int i=0;i<ComdArray.size();i++){
				 mCmdHandler1->CommandCreatHandler(ComdArray[i]);
			 }
}

