#include <iostream>
#include <vector>
#include <sstream>

class Component {
public:
    virtual void display(int depth) = 0;
};

class Department : public Component {
private:
    std::string name;
    std::vector<Component*> children;

public:
    Department(const std::string& name) : name(name) {}

    void add(Component* component) {
        children.push_back(component);
    }

    void display(int depth) override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << name << std::endl;
        for (Component* component : children) {
            component->display(depth + 1);
        }
    }
};

class Employee : public Component {
private:
    std::string name;

public:
    Employee(const std::string& name) : name(name) {}

    void display(int depth) override {
        std::string indent((depth + 1) * 2, ' ');
        std::cout << indent << name << std::endl;
    }
};

class Company {
private:
    std::string name;
    Department* root;

public:
    Company(const std::string& name) : name(name), root(new Department(name)) {}

    void add(Component* component) {
        root->add(component);
    }

    void display() {
        std::cout << "Company Structure:" << std::endl;
        root->display(0);
    }
};

#if 0
int main() {
    std::string companyName;
    std::getline(std::cin, companyName);

    Company company(companyName);

    int n;
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string type, name;
        std::cin >> type;
        std::getline(std::cin >> std::ws, name);

        if (type == "D") {
            Department* department = new Department(name);
            company.add(department);
        }
        else if (type == "E") {
            Employee* employee = new Employee(name);
            company.add(employee);
        }
    }

    company.display();

    return 0;
}
#endif
