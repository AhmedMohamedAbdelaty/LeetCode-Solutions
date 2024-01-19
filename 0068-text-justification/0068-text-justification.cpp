class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        int n = words.size(), i = 0;
        vector<string> ans;
        while (i < n) {
            vector<string> temp;
            int len = 0;
            while (i < n && len + words[i].size() <= maxWidth) {
                len += words[i].size() + 1; // 1 for space
                temp.push_back(words[i++]);
            }
            int words_cnt = temp.size();
            len--;
            // if one word or last line
            if (words_cnt == 1 || i == n) {
                string s = "";
                for (auto x : temp) {
                    s += x;
                    s += " ";
                }
                s.pop_back();
                while (s.size() < maxWidth)
                    s += " ";
                ans.push_back(s);
                continue;
            }
            int spaces = maxWidth - len + words_cnt - 1;
            int space = spaces / (words_cnt - 1); // 8 / 2 = 4
            int extra = spaces % (words_cnt - 1); // 8 % 2 = 0
            string s = "";
            for (int j = 0; j < words_cnt; j++) {
                s += temp[j];
                if (j != words_cnt - 1) {
                    for (int k = 0; k < space; k++)
                        s += " ";
                    if (extra > 0) {
                        s += " ";
                        extra--;
                    }
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};