class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int max = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (visited[i][j]) {
                    continue;
                }
                if (grid[i][j] == 0) {
                    continue;
                }
                int size = countArea(grid, visited, i, j, 0);
                if (size > max) {
                    max = size;
                }
            }
        }
        return max;
    }

    private int countArea(int[][] grid, boolean[][] visited, int i, int j, int size) {
        if (0 <= i && i < grid.length && 0 <= j && j < grid[0].length) {
            if (grid[i][j] == 1 && visited[i][j] == false) {
                size += 1;
                visited[i][j] = true;
                size = countArea(grid, visited, i, j-1, size);
                size = countArea(grid, visited, i-1, j, size);
                size = countArea(grid, visited, i, j+1, size);
                size = countArea(grid, visited, i+1, j, size); 
            }
            return size;
        } else {
            return size;
        }
    }
}
