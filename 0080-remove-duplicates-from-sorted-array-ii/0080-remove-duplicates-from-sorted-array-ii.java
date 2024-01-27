class Solution {
    // 80. Remove Duplicates from Sorted Array II
    public int removeDuplicates(int[] nums)
    {
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (j < 2 || nums[i] > nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
}