class Solution {
    bool isAlpha(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z'))
            return true;
        return false;
    }
    bool same(char a, char b)
    {
        a = tolower(a);
        b = tolower(b);
        if (a == b)
            return true;
        return false;
    }

public:
    bool isPalindrome(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        bool ans = true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isAlpha(s[i]))
                i++;
            while (i < j && !isAlpha(s[j]))
                j--;
            if (i < j && !same(s[i], s[j])) {
                ans = false;
                break;
            }
            i++;
            j--;
        }
        return ans;
    }
};