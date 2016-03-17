 ///
 /// @file    test_observer.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 08:27:16
 ///

#include "observer.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void){
	Observer * pOb1 = new ConcreateObserver;
	Observer * pOb2 = new ConcreateObserver;

	Subject * pSub = new ConcreateSubject;
	pSub->attach(pOb1);
	pSub->attach(pOb2);
	pSub->setState(66);
	pSub->notify();

	pSub->detach(pOb1);
	pSub->setState(88);
	pSub->notify();

	delete pOb1;
	delete pOb2;
	delete pSub;

	return 0;
}
