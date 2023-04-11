代理模式（Proxy Pattern）的使用场景包括：

1. 远程代理（Remote Proxy）：隐藏对象存在于不同的地址空间的事实，使得客户端可以像访问本地对象一样访问远程对象。
2. 虚拟代理（Virtual Proxy）：通过使用一个代理对象作为另一个对象的代表，可以延迟对象的初始化或计算，以达到提高性能的目的。
3. 安全代理（Protection Proxy）：控制真实对象的访问权限，以保护真实对象不被恶意用户访问或者误操作。
4. 智能指针（Smart Reference）：当一个对象被引用时，同时提供一些额外的操作，例如统计对象被引用的次数，或者当最后一个引用消失时自动删除该对象。

代理模式的优势包括：

1. **隐藏了对象的实现细节**，可以让**客户端更加方便地访问对象**，同时也使得对象更加易于维护和扩展。
2. 可以提高程序的性能，特别是在访问远程对象或者代价昂贵的对象时，可以通过使用虚拟代理和智能指针等技术来实现延迟加载和对象缓存，从而提高程序的运行效率。
3. 可以**提高程序的安全性**，特别是在控制对敏感对象的访问权限时，可以通过使用安全代理来实现授权和身份验证等功能。

```cpp
#include <iostream>
#include <string>

// 定义接口类
class Subject {
public:
    virtual ~Subject() {}
    virtual void request() = 0;
};

// 实现类
class RealSubject : public Subject {
public:
    void request() {
        std::cout << "RealSubject::request()" << std::endl;
    }
};

// 代理类
class Proxy : public Subject {
public:
    Proxy() : m_real_subject(nullptr) {}
    ~Proxy() {
        if (m_real_subject != nullptr) {
            delete m_real_subject;
        }
    }
    void request() {
        if (m_real_subject == nullptr) {
            m_real_subject = new RealSubject();
        }
        std::cout << "Proxy::request()" << std::endl;
        m_real_subject->request();
    }

private:
    RealSubject* m_real_subject; // 指向实际的对象
};

// 客户端调用
int main() {
    Proxy proxy;
    proxy.request();
    return 0;
}
```

这个示例代码中，`Subject`是接口类，`RealSubject`是实现类，`Proxy`是代理类，`RealSubject`实现了`Subject`接口，而`Proxy`继承了`Subject`接口，并包含了一个指向`RealSubject`实例的指针，通过实现`Subject`接口中的`request()`函数来间接调用`RealSubject`的`request()`函数。

当客户端调用`Proxy`的`request()`函数时，`Proxy`会先检查它内部的`m_real_subject`指针是否为空，如果为空，则创建一个`RealSubject`实例并保存到`m_real_subject`指针中，然后输出一条信息表示调用了代理类的`request()`函数，最后再调用`RealSubject`的`request()`函数。这样就实现了代理模式中的代理功能，隐藏了实现部分的细节，使得客户端可以更加方便地访问对象。