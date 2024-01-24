class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        swap(n, m);
        int i = 0, j = 0, k = 0;
        vector<int> temp(n + m);
        while (i < n && j < m) {
            if (nums1[i] < nums2[j])
                temp[k++] = nums1[i++];
            else
                temp[k++] = nums2[j++];
        }
        while (i < n)
            temp[k++] = nums1[i++];
        while (j < m)
            temp[k++] = nums2[j++];
        nums1 = temp;
    }
};