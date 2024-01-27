class Solution {
    // remove duplicates from sorted array I
    public int removeDuplicates(int[] nums)
    {
        int i = 0, j = 1;
        while (j < nums.length) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
                j++;
            } else {
                while (j < nums.length && nums[i] == nums[j]) {
                    j++;
                }
               
                // swap
                if (j < nums.length) {
                    int temp = nums[i + 1];
                    nums[i + 1] = nums[j];
                    nums[j] = temp;
                    i++;
                }
                
                j++;
            }
        }
        return i + 1;
    }
}