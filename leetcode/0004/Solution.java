class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int index1 = 0, index2 = 0, cur = 0, val1 = 0, val2 = 0, val = 0, pre = 0;
        int totalLength = nums1.length + nums2.length;
        int median = totalLength / 2;
        while (index1 < nums1.length || index2 < nums2.length) {
            pre = val;
            if (index1 < nums1.length && index2 < nums2.length) {
                val1 = nums1[index1];
                val2 = nums2[index2];
                if (val1 < val2) {
                    index1++;
                    val = val1;
                } else {
                    index2++;
                    val = val2;
                }
            } else if (index2 < nums2.length) {
                val2 = nums2[index2];
                val = val2;
                index2++;
            } else if (index1 < nums1.length) {
                val1 = nums1[index1];
                val = val1;
                index1++;
            }
            if (median == cur) {
                if (totalLength % 2 == 1) {
                    return val;
                } else {
                    return (pre + val) / 2.0;
                }
            }
            cur++;
        }
        return val;
    }
}