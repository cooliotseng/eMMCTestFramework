/*
 * IUpdateStatus.h
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#ifndef IUPDATESTATUS_H_
#define IUPDATESTATUS_H_

#include<iostream>
#include<string>
#include<fstream>
#include "json/json.h"
class IUpdateStatus {
public:
	IUpdateStatus();
	virtual ~IUpdateStatus();
	virtual void Update(Json::Value value) = 0;
};

#endif /* IUPDATESTATUS_H_ */
