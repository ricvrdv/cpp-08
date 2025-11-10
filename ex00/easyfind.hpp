#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <iostream>

template <typename T>
typename T::const_iterator  easyfind(const T&, int);

template <typename T>
typename T::iterator  easyfind(T&, int);

# include "easyfind.tpp"

#endif