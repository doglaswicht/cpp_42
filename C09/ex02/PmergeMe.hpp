#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <utility>
#include <stdexcept>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int>  _deque;

        bool isValidNumber(const std::string& argument, int& number) const;

        void printVector(const std::vector<int>& container) const;
        void printDeque(const std::deque<int>& container) const;

        void makeVectorPairs(std::vector<std::pair<int, int> >& pairs, bool& hasStraggler, int& straggler)const;
        void splitVectorPairs(const std::vector <std::pair<int, int> >& pairs, std::vector<int>& smaller, std::vector<int>& larger)const;
        std::vector<int> fordJohnsonVector(const std::vector<int>& input)const;
        void reorderVectorPairs(const std::vector< std::pair<int, int> >& pairs, const std::vector<int>& sortedLarger, std::vector< std::pair<int, int> >& orderedPairs) const;
        void buildVectorChains(const std::vector< std::pair<int, int> >& orderedPairs, std::vector<int>& mainChain, std::vector<int>& pending) const;

        std::size_t findVectorInsertionPosition(const std::vector<int>& mainChain, int value, std::size_t end) const;

        void insertVectorPendingInOrder(std::vector<int>& mainChain, const std::vector< std::pair<int, int> >& orderedPairs) const;
        std::vector<std::size_t> generateJacobsthalOrder(std::size_t totalPending) const;
        void insertVectorPendingJacobsthal(std::vector<int>& mainChain,const std::vector< std::pair<int, int> >& orderedPairs, bool hasStraggler, int straggler) const;

        std::deque<int> fordJohnsonDeque(const std::deque<int>& input) const;
        void reorderDequePairs(const std::deque< std::pair<int, int> >& pairs, const std::deque<int>& sortedLarger, std::deque< std::pair<int, int> >& orderedPairs) const;
        void buildDequeChains(const std::deque< std::pair<int, int> >& orderedPairs, std::deque<int>& mainChain, std::deque<int>& pending) const;
        std::size_t findDequeInsertionPosition(const std::deque<int>& mainChain, int value, std::size_t end) const;
        void insertDequePendingJacobsthal(std::deque<int>& mainChain, const std::deque< std::pair<int, int> >& orderedPairs, bool hasStraggler, int straggler) const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parseArguments(int argc, char** argv);
        void displayBefore() const;
        void sortAndDisplay() const;

        void testVectorPairs()const;
        void testSplitVectorPairs()const;
        void testOrderedVectorPairs() const;
        void testVectorChains() const;
        void testVectorBinaryInsertion() const;
        void testFordJohnsonVector() const;
        void testJacobsthalOrder() const;
        void testFordJohnsonDeque() const;
};

#endif
