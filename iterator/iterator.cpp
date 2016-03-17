 ///
 /// @file    iterator.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 05:32:58
 ///
 
#include "iterator.h"
#include <iostream>

using std::cout;
using std::endl;

ConcreateAggregate::ConcreateAggregate(int size)
:_size(size)
,_pData(new int[_size])
{
	cout<<"ConcreateAggregate(int)"<<endl;
	for(int i=0; i<_size; ++i){
		_pData[i] = i;
	}
}

Iterator * ConcreateAggregate::createIterator(){
	return new ConcreateIterator(this);
}

ConcreateAggregate::~ConcreateAggregate(){
	cout<<"~ConcreateAggregate()"<<endl;
	delete[] _pData;
}

int ConcreateAggregate::size(){
	return _size;
}

Data ConcreateAggregate::getItem(int index){
	return _pData[index];
}

ConcreateIterator::ConcreateIterator(Aggregate * pAggregate)
:_index(0)
,_pAggregate(pAggregate)
{
	cout<<"ConcreateIterator()"<<endl;
}

void ConcreateIterator::first(){
	_index = 0;
}

void ConcreateIterator::next(){
	if(_index < _pAggregate->size()){
		++_index;
	}
}

bool ConcreateIterator::isDone(){
	return _index == _pAggregate->size();
}

Data ConcreateIterator::currentItem(){
	return _pAggregate->getItem(_index);
}

