#include "Span.hpp"

// Default Constructor
Span::Span() : maxSize_(0) {}

// Parametric Constructor
Span::Span( unsigned int N ) : maxSize_(N) {
    numbers_.reserve(N);
}

// Copy Constructor
Span::Span( const Span &other ) {
    this->maxSize_ = other.maxSize_;
    for (unsigned int i = 0; i < maxSize_; i++) {
        this->numbers_[i] = other.numbers_[i];
    }
}
// Copy Assignment Operator
Span&   Span::operator=( const Span &other ) {
    if (this != &other) {
        this->maxSize_ = other.maxSize_;
        for (unsigned int i = 0; i < maxSize_; i++) {
            this->numbers_[i] = other.numbers_[i];
        }
    }
    return (*this);
}

// Destructor
Span::~Span() {}

// Getters
int     Span::getElement( unsigned int n ) const {
    if (n >= numbers_.size()) {
        throw std::out_of_range("Index out of range");
    }
    return numbers_[n];
}

unsigned int    Span::getMaxSize() const {
    return maxSize_;
}

size_t  Span::getSize() const {
    return (numbers_.size());
}

// Methods
void    Span::addNumber( int num ) {
    if (numbers_.size() >= maxSize_)
        throw MaxExceeded();
    numbers_.push_back(num);
}

int Span::shortestSpan() {
    if (numbers_.size() < 2)
        throw MinElements();
    std::vector<int> sorted(numbers_);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); i++) {
        minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
    }
    return minSpan;
}

int Span::longestSpan() {
    if (numbers_.size() < 2)
        throw MinElements();
    std::vector<int> sorted(numbers_);
    std::sort(sorted.begin(), sorted.end());
    return (sorted[sorted.size() - 1] - sorted[0]);
}

// Exceptions
const char* Span::MaxExceeded::what() const throw() {
    return "Span maximum capacity exceeded";
}

const char* Span::MinElements::what() const throw() {
    return "Span contains less than 2 elements";
}