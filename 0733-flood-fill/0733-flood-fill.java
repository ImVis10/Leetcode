class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        
        if (initColor == color) { // if starting pixel is already colored with 'color', no changes are needed to the image.
            return image;
        }
        
        image[sr][sc] = color;
        
        return dfs(image, sr, sc, initColor);
    }
    
    private int[][] dfs(int [][] image, int sr, int sc, int initColor) {
        int [][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < dir.length; i++) {
            int moveToRow = sr + dir[i][0];
            int moveToCol = sc + dir[i][1];
            
            if (moveToRow >= 0 && moveToRow < image.length && moveToCol >=0 && moveToCol < image[0].length) {
                if (image[moveToRow][moveToCol] == initColor) {
                    image[moveToRow][moveToCol] = image[sr][sc];
                    image = dfs(image, moveToRow, moveToCol, initColor);
                }
            }
        }
        return image;
    }
}