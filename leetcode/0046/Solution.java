class Solution {
    public List<List<Integer>> permute(int[] nums) {
        return permuteRecursive(nums, 0);
    }

    private List<List<Integer>> permuteRecursive(int[] nums, int start) {
        if (start == nums.length-1) {
            List<List<Integer>> result = new ArrayList<>();
            List<Integer> l = new ArrayList<>();
            l.add(nums[start]);
            result.add(l);
            return result;
        }

        List<List<Integer>> result = new ArrayList<>();
        List<List<Integer>> sub = permuteRecursive(nums, start+1);
        for (int i = 0; i < sub.size(); i++) {
            for (int j = 0; j <= sub.get(i).size(); j++) {
                List<Integer> newL = new ArrayList(sub.get(i));
                if (j == sub.get(i).size()) {
                    newL.add(nums[start]);
                } else {
                    newL.add(j, nums[start]);
                }
                result.add(newL);
            }
        }

        return result;
    }
}
