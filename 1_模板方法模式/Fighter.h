#pragma once 
// 注意，不加的话，全局变量、函数声明不会冲突（虽然这没加）。
// 但类Fighter会冲突，因为这虽然是类的声明，但也有点定义的意思在。

class Fighter {
public:
    Fighter() {}
    Fighter(int life, int magic, int attack):life_(life), magic_(magic), attack_(attack) {}
    virtual ~Fighter() {}

    // 通用技能：燃烧。
    void Burn();

protected:
    int life_ = 500;
    int magic_ = 300;
    int attack_ = 90;

private:
    virtual void EffectEnemy();
    virtual void EffectSelf();
    void Show();
};