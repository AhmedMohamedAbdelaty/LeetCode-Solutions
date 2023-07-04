class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ones = 0, twos = 0;
        // if a number present one time then it will be in ones
        // if present two times then remove it from ones and add it to twos
        // if present three times then remove it from twos
        for (auto& x : nums) {
            ones = (ones ^ x) & ~twos; // ~twos to check if it is not present in twos
            twos = (twos ^ x) & ~ones; // ~ones to check if it is not present in ones
        }
        return ones; // return the number which is present one time
    }
};