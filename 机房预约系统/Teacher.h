#pragma once
#define _CRE_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Identity.h"
#include"OrderFile.h"
#include<vector>
class Teacher :public Identity
{
public :
	//Ĭ�Ϲ���
	Teacher();
	
	//�вι���
	Teacher(int empid,string name,string pwd);

	//�����˵�����
	void operMenu();

	//�鿴����ԤԼ
	void showAllOder();

	//���ԤԼ
	void vaildOder();


	//ְ����
	int m_Empid;			//��ʦ���

};