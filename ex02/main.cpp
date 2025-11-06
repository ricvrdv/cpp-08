#include "MutantStack.hpp"
#include <list>

int main() {
    std::cout << GREEN << "\nBasic Operations Test "<< std::string(30, '=') << RESET << std::endl;
    MutantStack<int> mutStack;

    std::cout << "Stack initial size = " << mutStack.size() << std::endl;

    std::cout << "Pushing 1 ..." << std::endl;
    mutStack.push(1);
    std::cout << "Pushing 2 ..." << std::endl;
    mutStack.push(2);
    std::cout << "Pushing 3 ..." << std::endl;
    mutStack.push(3);

    std::cout << "Stack current size = " << mutStack.size() << std::endl;
    std::cout << "Top element -> " << mutStack.top() << std::endl;

    std::cout << "Pop top element ..." << std::endl;
    mutStack.pop();
    std::cout << "Stack current size = " << mutStack.size() << std::endl;

    std::cout << GREEN << "\nIterator Traversal Test "<< std::string(28, '=') << RESET << std::endl;
    std::cout << "non-const iterator traversal:" << std::endl;
    for (MutantStack<int>::iterator it = mutStack.begin(); it != mutStack.end(); it++) {
        std::cout << *it << std::endl;
    }

    const MutantStack<int>& constMutStack(mutStack);
    std::cout << "\nconst iterator traversal:" << std::endl;
    std::cout << "Stack initial size (copied from previous stack) = " << constMutStack.size() << std::endl;
    for (MutantStack<int>::const_iterator it = constMutStack.begin(); it != constMutStack.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << GREEN << "\nReverse Iterator Traversal Test "<< std::string(20, '=') << RESET << std::endl;
    std::cout << "Pushing 42 ..." << std::endl;
    mutStack.push(42);
    std::cout << "Pushing 95 ..." << std::endl;
    mutStack.push(95);
    std::cout << "Stack current size = " << mutStack.size() << std::endl;
    std::cout << "Top element -> " << mutStack.top() << std::endl;
    
    std::cout << "\nnon-const iterator traversal:" << std::endl;
    for (MutantStack<int>::reverse_iterator it = mutStack.rbegin(); it != mutStack.rend(); it++) {
        std::cout << *it << std::endl;
    }

    const MutantStack<int>& cRevMutStack(mutStack);
    std::cout << "\nconst iterator traversal:" << std::endl;
    std::cout << "Stack initial size (copied from previous stack) = " << cRevMutStack.size() << std::endl;
    for (MutantStack<int>::const_reverse_iterator it = cRevMutStack.rbegin(); it != cRevMutStack.rend(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << GREEN << "\nTest interoperability with std::stack "<< std::string(14, '=') << RESET << std::endl;
    std::stack<int> stdStack(mutStack);
    std::cout << "std::stack top element -> " << stdStack.top() << std::endl;
    std::cout << "Pushing 9 ..." << std::endl;
    stdStack.push(9);
    std::cout << "std::stack top element -> " << stdStack.top() << std::endl;

    std::cout << GREEN << "\nVerification with std::list "<< std::string(24, '=') << RESET << std::endl;
    std::list<int>  lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(42);
    lst.push_back(95);
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        std::cout << *it << std::endl; 
    }
    std::cout << "stack top element -> " << mutStack.top() << std::endl;
    std::cout << "list top element -> " << lst.back() << std::endl;
    return 0;
}