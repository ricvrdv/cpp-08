#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <limits>

class   Span {
    private:
        std::vector<int>    numbers_;
        unsigned int        max_size_;
    
    public:
        Span();
        Span( unsigned int N );
        Span( const Span &other );
        Span &operator=( const Span &other );
        ~Span();

        void    addNumber( int num );
        int     shortestSpan();
        int     longestSpan();

        class   MaxExceeded : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class   MinElements : public std::exception {
            public:
                virtual const char* what() const throw();
        }
};

#endif