#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Recursive solution
int matrixChainMultiplicationRecursive(const vector<int> &dims, int i, int j)
{
    if (i == j)
        return 0;

    int minOps = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int cost = matrixChainMultiplicationRecursive(dims, i, k) +
                   matrixChainMultiplicationRecursive(dims, k + 1, j) +
                   dims[i - 1] * dims[k] * dims[j];

        if (cost < minOps)
            minOps = cost;
    }

    return minOps;
}

int main()
{
    vector<int> dimensions = {5, 10, 15, 20, 30};

    // Recursive
    int recursiveResult = matrixChainMultiplicationRecursive(dimensions, 1, dimensions.size() - 1);
    cout << "Minimum multiplications (Recursive): " << recursiveResult << endl;

    return 0;
}