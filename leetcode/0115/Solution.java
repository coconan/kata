class Solution {
    public int numDistinct(String s, String t) {
        int count = 0;
        List<String> ls = comb(s, t.length());
        for (int i = 0; i < ls.size(); i++) {
            if (t.equals(ls.get(i))) {
                count += 1;
            }
        }

        return count;
    }

    private List<String> comb(String s, int n) {
        if (s.length() < n) {
            return new ArrayList<>();
        }
        if (s.length() == 0) {
            return new ArrayList<>();
        }
        if (n == 0) {
            List<String> result = new ArrayList<>();
            result.add("");
            return result;
        }
        if (n == s.length()) {
            List<String> result = new ArrayList<>();
            result.add(s);
            return result;
        }

        List<String> result = comb(s.substring(1), n);
        List<String> sub = comb(s.substring(1), n-1);
        for (int i = 0; i < sub.size(); i++) {
            result.add(s.charAt(0) + sub.get(i));
        }
        return result;
    }
}

class Solution {
    public int numDistinct(String s, String t) {
        int[][] dp = new int[t.length()+1][s.length()+1];
        for (int j = 0; j <= s.length(); j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= t.length(); i++) {
            for (int j = 1; j <= s.length(); j++) {
                if (s.charAt(j-1) == t.charAt(i-1)) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[t.length()][s.length()];
    }
}
