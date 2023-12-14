class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int n = ransomNote.size(), m = magazine.size();
        int freq[26] = { 0 };
        for (auto c : magazine)
            freq[c - 'a']++;
        for (auto c : ransomNote)
            if (--freq[c - 'a'] < 0)
                return false;
        return true;
    }
};