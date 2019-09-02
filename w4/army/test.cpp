#include <iostream>
#include <map>

class A {
    public:
        A() {};
        ~A() {};
};

class B : public A {
    public:
        B() {};
        ~B() {};
};

int main() {
    // std::map<std::string, B*> slaveList;

    // slaveList["Zalupa"] = new B();
    // slaveList["Pipison"] = new B();
    // slaveList["Auppy"] = new B();

    // // std::map<std::string,B*>

    // for (std::map<std::string, B*>::iterator it = slaveList.begin(); it != slaveList.end(); it++ ) {
    //     std::cout << it->first << std::endl;
    // }


    // std::cout << slaveList.size() << std::endl;

    B* b = new A();

    return 0;
}