 ///
 /// @file    test_iterator.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 07:13:39
 ///

#include "iterator.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void){
	Aggregate * pAggregate = new ConcreateAggregate(5);
	Iterator *pit = pAggregate->createIterator();

	for(; false==pit->isDone(); pit->next())
	{
		cout<<pit->currentItem()<<endl;
	}
	return 0;
}
