#pragma once

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const std::stack<T>& stack) : std::stack<T>(stack) {}
    MutantStack(const MutantStack<T>& mutantStack) : std::stack<T>(mutantStack) {}
    MutantStack<T>& operator=(const MutantStack<T>& mutantStack) { std::stack<T>::operator=(mutantStack); return *this; }
    ~MutantStack() {}
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return std::begin(this->c); }
    iterator end() { return std::end(this->c); }
};
