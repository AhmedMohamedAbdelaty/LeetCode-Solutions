class Solution {
    unordered_map<int, unordered_map<int, double>> dp;

public:
    double soupServings(int n)
    {
        if (n >= 5000)
            return 1.0;
        return f(n, n);
    }
    double f(int a, int b)
    {
        if (a <= 0 && b <= 0) // half probability
            return 0.5;
        if (a <= 0) // full probability
            return 1.0;
        if (b <= 0) // zero probability
            return 0.0;
        if (dp[a][b])
            return dp[a][b];
        double prob = 0.0;
        prob += 0.25 * f(a - 100, b);
        prob += 0.25 * f(a - 75, b - 25);
        prob += 0.25 * f(a - 50, b - 50);
        prob += 0.25 * f(a - 25, b - 75);
        return dp[a][b] = prob;
    }
};