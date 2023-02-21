#pragma once
#include <iostream>
#include <vector>

class Span {
    private:
        std::vector<int> m_vec;
        unsigned int m_size;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);
        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan() const;
};