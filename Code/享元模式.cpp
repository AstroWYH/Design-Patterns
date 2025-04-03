#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

enum ShapeType {
    CIRCLE, RECTANGLE, TRIANGLE
};

std::string shapeTypeToString(ShapeType type) {
    switch (type) {
    case CIRCLE:
        return "CIRCLE";
    case RECTANGLE:
        return "RECTANGLE";
    case TRIANGLE:
        return "TRIANGLE";
    default:
        return "UNKNOWN";
    }
}

class Position {
private:
    int x;
    int y;

public:
    Position(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

class Shape {
public:
    virtual void draw(const Position& position) = 0;
    virtual ~Shape() {}
};

class ConcreteShape : public Shape {
private:
    ShapeType shapeType;
    bool isFirstTime;

public:
    ConcreteShape(ShapeType shapeType) : shapeType(shapeType), isFirstTime(true) {}

    void draw(const Position& position) override {
        std::cout << shapeTypeToString(shapeType) << (isFirstTime ? " drawn" : " shared") << " at (" << position.getX() << ", " << position.getY() << ")\n";
    }

    void setFirstTime(bool firstTime) {
        isFirstTime = firstTime;
    }
};

class ShapeFactory {
private:
    std::unordered_map<ShapeType, Shape*> shapes;

public:
    Shape* getShape(ShapeType type) {
        if (shapes.find(type) == shapes.end()) {
            shapes[type] = new ConcreteShape(type);
        }
        return shapes[type];
    }

    ~ShapeFactory() {
        for (const auto& entry : shapes) {
            delete entry.second;
        }
    }
};

void processCommand(ShapeFactory& factory, const std::string& command);

#if 1
int main() {
    ShapeFactory factory;
    std::string command;

    while (std::getline(std::cin, command)) {
        processCommand(factory, command);
    }

    return 0;
}
#endif

void processCommand(ShapeFactory& factory, const std::string& command) {
    std::istringstream iss(command);
    std::string shapeTypeStr;
    int x, y;

    iss >> shapeTypeStr >> x >> y;

    ShapeType type;
    if (shapeTypeStr == "CIRCLE") {
        type = CIRCLE;
    }
    else if (shapeTypeStr == "RECTANGLE") {
        type = RECTANGLE;
    }
    else if (shapeTypeStr == "TRIANGLE") {
        type = TRIANGLE;
    }
    else {
        std::cerr << "Invalid shape type: " << shapeTypeStr << std::endl;
        return;
    }

    Shape* shape = factory.getShape(type);
    shape->draw(Position(x, y));
    dynamic_cast<ConcreteShape*>(shape)->setFirstTime(false);
}