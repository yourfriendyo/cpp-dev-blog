#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	friend ostream& operator<<(ostream& os, Date& d);
	friend istream& operator>>(istream& is, Date& d);
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& os, Date& d) 
{
	os << d._year << "/" << d._month << "/" << d._day;
	return os;
}
istream& operator>>(istream& is, Date& d) 
{
	is >> d._year >> d._month >> d._day;
	return is;
}
struct ServerInfo 
{
	char _ip[32];
	int _port;

	friend ostream& operator<<(ostream& os, ServerInfo& info);
	friend ostream& operator>>(ostream& os, ServerInfo& info);
};
ostream& operator<<(ostream& os, ServerInfo& info) {
	os << info._ip << " " << info._port;
	return os;
}
istream& operator>>(istream& is, ServerInfo& info) {
	is >> info._ip >> info._port;
	return is;
}
void TestC_Write_Bin() 
{
	ServerInfo info = { "192.168.1.1",80 };
	FILE* fout = fopen("info.bin", "wb");
	if (fout == nullptr) {
		exit(-1);
	}
	fwrite(&info, sizeof(ServerInfo), 1, fout);
	fclose(fout);
}
void TestC_Read_Bin() 
{
	ServerInfo info;
	FILE* fin = fopen("info.bin", "rb");
	if (fin == nullptr) {
		exit(-1);
	}
	fread(&info, sizeof(ServerInfo), 1, fin);
	cout << info << endl;
	fclose(fin);
}
void TestC_Write_Text() 
{
	ServerInfo info = { "192.168.1.1",80 };
	FILE* fout = fopen("info.txt", "w");
	if (fout == nullptr) {
		exit(-1);
	}
	fprintf(fout, "%s %d", info._ip, info._port);
	fclose(fout);
}
void TestC_Read_Text()
{
	ServerInfo info;
	FILE* fin = fopen("info.txt", "r");
	if (fin == nullptr) {
		exit(-1);
	}
	fscanf(fin, "%s %d", &info._ip, &info._port);
	cout << info << endl;
}

class ConfigManage
{
public:
	ConfigManage(const char* fileName)
		:_fileName(fileName)
	{}
	void WriteBin(ServerInfo& info, Date& d)
	{
		ofstream ofs(_fileName.c_str(),ios_base::out | ios_base::binary);
		//ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs << info << "\n" << d;
	}
	void ReadBin(ServerInfo& info, Date& d)
	{
		ifstream ifs(_fileName.c_str(), ios_base::in | ios_base::binary);
		//ifs.read((char*)&info, sizeof(ServerInfo));
		ifs >> info >> d;
		cout << info << "\n" << d << endl;
	}
	void WriteText(ServerInfo& info, Date& d)
	{
		//ofstream ofs(_fileName.c_str(), ios_base::out);
		ofstream ofs(_fileName.c_str());
		//ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs << info << "\n" << d;
	}
	void ReadText(ServerInfo& info, Date& d)
	{
		//ifstream ifs(_fileName.c_str(), ios_base::in);
		ifstream ifs(_fileName.c_str());
		//ifs.read((char*)&info, sizeof(ServerInfo));
		ifs >> info >> d;
		cout << info << "\n" <<  d << endl;
	}
private:
	string _fileName;
};

void TestCPP_Write_Bin() 
{
	ServerInfo info = { "192.168.1.1",80 };
	Date d(2022, 4, 7);
	ConfigManage con("config.bin");
	con.WriteBin(info,d);
}
void TestCPP_Read_Bin()
{
	ServerInfo info;
	Date d;
	ConfigManage con("config.bin");
	con.ReadBin(info,d);
}
void TestCPP_Write_Text()
{
	ServerInfo info = { "192.168.1.1",80 };
	Date d(2022, 4, 7);
	ConfigManage con("config.bin");
	con.WriteText(info, d);
}
void TestCPP_Read_Text()
{
	ServerInfo info;
	Date d;
	ConfigManage con("config.bin");
	con.ReadText(info,d);
}

struct PersonInfo 
{
	string _name;
	int _age;
	friend ostream& operator<<(ostream& os, PersonInfo& info);
	friend istream& operator>>(istream& is, PersonInfo& info);
};
ostream& operator<<(ostream& os, PersonInfo& info) 
{
	os << info._name << " " << info._age;
	return os;
}
istream& operator>>(istream& is, PersonInfo& info)
{
	is >> info._name >> info._age;
	return is;
}
void Test_String_Stream() 
{
	PersonInfo info1 = { string("zhangsan"), 20 };
	ostringstream oss;
	//oss << info1._name << " " << info1._age; //对象未重载<<
	oss << info1;
	string str = oss.str();
	cout << str << endl;

	PersonInfo info2;
	istringstream iss(str);
	iss.str(str);
	//iss >> info2._name >> info2._age; //对象未重载>>
	iss >> info2;
	cout << info2 << endl;
}
int main()
{
	
	//TestC_Write_Bin();
	//TestC_Read_Bin();

	//TestC_Write_Text();
	//TestC_Read_Text();

	//cout << ios_base::in << endl;
	//cout << ios_base::out << endl;
	//cout << ios_base::binary << endl;

	//TestCPP_Write_Bin();
	//TestCPP_Read_Bin();
	//TestCPP_Write_Text();
	//TestCPP_Read_Text();
	
	Test_String_Stream();

	return 0;
}