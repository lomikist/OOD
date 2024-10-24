#include <iostream>
#include <string>

class AbstractProductA{
public:
    virtual ~AbstractProductA(){};
    virtual std::string UsefulFunctionalA() const = 0;
};


class ConcretProductA1 : public AbstractProductA {
public:
    std::string UsefulFunctionalA() const override {
        return "The result of the product A1\n";
    }
};

class ConcretProductA2 : public AbstractProductA {
public:
    std::string UsefulFunctionalA() const override {
        return "The result of the product A2\n";
    }
};


class AbstractProductB {
public:
    virtual ~AbstractProductB(){};
    virtual std::string UsefulFunctionalB() const = 0;

   virtual std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0; 
};


class ConcretProductB1 : public AbstractProductB {
public:
    std::string UsefulFunctionalB() const override {
        return "The result of the product B1\n";
    }

    std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionalA();
        return "The result of the B1 collaborator whit ( " + result + " )\n";
    }
};


class ConcretProductB2 : public AbstractProductB {
public:
    std::string UsefulFunctionalB() const override {
        return "The result of the product B2\n";
    }

    std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionalA();
        return "The result of the B2 collaborator whit ( " + result + " )\n";
    }
};


class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() const = 0;
    virtual AbstractProductB* CreateProductB() const = 0;
};

class ConcretFactory1 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override {
        return new ConcretProductA1();
    }

    AbstractProductB* CreateProductB() const override {
        return new ConcretProductB1();
    } 
};


class ConcretFactory2 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override {
        return new ConcretProductA2();
    }

    AbstractProductB* CreateProductB() const override {
        return new ConcretProductB2();
    } 
};


void ClientCode(const AbstractFactory & factory){
    const AbstractProductA* product_a = factory.CreateProductA();
    const AbstractProductB* product_b = factory.CreateProductB();
    std::cout << product_b->UsefulFunctionalB();
    std::cout << product_b->AnotherUsefulFunctionB(*product_a);
    delete product_a;
    delete product_b;
}


int main(){
    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcretFactory1 *f1 = new ConcretFactory1();
    ClientCode(*f1);
    delete f1;
    std::cout << std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    ConcretFactory2 *f2 = new ConcretFactory2();
    ClientCode(*f2);
    delete f2;
    return 0;
}
