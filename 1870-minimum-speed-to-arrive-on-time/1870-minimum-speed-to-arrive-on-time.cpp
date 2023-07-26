class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int n = dist.size();
        int l = 1, r = 1e7;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            double time = 0;
            for (int i = 0; i < n - 1; i++) {
                time += ceil((double)dist[i] / mid);
            }
            time += (double)dist[n - 1] / mid;
            if (time <= hour) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};