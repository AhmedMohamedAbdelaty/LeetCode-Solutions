class Solution {
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        vector<int> dif;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i])
                dif.push_back(i);
        }
        if (dif.size()==2){
            swap(s[dif[0]], s[dif[1]]);
            return s==goal;
        }
        if (dif.size()==0){
            sort(s.begin(),s.end());
            if (unique(s.begin(),s.end())==s.end())
                return false;
            return true;
        }
        return false;
    }
};