#pragma once
#include<iostream>
using namespace std;
#include<string>

//身分类的抽象
class Identity
{
public:
	//操作菜单的函数
	virtual void operMenu();			//基类虚函数


	string m_Name;
	string m_Pwd;

};