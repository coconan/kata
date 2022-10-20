class Solution {
    public String longestPalindrome(String s) {
        int maxStart = 0, maxEnd = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; i-j >= 0 && i+j < s.length(); j++) {
                if (s.charAt(i-j) == s.charAt(i+j)) {
                    if (2 * j + 1 > maxEnd - maxStart) {
                        maxStart = i - j;
                        maxEnd = i + j +1;
                    }
                } else {
                    break;
                }
            }
            for (int j = 0; i-1-j >= 0 && i+j < s.length(); j++) {
                if (s.charAt(i-1-j) == s.charAt(i+j)) {
                    if (2 * (j+1) > maxEnd - maxStart) {
                        maxStart = i-1-j;
                        maxEnd = i + j + 1;
                    }
                } else {
                    break;
                }
            }
        }
        return s.substring(maxStart, maxEnd);
    }
}