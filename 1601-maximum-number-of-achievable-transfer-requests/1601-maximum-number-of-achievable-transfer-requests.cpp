class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests)
    {
        int m = requests.size();
        int ans = 0;
        for (int mask = 0; mask < (1 << m); mask++) { // loop through all possible combinations of requests
            vector<int> indeg(n), outdeg(n);
            int cnt = 0;
            for (int i = 0; i < m; i++) { // loop through all requests
                if (mask & (1 << i)) { // if the i-th request is included in the current combination
                    int u = requests[i][0], v = requests[i][1]; // get the source and destination vertices of the i-th request
                    outdeg[u]++, indeg[v]++; // increment the outdegree of u and the indegree of v
                    cnt++; // increment the count
                }
            }
            bool ok = true;
            for (int i = 0; i < n; i++) { // loop through all vertices
                if (indeg[i] != outdeg[i]) { // if the indegree and outdegree of the i-th vertex are not equal
                    ok = false;
                    break; 
                }
            }
            if (ok) {
                ans = max(ans, cnt); // update the answer to the maximum of the current answer and the count
            }
        }
        return ans;
    }
};