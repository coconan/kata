class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<String> set = new HashSet<>();
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i+1; j < nums.length; j++) {
                int index = Arrays.binarySearch(nums, j + 1, nums.length, -(nums[i] + nums[j]));
                if (index >= 0 && index > j) {
                    List<Integer> triplet = new ArrayList<>();
                    triplet.add(nums[i]);
                    triplet.add(nums[j]);
                    triplet.add(nums[index]);
                    String s = "" + nums[i] + nums[j] + nums[index];
                    if (!set.contains(s)) {
                        result.add(triplet);
                        set.add(s);    
                    }
                }
            }
        }
        return result;
    }
}