class Solution {
    using ll = long long;

public:
    long long putMarbles(vector<int>& weights, int k)
    {
        int n = weights.size();
        vector<int> pairs;
        for (int i = 0; i < n - 1; i++) {
            pairs.push_back(weights[i + 1] + weights[i]);
        }
        sort(pairs.begin(), pairs.end());
        ll mn = 0, mx = 0;
        for (int i = 0; i < k - 1; i++) {
            mn += pairs[i];
            mx += pairs[n - i - 2];
        }
        return mx - mn;
    }
};