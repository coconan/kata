class Solution {
    public boolean canJump(int[] nums) {
        boolean[] reachables = new boolean[nums.length];
        reachables[0] = true;
        for (int i = 0; i < nums.length; i++) {
            if (reachables[i] == false) {
                continue;
            }
            for (int j = 0; j <= nums[i];j ++) {
                if (j + i < nums.length) {
                    reachables[j+i] = true;
                }
            }
        }
        return reachables[nums.length-1];
    }
}

class Solution {
    public boolean canJump(int[] nums) {
        boolean[] reachables = new boolean[nums.length];
        reachables[0] = true;
        for (int i = 0; i < nums.length; i++) {
            if (reachables[i] == false) {
                continue;
            }
            for (int j = 0; j <= nums[i];j ++) {
                if (j + i < nums.length) {
                    reachables[j+i] = true;
                }
                if (reachables[nums.length-1]) {
                    return true;
                }
            }
        }
        return reachables[nums.length-1];
    }
}

class Solution {
    public boolean canJump(int[] nums) {
        boolean[] reachables = new boolean[nums.length];
        reachables[0] = true;
        for (int i = 0; i < nums.length; i++) {
            if (reachables[i] == false) {
                continue;
            }
            if (i > 0 && nums[i] < nums[i-1]) {
                continue;
            }
            for (int j = 0; j <= nums[i];j++) {
                if (j + i < nums.length) {
                    reachables[j+i] = true;
                }
                if (reachables[nums.length-1]) {
                    return true;
                }
            }
        }
        return reachables[nums.length-1];
    }
}

class Solution {
    public boolean canJump(int[] nums) {
        int maxReachable = 0;
        for (int i = 0; i < nums.length; i++) {
            if (maxReachable >= i) {
                maxReachable = Math.max(maxReachable, i + nums[i]);
            } else {
                return false;
            }
        }
        return maxReachable >= nums.length-1;
    }
}

class Solution {
    public boolean canJump(int[] nums) {
        int maxReachable = 0;
        for (int i = 0; i < nums.length; i++) {
            if (maxReachable >= nums.length - 1) {
                return true;
            }
            if (maxReachable >= i) {
                maxReachable = Math.max(maxReachable, i + nums[i]);
            } else {
                return false;
            }
        }
        return maxReachable >= nums.length-1;
    }
}