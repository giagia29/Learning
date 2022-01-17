import java.util.ArrayList;

public class ListMerge
{
  public static ArrayList<String> listMerge(ArrayList<String> A, ArrayList<String> B)
  {
      int i = 0;
      int j = 0;
      ArrayList<String> result = new ArrayList<>();
      while (i < A.size())
      {
          result.add(A.get(i));
          i = i + 1;
      }
      while (j < B.size())
      {
          result.add(B.get(j));
          j = j + 1;
      }
      return result;
  }
    
  public static void printStringList(String name, ArrayList<String> a)
  {
    System.out.printf("%7s: ", name);
    if (a == null)
    {
      System.out.printf("Null array!\n\n");
      return;
    }
    
    for (int i = 0; i < a.size(); i++)
    {
      System.out.printf("%12s", a.get(i));
    }
    System.out.printf("\n");
  }
  
  public static void main(String[] args)
  {
    ArrayList<String> a = new ArrayList<String>();
    a.add("Chicago");
    a.add("New York");
    a.add("Dallas");
    
    ArrayList<String> b = new ArrayList<String>();
    b.add("Berlin");
    b.add("London");
    b.add("Paris");
    b.add("Rome");
      
    ArrayList<String> result = listMerge(a, b);
    printStringList("a", a);
    printStringList("b", b);
    printStringList("result", result);
  }
}
