#include "Span.hpp"

int main() {
    std::cout << GREEN << "* Basic Functionality " << std::string(26, '=') << RESET << std::endl;
    
    Span sp = Span(5);

    std::cout << "sp Max Size = " << sp.getMaxSize() << std::endl;
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "sp Size = " << sp.getSize() << std::endl;
    
    try {
        std::cout << "\nShortest span = " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "\nException: " << RESET << e.what() << std::endl;
    }

    try {
        std::cout << "Longest span = " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "\nException: " << RESET << e.what() << std::endl;
    }

    std::cout << GREEN << "\n* Test Exceptions " << std::string(30, '=') << RESET << std::endl;

    Span    sp2(2);

    std::cout << "sp2 Max Size = " << sp2.getMaxSize() << std::endl;
    std::cout << "sp2 Size = " << sp2.getSize() << std::endl;
    try {
        std::cout << "\nShortest span = " << sp2.shortestSpan() << std::endl;
        std::cerr << "\nError: Exception not thrown!\n";
    }
    catch (std::exception &e) {
        std::cerr << RED << "\nException: " << RESET << e.what() << std::endl;
    }

    try {
        std::cout << "\nLongest span = " << sp2.longestSpan() << std::endl;
        std::cerr << "\nError: Exception not thrown!\n";
    }
    catch (std::exception &e) {
        std::cerr << RED << "\nException: " << RESET << e.what() << std::endl;
    }

    try {
        std::cout << "\nAdding 0 to sp2...\n";
        sp2.addNumber(0);
        std::cout << "Adding 1 to sp2...\n";
        sp2.addNumber(1);
        std::cout << "Adding 2 to sp2...\n";
        sp2.addNumber(2);
        std::cout << "Adding 3 to sp2...\n";
        sp2.addNumber(3);
    }
    catch (std::exception &e) {
        std::cerr << RED << "Exception: " << RESET << e.what() << std::endl;
    }

    std::cout << GREEN << "\n* Add Multiple and Large Test " << std::string(18, '=') << RESET << std::endl;

    Span sp3(20000);
    std::vector<int>    numbers;

    std::cout << "sp3 Max Size = " << sp3.getMaxSize() << std::endl;
    for (unsigned int i = 0; i < sp3.getMaxSize(); i++) {
        numbers.push_back(i * 2);
    }
    sp3.addMultiple(numbers.begin(), numbers.end());
    std::cout << "sp3 Size = " << sp3.getSize() << std::endl;
    
    try {
        std::cout << "\nShortest span = " << sp3.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "\nException: " << RESET << e.what() << std::endl;
    }

    try {
        std::cout << "Longest span = " << sp3.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "\nException: " << RESET << e.what() << std::endl;
    }

    try {
        std::cout << "\nAdding 42 to sp3...";
        sp3.addNumber(42);
    }
    catch (std::exception &e) {
        std::cerr << RED << "\nException: " << RESET << e.what() << std::endl;
    }

    return 0;
}