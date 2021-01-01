#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"ComputerRoom.h"
#include<vector>
#include"OrderFile.h"

class Student:public Identity
{
public:
	//默认构造
	Student();
	//有参构造  学号 姓名 密码
	Student(int id, string name, string pwd);

	//操作菜单界面
	void operMenu();


	//申请预约
	void applyOder();

	//查看预约
	void showMyOder();

	//查看所有预约
	void showAllOder();
	void cancelOder();
	
	vector<ComputerRoom> vCom;

	int m_id;

};