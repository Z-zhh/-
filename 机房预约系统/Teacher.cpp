#include "Teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_Empid = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;


}

void Teacher::operMenu()
{
	cout << "欢迎教师" << this->m_Name << "登录" << endl;
	cout << "\t\t-----------------------\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      1.查看所有预约   |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      2.审核预约       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      0 .注销登录      |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t-----------------------\n";
	cout << "输入你的选择：";
}

void Teacher::showAllOder()
{
	OderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_OrderData[i]["date"];
		cout << "时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "机房：" << of.m_OrderData[i]["roomId"];
		string status = "状态：";			//0取消预约 1审核中 2已预约 -1预约失败
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
}

void Teacher::vaildOder()
{
	OderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请审核相关的预约" << endl;

	vector<int>v;
	int indext = 1;

	for (int i = 0; i < of.m_Size; i++)
	{
		
			//筛选出审核中或者预约成功的
			if (of.m_OrderData[i]["status"] == "1" )
			{
				v.push_back(i);
				cout << indext++ << "、";
				cout << "预约日期：周" << of.m_OrderData[i]["date"];
				cout << "预约时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房编号:" << of.m_OrderData[i]["roomId"];

				string status = "状态：";
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "审核中";

				}
				cout << status << endl;
			}

		}
	
	cout << "输入审核的记录,0代表返回:" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 || select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_OrderData[v[select-1]]["status"] = "2";
				of.update();

				cout << "审核通过" << endl;
				break;
			}
		}
		cout << "输入有误，请重输入" << endl;
	}
	system("pause");
	system("cls");
	
}

