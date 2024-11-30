#include <iostream>
#include <string>


class Target {
public:
    virtual void Request() const {
        std::cout << "Target: ���������� ����������� �����." << std::endl;
    }
    virtual ~Target() = default;
};


class Adaptee {
public:
    void SpecificRequest() const {
        std::cout << "Adaptee: ���������� ����������� �����." << std::endl;
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee_; 

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
    void Request() const override {
        std::cout << "Adapter: ������������ �������..." << std::endl;
        adaptee_->SpecificRequest(); 
    }
};


void ClientCode(const Target* target) {
    target->Request();
}

int main() {
    std::cout << "�볺��: � ���� ��������� � ������������ ������������:" << std::endl;
    Target* target = new Target;
    ClientCode(target);

    std::cout << "\n�볺��: � ���� � ���� �� ����������� �����������, ���� � �� ���� ���������������:" << std::endl;
    Adaptee* adaptee = new Adaptee;
    std::cout << "Adaptee: ";
    adaptee->SpecificRequest();

    std::cout << "\n�볺��: ��� ����� � ���� ��������������� ���� ����� �������:" << std::endl;
    Adapter* adapter = new Adapter(adaptee);
    ClientCode(adapter);

    
    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}
