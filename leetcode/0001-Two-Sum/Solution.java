import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> reverseIndexMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            reverseIndexMap.put(nums[i], i);
        }
        for (int i = 0; i < nums.length; i++) {
            Integer index = reverseIndexMap.get(target - nums[i]);
            if (index != null && index != i) {
                return new int[]{i, index};
            }
        }
        return new int[]{-1, -1};
    }
}