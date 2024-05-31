class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        long long XOR_ALL = 0;
        for (int i = 0; i < nums.size(); i++) {
            XOR_ALL ^= nums[i];
        }

        long long mask = XOR_ALL & (-XOR_ALL);

        int a = 0, b = 0;
        for (auto x : nums) {
            if (x & mask)
                a ^= x;
            else
                b ^= x;
        }
        return { a, b };
    }
};