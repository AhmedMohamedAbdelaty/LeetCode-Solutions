class Solution {
public:
    int countTriplets(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> pre(arr.begin(), arr.end());
        pre.insert(pre.begin(), 0);
        for (int i = 1; i <= n; i++) {
            pre[i] ^= pre[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 1; j < n + 1; j++) {
                if (pre[i] == pre[j]) {
                    ans += j - i - 1;
                }
            }
        }
        return ans;
    }
};