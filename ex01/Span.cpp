#include "Span.hpp"

// Default Constructor
Span::Span() : max_size_(0) {}

// Parametric Constructor
Span::Span( unsigned int N ) : max_size_(N) {
    numbers_.reserve(N);
}

// Copy Constructor
Span::Span( const Span &other ) {
    this->max_size_ = other.max_size_;
    for (unsigned int i = 0; i < max_size_; i++) {
        this->numbers_[i] = other.numbers_[i];
    }
}
// Copy Assignment Operator
Span&   Span::operator=( const Span &other ) {
    if (this != &other) {
        this->max_size_ = other.max_size_;
        for (unsigned int i = 0; i < max_size_; i++) {
            this->numbers_[i] = other.numbers_[i];
        }
    }
    return (*this);
}

// Destructor
Span::~Span() {}

// Methods
void    Span::addNumber( int num ) {
    if (numbers_.size() >= max_size_)
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
}

// Exceptions
const char* Span::MaxExceeded::what() const throw() {
    return "Span maximum capacity exceeded";
}

const char* Span::MinElements::what() const throw() {
    return "Span contains less than 2 elements";
}