#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"

class Manager :public Identity
{
public:

	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);
	
	//选择菜单
	void operMenu();


	//添加账号
	void addPerson();

	//查看账号
	void showPerson();
	
	//查看机房信息
	void showComputer();
	
	//清空预约记录
	void cleanFile();

	//初始化人员容器
	void initvector();

	//学生容器
	vector<Student>vStu;
	//教师容器
	vector<Teacher>vTea;
	//机房容器
	vector<ComputerRoom> vCom;
	//初始化机房容器
	void innitComVector();
	//检测重复
	bool checkRepeat(int id ,int type);
};