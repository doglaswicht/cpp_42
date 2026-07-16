#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try
    {
        PmergeMe program;

        program.parseArguments(argc, argv);
        program.displayBefore();
        program.sortAndDisplay();
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }

    return 0;
}
