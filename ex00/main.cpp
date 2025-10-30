#include "easyfind.hpp"
#include <vector>
#include <string>

int main() {
    std::vector<int>    vec;

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    std::cout << "Vector: { ";
    for (unsigned int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "}" << std::endl;
    
    int val1 = 3;
    int val2 = 8;
    
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
    return 0;
}