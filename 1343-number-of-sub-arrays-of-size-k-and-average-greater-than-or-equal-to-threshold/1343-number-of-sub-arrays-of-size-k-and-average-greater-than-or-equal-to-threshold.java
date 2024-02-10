class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold)
    {
        int l = 0, r = k - 1;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int count = 0;
        while (r < arr.length) {
            if (sum / k >= threshold) {
                count++;
            }
            sum -= arr[l];
            l++;
            r++;
            if (r < arr.length) {
                sum += arr[r];
            }
        }
        return count;
    }
}