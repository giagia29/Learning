import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
public class GetMonth
{
    public static int getMonth(String date)
    {
        int x = 0;
        String[] num = date.split(" ");
        try{
           x = Integer.parseInt(num[1].split("/")[0]);
        }
        catch(Exception e)
        {
            return 0;
        }
        return x;
    }
    
    public static ArrayList<String> readFile(String filename)
    {
        ArrayList<String> result = new ArrayList<>();
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
        
        while(input_file.hasNextLine())
        {
           String line = input_file.nextLine();
           result.add(line);
        }
    
        input_file.close();
        return result;
    } 
    
    public static void printMonths(String filename)
    {
        ArrayList<String> lines = readFile(filename);
        if (lines == null)
        {
            return;
        }
        for (int i = 1; i < lines.size(); i++)
        {    
            String line = lines.get(i);
            String[] columns = line.split(",");
            String date = columns[0];
            int line_month = getMonth(columns[0]);
            System.out.printf("row %d, month = %d\n", i, line_month);
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
      printMonths(filename);
      System.out.printf("\n");
    }
  }
}