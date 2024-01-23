#include <iostream>
#include <vector>
using namespace:: std;

int main() {
    vector<int> dieA = {1, 2, 3, 4, 5, 6};
    vector<int> dieB = {1, 2, 3, 4, 5, 6};

    int totalCombinations = dieA.size() * dieB.size();

    cout << "Total Combinations: " << totalCombinations << endl;

    return 0;
}
