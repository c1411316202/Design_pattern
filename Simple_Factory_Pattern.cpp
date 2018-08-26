#include<bits/stdc++.h>

using namespace std ;

/*
一个简单工厂模式由三个部分构成
1：抽象产品角色 breakfast
2：具体产品角色 ordinary_breakfast luxury_breakfast
3：工厂角色 xidian_canteen
*/
class breakfast
{
	public:
		virtual void show() = 0 ;
		virtual ~breakfast() 
		{
			cout << "enjoy your breakfast" << endl ; 
		};
		
};

class ordinary_breakfast: public breakfast
{
	public:
		void show() 
		{
			cout << "milk and egg" << endl ;
		}
};

class luxury_breakfast: public breakfast
{
	public:
		void show() 
		{
			cout << "deep-fried dough sticks and tofu jelly" << endl ;
		}
};

class xidian_canteen
{
	public:
		enum breakfast_type {
			ordinary ,
			luxury
		};
		breakfast* create_breakfast( breakfast_type type )
		{
			switch(type)
			{
				case breakfast_type::ordinary : return new ordinary_breakfast() ; 
				case breakfast_type::luxury : return new luxury_breakfast() ; 
				default : return NULL ;
			}
		}
};

int main()
{
	xidian_canteen *pcanteen = new xidian_canteen() ;
	breakfast* pbreakfast1 = pcanteen->create_breakfast(xidian_canteen::ordinary) ;
	breakfast* pbreakfast2 = pcanteen->create_breakfast(xidian_canteen::luxury) ;
	pbreakfast1->show() ;
	delete pbreakfast1 ;
	pbreakfast2->show() ;
	delete pbreakfast2 ;
	
	return 0 ;
}
