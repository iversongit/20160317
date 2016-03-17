 ///
 /// @file    iterator.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 05:11:54
 ///

#ifndef __ITERATOR_H__
#define __ITERATOR_H__

typedef int Data;
class Iterator;

class Aggregate{
	public:
		virtual Iterator * createIterator()=0;
		virtual ~Aggregate()
		{
		}
		virtual int size() = 0;
		virtual Data getItem(int index) = 0;
};

class Iterator{
	public:
		virtual ~Iterator(){
		}

		virtual void first() = 0;
		virtual void next() = 0;
		virtual bool isDone() = 0;
		virtual Data currentItem()=0;
};

class ConcreateAggregate : public Aggregate{
	public:
		ConcreateAggregate(int size);
		virtual ~ConcreateAggregate();
		virtual Iterator * createIterator();
		virtual int size();
		virtual Data getItem(int index);
	private:
		int _size;
		Data *_pData;

};

class ConcreateIterator : public Iterator{
	public:
		ConcreateIterator(Aggregate *pAggregate);
		virtual ~ConcreateIterator(){
		}
		virtual void first();
		virtual void next();
		virtual bool isDone();
		virtual Data currentItem();

	private:
		int _index;
		Aggregate *_pAggregate;
};

#endif
