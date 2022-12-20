#pragma once
#include <iostream>

using namespace std;

class LogToFile {
public:
	void InitFile() {
		cout << "LogToFile初始化" << endl;
	}

	void WriteToFile() {
		cout<< "LogToFile写入" << endl;
	}

	void ReadFromFile() {
		cout << "LogToFile读取" << endl;
	}

	void CloseFile() {
		cout << "LogToFile关闭" << endl;
	}
};
