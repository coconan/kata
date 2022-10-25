class Solution {
    public String longestCommonPrefix(String[] strs) {
        String result = null;
        for (int i = 0; i < strs.length; i++) {
            if (result == null) {
                result = strs[i];
                continue;
            }
            if (result == "" || strs[i] == "") {
                return "";
            }
            StringBuilder temp = new StringBuilder();
            for (int j = 0; j < strs[i].length() && j < result.length(); j++) {
                if (strs[i].charAt(j) != result.charAt(j)) {
                    break;
                } else {
                    temp.append(result.charAt(j));
                }
            }
            result = temp.toString();
        }
        return result;
    }
}