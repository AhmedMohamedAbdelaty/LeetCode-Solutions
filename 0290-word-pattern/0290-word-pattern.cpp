class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        words.push_back(word);
        if (pattern.length() != words.size())
            return false;
        unordered_map<char, string> mp; // char -> string, a -> dog
        unordered_map<string, char> mp2; // string -> char, dog -> a
        for (int i = 0; i < pattern.length(); i++) {
            // link pattern[i] to words[i] -> a to dog
            if (mp.find(pattern[i]) == mp.end()) {
                mp[pattern[i]] = words[i];
            } else {
                if (mp[pattern[i]] != words[i])
                    return false;
            }
            // link words[i] to pattern[i] -> dog to a
            if (mp2.find(words[i]) == mp2.end()) {
                mp2[words[i]] = pattern[i];
            } else {
                if (mp2[words[i]] != pattern[i])
                    return false;
            }
        }
        return true;
    }
};