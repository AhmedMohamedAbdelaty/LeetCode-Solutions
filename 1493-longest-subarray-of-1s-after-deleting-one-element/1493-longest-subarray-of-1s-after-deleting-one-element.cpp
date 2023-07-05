class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        vector<pair<int, pair<int, int>>> ones;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (c) {
                    ones.push_back({ c, { i - c, i - 1 } });
                }
                c = 0;
            } else {
                c++;
            }
        }
        if (c) {
            ones.push_back({ c, { (int)nums.size() - c, (int)nums.size() - 1 } });
        }
        int mx = 0;
        if (!ones.empty()) {
            for (int i = 0; i < ones.size() - 1; i++) {
                int my_end = ones[i].second.second;
                int next_start = ones[i + 1].second.first;
                if (next_start - 2 == my_end) {
                    mx = max(mx, ones[i].first + ones[i + 1].first);
                } else {
                    mx = max(mx, ones[i].first);
                }
            }
            mx = max(mx, ones.back().first);
            if (ones.size() == 1 && ones[0].first == nums.size()) {
                return ones[0].first - 1;
            }
        }
        return mx;
    }
};