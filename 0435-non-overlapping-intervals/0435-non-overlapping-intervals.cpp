class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size();
        int ans = 0;
        int last = -1e9;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] >= last) {
                last = intervals[i][1];
            } else {
                ans++;
            }
        }
        return ans;
    }
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
};