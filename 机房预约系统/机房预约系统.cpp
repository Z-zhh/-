#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globallFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"



//��ʦ�˵�
void TeacherMenu(Identity * teacher)
{
	while (true)
	{
		int select = 0;
		teacher->operMenu();
		Teacher *tea = (Teacher*)teacher;
		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOder();
		}
		else if (select == 2)
		{
			tea->vaildOder();
		}
		else if(select==0)
		{
			cout << "ע���ɹ� " << endl ;
			delete teacher;
			system("pause");
			system("cls");

			return;
		}
		else {
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
		}
	}
}

//ѧ���˵�
void studentMenu(Identity *student)
{
	while (true)
	{
		int select = 0;
		int id;
		string name;
		string pwd;
		Student *stu = (Student*)student;
		stu->operMenu();
		cin >> select;
		if (select == 1)		//����ԤԼ
		{
			stu->applyOder();

		}
		else if (select == 2)	//�鿴����ԤԼ
		{
			stu->showMyOder();
		}
		else if (select == 3)
		{
			stu->showAllOder();		//�鿴����ԤԼ
		}
		else if (select == 4)
		{
			stu->cancelOder();		//ȡ��ԤԼ
		}
		else if (select == 0)
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
void managerMenu(Identity * manager) {
	while (true)
	{
		//����ǻ���ָ��
		manager->operMenu();

		Manager * man = (Manager*)manager;	//ǿת������ָ��

		int select = 0;

		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)	//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}



//��¼����		�����ļ�����		�����ļ�����
void LoginIn(string fileName ,int type){
	//����ָ�� ����ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������";
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
//����ֲ��������ڴ���û���Ϣ��������ΪLoginIn�����ڣ�����ִ�����ͷ�
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)	//ѧ��
	{
		cout << "���������ѧ�ţ�";
		cin >> id;

	}
	else if (type == 2)		//��ʦ
	{
		cout << "���������ְ���ţ�";
		cin >> id;
	}
	cout << "�����û���:" << endl;
	cin >> name;

	cout << "�������룺" << endl;
	cin >> pwd;
	
	
	if (type == 1)
	{//ѧ�������֤
		int FId;
		string FName;
		string FPwd;
		while (ifs >> FId&&ifs >> FName&&ifs >> FPwd)
		{
			if (id == FId&&name == FName&&pwd == FPwd)
			{
				cout << "ѧ����¼�ɹ�"<<endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				
				//����ѧ���˵�����
				studentMenu(person);


				return;
			}
		}
	}else if (type == 2)
	{
		//��ʦ�����֤
		int FId;
		string FName;
		string FPwd;
		while (ifs >> FId&&ifs >> FName&&ifs >> FPwd)
		{
			if (id == FId&&name == FName&&pwd == FPwd)
			{
				cout << "��ʦ��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//�����ʦ����
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{//����Ա�������֤
		string FName;
		string FPwd;
		while (ifs >> FName&&ifs >> FPwd)
		{
			if (name == FName&&pwd == FPwd)
			{
				cout << "����Ա��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�"<<endl;
	system("pause");
	system("cls");
	return;



}
int main()
{
	int select = 0;
	while (true) {
		cout << "============== ��ӭ����Zzh�Ļ���ԤԼϵͳ ============="
			<< endl;
		cout << endl << "�����������" << endl;
		cout << "\t\t-----------------------\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|      1.ѧ������       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|      2.��    ʦ       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|      3.�� �� Ա       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|      0.��    ��       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t-----------------------\n";
		cout << "�������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:		//ѧ�����
			LoginIn("student.txt", 1);
			break;
		case 2:		//��ʦ
			LoginIn("teacher.txt", 2);
			break;
		case 3:		//����Ա
			LoginIn("admin.txt", 3);
			break;
		case 0:		//�˳�
			cout << "��ӭ�´�ʹ�ã�";
			system("pause");
			return EXIT_SUCCESS;
		default:
			cout << "�����������������룺";
			system("pause");
			system("cls");
			break;
		}
	}

}
