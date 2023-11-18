class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int maxFreq = 1;
        for (int i = 0; i < nums.length; i++) {
            if (i + 1 < nums.length && nums[i] == nums[i+1]) {
                continue;
            }
            int r = k;
            int j = i - 1;
            while (r >= 0 && j >= 0) {
                r -= nums[i]-nums[j];
                if (r < 0) {
                    break;
                }
                j--;
                if (i - j > maxFreq) {
                    maxFreq = i - j;
                }
            }
        }

        return maxFreq;
    }
}
