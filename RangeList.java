/******************************************************************************
 *  Compilation:  javac RangeList.java
 *  Execution:    java RangeList
 *
 *  A range list, implemented using a java standard ArrayList.
 *
 ******************************************************************************/
import java.util.List;
import java.util.ArrayList;

public class RangeList {
    private List<Range> ranges = new ArrayList<>();

    /**
     * Adds a range to the list
     * @param {Array<number>} range - Array of two integers that specify beginning and end of range.
     */
    public void add(int[] rawRange) {
        Range range = new Range(rawRange[0], rawRange[1]);
        if (range.isEmpty()) {
            return;
        }
        
        List<Range> lowerRanges = new ArrayList<>();
        List<Range> higherRanges = new ArrayList<>();
        List<Range> newRanges = new ArrayList<>();
        /**
         * loop invariant:
         *   newRanges[i] is not empty
         *   newRanges[i] lessThan newRanges[i+1]
         *   newRanges[i] disjoint newRanges[i+1]
         */
        for (Range current : ranges) {
            if (range.intersectWith(current)) {
                range = range.union(current);
            } else if (current.lessThan(range)) {
                lowerRanges.add(current);
            } else {
                higherRanges.add(current);
            }
        }
        newRanges.addAll(lowerRanges);
        newRanges.add(range);
        newRanges.addAll(higherRanges);
        ranges = newRanges;
    }
    
    /**
     * Removes a range from the list
     * @param {Array<number>} range - Array of two integers that specify beginning and end of range.
     */
    public void remove(int[] rawRange) {
        Range range = new Range(rawRange[0], rawRange[1]);
        if (range.isEmpty()) {
            return;
        }

        List<Range> newRanges = new ArrayList<>();
        /**
         * loop invariant:
         *   newRanges[i] is not empty
         *   newRanges[i] lessThan newRanges[i+1]
         *   newRanges[i] disjoint newRanges[i+1]
         */
        for (Range current : ranges) {
            if (range.intersectWith(current)) {
                List<Range> diffRanges = current.diff(range);
                if (!diffRanges.get(0).isEmpty()) {
                    newRanges.add(diffRanges.get(0));
                }
                if (!diffRanges.get(1).isEmpty()) {
                    newRanges.add(diffRanges.get(1));
                }
            } else {
                newRanges.add(current);
            }
        }
        ranges = newRanges;
    }
    
    /**
     * Prints out the list of ranges in the range list
     */
    public void print() {
        for (Range range : ranges) {
            System.out.printf("[%d, %d) ", range.lower, range.upper);
        }
        System.out.println();
    }

    /**
     * for test
     * @param rawRangeList
     * @return
     */
    public boolean equalsTo(int[][] rawRangeList) {
        if (ranges.size() != rawRangeList.length) {
            return false;
        }
        for (int i = 0; i < ranges.size(); i++) {
            if (rawRangeList[i][0] != ranges.get(i).lower
                || rawRangeList[i][1] != ranges.get(i).upper) {
                return false;
            }
        }
        return true;
    }

    static class Range {
        int lower;
        int upper;

        /**
         * precondition: lower <= upper
         * @param lower
         * @param upper
         */
        public Range(int lower, int upper) {
            if (lower > upper) {
                throw new RuntimeException("lower bound should be less than or equal to upper bound");
            }
            this.lower = lower;
            this.upper = upper;
        }

        public boolean isEmpty() {
            return lower == upper;
        }
    
        /**
         * all points in this range are less than that range
         * @param that
         * @return
         */
        public boolean lessThan(Range that) {
            return this.upper < that.lower;
        }

        /**
         * this range is overlap with that range
         * @param that
         * @return
         */
        public boolean intersectWith(Range that) {
            return !(this.lessThan(that) || that.lessThan(this));
        }
    
        /**
         * precondition: this range is intersect with that range
         * @param that
         * @return unioned range
         */
        public Range union(Range that) {
            return new Range(Math.min(this.lower, that.lower), Math.max(this.upper, that.upper));
        }
    
        /**
         * remove that range from this range, break into two ranges (maybe empty range)
         * precondition: this range is intersect with that range
         * @param that
         * @return List<Range> diffRanges
         */
        public List<Range> diff(Range that) {
            Range lowerRange = new Range(this.lower, Math.max(this.lower, that.lower));
            Range upperRange = new Range(Math.min(this.upper, that.upper), this.upper);
        
            List<Range> diffRanges = new ArrayList<>();
            diffRanges.add(lowerRange);
            diffRanges.add(upperRange);
    
            return diffRanges;
        }
    }
    
    public static int[] rawRange(int lower, int upper) {
        return new int[]{lower, upper};
    }

    public static int[][] rawRangeList(int[]... rawRangeArray) {
        return rawRangeArray;
    }

    public static void assertCase(String message, boolean condition) {
        if (condition == false) {
            throw new RuntimeException("test case failed for: " + message);
        }
    }

    public static void main(String[] args) {
        RangeList rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.print(); // Should display: [1, 5)
        rl.add(rawRange(10, 20));
        rl.print(); // Should display: [1, 5) [10, 20)
        rl.add(rawRange(20, 20));
        rl.print(); // Should display: [1, 5) [10, 20)
        rl.add(rawRange(20, 21));
        rl.print(); // Should display: [1, 5) [10, 21)
        rl.add(rawRange(2, 4));
        rl.print(); // Should display: [1, 5) [10, 21)
        rl.add(rawRange(3, 8));
        rl.print(); // Should display: [1, 8) [10, 21)
        rl.remove(rawRange(10, 10));
        rl.print(); // Should display: [1, 8) [10, 21)
        rl.remove(rawRange(10, 11));
        rl.print(); // Should display: [1, 8) [11, 21)
        rl.remove(rawRange(15, 17));
        rl.print(); // Should display: [1, 8) [11, 15) [17, 21)
        rl.remove(rawRange(3, 19));
        rl.print(); // Should display: [1, 3) [19, 21)

        rl = new RangeList();
        rl.add(rawRange(0, 0));
        assertCase("add an empty range to empty range list",
            rl.equalsTo(rawRangeList()));

        rl = new RangeList();
        rl.add(rawRange(1, 5));
        assertCase("add a range to empty range list",
            rl.equalsTo(rawRangeList(rawRange(1, 5))));

        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(1, 5));
        assertCase("add a dumplicated range",
            rl.equalsTo(rawRangeList(rawRange(1, 5))));
        
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));
        assertCase("add a disjoint range",
            rl.equalsTo(rawRangeList(rawRange(1, 5), rawRange(15, 20))));
        
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));
        rl.add(rawRange(20, 20));
        assertCase("add an empty range",
            rl.equalsTo(rawRangeList(rawRange(1, 5), rawRange(15, 20))));

        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));
        rl.add(rawRange(13, 15));
        assertCase( "add an lower adjacent range",
            rl.equalsTo(rawRangeList(rawRange(1, 5), rawRange(13, 20))));


        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));
        rl.add(rawRange(20, 21));
        assertCase("add an upper adjacent range",
            rl.equalsTo(rawRangeList(rawRange(1, 5), rawRange(15, 21))));
    
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));
        rl.add(rawRange(2, 4));
        assertCase("add a contained range",
            rl.equalsTo(rawRangeList(rawRange(1, 5), rawRange(15, 20))));
        
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));    
        rl.add(rawRange(3, 8));
        assertCase("add an overlapping range",
            rl.equalsTo(rawRangeList(rawRange(1, 8), rawRange(15, 20))));
        
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));
        rl.add(rawRange(0, 9));
        assertCase("add a extended range",
            rl.equalsTo(rawRangeList(rawRange(0, 9), rawRange(15, 20))));

        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));
        rl.add(rawRange(5, 15));
        assertCase("add a range to join two range into one",
            rl.equalsTo(rawRangeList(rawRange(1, 20))));

        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(15, 20));    
        rl.add(rawRange(30, 35));
        rl.add(rawRange(0, 35));
        assertCase("add a range to contain all ranges into one",
            rl.equalsTo(rawRangeList(rawRange(0, 35))));

        rl = new RangeList();    
        rl.remove(rawRange(0, 0));
        assertCase("remove empty range from empty range list",
            rl.equalsTo(rawRangeList()));
        
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.remove(rawRange(0, 0));
        rl.remove(rawRange(3, 3));
        rl.remove(rawRange(20, 20));
        assertCase("remove empty range lower, overlapping, upper",
            rl.equalsTo(rawRangeList(rawRange(1, 5))));

        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.remove(rawRange(1, 5));
        assertCase("remove the only one range",
            rl.equalsTo(rawRangeList()));
    
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.remove(rawRange(0, 3));
        assertCase("remove overlapping range lower",
            rl.equalsTo(rawRangeList(rawRange(3, 5))));
        
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.remove(rawRange(4, 5));
        assertCase("remove overlapping range upper",
            rl.equalsTo(rawRangeList(rawRange(1, 4))));
    
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.remove(rawRange(2, 4));
        assertCase("remove overlapping range contained",
            rl.equalsTo(rawRangeList(rawRange(1, 2), rawRange(4, 5))));
    
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(7, 10));
        rl.remove(rawRange(4, 9));
        assertCase("remove a range overlapping with two ranges",
            rl.equalsTo(rawRangeList(rawRange(1, 4), rawRange(9, 10))));
    
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(7, 10));
        rl.add(rawRange(10, 15));
        rl.remove(rawRange(0, 20));
        assertCase("remove a range contains all ranges",
            rl.equalsTo(rawRangeList()));
    
        rl = new RangeList();
        rl.add(rawRange(1, 5));
        rl.add(rawRange(10, 20));
        rl.add(rawRange(20, 20));
        rl.add(rawRange(20, 21));
        rl.add(rawRange(2, 4));
        rl.add(rawRange(3, 8));
        rl.remove(rawRange(10, 10));
        rl.remove(rawRange(10, 11));
        rl.remove(rawRange(15, 17));
        rl.remove(rawRange(3, 19));
        assertCase("sanity check",
            rl.equalsTo(rawRangeList(rawRange(1, 3), rawRange(19, 21))));
    }
}
