#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
    std::vector<int>    vec;
    std::list<int>      lst;
    std::deque<int>     deq;
    int val1 = 3;
    int val2 = 8;

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
        lst.push_back(i);
        deq.push_back(i);
        if (i != 0)
            deq.push_front(i);
    }

    std::cout << "Vector: { ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "}" << std::endl;
    
    try {
        std::cout << "\nSearching for value = " << val1 << "\n";
        easyfind(vec, val1);
        std::cout << GREEN << "Value found in container" << RESET << "\n";

        std::cout << "\nSearching for value = " << val2 << "\n";
        easyfind(vec, val2);
        std::cout << GREEN << "Value found in container" << RESET << "\n";
    }
    catch (std::exception &e) {
        std::cerr << RED << "Exception: "<< RESET << e.what() << std::endl;
    }

    std::cout << std::endl << std::string(30, '-') << std::endl;

    std::cout << "\nList: { ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;

    try {
        std::cout << "\nSearching for value = " << val1 << "\n";
        easyfind(lst, val1);
        std::cout << GREEN << "Value found in container" << RESET << "\n";

        std::cout << "\nSearching for value = " << val2 << "\n";
        easyfind(lst, val2);
        std::cout << GREEN << "Value found in container" << RESET << "\n";
    }
    catch (std::exception &e) {
        std::cerr << RED << "Exception: "<< RESET << e.what() << std::endl;
    }
    
    std::cout << std::endl << std::string(30, '-') << std::endl;

    std::cout << "\nDeque: { ";
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << "}" << std::endl;

    try {
        std::cout << "\nSearching for value = " << val1 << "\n";
        easyfind(deq, val1);
        std::cout << GREEN << "Value found in container" << RESET << "\n";

        std::cout << "\nSearching for value = " << val2 << "\n";
        easyfind(deq, val2);
        std::cout << GREEN << "Value found in container" << RESET << "\n";
    }
    catch (std::exception &e) {
        std::cerr << RED << "Exception: "<< RESET << e.what() << std::endl;
    }
    return 0;
}