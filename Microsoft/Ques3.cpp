void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
      for(int i = 0;i<n;i++)  // reverse each row.
        {
            for(int j = 0;j<n/2;j++)
            {
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
   for(int i = 0;i<n;i++)  // matrix transpose
        {
            for(int j = i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]); 
            }
        }
}
