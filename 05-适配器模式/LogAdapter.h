#pragma once
#include <iostream>
#include "LogToFile.h"
#include <memory>
#include "LogToDB.h"

using namespace std;

class LogAdapter : public LogToDB {
public:
	LogAdapter(shared_ptr<LogToFile> file) {
		file_ = file;
	}

	virtual void InitDB() {
		cout << "在LogAdapter中初始化" << endl;
		file_->InitFile();
	}

	virtual void WriteToDB() {
		cout << "在LogAdapter中写入" << endl;
		file_->InitFile();
	}

	virtual void ReadFromDB() {
		cout << "在LogAdapter中读取" << endl;
		file_->InitFile();
	}

	virtual void CloseDB() {
		cout << "在LogAdapter中关闭" << endl;
		file_->InitFile();
	}

private:
	shared_ptr<LogToFile> file_ = nullptr;
};