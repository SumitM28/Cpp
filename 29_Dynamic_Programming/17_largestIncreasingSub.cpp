// Largest Increasing subsequence
#include <bits/stdc++.h>
using namespace std;

// using recursion
int solve(int n, int a[], int curr, int prev)
{
    // base case
    if (curr == n)
        return 0;

    // include
    int include = 0;
    if (prev == -1 || a[curr] > a[prev])
    {
        include = 1 + solve(n, a, curr + 1, curr);
    }

    int exclude = 0 + solve(n, a, curr + 1, prev);
    return max(include, exclude);
}

// using dp approach 1st
// recursion + memoization
int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
{
    // base case
    if (curr == n)
        return 0;

    // if ans is present in dp array
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // include
    int include = 0;
    if (prev == -1 || a[curr] > a[prev])
    {
        include = 1 + solveMem(n, a, curr + 1, curr, dp);
    }

    int exclude = 0 + solveMem(n, a, curr + 1, prev, dp);
    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

// using dp approach 2nd
// tabulation
int solveTab(int n, int a[], int curr, int prev)
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                include = 1 + dp[curr + 1][curr + 1];
            }

            int exclude = 0 + dp[curr + 1][prev + 1];
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

// space optimize
int solveSpaceOptimize(int n, int a[])
{

    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                include = 1 + nextRow[curr + 1];
            }

            int exclude = 0 + nextRow[prev + 1];
            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

// dp + binary search
int solveOptimal(int n, int a[])
{
    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans.back())
        {
            ans.push_back(a[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }

    return ans.size();
}

// Function to find length of longest increasing subsequence.
int longestSubsequence(int n, int a[])
{
    // using recursion
    // return solve(n, a, 0, -1);

    // usign dp 1
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return solveMem(n, a, 0, -1, dp);

    // using DP approach 2nd
    return solveTab(n, a, 0, -1);
}

int main()
{
}