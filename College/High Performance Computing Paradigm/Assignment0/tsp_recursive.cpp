#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits> 


using namespace std;

const int INF = INT_MAX;

double distance(pair<int, int>& city1, pair<int, int>& city2) {
    int dx = city1.first - city2.first;
    int dy = city1.second - city2.second;
    return sqrt(dx * dx + dy * dy);
}

double tspRecursive(vector<pair<int, int>>& cities, int current, int mask, vector<vector<double>>& memo) {
    int n = cities.size();
    
    if (mask == (1 << n) - 1) {
        return distance(cities[current], cities[0]);
    }

    if (memo[current][mask] != -1.0) {
        return memo[current][mask];
    }

    double minCost = INF;

    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) {
            double cost = distance(cities[current], cities[next]) +
                          tspRecursive(cities, next, mask | (1 << next), memo);

            minCost = min(minCost, cost);
        }
    }

    memo[current][mask] = minCost;
    return minCost;
}

double solveTSP(vector<pair<int, int>>& cities) {
    int n = cities.size();
    vector<vector<double>> memo(n, vector<double>(1 << n, -1.0));
    return tspRecursive(cities, 0, 1, memo);
}

int main() {
    srand(time(0));

    // Generate a larger test case with 20 cities
    vector<pair<int, int>> cities;
    for (int i = 0; i < 20; ++i) {
        cities.push_back({rand() % 100, rand() % 100});
    }

    double minCost;

    minCost = solveTSP(cities);

    cout << "Minimum cost of TSP tour: " << minCost << endl;

    return 0;
}
