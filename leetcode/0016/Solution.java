class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int l = i+1, r = nums.length - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (Math.abs(target - sum) < Math.abs(target - result)) {
                    result = sum;
                }
                if (target - sum > 0) {
                    l++;
                } else if (target - sum < 0) {
                    r--;
                } else {
                    return sum;
                }
            }
        }
        return result;
    }
}