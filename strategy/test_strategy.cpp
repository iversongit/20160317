 ///
 /// @file    test_strategy.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 09:12:17
 ///

#include "strategy.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void){

	Strategy * strA = new ConcreateStrategyA;
	Strategy * strB = new ConcreateStrategyB;
	Context *conA = new Context(strA);
	Context *conB = new Context(strB);
	conA->contextInterface();
	conB->contextInterface();
	delete strA;
	delete strB;
	delete conA;
	delete conB;
	return 0;
}
