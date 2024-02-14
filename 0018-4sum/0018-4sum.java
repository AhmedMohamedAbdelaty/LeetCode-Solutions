class Solution {
	public List<List<Integer>> fourSum(int[] nums, int target)
	{
		List<List<Integer>> result = new ArrayList<>();
		List<Integer> numList = new ArrayList<>();
		for (int num : nums) {
			numList.add(num);
		}
		int n = nums.length;
		Collections.sort(numList);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long sum = numList.get(i) + numList.get(j);
				sum = target - sum;
				int l = j + 1, r = n - 1;
				long currSum = 0;
				while (l < r) {
					currSum = numList.get(l) + numList.get(r);
					if (currSum == sum) {
						List<Integer> list = new ArrayList<>();
						list.add(numList.get(i));
						list.add(numList.get(j));
						list.add(numList.get(l));
						list.add(numList.get(r));
						if (!result.contains(list)) {
							result.add(list);
						}
						while (l < r && numList.get(l) == list.get(2)) {
							l++;
						}
						while (l < r && numList.get(r) == list.get(3)) {
							r--;
						}
					} else
					if (currSum > sum) {
						r--;
					} else {
						l++;
					}
				}
			}
		}
		return result;
	}
}