#include "./include/Span.hpp"

Span::Span() : m_size(0) {}

Span::Span(unsigned int n) : m_size(n) {}

Span::Span(const Span& other) : m_vec(other.m_vec), m_size(other.m_size) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        m_vec = other.m_vec;
        m_size = other.m_size;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (m_vec.size() < m_size) {
        m_vec.push_back(n);
    }
    else {
        throw std::exception();
    }
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (static_cast<unsigned long>(std::distance(begin, end)) > m_size - m_vec.size()) {
        throw std::out_of_range("Not enough space in Span");
    }
    m_vec.insert(m_vec.end(), begin, end);
}

int Span::shortestSpan() {
    if (m_vec.size() < 2) {
        throw std::exception();
    }
    std::sort(m_vec.begin(), m_vec.end());
    int min = m_vec[1] - m_vec[0];
    for (unsigned int i = 1; i < m_vec.size() - 1; i++) {
        if (m_vec[i + 1] - m_vec[i] < min) {
            min = m_vec[i + 1] - m_vec[i];
        }
    }
    return min;
}

int Span::longestSpan() const {
    if (m_vec.size() < 2) {
        throw std::logic_error("Not enough m_vec in Span");
    }
    int max = *std::max_element(m_vec.begin(), m_vec.end());
    int min = *std::min_element(m_vec.begin(), m_vec.end());
    return max - min;
}