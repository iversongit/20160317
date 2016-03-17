 ///
 /// @file    observer.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 08:02:20
 ///

#include "observer.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

void Subject::attach(Observer * observer){
	cout<<"Subject::attach(Observer*)"<<endl;
	_observerList.push_back(observer);
}

void Subject::detach(Observer * observer){
	cout<<"Subject::detach(Observer*)"<<endl;
	list<Observer*>::iterator it;
	it = std::find(_observerList.begin(),_observerList.end(),observer);
	if(it != _observerList.end()){
		_observerList.erase(it);
	}
}

void Subject::notify(){
	cout<<"notify all observers"<<endl;
	list<Observer*>::iterator it;
	for(it=_observerList.begin(); it !=_observerList.end(); ++it){
		(*it)->update(this);
	}
}

void Subject::setState(State state){
	_state = state;
}

State Subject::getState(){
	return _state;
}

Subject::~Subject(){
	cout<<"~Subject()"<<endl;
	_observerList.clear();
}

void ConcreateSubject::setState(State state){
	_state = state;
}

State ConcreateSubject::getState(){
	return _state;
}

void ConcreateObserver::update(Subject * subject){
	if(subject != NULL){
		_observerState = subject->getState();
	}
	cout<<"the Subject's state is"<<_observerState<<endl;
}
