#include "Manager.h"


//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//管理员要用到这些数据，所以把这些数据从文件中读出来，然后存进容器中
	//初始化人员容器
	this->initvector();
	//初始化机房容器
	this->innitComVector();

}

//操作菜单

void Manager::operMenu()
{
	cout << "欢迎管理员" << this->m_Name << "登录" << endl;
	cout << "\t\t-----------------------\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      1.添加账号       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      2.查看账号       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      3.查看机房       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      4.清空预约       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t|      0 .注销登录       |\n";
	cout << "\t\t|                       |\n";
	cout << "\t\t-----------------------\n";
	cout << "输入你的选择：";
}

//添加人员
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = "student.txt";
		tip = "请输入你的学号:";
	
	}
	else if(select==2)
	{
		fileName = "teacher.txt";
		tip = "请输入你的职工号";
	}
	else {
		cout << "操作错误：" << endl;
		return;
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	if(!this->checkRepeat(id,select))
	{
		ofs << id << " " << name << " " << pwd << endl;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");

		ofs.close();
	}
	else {
		cout << "重复添加" << endl;
		return;
	}

}


//查看人员
void Manager::showPerson()
{
	cout << "请输入查看账号的类型" << endl;
	cout << "1.查看学生" << endl;
	cout << "2.查看老师" << endl;

	string Fname;
	string fileName;
//	ifstream ifs;
	
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "学生信息：" << endl;
		//fileName = "student.txt";
		this->initvector();
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			cout << "学号："<<it->m_id <<" "<<"姓名："<< it->m_Name <<" "<<"密码："<< it->m_Pwd << endl;
		}
		system("pause");
		system("cls");
	}
	else if(select==2){
		cout << "教师信息" << endl;
	//	fileName = "teacher.txt";
		this->initvector();
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			cout <<"职工编号："<< it->m_Empid << " " <<"姓名："<< it->m_Name << " " <<"密码："<< it->m_Pwd << endl;
		}
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "输入有误,请重新输入" << endl;
		return;
	}
//	ifs.open(fileName, ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "打开文件失败" << endl;
//		system("pause");
//		system("cls");
//		return;
//	}
	
}

//查看机房
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin() ; it!=vCom.end(); it++)
	{
		cout << "机房号:" << it->m_ComId << "机房容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约
void Manager::cleanFile()
{
	ofstream ofs("oder.txt",ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");

}

void Manager::initvector()
{
	//读取学生文件中的信息
	ifstream ifs;
	ifs.open("student.txt", ios::in);		//打开文件
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}
	vTea.clear();
	vStu.clear();
	Student s;
	//读文件
	while (ifs >> s.m_id&&ifs >> s.m_Name&&ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生的数量为：" << vStu.size() << endl;
	ifs.close();

	//读取老师信息
	ifs.open("teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}
	Teacher t;
	//读老师文件
	while (ifs>>t.m_Empid&&ifs>>t.m_Name&&ifs>>t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师的数量为：" << vTea.size()<<endl;
	ifs.close();
}


void Manager::innitComVector()
{
	ComputerRoom c;
	ifstream ifs;
	ifs.open("computerRoom.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败，找不到此文件" << endl;
		return;
	}
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房容量为:" << vCom.size() << endl;
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
