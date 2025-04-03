#include <iostream>
#include <vector>
#include <cmath>

// �������Żݲ��Խӿ�
class DiscountStrategy {
public:
    virtual int applyDiscount(int originalPrice) = 0;
    virtual ~DiscountStrategy() = default; // �������������
};

// �����Żݲ���
class DiscountStrategy1 : public DiscountStrategy {
public:
    int applyDiscount(int originalPrice) override {
        return static_cast<int>(std::round(originalPrice * 0.9));
    }
};

// �����Żݲ���
class DiscountStrategy2 : public DiscountStrategy {
private:
    int thresholds[4] = { 100, 150, 200, 300 };
    int discounts[4] = { 5, 15, 25, 40 };

public:
    int applyDiscount(int originalPrice) override {
        for (int i = sizeof(thresholds) / sizeof(thresholds[0]) - 1; i >= 0; i--) {
            if (originalPrice >= thresholds[i]) {
                return originalPrice - discounts[i];
            }
        }
        return originalPrice;
    }
};

// ��������
class DiscountContext {
private:
    DiscountStrategy* discountStrategy;

public:
    void setDiscountStrategy(DiscountStrategy* discountStrategy) {
        this->discountStrategy = discountStrategy;
    }

    int applyDiscount(int originalPrice) {
        return discountStrategy->applyDiscount(originalPrice);
    }
};

#if 0
int main() {
    // ��ȡ��Ҫ�����ŻݵĴ���
    int N;
    std::cin >> N;
    std::cin.ignore(); // ���Ի��з�

    for (int i = 0; i < N; i++) {
        // ��ȡ��Ʒ�۸���Żݲ���
        int M, strategyType;
        std::cin >> M >> strategyType;

        // �����Żݲ���������Ӧ�Ĵ��۲���
        DiscountStrategy* discountStrategy;
        switch (strategyType) {
        case 1:
            discountStrategy = new DiscountStrategy1();
            break;
        case 2:
            discountStrategy = new DiscountStrategy2();
            break;
        default:
            // ����δ֪��������
            std::cout << "Unknown strategy type" << std::endl;
            return 1;
        }

        // ���ô��۲���
        DiscountContext context;
        context.setDiscountStrategy(discountStrategy);

        // Ӧ�ô��۲��Բ�����Żݺ�ļ۸�
        int discountedPrice = context.applyDiscount(M);
        std::cout << discountedPrice << std::endl;

        // �ͷŶ�̬����Ĵ��۲��Զ���
        delete discountStrategy;
    }

    return 0;
}
#endif
