import java.io.File;
import java.util.Scanner;
public class SumIntegers
{
  public static int sumIntegers(String filename)
  {
      File open = new File(filename);
      Scanner input;
      try{
          input = new Scanner(open);
      }
      catch(Exception e)
      {
          return 0;
      }
      int t = 0, sum = 0;
      while(input.hasNextLine())
      {
          String x = input.nextLine();
          try{
              t = Integer.parseInt(x);
          }
          catch(Exception e)
          {
              continue;
          }
          sum = sum + t;
      }
      input.close();
      return sum;
  }
  
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    System.out.printf("Please enter the name of the input file: ");  
    String filename = in.nextLine();
 
    int result = sumIntegers(filename);
    System.out.printf("result = %d.\n", result);
  }
}
