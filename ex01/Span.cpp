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
}

// Destructor
Span::~Span() {}