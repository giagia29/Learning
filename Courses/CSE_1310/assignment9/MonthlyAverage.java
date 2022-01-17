import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;
public class MonthlyAverage
{
    public static double monthlyAverage(String filename, int column, int month)
    {
       String[][] result = readSpreadsheet(filename);
       int x = 0;
       if (result == null)
       {
           return -1;
       }
       if (column >= result[0].length){
           return -1;
       }
       else{
           int i = 1;
           double sum = 0;
           int count = 0;
           while(i < result.length)
           {
               String[] num = result[i][0].split(" ");
               try{
                    x = Integer.parseInt(num[1].split("/")[0]);
                    if (x == month)
                    {
                        sum = sum + Double.parseDouble(result[i][column]);
                        count = count + 1;
                    }
                    i = i + 1;
               }
               catch(Exception e)
               {
                   i = i + 1;
               }
           }
           if (sum == 0) return -1;
           double average = (double) (sum / count);
           return average;
       }
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
  
   public static String columnName(String filename, int column)
    {
        ArrayList<String> lines = read_file(filename);
        if (lines == null)
        {
            return null;
        }
        String[] word = lines.get(0).split(",");
        if ((column >= word.length) || (column < 0))
        {
                return null;
        }
        else
        {
            String x = word[column];
            return x;
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
            String name = columnName(filename, column);
            if (name == null)
            {
                System.out.printf("Failed to extract a valid column name for column %d of %s\n\n",
                          column, filename);
                continue;
            }
            int month = userInteger("Enter a month: ");
            double average = monthlyAverage(filename, column, month);
            if (average == -1.00)
            {
                System.out.printf("In file %s, there is no data for %s for month %d.\n\n",
                          filename, name, month);
            }
            else
            {
                System.out.printf("In file %s, the average %s for month %d is %.2f.\n\n",
                          filename, name, month, average);
            }
        }
    }
}