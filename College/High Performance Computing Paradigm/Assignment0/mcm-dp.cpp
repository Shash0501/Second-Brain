#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Dynamic Programming solution
int matrixChainMultiplicationDP(const vector<int> &dims)
{
    int n = dims.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    vector<int> dimensions = {5, 10, 15, 20, 30};

    // Dynamic Programming
    int dpResult = matrixChainMultiplicationDP(dimensions);
    cout << "Minimum multiplications (Dynamic Programming): " << dpResult << endl;

    return 0;
}