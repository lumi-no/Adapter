#include <iostream>
#include <string>


class Target {
public:
    virtual void Request() const {
        std::cout << "Target: Виконується стандартний запит." << std::endl;
    }
    virtual ~Target() = default;
};


class Adaptee {
public:
    void SpecificRequest() const {
        std::cout << "Adaptee: Виконується специфічний запит." << std::endl;
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee_; 

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
    void Request() const override {
        std::cout << "Adapter: Перетворення виклику..." << std::endl;
        adaptee_->SpecificRequest(); 
    }
};


void ClientCode(const Target* target) {
    target->Request();
}

int main() {
    std::cout << "Клієнт: Я можу працювати зі стандартними інтерфейсами:" << std::endl;
    Target* target = new Target;
    ClientCode(target);

    std::cout << "\nКлієнт: У мене є клас із специфічним інтерфейсом, який я не можу використовувати:" << std::endl;
    Adaptee* adaptee = new Adaptee;
    std::cout << "Adaptee: ";
    adaptee->SpecificRequest();

    std::cout << "\nКлієнт: Але тепер я можу використовувати його через адаптер:" << std::endl;
    Adapter* adapter = new Adapter(adaptee);
    ClientCode(adapter);

    
    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}
