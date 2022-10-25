class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        Set<String> set = new HashSet<>();
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int l = j + 1, r = nums.length - 1;
                while (l < r) {
                    long sum = (long) nums[i] + (long) nums[j] + (long) nums[l] + (long) nums[r];
                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        String s = "" + nums[i] + nums[j] + nums[l] + nums[r];
                        if (!set.contains(s)) {
                            set.add(s);
                            List<Integer> quadruplet = new ArrayList<>();
                            quadruplet.add(nums[i]);
                            quadruplet.add(nums[j]);
                            quadruplet.add(nums[l]);
                            quadruplet.add(nums[r]);
                            result.add(quadruplet);
                        }
                        l++;
                        r--;
                    }
                }
            }
        }
        return result;
    }
}