#include <bits/stdc++.h>
using namespace std;

int tspBruteForce(vector<vector<int>> &dist, int n)
{
    vector<int> cities;
    for (int i = 1; i < n; i++)
    {
        cities.push_back(i);
    }

    int minCost = INT_MAX;

    do
    {
        int cost = 0;
        int current = 0;

        // Visit all cities in this permutation
        for (int city : cities)
        {
            cost += dist[current][city];
            current = city;
        }

        // Return to starting city
        cost += dist[current][0];

        minCost = min(minCost, cost);

    } while (next_permutation(cities.begin(), cities.end()));

    return minCost;
}

int main()
{
    vector<vector<int>> dist = {
        {0, 3, 6, 8},
        {3, 0, 9, 4},
        {6, 9, 0, 2},
        {8, 4, 2, 0}};

    int n = dist.size();
    cout << "Minimum TSP cost: " << tspBruteForce(dist, n) << endl;

    return 0;
}
