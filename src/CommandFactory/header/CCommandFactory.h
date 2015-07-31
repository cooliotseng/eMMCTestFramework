/*
 * CCommandFactory.h
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#ifndef CCOMMANDFACTORY_H_
#define CCOMMANDFACTORY_H_

#include "CFactory.h"

class CCommandFactory: public CFactory {
public:
	CCommandFactory(CConcreteCommandAct *_pAct,string _Pathname);
	virtual ~CCommandFactory();
	void CreatCommandList(Json::Value _value);
};

#endif /* CCOMMANDFACTORY_H_ */
