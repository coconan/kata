import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class RangeList {
    private List<List<Integer>> ranges = new ArrayList<>();

    /**
     * Adds a range to the list
     * @param {Array<number>} range - Array of two integers that specify beginning and end of range.
     */
    public void add(List<Integer> range) {
        if (empty(range)) {
            return;
        }
        List<List<Integer>> newRanges = new ArrayList<>();
        for (int i = 0; i < ranges.size(); i++) {
            if (range == null) {
                newRanges.add(ranges.get(i));
            } else if (less(ranges.get(i), range)) {
                newRanges.add(ranges.get(i));
            } else if (intersect(range, ranges.get(i))) {
                range = union(range, ranges.get(i));
            } else {
                newRanges.add(range);
                newRanges.add(ranges.get(i));
                range = null;
            }
        }
        if (range != null) {
            newRanges.add(range);
        }
        ranges = newRanges;
    }
    
    /**
     * Removes a range from the list
     * @param {Array<number>} range - Array of two integers that specify beginning and end of range.
     */
    public void remove(List<Integer> range) {
        List<List<Integer>> newRanges = new ArrayList<>();
        for (int i = 0; i < ranges.size(); i++) {
            if (intersect(ranges.get(i), range)) {
                List<List<Integer>> diffRanges = diff(ranges.get(i), range);
                if (!empty(diffRanges.get(0))) {
                    newRanges.add(diffRanges.get(0));
                }
                if (!empty(diffRanges.get(1))) {
                    newRanges.add(diffRanges.get(1));
                }
            } else {
                newRanges.add(ranges.get(i));
            }
        }
        ranges = newRanges;
    }
    
    /**
     * Prints out the list of ranges in the range list
     */
    public void print() {
        for (List<Integer> range : ranges) {
            System.out.printf("[%d, %d) ", range.get(0), range.get(1));
        }
        System.out.println();
    }

    private boolean empty(List<Integer> range) {
        return range.get(0) == range.get(1);
    }

    private boolean intersect(List<Integer> range1, List<Integer> range2) {
        if (range1.get(0) < range2.get(0)) {
            return range2.get(0) <= range1.get(1);
        } else {
            return range1.get(0) <= range2.get(1);
        }
    }

    private boolean less(List<Integer> range1, List<Integer> range2) {
        return range1.get(1) < range2.get(0);
    }

    private List<Integer> union(List<Integer> range1, List<Integer> range2) {
        List<Integer> range = new ArrayList<>();
        range.add(Math.min(range1.get(0), range2.get(0)));
        range.add(Math.max(range1.get(1), range2.get(1)));
        return range;
    }

    private List<List<Integer>> diff(List<Integer> range1, List<Integer> range2) {
        List<Integer> lowerRange = new ArrayList<>();
        lowerRange.add(range1.get(0));
        lowerRange.add(Math.max(range1.get(0), range2.get(0)));
        
        List<Integer> upperRange = new ArrayList<>();
        upperRange.add(Math.min(range1.get(1), range2.get(1)));
        upperRange.add(range1.get(1));
    
        List<List<Integer>> diffRanges = new ArrayList<>();
        diffRanges.add(lowerRange);
        diffRanges.add(upperRange);

        return diffRanges;
    }
    
    public static void main(String[] args) {
        RangeList rl = new RangeList();
        rl.add(Arrays.asList(1, 5));
        rl.print(); // Should display: [1, 5)
        rl.add(Arrays.asList(10, 20));
        rl.print(); // Should display: [1, 5) [10, 20)
        rl.add(Arrays.asList(20, 20));
        rl.print(); // Should display: [1, 5) [10, 20)
        rl.add(Arrays.asList(20, 21));
        rl.print(); // Should display: [1, 5) [10, 21)
        rl.add(Arrays.asList(2, 4));
        rl.print(); // Should display: [1, 5) [10, 21)
        rl.add(Arrays.asList(3, 8));
        rl.print(); // Should display: [1, 8) [10, 21)
        rl.remove(Arrays.asList(10, 10));
        rl.print(); // Should display: [1, 8) [10, 21)
        rl.remove(Arrays.asList(10, 11));
        rl.print(); // Should display: [1, 8) [11, 21)
        rl.remove(Arrays.asList(15, 17));
        rl.print(); // Should display: [1, 8) [11, 15) [17, 21)
        rl.remove(Arrays.asList(3, 19));
        rl.print(); // Should display: [1, 3) [19, 21)
    }
}
