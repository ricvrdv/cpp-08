#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

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

        void    addNumber(int num);
        void    shortestSpan();
        void    longestSpan();
};

#endif