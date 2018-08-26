#include<bits/stdc++.h>

using namespace std ;

/*
һ�����󹤳�ģʽ���ĸ����ֹ���
1�������Ʒ 
1�������Ʒ 
2�����󹤳� 
3�����幤�� 
*/
class breakfast //  �����Ʒ 
{
	public:
		virtual void show() = 0 ;
		virtual ~breakfast() 
		{
			cout << "enjoy your breakfast" << endl ; 
		};
		
};

class ordinary_breakfast: public breakfast // �����Ʒ 
{
	public:
		void show() 
		{
			cout << "milk and egg" << endl ;
		}
};

class luxury_breakfast: public breakfast // �����Ʒ 
{
	public:
		void show() 
		{
			cout << "deep-fried dough sticks and tofu jelly" << endl ;
		}
};

class canteen_base //  ���󹤳� 
{
	public:
		virtual breakfast* creatbreakfast() = 0 ;
};

class luxury_canteen:public canteen_base //  ���幤�� 
{
	public:
		breakfast* creatbreakfast()
		{
			return new luxury_breakfast ;
		} ;
};

class ordinary_canteen:public canteen_base //  ���幤�� 
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
