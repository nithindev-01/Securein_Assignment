#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int findNextDie(vector<int> originalDie, vector<int> &newDie, int index)
{
    for (int val = 1; val < 10; val++)
    {
        newDie[index] = val;

        if (index == 5)
        {
            vector<int> targetProb = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
            vector<int> newProb(11, 0);

            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    newProb[originalDie[i] + newDie[j] - 2] += 1;
                }
            }

            int probMatch = 1;

            for (int i = 0; i < 11; i++)
            {
                if (targetProb[i] != newProb[i])
                {
                    if (val == 9)
                        return 0;
                    probMatch = 0;
                    break;
                }
            }

            if (probMatch == 0)
                continue;

            return 1;
        }

        int flag = findNextDie(originalDie, newDie, index + 1);

        if (flag == 1)
        {
            return 1;
        }
    }

    return 0;
}

pair<vector<int>, vector<int>> undoomDice(vector<int> dieA, vector<int> dieB)
{
    vector<int> newDieA = {1, 0, 0, 0, 0, 4};

    for (int i = 2; i <= 3; i++)
    {
        for (int j = 2; j <= 3; j++)
        {
            for (int k = 2; k <= 3; k++)
            {
                for (int l = 2; l <= 3; l++)
                {
                    newDieA[1] = i;
                    newDieA[2] = j;
                    newDieA[3] = k;
                    newDieA[4] = l;

                    vector<int> newDieB(6, 0);

                    int flag = findNextDie(newDieA, newDieB, 0);

                    if (flag == 1)
                    {
                        return make_pair(newDieA, newDieB);
                    }
                }
            }
        }
    }

    return make_pair(newDieA, newDieA);
}

int main()
{
    vector<int> initialDice = {1, 2, 3, 4, 5, 6};
    auto outcome = undoomDice(initialDice, initialDice);

    cout << "New Die A: ";
    for (int num : outcome.first)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "New Die B: ";
    for (int num : outcome.second)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
