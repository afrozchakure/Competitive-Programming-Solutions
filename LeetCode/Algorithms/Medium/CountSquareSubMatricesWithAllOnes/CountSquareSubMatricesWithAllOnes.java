class CountSquareSubMatricesWithAllOnes {
    public int countSquares(int[][] matrix) {
        //Find no of rows and columns
        int rows=matrix.length;
        int cols=matrix[0].length;

        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j]+=Math.min(matrix[i-1][j],Math.min(matrix[i][j-1],matrix[i-1][j-1]));
                }
            }
        }

        //Number of squares possible
        int total=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                total+=matrix[i][j];
            }
        }
        return total;
    }
}
