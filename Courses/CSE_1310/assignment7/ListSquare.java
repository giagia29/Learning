import java.util.ArrayList;

public class ListSquare
{
    
  public static ArrayList<Double> listSquare(ArrayList<Double> A)
  {
       ArrayList<Double> result = new ArrayList<>();
       int i = 0;
       while (i < A.size())
       {
           result.add(Math.pow(A.get(i), 2));
           i = i + 1;
       }
       return result;
  }
    
  public static void printDoubleList(String name, ArrayList<Double> a)
  {
    System.out.printf("%20s: ", name);
    if (a == null)
    {
      System.out.printf("Null array!\n\n");
      return;
    }
    
    for (int i = 0; i < a.size(); i++)
    {
      System.out.printf("%7.2f", a.get(i));
    }
    System.out.printf("\n");
  }
    
  public static void main(String[] args)
  {
    ArrayList<Double> a = new ArrayList<Double>();
    a.add(3.2);
    a.add(2.1);  
    a.add(5.3);  
    a.add(8.0);  
    a.add(4.9);  
    a.add(5.7);  

    ArrayList<Double> b = new ArrayList<Double>();
    b.add(1.1);
    b.add(2.2);  
    b.add(3.3);  
    b.add(4.4);  
    b.add(5.5);  
    b.add(6.6);  
      
    ArrayList<Double> result = listSquare(a);
    printDoubleList("a", a);
    printDoubleList("listSquare(a)", result);
    
    result = listSquare(b);
    System.out.printf("\n");
    printDoubleList("b", b);
    printDoubleList("listSquare(b)", result);
  }
}
