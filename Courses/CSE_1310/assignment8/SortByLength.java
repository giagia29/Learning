import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;
public class SortByLength
{
  public static ArrayList<String> sortByLength(ArrayList<String> input_list)
  {
      int t = 0;
      String x = "";
      ArrayList<String> result = new ArrayList<>(input_list.size());
      while(t < input_list.size())
      {
          result.add(input_list.get(t));
          t = t + 1;
      }
      for (int i = 0; i < result.size() - 1; i++)
      {
          for (int j = i + 1; j < result.size(); j++)
          {
              if (result.get(i).length() > result.get(j).length())
              {
                 String a = result.get(j);
                 String b = result.get(i);
                 result.remove(i);
                 result.add(i, a);
                 result.remove(j);
                 result.add(j, b);
              }
          }
      }
      return result;
    }
    
    
  public static ArrayList<String> readFile(String filename)
  {
    File temp = new File(filename);
    Scanner input_file;
    try
    {
      input_file = new Scanner(temp);
    }
    catch (Exception e)
    {
      System.out.printf("Failed to open file %s\n",
                        filename);
      return null;
    }

    ArrayList<String> result = new ArrayList<>();
    while(input_file.hasNextLine())
    {
      String line = input_file.nextLine();
      result.add(line);
    }
    
    input_file.close();
    return result;
  } 

  
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    
    System.out.printf("Please enter the name of the input file: ");
    String filename = in.nextLine();
    ArrayList<String> input_list = readFile(filename);
    if (input_list == null)
    {
      System.out.printf("Exiting...\n");
      System.exit(0);
    }
    
    ArrayList<String> output_list = sortByLength(input_list);
    System.out.printf("Input:  ");
    System.out.println(input_list);
    System.out.printf("Output: ");
    System.out.println(output_list);  
  }
}