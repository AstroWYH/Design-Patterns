#pragma once
#include <iostream>

using namespace std;

class LogToDB {
public:
	virtual void InitDB() {
		cout << "LogToDB初始化" << endl;
	}
	virtual void WriteToDB() {
		cout << "LogToDB写入" << endl;
	}
	virtual void ReadFromDB() {
		cout << "LogToDB读取" << endl;
	}
	virtual void CloseDB() {
		cout << "LogToDB关闭" << endl;
	}
};