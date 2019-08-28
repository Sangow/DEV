#include <iostream>c++
#include <map>

int main() {
    std::map<std::string, int> container;

    container.insert(std::pair<std::string, int>("koko", 10));
    container.insert(std::pair<std::string, int>("kiki", 20));
    container.insert(std::pair<std::string, int>("kookoo", 100));

    std::cout << container["zhopa"] << std::endl;

    return 0;
}