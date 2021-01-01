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

	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);
	
	//ѡ��˵�
	void operMenu();


	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();
	
	//�鿴������Ϣ
	void showComputer();
	
	//���ԤԼ��¼
	void cleanFile();

	//��ʼ����Ա����
	void initvector();

	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;
	//��������
	vector<ComputerRoom> vCom;
	//��ʼ����������
	void innitComVector();
	//����ظ�
	bool checkRepeat(int id ,int type);
};