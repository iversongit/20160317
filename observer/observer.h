 ///
 /// @file    observer.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 07:40:34
 ///

#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <list>
using std::list;

typedef int State;

class Observer;

class Subject{
	public:
		Subject(): _state(-1){};
		void attach(Observer *);
		void detach(Observer *);
		void notify();

		virtual State getState();
		virtual void setState(State state);
		virtual ~Subject();

	protected:
		State _state;
		list<Observer *> _observerList;
};

class Observer{
	public:
		Observer(): _observerState(-1){}
		virtual void update(Subject * subject) = 0;
		virtual ~Observer(){}
	protected:
		State _observerState;
};

class ConcreateSubject : public Subject{
	public:
		ConcreateSubject(){};
		virtual void setState(State state);
		virtual State getState();
};

class ConcreateObserver : public Observer{
	public:
		ConcreateObserver(){}
		virtual void update(Subject * subject);
};

#endif
