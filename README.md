# Design-Patterns
常用设计模式知识整理，Head First设计模式（Java）的C++整理实现版----AstroWYH



### 01-Duck

- 在Duck基类里，如果加上Fly行为，则会出现问题，因为不是所有的鸭子都会飞，比如如果RedHeadDuck不会飞的话，则其也具有了Fly行为，这是不对的。而Swim行为则没问题，因为所有的鸭子都会游泳。而Quack和Fly类似。
- 基于上述考虑，如果直接将Fly行为从Duck类中抽出，将其作为接口（interface，C++中用只含纯虚函数的类表示），每个Duck的子类实现（implement）该接口，则代码的复用性很差。比如一共有50种不同鸭子的子类，其中20种子类里写了某种Fly，比如FlyWithWings，另外30种子类里写了另一种Fly，比如FlyNoWay，则相当于重复的代码写了20次+30次。
- 基于上述考虑，将Fly这种行为再进行抽象一层。如FlyBehavior作为接口，提供Fly函数，而FlyWithWings作为一个类实现该接口，其内实现Fly；同理，FlyNoWay作为另一个类实现Fly。并将FlyBehavior接口的引用（C++中用unique_ptr即可）放入Duck父类，如此一来，每个Duck子类只需要在构造时，对从Duck父类继承到的FlyBehavior，进行赋值即可（多态的体现，父类指针/引用指向子类对象）。这样，20次+30次的重复代码就没有了，代码复用性提高。
- 系统设计时，总会有不变+会变的两部分，需将不变+会变拆分。
- 针对接口编程，而不是针对实现编程。

