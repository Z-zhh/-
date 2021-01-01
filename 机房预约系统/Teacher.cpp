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
	cout << "��ӭ��ʦ" << this->m_Name << "��¼" << endl;
	cout << "\t\t-----------------------\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      1.�鿴����ԤԼ   |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      2.���ԤԼ       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      0 .ע����¼      |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t-----------------------\n";
	cout << "�������ѡ��";
}

void Teacher::showAllOder()
{
	OderFile of;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
		cout << "ʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
		cout << "������" << of.m_OrderData[i]["roomId"];
		string status = "״̬��";			//0ȡ��ԤԼ 1����� 2��ԤԼ -1ԤԼʧ��
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
}

void Teacher::vaildOder()
{
	OderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "�������ص�ԤԼ" << endl;

	vector<int>v;
	int indext = 1;

	for (int i = 0; i < of.m_Size; i++)
	{
		
			//ɸѡ������л���ԤԼ�ɹ���
			if (of.m_OrderData[i]["status"] == "1" )
			{
				v.push_back(i);
				cout << indext++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
				cout << "ԤԼʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << "�������:" << of.m_OrderData[i]["roomId"];

				string status = "״̬��";
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "�����";

				}
				cout << status << endl;
			}

		}
	
	cout << "������˵ļ�¼,0������:" << endl;
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

				cout << "���ͨ��" << endl;
				break;
			}
		}
		cout << "����������������" << endl;
	}
	system("pause");
	system("cls");
	
}

