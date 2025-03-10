#include "OrderFile.h"

OderFile::OderFile()
{

	//把文件内容用 map接收

	ifstream ifs;
	ifs.open("order.txt",ios::in);
	
	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;			//预约记录条数


	while (ifs >> date && ifs >> interval&&ifs >> stuId&&ifs >> stuName&&ifs >> roomId&&ifs >> status)
	{
		string key;
		string value;
		map<string, string> m;
		int pos = date.find(":");			//下标
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");			//下标
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");			//下标
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");			//下标
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");			//下标
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");			//下标
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		}

		this->m_OrderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}

	ifs.close();

}

void OderFile::update()
{

	//把map容器的内容重新写进order.txt
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs("order.txt", ios::out | ios::trunc);
	
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"]<<" ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] << endl;
	}

	ofs.close();
}
