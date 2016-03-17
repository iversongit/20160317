 ///
 /// @file    strategy.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 08:37:37
 ///
#ifndef __STRATEGY_H__
#define __STRATEGY_H__

class Strategy;

class Context{
	public:
		Context(Strategy * strategy);
		~Context();
		void contextInterface();
	private:
		Strategy *_pStrategy;
};

class Strategy{
	public:
		virtual ~Strategy(){}
		virtual void algorithmInterface() = 0;
};

class ConcreateStrategyA : public Strategy{
	public:
		virtual ~ConcreateStrategyA() {}
		virtual void algorithmInterface();
};

class ConcreateStrategyB : public Strategy{
	public:
		virtual ~ConcreateStrategyB() {}
		virtual void algorithmInterface();
};

#endif

