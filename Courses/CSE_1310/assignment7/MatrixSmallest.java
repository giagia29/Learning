public class MatrixSmallest 
{

    public static double[][] matrixSmallest (double[][] A, double[][] B)
    {
        double[][] result = new double[A.length][A[0].length];
        int i = 0, j = 0, count1 = 0, count2 = 0, t = 0;
        while (j < A[0].length)
        {
            if (A[i][j] < B[i][j])
            {
                result[count1][count2] = A[i][j];
                count2 = count2 + 1;
            }
            else if (A[i][j] > B[i][j])
            {
                result[count1][count2] = B[i][j];
                count2 = count2 + 1;
            }
            j = j + 1;
        }
        i = i + 1;
        count1 = count1 + 1;
        count2 = 0;
        while (t < A[0].length)
        {
            if (A[i][t] < B[i][t])
            {
                result[count1][count2] = A[i][t];
                count2 = count2 + 1;
            }
            else if (A[i][t] > B[i][t])
            {
                result[count1][count2] = B[i][t];
                count2 = count2 + 1;
            }
            t = t + 1;
        }
        return result;
    }    
    
    public static void printDoubleMatrix(String name, double[][] a)
  {
    if (a == null)
    {
      System.out.printf("%s: null\n", name);    
      return;
    }
    System.out.printf("%s:\n", name);    
    for (int i = 0; i < a.length; i++)
    {
      for (int j = 0; j < a[i].length; j++)
      {
        System.out.printf("%7.1f", a[i][j]);
      }
      System.out.printf("\n");
    }
    System.out.printf("\n");
  }
  
  
  public static void main(String[] args)
  {
    double[][] a = { {3.2, 2.1, 5.3},
                     {8.0, 4.9, 5.7} };
    double[][] b = { {1.1, 2.2, 3.3}, 
                     {4.4, 5.5, 6.6} };
      
    double[][] result = matrixSmallest(a, b);
    printDoubleMatrix("a", a);
    printDoubleMatrix("b", b);
    printDoubleMatrix("result", result);
  }
    
}
