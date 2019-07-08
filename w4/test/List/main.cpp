#include <iostream>
#include <map>

int main() {
    std::map<size_t, std::string>* list = new std::map<size_t, std::string>();
    std::map<size_t, std::string>::iterator it;

    list->insert(std::pair<size_t, std::string>(4, "delta"));
    list->insert(std::pair<size_t, std::string>(3, "charlie"));
    list->insert(std::pair<size_t, std::string>(1, "alpha"));
    list->insert(std::pair<size_t, std::string>(2, "bravo"));
    list->insert(std::pair<size_t, std::string>(100, "sto"));
    list->insert(std::pair<size_t, std::string>(101, "sto"));

    it = list->begin();

    for ( ; it != list->end(); it++ ) {
        std::cout << it->first << ", " << it->second << list->size() << std::endl;
    }

    std::cout << "-------------" << std::endl;

    for ( it = list->begin(); it != list->end(); it++ ) {
        if (it->second == "sto") {
            list->erase(it);
        }
    }

    for ( it = list->begin(); it != list->end(); it++ ) {
        std::cout << it->first << ", " << it->second << std::endl;
    }

    return 0;
}