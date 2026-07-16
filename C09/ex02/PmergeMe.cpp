#include "PmergeMe.hpp"

#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }

    return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::isValidNumber(const std::string& argument,int& number) const
{
    if (argument.empty())
        return false;

    for (std::size_t i = 0; i < argument.length(); ++i)
    {
        if (argument[i] < '0' || argument[i] > '9')
            return false;
    }

    std::istringstream stream(argument);
    long value;

    stream >> value;

    if (stream.fail() || !stream.eof())
        return false;

    if (value <= 0 || value > INT_MAX)
        return false;

    number = static_cast<int>(value);

    return true;
}

void PmergeMe::parseArguments(int argc, char** argv)
{
    if (argc < 2)
        throw std::runtime_error("Error");

    for (int i = 1; i < argc; ++i)
    {
        int number;

        if (!isValidNumber(argv[i], number))
            throw std::runtime_error("Error");

        for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
    {
        if (*it == number)
            throw std::runtime_error("Error");
    }    
        _vector.push_back(number);
        _deque.push_back(number);
    }
}

void PmergeMe::printVector(const std::vector<int>& container) const
{
    for (std::vector<int>::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        std::cout << *it;

        if (it + 1 != container.end())
            std::cout << " ";
    }

    std::cout << std::endl;
}

void PmergeMe::printDeque(const std::deque<int>& container) const
{
    for (std::deque<int>::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        std::cout << *it;

        if (it + 1 != container.end())
            std::cout << " ";
    }

    std::cout << std::endl;
}

void PmergeMe::displayBefore() const
{
    std::cout << "Before: ";
    printVector(_vector);
}

void PmergeMe::sortAndDisplay() const
{
    std::clock_t vectorStart = std::clock();
    std::vector<int> vectorResult = fordJohnsonVector(_vector);
    std::clock_t vectorEnd = std::clock();

    std::clock_t dequeStart = std::clock();
    std::deque<int> dequeResult = fordJohnsonDeque(_deque);
    std::clock_t dequeEnd = std::clock();

    if (vectorResult.size() != dequeResult.size())
        throw std::runtime_error("Error: containers produced different results");

    for (std::size_t i = 0; i < vectorResult.size(); ++i)
    {
        if (vectorResult[i] != dequeResult[i])
            throw std::runtime_error("Error: containers produced different results");

        if (i > 0 && vectorResult[i - 1] > vectorResult[i])
            throw std::runtime_error("Error: sequence was not sorted");
    }

    double vectorTime =
        static_cast<double>(vectorEnd - vectorStart)
        / CLOCKS_PER_SEC
        * 1000000.0;

    double dequeTime =
        static_cast<double>(dequeEnd - dequeStart)
        / CLOCKS_PER_SEC
        * 1000000.0;

    std::cout << "After:  ";
    printVector(vectorResult);

    std::cout
        << "Time to process a range of "
        << _vector.size()
        << " elements with std::vector : "
        << std::fixed
        << std::setprecision(5)
        << vectorTime
        << " us"
        << std::endl;

    std::cout
        << "Time to process a range of "
        << _deque.size()
        << " elements with std::deque  : "
        << std::fixed
        << std::setprecision(5)
        << dequeTime
        << " us"
        << std::endl;
}

void PmergeMe::makeVectorPairs(std::vector<std::pair<int, int> >& pairs, bool& hasStraggler, int& straggler)const
{
    hasStraggler = false;
    straggler = 0;
    std::size_t i = 0;

    while(i + 1 < _vector.size())
    {

        int first  = _vector[i];
        int second = _vector[i + 1];


        if(first > second)
        {
            int temporary = first;
            first = second;
            second = temporary;
        }
        pairs.push_back(std::make_pair(first, second));
        i += 2;
    }
    if(_vector.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = _vector.back();
    }

}

void PmergeMe::testVectorPairs()const
{
    std::vector< std::pair<int,  int> > pairs;
    bool hasStraggler;
    int straggler;

    makeVectorPairs(pairs, hasStraggler, straggler);
    std::cout << "Pairs:" << std::endl;

    for(std::vector< std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        std::cout << "(" << it->first << "," << it->second << ")" << std::endl;
    }
    if(hasStraggler)
        std::cout << "Straggler: " << straggler << std::endl;
}


void PmergeMe::splitVectorPairs(const std::vector <std::pair<int, int> >& pairs, std::vector<int>& smaller, std::vector<int>& larger)const
{
    for(std::vector< std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        smaller.push_back(it->first);
        larger.push_back(it->second);
    }
}

void PmergeMe::testSplitVectorPairs()const
{
    std::vector< std::pair<int, int> > pairs;
    std::vector<int> smaller;
    std::vector<int> larger;

    bool hasStraggler;
    int straggler;

    makeVectorPairs(pairs, hasStraggler, straggler);
    splitVectorPairs(pairs, smaller, larger);

    std::cout << "Smaller: ";
    printVector(smaller);

    std::cout << "Larger: ";
    printVector(larger);

    if(hasStraggler)
        std::cout << "Straggler: " << straggler << std::endl;
}

void PmergeMe::reorderVectorPairs(
    const std::vector< std::pair<int, int> >& pairs,
    const std::vector<int>& sortedLarger,
    std::vector< std::pair<int, int> >& orderedPairs
) const
{
    for (
        std::vector<int>::const_iterator largerIt
            = sortedLarger.begin();
        largerIt != sortedLarger.end();
        ++largerIt
    )
    {
        for (
            std::vector< std::pair<int, int> >::const_iterator pairIt
                = pairs.begin();
            pairIt != pairs.end();
            ++pairIt
        )
        {
            if (pairIt->second == *largerIt)
            {
                orderedPairs.push_back(*pairIt);
                break;
            }
        }
    }
}

std::vector<int> PmergeMe::fordJohnsonVector(
    const std::vector<int>& input
) const
{
    if (input.size() <= 1)
        return input;

    std::vector< std::pair<int, int> > pairs;
    std::vector<int> larger;

    bool hasStraggler = false;
    int straggler = 0;

    std::size_t i = 0;

    while (i + 1 < input.size())
    {
        int first = input[i];
        int second = input[i + 1];

        if (first > second)
        {
            int temporary = first;
            first = second;
            second = temporary;
        }

        pairs.push_back(
            std::make_pair(first, second)
        );

        larger.push_back(second);

        i += 2;
    }

    if (input.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = input.back();
    }

    std::vector<int> sortedLarger =
        fordJohnsonVector(larger);

    std::vector< std::pair<int, int> > orderedPairs;

    reorderVectorPairs(
        pairs,
        sortedLarger,
        orderedPairs
    );

    std::vector<int> mainChain;
    std::vector<int> pending;

    buildVectorChains(
        orderedPairs,
        mainChain,
        pending
    );

    (void)pending;

    insertVectorPendingJacobsthal(
        mainChain,
        orderedPairs,
        hasStraggler,
        straggler
    );

    return mainChain;
}

void PmergeMe::testOrderedVectorPairs() const
{
    std::vector< std::pair<int, int> > pairs;
    std::vector<int> smaller;
    std::vector<int> larger;
    std::vector<int> sortedLarger;
    std::vector< std::pair<int, int> > orderedPairs;

    bool hasStraggler;
    int straggler;

    makeVectorPairs(pairs, hasStraggler, straggler);
    splitVectorPairs(pairs, smaller, larger);

    if (
        larger.size() == 3
        && larger[0] == 6
        && larger[1] == 4
        && larger[2] == 7
    )
    {
        sortedLarger.push_back(4);
        sortedLarger.push_back(6);
        sortedLarger.push_back(7);
    }
    else
    {
        std::cout
            << "Use the test sequence: 3 6 4 2 5 7"
            << std::endl;
        return;
    }

    reorderVectorPairs(
        pairs,
        sortedLarger,
        orderedPairs
    );

    std::cout << "Ordered pairs:" << std::endl;

    for (
        std::vector< std::pair<int, int> >::const_iterator it
            = orderedPairs.begin();
        it != orderedPairs.end();
        ++it
    )
    {
        std::cout
            << "("
            << it->first
            << ","
            << it->second
            << ")"
            << std::endl;
    }

    (void)hasStraggler;
    (void)straggler;
}

void PmergeMe::buildVectorChains(
    const std::vector< std::pair<int, int> >& orderedPairs,
    std::vector<int>& mainChain,
    std::vector<int>& pending
) const
{
    if (orderedPairs.empty())
        return;

    mainChain.push_back(orderedPairs[0].first);
    mainChain.push_back(orderedPairs[0].second);

    for (std::size_t i = 1; i < orderedPairs.size(); ++i)
    {
        pending.push_back(orderedPairs[i].first);
        mainChain.push_back(orderedPairs[i].second);
    }
}

void PmergeMe::testVectorChains() const
{
    std::vector< std::pair<int, int> > pairs;
    std::vector<int> sortedLarger;
    std::vector< std::pair<int, int> > orderedPairs;
    std::vector<int> mainChain;
    std::vector<int> pending;

    bool hasStraggler;
    int straggler;

    makeVectorPairs(pairs, hasStraggler, straggler);

    if (
        pairs.size() == 3
        && pairs[0].second == 6
        && pairs[1].second == 4
        && pairs[2].second == 7
    )
    {
        sortedLarger.push_back(4);
        sortedLarger.push_back(6);
        sortedLarger.push_back(7);
    }
    else
    {
        std::cout
            << "Use the test sequence: 3 6 4 2 5 7"
            << std::endl;
        return;
    }

    reorderVectorPairs(
        pairs,
        sortedLarger,
        orderedPairs
    );

    buildVectorChains(
        orderedPairs,
        mainChain,
        pending
    );

    std::cout << "Main chain: ";
    printVector(mainChain);

    std::cout << "Pending: ";
    printVector(pending);

    (void)hasStraggler;
    (void)straggler;
}

std::size_t PmergeMe::findVectorInsertionPosition(
    const std::vector<int>& mainChain,
    int value,
    std::size_t end
) const
{
    std::size_t begin = 0;

    while (begin < end)
    {
        std::size_t middle = begin + (end - begin) / 2;

        if (value < mainChain[middle])
            end = middle;
        else
            begin = middle + 1;
    }

    return begin;
}

void PmergeMe::insertVectorPendingInOrder(
    std::vector<int>& mainChain,
    const std::vector< std::pair<int, int> >& orderedPairs
) const
{
    for (std::size_t i = 1; i < orderedPairs.size(); ++i)
    {
        int pendingValue = orderedPairs[i].first;
        int partnerValue = orderedPairs[i].second;

        std::size_t partnerPosition = 0;

        while (
            partnerPosition < mainChain.size()
            && mainChain[partnerPosition] != partnerValue
        )
        {
            ++partnerPosition;
        }

        std::size_t insertionPosition =
            findVectorInsertionPosition(
                mainChain,
                pendingValue,
                partnerPosition
            );

        mainChain.insert(
            mainChain.begin() + insertionPosition,
            pendingValue
        );
    }
}

void PmergeMe::testVectorBinaryInsertion() const
{
    std::vector< std::pair<int, int> > orderedPairs;
    std::vector<int> mainChain;
    std::vector<int> pending;

    orderedPairs.push_back(std::make_pair(2, 4));
    orderedPairs.push_back(std::make_pair(3, 6));
    orderedPairs.push_back(std::make_pair(5, 7));

    buildVectorChains(
        orderedPairs,
        mainChain,
        pending
    );

    std::cout << "Before insertion: ";
    printVector(mainChain);

    insertVectorPendingInOrder(
        mainChain,
        orderedPairs
    );

    std::cout << "After insertion: ";
    printVector(mainChain);

    (void)pending;
}



void PmergeMe::testFordJohnsonVector() const
{
    std::vector<int> result =
        fordJohnsonVector(_vector);

    std::cout << "Ford-Johnson result: ";
    printVector(result);
}

std::vector<std::size_t> PmergeMe::generateJacobsthalOrder(
    std::size_t totalPending
) const
{
    std::vector<std::size_t> order;

    if (totalPending <= 1)
        return order;

    std::size_t previousBoundary = 1;
    std::size_t previousJacobsthal = 1;
    std::size_t currentJacobsthal = 3;

    while (previousBoundary < totalPending)
    {
        std::size_t upperBoundary = currentJacobsthal;

        if (upperBoundary > totalPending)
            upperBoundary = totalPending;

        for (
            std::size_t index = upperBoundary;
            index > previousBoundary;
            --index
        )
        {
            order.push_back(index);
        }

        previousBoundary = upperBoundary;

        std::size_t nextJacobsthal =
            currentJacobsthal
            + (2 * previousJacobsthal);

        previousJacobsthal = currentJacobsthal;
        currentJacobsthal = nextJacobsthal;
    }

    return order;
}

void PmergeMe::testJacobsthalOrder() const
{
    std::vector<std::size_t> order =
        generateJacobsthalOrder(11);

    std::cout << "Jacobsthal insertion order: ";

    for (
        std::vector<std::size_t>::const_iterator it
            = order.begin();
        it != order.end();
        ++it
    )
    {
        std::cout << *it;

        if (it + 1 != order.end())
            std::cout << " ";
    }

    std::cout << std::endl;
}

void PmergeMe::insertVectorPendingJacobsthal(
    std::vector<int>& mainChain,
    const std::vector< std::pair<int, int> >& orderedPairs,
    bool hasStraggler,
    int straggler
) const
{
    std::size_t totalPending = orderedPairs.size();

    if (hasStraggler)
        ++totalPending;

    std::vector<std::size_t> insertionOrder =
        generateJacobsthalOrder(totalPending);

    for (
        std::vector<std::size_t>::const_iterator it =
            insertionOrder.begin();
        it != insertionOrder.end();
        ++it
    )
    {
        std::size_t pendingIndex = *it;

        int pendingValue;
        std::size_t searchLimit;

        if (pendingIndex <= orderedPairs.size())
        {
            std::size_t pairIndex = pendingIndex - 1;

            pendingValue = orderedPairs[pairIndex].first;

            int partnerValue =
                orderedPairs[pairIndex].second;

            searchLimit = 0;

            while (
                searchLimit < mainChain.size()
                && mainChain[searchLimit] != partnerValue
            )
            {
                ++searchLimit;
            }
        }
        else
        {
            pendingValue = straggler;
            searchLimit = mainChain.size();
        }

        std::size_t insertionPosition =
            findVectorInsertionPosition(
                mainChain,
                pendingValue,
                searchLimit
            );

        mainChain.insert(
            mainChain.begin() + insertionPosition,
            pendingValue
        );
    }
}

std::deque<int> PmergeMe::fordJohnsonDeque(
    const std::deque<int>& input
) const
{
    if (input.size() <= 1)
        return input;

    std::deque< std::pair<int, int> > pairs;
    std::deque<int> larger;

    bool hasStraggler = false;
    int straggler = 0;

    std::size_t i = 0;

    while (i + 1 < input.size())
    {
        int first = input[i];
        int second = input[i + 1];

        if (first > second)
        {
            int temporary = first;
            first = second;
            second = temporary;
        }

        pairs.push_back(std::make_pair(first, second));
        larger.push_back(second);

        i += 2;
    }

    if (input.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = input.back();
    }

    std::deque<int> sortedLarger =
        fordJohnsonDeque(larger);

    std::deque< std::pair<int, int> > orderedPairs;

    reorderDequePairs(
        pairs,
        sortedLarger,
        orderedPairs
    );

    std::deque<int> mainChain;
    std::deque<int> pending;

    buildDequeChains(
        orderedPairs,
        mainChain,
        pending
    );

    (void)pending;

    insertDequePendingJacobsthal(
        mainChain,
        orderedPairs,
        hasStraggler,
        straggler
    );

    return mainChain;
}

void PmergeMe::reorderDequePairs(
    const std::deque< std::pair<int, int> >& pairs,
    const std::deque<int>& sortedLarger,
    std::deque< std::pair<int, int> >& orderedPairs
) const
{
    for (
        std::deque<int>::const_iterator largerIt
            = sortedLarger.begin();
        largerIt != sortedLarger.end();
        ++largerIt
    )
    {
        for (
            std::deque< std::pair<int, int> >::const_iterator pairIt
                = pairs.begin();
            pairIt != pairs.end();
            ++pairIt
        )
        {
            if (pairIt->second == *largerIt)
            {
                orderedPairs.push_back(*pairIt);
                break;
            }
        }
    }
}

void PmergeMe::buildDequeChains(
    const std::deque< std::pair<int, int> >& orderedPairs,
    std::deque<int>& mainChain,
    std::deque<int>& pending
) const
{
    if (orderedPairs.empty())
        return;

    mainChain.push_back(orderedPairs[0].first);
    mainChain.push_back(orderedPairs[0].second);

    for (std::size_t i = 1; i < orderedPairs.size(); ++i)
    {
        pending.push_back(orderedPairs[i].first);
        mainChain.push_back(orderedPairs[i].second);
    }
}

std::size_t PmergeMe::findDequeInsertionPosition(
    const std::deque<int>& mainChain,
    int value,
    std::size_t end
) const
{
    std::size_t begin = 0;

    while (begin < end)
    {
        std::size_t middle = begin + (end - begin) / 2;

        if (value < mainChain[middle])
            end = middle;
        else
            begin = middle + 1;
    }

    return begin;
}

void PmergeMe::insertDequePendingJacobsthal(
    std::deque<int>& mainChain,
    const std::deque< std::pair<int, int> >& orderedPairs,
    bool hasStraggler,
    int straggler
) const
{
    std::size_t totalPending = orderedPairs.size();

    if (hasStraggler)
        ++totalPending;

    std::vector<std::size_t> insertionOrder =
        generateJacobsthalOrder(totalPending);

    for (
        std::vector<std::size_t>::const_iterator it
            = insertionOrder.begin();
        it != insertionOrder.end();
        ++it
    )
    {
        std::size_t pendingIndex = *it;

        int pendingValue;
        std::size_t searchLimit;

        if (pendingIndex <= orderedPairs.size())
        {
            std::size_t pairIndex = pendingIndex - 1;

            pendingValue = orderedPairs[pairIndex].first;

            int partnerValue = orderedPairs[pairIndex].second;

            searchLimit = 0;

            while (
                searchLimit < mainChain.size()
                && mainChain[searchLimit] != partnerValue
            )
            {
                ++searchLimit;
            }
        }
        else
        {
            pendingValue = straggler;
            searchLimit = mainChain.size();
        }

        std::size_t insertionPosition =
            findDequeInsertionPosition(
                mainChain,
                pendingValue,
                searchLimit
            );

        mainChain.insert(
            mainChain.begin() + insertionPosition,
            pendingValue
        );
    }
}

void PmergeMe::testFordJohnsonDeque() const
{
    std::deque<int> result =
        fordJohnsonDeque(_deque);

    std::cout << "Ford-Johnson deque result: ";
    printDeque(result);
}
