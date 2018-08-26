#include<bits/stdc++.h>

using namespace std ;

/*
一个抽象工厂模式由四个部分构成
1：抽象产品 
1：具体产品 
2：抽象工厂 
3：具体工厂 
*/
class breakfast //  抽象产品 
{
	public:
		virtual void show() = 0 ;
		virtual ~breakfast() 
		{
			cout << "enjoy your breakfast" << endl ; 
		};
		
};

class ordinary_breakfast: public breakfast // 具体产品 
{
	public:
		void show() 
		{
			cout << "milk and egg" << endl ;
		}
};

class luxury_breakfast: public breakfast // 具体产品 
{
	public:
		void show() 
		{
			cout << "deep-fried dough sticks and tofu jelly" << endl ;
		}
};

class canteen_base //  抽象工厂 
{
	public:
		virtual breakfast* creatbreakfast() = 0 ;
};

class luxury_canteen:public canteen_base //  具体工厂 
{
	public:
		breakfast* creatbreakfast()
		{
			return new luxury_breakfast ;
		} ;
};

class ordinary_canteen:public canteen_base //  具体工厂 
{
	public:
		breakfast* creatbreakfast()
		{
			return new ordinary_breakfast ;
		} ;
};

int main()
{
	canteen_base* xidian_canteen = new ordinary_canteen ;
	breakfast* my_breakfast = xidian_canteen->creatbreakfast() ;
	my_breakfast->show() ;
	delete xidian_canteen ;
	delete my_breakfast ;
	xidian_canteen = new luxury_canteen ;
	my_breakfast = xidian_canteen->creatbreakfast() ;
	my_breakfast->show() ;
	delete xidian_canteen ;
	delete my_breakfast ;
	return 0 ;
}
