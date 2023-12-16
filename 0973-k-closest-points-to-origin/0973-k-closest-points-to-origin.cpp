class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        int n = points.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> p;
        for (int i = 0; i < n; i++) {
            double st = points[i][0], en = points[i][1];
            double dis = sqrt((st * st) + (en * en));
            p.push({ dis, { st, en } });
        }
        vector<vector<int>> ans;
        while (k--) {
            auto top = p.top();
            ans.push_back({ top.second.first, top.second.second });
            p.pop();
        }
        return ans;
    }
};