#include<bits/stdc++.h>

using namespace std ;

/*
一个抽象工厂模式由四个部分构成
1：抽象产品 
1：具体产品 
2：抽象工厂 
3：具体工厂 
*/
class phone //  抽象产品手机 
{
	public:
		virtual void show() = 0 ;		
};

class computer //  抽象产品电脑
{
	public:
		virtual void show() = 0 ;		
};

class huawei_phone: public phone // 具体产品华为手机 
{
	public:
		void show() 
		{
			cout << "huawei_phone" << endl ;
		}
};

class lenovo_phone: public phone // 具体产品联想手机 
{
	public:
		void show() 
		{
			cout << "lenovo_phone" << endl ;
		}
};

class huawei_computer: public computer // 具体产品华为电脑
{
	public:
		void show() 
		{
			cout << "huawei_computer" << endl ;
		}
};

class lenovo_computer: public computer // 具体产品联想电脑
{
	public:
		void show() 
		{
			cout << "lenovo_computer" << endl ;
		}
};


class foctory //  抽象工厂 
{
	public:
		enum FACTORY_TYPE {
        	HUAWEI,  
        	LENOVO
    	};
		virtual phone* createphone() = 0 ;
		virtual computer* createcomputer() = 0 ;
		static foctory* createfoctory(FACTORY_TYPE type) ;
};

class huawei_foctory:public foctory //  具体工厂 
{
	public:
		phone* createphone() 
		{
			return new huawei_phone ;
		} ;
		computer* createcomputer()
		{
			return new huawei_computer ;
		} ;
};

class lenovo_foctory:public foctory //  具体工厂 
{
	public:
		phone* createphone()
		{
			return new lenovo_phone ;
		} ;
		computer* createcomputer()
		{
			return new lenovo_computer ;
		} ;
};

foctory* foctory::createfoctory(FACTORY_TYPE type) 
		{
			switch( type )
			{
				case HUAWEI : return new huawei_foctory ;
				case LENOVO : return new lenovo_foctory ;
				default : return NULL ;
			}
		};

int main()
{
	foctory* pfoctory = foctory::createfoctory(foctory::HUAWEI) ;
	phone* pphone = pfoctory->createphone();
	computer * pcomputer = pfoctory->createcomputer() ;
	pphone->show() ;
	pcomputer->show() ;
	delete pfoctory ;
	delete pphone ;
	delete pcomputer ;
	pfoctory = foctory::createfoctory(foctory::LENOVO) ;
	pphone = pfoctory->createphone();
	pcomputer = pfoctory->createcomputer() ;
	pphone->show() ;
	pcomputer->show() ;
	delete pfoctory ;
	delete pphone ;
	delete pcomputer ;
	return 0 ;
}
