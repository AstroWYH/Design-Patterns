#include <iostream>
#include <memory>
#include "LogToFile.h"
#include "LogToDB.h"
#include "LogAdapter.h"

using namespace std;

int main() {
	shared_ptr<LogToFile> file = make_shared<LogToFile>();
	shared_ptr<LogToDB> db = make_shared<LogAdapter>(file);
	db->InitDB();
	db->ReadFromDB();
	db->WriteToDB();
	db->CloseDB();

	return 0;
}