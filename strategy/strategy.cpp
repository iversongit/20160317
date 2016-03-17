 ///
 /// @file    strategy.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 08:59:33
 ///

#include "strategy.h"
#include <iostream>

using std::cout;
using std::endl;

Context::Context(Strategy * strategy)
:_pStrategy(strategy)
{
	cout<<"Context(Strategy *)"<<endl;
}

Context::~Context(){
	cout<<"~Context()"<<endl;
}

void Context::contextInterface(){
	if(_pStrategy != NULL){
		_pStrategy->algorithmInterface();
	}
}

void ConcreateStrategyA::algorithmInterface(){
	cout<<"ConcreateStrategyA algorithm !"<<endl;
}

void ConcreateStrategyB::algorithmInterface(){
	cout<<"ConcreateStrategyB algorithm !"<<endl;
}
