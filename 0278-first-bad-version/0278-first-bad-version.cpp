// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n, mid;
        while (l <= r){
            mid = (l + r) / 2;
            bool bad = isBadVersion(mid);
            if (bad) r = mid-1;
            else l = mid + 1;
        }
        return l;
    }
};