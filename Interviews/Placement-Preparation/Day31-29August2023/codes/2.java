public class LC36 {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            boolean[] row = new boolean[10];
            boolean[] column = new boolean[10];
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && row[((int) board[i][j] - 48)]) return false;
                if (board[j][i] != '.' && column[((int) board[j][i] - 48)]) return false;
                if (board[i][j] != '.') row[((int) board[i][j] - 48)] = true;
                if (board[j][i] != '.') column[((int) board[j][i] - 48)] = true;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                boolean[] check = new boolean[10];
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] == '.') continue;
                        if (check[((int) board[k][l] - 48)]) return false;
                        check[((int) board[k][l] - 48)] = true;
                    }
                }
            }
        }

        return true;
    }
}