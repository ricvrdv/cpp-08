#ifndef SPAN_HPP
# define SPAN_HPP

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <limits>

class   Span {
    private:
        std::vector<int>    numbers_;
        unsigned int        maxSize_;
    
    public:
        Span();
        Span( unsigned int N );
        Span( const Span &other );
        Span &operator=( const Span &other );
        ~Span();

        int     getElement( unsigned int n ) const;
        unsigned int    getMaxSize() const;
        size_t  getSize() const;
        
        void    addNumber( int num );
        int     shortestSpan();
        int     longestSpan();

        template <typename Iter>
        void    addMultiple(Iter begin, Iter end);

        class   MaxExceeded : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class   MinElements : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

template <typename Iter>
void    Span::addMultiple(Iter begin, Iter end) {
    if (std::distance(begin, end) + numbers_.size() > maxSize_) {
        throw MaxExceeded();
    }
    numbers_.insert(numbers_.end(), begin, end);
};

#endif