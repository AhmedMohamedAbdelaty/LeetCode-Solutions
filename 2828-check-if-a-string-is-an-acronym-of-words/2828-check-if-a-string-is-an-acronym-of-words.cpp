class Solution {
public:
    bool isAcronym(vector<string>& words, string s)
    {
        string str = "";
        for (auto& word : words)
            str += word[0];
        return str == s;
    }
};