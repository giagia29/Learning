public class ArrayMerge
{
  public static String[] arrayMerge(String[] a, String[] b)
  {
     int i = 0;
     int count = 0;
     int j = 0;
     String[] result = new String[a.length + b.length];
     {
         while (i < a.length)
         {
             result[count] = a[i];
             count = count + 1;
             i = i + 1;
         }
         while (j < b.length)
         {
             result[count] =  b[j];
             count = count + 1;
             j = j + 1;
         }
     }
     return result;
  }
    
    
  public static void printStringArray(String name, String[] a)
  {
    System.out.printf("%7s: ", name);
    if (a == null)
    {
      System.out.printf("Null array!\n\n");
      return;
    }
    
    for (int i = 0; i < a.length; i++)
    {
      System.out.printf("%12s", a[i]);
    }
    System.out.printf("\n");
  }
  
  public static void main(String[] args)
  {
    String[] a = {"Chicago", "New York", "Dallas"};
    String[] b = {"Berlin", "London", "Paris", "Rome"};
      
    String[] result = arrayMerge(a, b);
    printStringArray("a", a);
    printStringArray("b", b);
    printStringArray("result", result);
  }
}
