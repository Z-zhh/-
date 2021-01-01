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
	//默认构造
	Teacher();
	
	//有参构造
	Teacher(int empid,string name,string pwd);

	//操作菜单界面
	void operMenu();

	//查看所有预约
	void showAllOder();

	//审核预约
	void vaildOder();


	//职工号
	int m_Empid;			//教师编号

};