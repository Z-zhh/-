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
	//Ĭ�Ϲ���
	Student();
	//�вι���  ѧ�� ���� ����
	Student(int id, string name, string pwd);

	//�����˵�����
	void operMenu();


	//����ԤԼ
	void applyOder();

	//�鿴ԤԼ
	void showMyOder();

	//�鿴����ԤԼ
	void showAllOder();
	void cancelOder();
	
	vector<ComputerRoom> vCom;

	int m_id;

};