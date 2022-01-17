import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;
public class ColumnSum
{
    public static ArrayList<String> read_file(String filename)
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
   
   public static String[][] readSpreadsheet(String filename)
    {
        ArrayList<String> lines = read_file(filename);
        if (lines == null) return null;
        int rows = lines.size();
        String[][] result = new String[rows][];
           
        for (int i = 0; i < lines.size(); i++)
        {
            String line = lines.get(i);
            String [] values = line.split(",");
            result[i] = values;
        }
        return result;
    }  
     
    
    public static double columnSum(String filename, int column)
    {
       double x = 0;
       String[][] result = readSpreadsheet(filename);
       if (result == null)
       {
           return 0;
       }
       if (column >= result[0].length){
           return 0;
       }
       else{
           int i = 1;
           double sum = 0;
           while(i < result.length)
           {
              try{
                x = Double.parseDouble(result[i][column]);
                 sum = sum + x;
                 i = i + 1;
              }
              catch(Exception e){
                 i = i + 1;
              }
           }
           return sum;
       }
    }
   
    
  public static int userInteger(String message)
  {
    Scanner in = new Scanner(System.in);
    int result;
    while (true)
    {
      System.out.printf(message);
      String s = in.next();
      if (s.equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      
      try
      {
        result = Integer.parseInt(s);
      } 
      catch (Exception e)
      {
        System.out.printf("%s is not a valid number, try again.\n\n", s);
        continue;
      }
      
      return result;
    }
  }  
  
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    while (true)
    {
      System.out.printf("Enter a filename (or q to quit): ");
      String filename = in.next();
      if (filename.equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      int column = userInteger("Enter a column: ");
      
      double sum = columnSum(filename, column);
      System.out.printf("In file %s, column %d has sum %.2f\n\n",
                        filename, column, sum);
    }
  }
}