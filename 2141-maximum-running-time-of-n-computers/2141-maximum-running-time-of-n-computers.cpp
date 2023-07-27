class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries)
    {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        priority_queue<long long> pq(batteries.begin(), batteries.end());
        while (pq.top() > sum / n) {
            sum -= pq.top();
            pq.pop();
            --n;
        }
        return sum / n;
    }
};