#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include<string>


class OderFile
{
public:
	//���캯��
	OderFile();

	//����ԤԼ��¼
	void update();

	//��¼����KEY ��¼������ value �����¼��ֵ����Ϣ
	map<int, map<string, string>>m_OrderData;		//����һ����ά���飬����ÿ����Ԫ�Ǵ���һ����ֵ�Ե�


	int m_Size;
};