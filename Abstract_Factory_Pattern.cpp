#include<bits/stdc++.h>

using namespace std ;

/*
һ�����󹤳�ģʽ���ĸ����ֹ���
1�������Ʒ 
1�������Ʒ 
2�����󹤳� 
3�����幤�� 
*/
class phone //  �����Ʒ�ֻ� 
{
	public:
		virtual void show() = 0 ;		
};

class computer //  �����Ʒ����
{
	public:
		virtual void show() = 0 ;		
};

class huawei_phone: public phone // �����Ʒ��Ϊ�ֻ� 
{
	public:
		void show() 
		{
			cout << "huawei_phone" << endl ;
		}
};

class lenovo_phone: public phone // �����Ʒ�����ֻ� 
{
	public:
		void show() 
		{
			cout << "lenovo_phone" << endl ;
		}
};

class huawei_computer: public computer // �����Ʒ��Ϊ����
{
	public:
		void show() 
		{
			cout << "huawei_computer" << endl ;
		}
};

class lenovo_computer: public computer // �����Ʒ�������
{
	public:
		void show() 
		{
			cout << "lenovo_computer" << endl ;
		}
};


class foctory //  ���󹤳� 
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

class huawei_foctory:public foctory //  ���幤�� 
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

class lenovo_foctory:public foctory //  ���幤�� 
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
