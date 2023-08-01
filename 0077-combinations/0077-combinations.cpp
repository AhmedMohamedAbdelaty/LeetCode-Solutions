class Solution {
    vector<vector<int>> ans;

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        vector<int> aux;
        solve(v, aux, 0, k);
        return ans;
    }
    void solve(vector<int>& v, vector<int>& aux, int idx, int k)
    {
        if (aux.size() == k) {
            ans.push_back(aux);
            return;
        }
        if (idx == v.size())
            return;
        aux.push_back(v[idx]);
        solve(v, aux, idx + 1, k);
        aux.pop_back();
        solve(v, aux, idx + 1, k);
    }
};