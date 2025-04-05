class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {
        int m = boxGrid.length;       // number of rows in the original box
        int n = boxGrid[0].length;    // number of columns in the original box

        // Step 1: Simulate gravity for each row
        for (int row = 0; row < m; row++) {
            int empty = n - 1;
            for (int col = n - 1; col >= 0; col--) {
                if (boxGrid[row][col] == '*') {
                    empty = col - 1;
                } else if (boxGrid[row][col] == '#') {
                    if (col != empty) {
                        boxGrid[row][empty] = '#';
                        boxGrid[row][col] = '.';
                    }
                    empty--;
                }
            }
        }

        // Step 2: Rotate 90 degrees clockwise
        char[][] rotated = new char[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return rotated;
    }
}
