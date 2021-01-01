#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include<string>


class OderFile
{
public:
	//构造函数
	OderFile();

	//更新预约记录
	void update();

	//记录容器KEY 记录的条数 value 具体记录键值对信息
	map<int, map<string, string>>m_OrderData;		//类似一个二维数组，但是每个单元是储存一个键值对的


	int m_Size;
};