#pragma once

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