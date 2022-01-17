public class ArraySquare {

    public static double[] arraySquare(double[] A)
    {
        double[] result = new double[A.length];
        int i = 0;
        int count = 0;
        while (i < A.length)
        {
            result[count] = (double) Math.pow(A[i], 2);
            count = count + 1;
            i = i + 1;
        }
        return result;
    }
    
    
    public static void printDoubleArray(String name, double[] a)
    {
        System.out.printf("%20s: ", name);
        if (a == null)
        {
            System.out.printf("Null array!\n\n");
            return;
        }
        
        for (int i = 0; i < a.length; i++)
        {
            System.out.printf("%7.2f", a[i]);
        }
        System.out.printf("\n");
    }
    
    
    
    public static void main(String[] args) 
    {
        double[] a = {3.2, 2.1, 5.3, 8.0, 4.9, 5.7};
        double[] b = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
        double[] result = arraySquare(a);
        printDoubleArray("a", a);
        printDoubleArray("arraySquare(a)", result);
        
        result = arraySquare(b);
        System.out.printf("\n");
        printDoubleArray("b", b);
        printDoubleArray("arraySquare(b)", result);
    }
    
}
