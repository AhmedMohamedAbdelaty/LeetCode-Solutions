class Solution {
    public boolean isHappy(int n) {
        boolean ans = false;
        HashMap<Integer, Integer> map = new HashMap<>();
        while (n != 1) {
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
            if (map.containsKey(n)) {
                ans = false;
                break;
            }
            map.put(n, 1);
        }
        if (n == 1) {
            ans = true;
        }
        return ans;
    }
}