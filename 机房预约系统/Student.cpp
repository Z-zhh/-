#include "Student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open("computerRoom.txt", ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId&&ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

void Student::operMenu()
{
	cout << "欢迎学生代表" << this->m_Name << "登录" << endl;
	cout << "\t\t-----------------------\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      1.申请预约       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      2.查看预约       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      3.查看所有预约   |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      4.取消预约       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      0 .注销登录      |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t-----------------------\n";
	cout << "输入你的选择：";
}

void Student::applyOder()
{
	cout << "机房开放的时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间："<< endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入:" << endl;
	}


	cout << "请输入预约的时间段:" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入:" << endl;
	}

	cout << "请选择机房:" << endl;
	cout << "1号机房容量:" << vCom[0].m_MaxNum << endl;
	cout << "2号机房容量:" << vCom[1].m_MaxNum << endl;
	cout << "3号机房容量:" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 0 && room <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入:" << endl;
	}
	cout << "预约成功！审核中" << endl;

	ofstream ofs("order.txt", ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << " " << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyOder()
{
OderFile of;		//初始化就直接把order.txt文件内容写进map容器

if (of.m_Size == 0)
{
	cout << "无预约记录" << endl;
	system("pause");
	system("cls");
	return;
}
for (int i = 0; i < of.m_Size; i++)
{
	if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_id)		//找到当前登录学生信息于容器中相匹配部分
	{
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
system("pause");
system("cls");
}

void Student::showAllOder()
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

void Student::cancelOder()
{
	OderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或者预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int>v;
	int indext = 1;

	for (int i = 0; i < of.m_Size; i++)
	{
		//筛选出属于自己的
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_id)
		{
			//筛选出审核中或者预约成功的
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
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
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "预约通过";
				}
				cout << status << endl;
			}

		}
	}
	cout << "输入取消的记录,0代表返回:" << endl;
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
				of.m_OrderData[v[select]]["status"] = "0";
				of.update();

				cout << "取消成功" << endl;
				break;
			}
		}
		cout << "输入有误，请重输入" << endl;
	}
	system("pause");
	system("cls"); 
}
