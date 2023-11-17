class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int max = nums[0] + nums[nums.length-1];
        for (int i = 0; i < nums.length / 2; i++) {
            if (nums[i] + nums[nums.length-i-1] > max) {
                max = nums[i] + nums[nums.length-i-1];
            }
        }
        
        return max;
    }
}
