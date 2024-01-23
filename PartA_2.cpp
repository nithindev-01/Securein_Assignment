#include <iostream>
#include <vector>

int main()
{
    // Represent Die A and Die B
    std::vector<int> dieA = {1, 2, 3, 4, 5, 6};
    std::vector<int> dieB = {1, 2, 3, 4, 5, 6};

    // Display the distribution
    std::cout << "Distribution of Combinations:" << std::endl;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            std::cout << "(" << dieA[i] << "," << dieB[j] << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}
