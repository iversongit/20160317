 ///
 /// @file    factory.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-17 04:15:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Product;

class Factory{
	public:
		Product * create()
		{
			return factoryMethod();
		}

		virtual Product * factoryMethod() = 0;
};

class Product{
	public:
		Product()
		{
			cout<<"Product()"<<endl;
		}

		virtual ~Product()
		{
			cout<<"~Product()"<<endl;
		}
};

class ProductA : public Product{
	public:
		ProductA()
		{
			cout<<"ProductA()"<<endl;
		}

		~ProductA()
		{
			cout<<"~ProductA()"<<endl;
		}
};

class ProductB : public Product{
	public:
		ProductB()
		{
			cout<<"ProductB()"<<endl;
		}

		~ProductB()
		{
			cout<<"~ProductB()"<<endl;
		}
};

class ConcreateFactoryA : public Factory{
	public:
		virtual Product * factoryMethod(){
			return new ProductA;
		}
};

class ConcreateFactoryB : public Factory{
	public:
		virtual Product * factoryMethod(){
			return new ProductB;
		}
};

int main(void){
	Factory * pFactA = new ConcreateFactoryA;
	Product * pProdA = pFactA->create();

	Factory * pFactB = new ConcreateFactoryB;
	Product * pProdB = pFactB->create();

	delete pProdA;
	delete pProdB;
	return 0;
}

