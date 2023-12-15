class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0, st = newInterval[0], en = newInterval[1];
        while (i < n && st > intervals[i][1]) {
            ans.push_back(intervals[i]);
            i++;
        }
        // merge the overlapping intervals
        while (i < n && en >= intervals[i][0]) {
            st = min(st, intervals[i][0]);
            en = max(en, intervals[i][1]);
            i++;
        }
        // push the merged interval
        ans.push_back({ st, en });
        // push the remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};