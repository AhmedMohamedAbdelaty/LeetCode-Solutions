class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int i = 0, mx = 0;
        unordered_map<char, int> mp;
        for (int j = 0; j < answerKey.size(); j++) {
            mp[answerKey[j]]++;
            while (mp['T'] > k && mp['F'] > k) {
                mp[answerKey[i]]--;
                i++;
            }
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};