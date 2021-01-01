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
	cout << "��ӭѧ������" << this->m_Name << "��¼" << endl;
	cout << "\t\t-----------------------\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      1.����ԤԼ       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      2.�鿴ԤԼ       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      3.�鿴����ԤԼ   |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      4.ȡ��ԤԼ       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      0 .ע����¼      |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t-----------------------\n";
	cout << "�������ѡ��";
}

void Student::applyOder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺"<< endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

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
		cout << "������������������:" << endl;
	}


	cout << "������ԤԼ��ʱ���:" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������:" << endl;
	}

	cout << "��ѡ�����:" << endl;
	cout << "1�Ż�������:" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż�������:" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż�������:" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 0 && room <= 2)
		{
			break;
		}
		cout << "������������������:" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

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
OderFile of;		//��ʼ����ֱ�Ӱ�order.txt�ļ�����д��map����

if (of.m_Size == 0)
{
	cout << "��ԤԼ��¼" << endl;
	system("pause");
	system("cls");
	return;
}
for (int i = 0; i < of.m_Size; i++)
{
	if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_id)		//�ҵ���ǰ��¼ѧ����Ϣ����������ƥ�䲿��
	{
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
system("pause");
system("cls");
}

void Student::showAllOder()
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

void Student::cancelOder()
{
	OderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;
	int indext = 1;

	for (int i = 0; i < of.m_Size; i++)
	{
		//ɸѡ�������Լ���
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_id)
		{
			//ɸѡ������л���ԤԼ�ɹ���
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
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
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "ԤԼͨ��";
				}
				cout << status << endl;
			}

		}
	}
	cout << "����ȡ���ļ�¼,0������:" << endl;
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

				cout << "ȡ���ɹ�" << endl;
				break;
			}
		}
		cout << "����������������" << endl;
	}
	system("pause");
	system("cls"); 
}
