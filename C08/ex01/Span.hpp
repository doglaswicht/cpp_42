#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public:
        Span(unsigned int N);
        Span(const Span &other);     
        ~Span();

        Span& operator=(const Span &other);
        
        void addNumber(int number);
    
        int shortestSpan() const;
        int longestSpan() const;

        template<typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            while(begin != end)
            {
                addNumber(*begin);
                ++begin;
            }
        }
};


#endif
