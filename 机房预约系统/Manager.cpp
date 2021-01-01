#include "Manager.h"


//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//����ԱҪ�õ���Щ���ݣ����԰���Щ���ݴ��ļ��ж�������Ȼ����������
	//��ʼ����Ա����
	this->initvector();
	//��ʼ����������
	this->innitComVector();

}

//�����˵�

void Manager::operMenu()
{
	cout << "��ӭ����Ա" << this->m_Name << "��¼" << endl;
	cout << "\t\t-----------------------\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      1.����˺�       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      2.�鿴�˺�       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      3.�鿴����       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      4.���ԤԼ       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      0 .ע����¼       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t-----------------------\n";
	cout << "�������ѡ��";
}

//�����Ա
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = "student.txt";
		tip = "���������ѧ��:";
	
	}
	else if(select==2)
	{
		fileName = "teacher.txt";
		tip = "���������ְ����";
	}
	else {
		cout << "��������" << endl;
		return;
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;
	cout << "������������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	if(!this->checkRepeat(id,select))
	{
		ofs << id << " " << name << " " << pwd << endl;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");

		ofs.close();
	}
	else {
		cout << "�ظ����" << endl;
		return;
	}

}


//�鿴��Ա
void Manager::showPerson()
{
	cout << "������鿴�˺ŵ�����" << endl;
	cout << "1.�鿴ѧ��" << endl;
	cout << "2.�鿴��ʦ" << endl;

	string Fname;
	string fileName;
//	ifstream ifs;
	
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "ѧ����Ϣ��" << endl;
		//fileName = "student.txt";
		this->initvector();
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			cout << "ѧ�ţ�"<<it->m_id <<" "<<"������"<< it->m_Name <<" "<<"���룺"<< it->m_Pwd << endl;
		}
		system("pause");
		system("cls");
	}
	else if(select==2){
		cout << "��ʦ��Ϣ" << endl;
	//	fileName = "teacher.txt";
		this->initvector();
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			cout <<"ְ����ţ�"<< it->m_Empid << " " <<"������"<< it->m_Name << " " <<"���룺"<< it->m_Pwd << endl;
		}
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "��������,����������" << endl;
		return;
	}
//	ifs.open(fileName, ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "���ļ�ʧ��" << endl;
//		system("pause");
//		system("cls");
//		return;
//	}
	
}

//�鿴����
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin() ; it!=vCom.end(); it++)
	{
		cout << "������:" << it->m_ComId << "����������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Manager::cleanFile()
{
	ofstream ofs("oder.txt",ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");

}

void Manager::initvector()
{
	//��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open("student.txt", ios::in);		//���ļ�
	if (!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
		return;
	}
	vTea.clear();
	vStu.clear();
	Student s;
	//���ļ�
	while (ifs >> s.m_id&&ifs >> s.m_Name&&ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open("teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
		return;
	}
	Teacher t;
	//����ʦ�ļ�
	while (ifs>>t.m_Empid&&ifs>>t.m_Name&&ifs>>t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ��" << vTea.size()<<endl;
	ifs.close();
}


void Manager::innitComVector()
{
	ComputerRoom c;
	ifstream ifs;
	ifs.open("computerRoom.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʧ�ܣ��Ҳ������ļ�" << endl;
		return;
	}
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ:" << vCom.size() << endl;
	ifs.close();

}

bool Manager::checkRepeat(int id, int type)
{
	this->initvector();
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		

		}

	}else if(type == 2)
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_Empid)
			{
				return true;
			}
		
		}
	}
	return false;

}
