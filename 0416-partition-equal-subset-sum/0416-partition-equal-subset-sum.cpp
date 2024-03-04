class Solution {
public:
	bool canPartition(vector<int>& nums)
	{
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += nums[i];
		int remainingSum = sum;
		vector<vector<int>> memo(n, vector<int>(remainingSum + 1, -1));
		return solve(nums, 0, 0, remainingSum, memo);
	}
	bool solve(vector<int>& nums, int i, int currSum, int remainingSum, vector<vector<int>>& memo)
	{
		if (currSum == remainingSum)
			return true;
		if (i == (int)nums.size())
			return false;
		if (currSum > remainingSum)
			return false;
		if (memo[i][currSum] != -1)
			return memo[i][currSum];
		bool result = solve(nums, i + 1, currSum + nums[i], remainingSum - nums[i], memo) || solve(nums, i + 1, currSum, remainingSum, memo);
		memo[i][currSum] = result;
		return result;
	}
};