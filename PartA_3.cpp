
#include <iostream>
#include <iomanip>
#include <vector>
using namespace::   std;

int main()
{
    vector<vector<int>> distribution_matrix(6, vector<int>(6, 0));

    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            distribution_matrix[i][j] = (i + 1) + (j + 1);
        }
    }

    int total_combinations = 6 * 6;

    cout << "Probability of Sums:" << endl;
    for (int i = 2; i <= 12; ++i)
    {
        int count = 0;
        for (int j = 0; j < 6; ++j)
        {
            for (int k = 0; k < 6; ++k)
            {
                if (distribution_matrix[j][k] == i)
                {
                    count++;
                }
            }
        }
        double probability = static_cast<double>(count) / total_combinations;
        cout << "P(Sum = " << i << ") = " << fixed << setprecision(4) << probability << endl;
    }

    return 0;
}
