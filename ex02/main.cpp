#include "MutantStack.hpp"

int main() {
    MutantStack<int> mutant;

    mutant.push(42);
    mutant.push(95);
    mutant.push(63);
    mutant.push(9);
    std::cout << mutant.size() << std::endl;

    MutantStack<int>::iterator it = mutant.begin();
    MutantStack<int>::iterator ite = mutant.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}