// https://leetcode.com/problems/n-queens/description/
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> solutions = new ArrayList<>();
        int[] board = new int[n];
        int col = 0;
        while (col >= 0) {
            if (valid(board, col)) {
                col += 1;
                if (col == n) {
                    addSolution(solutions, board);
                    col -= 1;
                } else {
                    board[col] = 0;
                    continue;
                }
            }
            board[col] += 1;
            while (col >= 0 && board[col] == n) {
                col -= 1;
                if (col >= 0) {
                    board[col] += 1;
                }
            }
        }

        return solutions;
    }

    private boolean valid(int[] board, int col) {
        for (int i = 0; i < col; i++) {
            if (board[i] == board[col]
             || Math.abs(board[i] - board[col]) == Math.abs(i - col)) {
                 return false;
             }
        }

        return true;
    }

    private void addSolution(List<List<String>> solutions, int[] board) {
        List<String> solution = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < board.length; j++) {
                if (board[i] == j) {
                    s.append("Q");
                } else {
                    s.append(".");
                }
            }
            solution.add(s.toString());
        }
        solutions.add(solution);
    }
}