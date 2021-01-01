#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globallFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"



//教师菜单
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
			//查看所有预约
			tea->showAllOder();
		}
		else if (select == 2)
		{
			tea->vaildOder();
		}
		else if(select==0)
		{
			cout << "注销成功 " << endl ;
			delete teacher;
			system("pause");
			system("cls");

			return;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
}

//学生菜单
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
		if (select == 1)		//申请预约
		{
			stu->applyOder();

		}
		else if (select == 2)	//查看自身预约
		{
			stu->showMyOder();
		}
		else if (select == 3)
		{
			stu->showAllOder();		//查看所有预约
		}
		else if (select == 4)
		{
			stu->cancelOder();		//取消预约
		}
		else if (select == 0)
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMenu(Identity * manager) {
	while (true)
	{
		//这个是基类指针
		manager->operMenu();

		Manager * man = (Manager*)manager;	//强转成子类指针

		int select = 0;

		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)	//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}



//登录功能		操作文件名称		操作文件类型
void LoginIn(string fileName ,int type){
	//父类指针 用于指向子类对象
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在";
		ifs.close();
		return;
	}
	//准备接受用户信息
//申请局部变量用于存放用户信息：作用域为LoginIn函数内，函数执行完释放
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)	//学生
	{
		cout << "请输入你的学号：";
		cin >> id;

	}
	else if (type == 2)		//老师
	{
		cout << "请输入你的职工号：";
		cin >> id;
	}
	cout << "输入用户名:" << endl;
	cin >> name;

	cout << "输入密码：" << endl;
	cin >> pwd;
	
	
	if (type == 1)
	{//学生身份验证
		int FId;
		string FName;
		string FPwd;
		while (ifs >> FId&&ifs >> FName&&ifs >> FPwd)
		{
			if (id == FId&&name == FName&&pwd == FPwd)
			{
				cout << "学生登录成功"<<endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				
				//进入学生菜单界面
				studentMenu(person);


				return;
			}
		}
	}else if (type == 2)
	{
		//教师身份验证
		int FId;
		string FName;
		string FPwd;
		while (ifs >> FId&&ifs >> FName&&ifs >> FPwd)
		{
			if (id == FId&&name == FName&&pwd == FPwd)
			{
				cout << "教师登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入教师界面
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{//管理员的身份验证
		string FName;
		string FPwd;
		while (ifs >> FName&&ifs >> FPwd)
		{
			if (name == FName&&pwd == FPwd)
			{
				cout << "管理员登录成功" << endl;
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);
				//进入管理员子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败！"<<endl;
	system("pause");
	system("cls");
	return;



}
int main()
{
	int select = 0;
	while (true) {
		cout << "============== 欢迎来到Zzh的机房预约系统 ============="
			<< endl;
		cout << endl << "输入您的身份" << endl;
		cout << "\t\t-----------------------\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|      1.学生代表       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|      2.老    师       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|      3.管 理 员       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|      0.退    出       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t-----------------------\n";
		cout << "输入你的选择：";
		cin >> select;
		switch (select)
		{
		case 1:		//学生身份
			LoginIn("student.txt", 1);
			break;
		case 2:		//老师
			LoginIn("teacher.txt", 2);
			break;
		case 3:		//管理员
			LoginIn("admin.txt", 3);
			break;
		case 0:		//退出
			cout << "欢迎下次使用：";
			system("pause");
			return EXIT_SUCCESS;
		default:
			cout << "输入有误请重新输入：";
			system("pause");
			system("cls");
			break;
		}
	}

}
