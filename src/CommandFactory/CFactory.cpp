/*
 * CFactory.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#include "./header/CFactory.h"

CFactory::CFactory(CConcreteCommandAct *_pAct,string _Pathname){
	// TODO Auto-generated constructor stub
	pmUpdateStatus = new CUpdateStatus(_Pathname);
	mCmdHandler1 = new CCmdIndexHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler2 = new CTestCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler3 = new CWriteCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler4 = new CReadCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler5 = new CEraseCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler6 = new CGppCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler7 = new CEudaCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler8 = new CResetCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler9 = new CInitializationHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler10 = new CBufferLengthCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler11 = new CDeviceTypeCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler12 = new CSingleFileCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler13 = new CTwoFileCaseHandler(_pAct,this->pmUpdateStatus);
	mCmdHandler14 = new CSingleFileDiskCaseHandler(_pAct,this->pmUpdateStatus);


	mCmdHandler1->setNext(mCmdHandler2);
	mCmdHandler2->setNext(mCmdHandler3);
	mCmdHandler3->setNext(mCmdHandler4);
	mCmdHandler4->setNext(mCmdHandler5);
	mCmdHandler5->setNext(mCmdHandler6);
	mCmdHandler6->setNext(mCmdHandler7);
	mCmdHandler7->setNext(mCmdHandler8);
	mCmdHandler8->setNext(mCmdHandler9);
	mCmdHandler9->setNext(mCmdHandler10);
	mCmdHandler10->setNext(mCmdHandler11);
	mCmdHandler11->setNext(mCmdHandler12);
	mCmdHandler12->setNext(mCmdHandler13);
	mCmdHandler13->setNext(mCmdHandler14);
}

CFactory::~CFactory() {
	// TODO Auto-generated destructor stub
}



