class Solution {
    public boolean isMatch(String s, String p) {
        return matchhere(s, p);
    }
    
    public boolean matchhere(String s, String p) {
        if (p.length() == 0 && s.length() == 0) {
            return true;
        }
        if (p.length() >= 2 && p.charAt(1) == '*') {
            return matchstar(p.charAt(0), s, p.substring(2));
        }
        if (s.length() > 0 && p.length() > 0 && (p.charAt(0) == '.' || s.charAt(0) == p.charAt(0))) {
            return matchhere(s.substring(1), p.substring(1));
        }
        return false;
    }
    
    public boolean matchstar(Character c, String s, String p) {
        int k = 0;
        for (; k < s.length() && (c == '.' || s.charAt(k) == c); k++)
            ;
        do {
            if (matchhere(s.substring(k), p)) {
                return true;
            }
        } while (k-- > 0);
        return false;
    }
}