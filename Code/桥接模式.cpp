#include <iostream>
#include <sstream>
#include <vector>

// 步骤1: 创建实现化接口
class TV {
public:
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual void switchChannel() = 0;
};

// 步骤2: 创建具体实现化类
class SonyTV : public TV {
public:
	void turnOn() override {
		std::cout << "Sony TV is ON" << std::endl;
	}

	void turnOff() override {
		std::cout << "Sony TV is OFF" << std::endl;
	}

	void switchChannel() override {
		std::cout << "Switching Sony TV channel" << std::endl;
	}
};

class TCLTV : public TV {
public:
	void turnOn() override {
		std::cout << "TCL TV is ON" << std::endl;
	}

	void turnOff() override {
		std::cout << "TCL TV is OFF" << std::endl;
	}

	void switchChannel() override {
		std::cout << "Switching TCL TV channel" << std::endl;
	}
};

// 步骤3: 创建抽象化接口
class RemoteControl {
protected:
	TV* tv;

public:
	RemoteControl(TV* tv) : tv(tv) {}

	virtual void performOperation() = 0;
};

// 步骤4: 创建扩充抽象化类
class PowerOperation : public RemoteControl {
public:
	PowerOperation(TV* tv) : RemoteControl(tv) {}

	void performOperation() override {
		tv->turnOn();
	}
};

class OffOperation : public RemoteControl {
public:
	OffOperation(TV* tv) : RemoteControl(tv) {}

	void performOperation() override {
		tv->turnOff();
	}
};

class ChannelSwitchOperation : public RemoteControl {
public:
	ChannelSwitchOperation(TV* tv) : RemoteControl(tv) {}

	void performOperation() override {
		tv->switchChannel();
	}
};

#if 0
// 步骤5: 客户端代码
int main() {
	int N;
	std::cin >> N;
	std::cin.ignore();

	for (int i = 0; i < N; i++) {
		std::string input;
		std::getline(std::cin, input);
		std::istringstream iss(input);

		int brand, operation;
		iss >> brand >> operation;

		TV* tv;
		if (brand == 0) {
			tv = new SonyTV();
		}
		else {
			tv = new TCLTV();
		}

		RemoteControl* remoteControl;
		if (operation == 2) {
			remoteControl = new PowerOperation(tv);
		}
		else if (operation == 3) {
			remoteControl = new OffOperation(tv);
		}
		else {
			remoteControl = new ChannelSwitchOperation(tv);
		}

		remoteControl->performOperation();

		delete tv;
		delete remoteControl;
	}

	return 0;
}
#endif
