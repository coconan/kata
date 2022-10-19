class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> index = new HashMap<>();
        int maxStart = 0, maxEnd = 0, curStart = 0;
        for (int i = 0; i < s.length(); i++) {
            if (index.get(s.charAt(i)) != null) {
                if (i - curStart > maxEnd - maxStart) {
                    maxEnd = i;
                    maxStart = curStart;
                }
                curStart = Math.max(curStart, index.get(s.charAt(i)) + 1);
            }
            index.put(s.charAt(i), i);
        }
        if (s.length() - curStart > maxEnd - maxStart) {
            maxEnd = s.length();
            maxStart = curStart;
        }
        return maxEnd - maxStart;
    }
}