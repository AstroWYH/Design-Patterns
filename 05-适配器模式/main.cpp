#include <iostream>
#include <memory>
#include "LogToFile.h"
#include "LogToDB.h"
#include "LogAdapter.h"

using namespace std;

int main() {
	shared_ptr<LogToFile> file = make_shared<LogToFile>();
	shared_ptr<LogAdapter> adapter = make_shared<LogAdapter>(file);
	adapter->InitDB();
	adapter->ReadFromDB();
	adapter->WriteToDB();
	adapter->CloseDB();

	return 0;
}