class Solution {
    public int countNicePairs(int[] nums) {
        int[] revs = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            revs[i] = rev(nums[i]);
        }
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + revs[j] == nums[j] + revs[i]) {
                    count = (count + 1) % (1000000000 + 7);
                }
            }
        }
        return count;
    }

    public int rev(int n) {
        int r = 0;
        while (n > 0) {
            r = r * 10 + n % 10;
            n = n / 10;
        }

        return r;
    }
}