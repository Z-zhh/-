#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<fstream>
//机房类
class ComputerRoom
{
public:
	int m_ComId;		//机房id

	int m_MaxNum;		//最大容量
	
	ComputerRoom();
	
	
	
	vector<ComputerRoom> vCom;
	
};