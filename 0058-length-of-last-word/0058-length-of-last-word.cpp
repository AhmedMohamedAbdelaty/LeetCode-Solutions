class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0;
        int i = s.size()-1;
        while (i>=0) {
            if (s[i] != ' ') break;
            i--;
        }

        for (; i>=0 && s[i]!=' '; i--){
            n++;
        }
        return n;
    }
};