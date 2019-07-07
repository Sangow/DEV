#include <iostream>
#include "List.cpp"

int main() {
    List<std::string>* list = new List<std::string>();

    list->append("alpha");
    list->append("bravo");
    list->append("charlie");
    list->append("delta");

    Iterator<std::string> it = Iterator<std::string>(list->last);

    it.begin();
    // std::cout << &it << std::endl;

    // it++;
    // std::cout << &it << std::endl;

    for ( ; !it.isOver(); it++ ) {
        std::cout << &it << std::endl;
    }
    std::cout << &it << std::endl;

    delete list;

    return 0;
}