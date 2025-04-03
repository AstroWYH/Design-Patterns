#include <iostream>
#include <vector>
#include <algorithm> 

// 观察者接口
class Observer {
public:
    virtual void update(int hour) = 0;
    virtual ~Observer() = default; // 添加虚析构函数
};

// 主题接口
class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default; // 添加虚析构函数
};

// 具体主题实现
class Clock : public Subject {
private:
    std::vector<Observer*> observers;
    int hour;

public:
    Clock() : hour(0) {}

    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(hour);
        }
    }

    // 添加获取观察者的函数
    const std::vector<Observer*>& getObservers() const {
        return observers;
    }

    void tick() {
        hour = (hour + 1) % 24; // 模拟时间的推移
        notifyObservers();
    }
};

// 具体观察者实现
class Student : public Observer {
private:
    std::string name;

public:
    Student(const std::string& name) : name(name) {}

    void update(int hour) override {
        std::cout << name << " " << hour << std::endl;
    }
};

#if 0
int main() {
    // 读取学生数量
    int N;
    std::cin >> N;

    // 创建时钟
    Clock clock;

    // 注册学生观察者
    for (int i = 0; i < N; i++) {
        std::string studentName;
        std::cin >> studentName;
        clock.registerObserver(new Student(studentName));
    }

    // 读取时钟更新次数
    int updates;
    std::cin >> updates;

    // 模拟时钟每隔一个小时更新一次
    for (int i = 0; i < updates; i++) {
        clock.tick();
    }

    // 释放动态分配的观察者对象
    for (Observer* observer : clock.getObservers()) {
        delete observer;
    }

    return 0;
}
#endif
