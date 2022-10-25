class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<String>();
        if (n == 1) {
            result.add("()");
            return result;
        }
        List<String> sub = generateParenthesis(n - 1);
        Set<String> set = new HashSet<>();
        for (int i = 0; i < sub.size(); i++) {
            String s = sub.get(i);
            for (int j = 0; j < s.length(); j++) {
                String next = s.substring(0, j) + "()" + s.substring(j);
                if (!set.contains(next)) {
                    set.add(next);
                    result.add(next);
                }
            }
        }
        return result;
    }
}