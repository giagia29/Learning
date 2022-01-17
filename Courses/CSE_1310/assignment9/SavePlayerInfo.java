import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;
public class SavePlayerInfo
{
    public static void savePlayerInfo(String[][] data, String player, String output_name)
    {
      File open = new File(output_name);
      PrintWriter out;
      try{
          out = new PrintWriter(open);
      }
      catch(Exception e)
      {
          return;
      }
      ArrayList<String> result = new ArrayList<>();
      if (data == null)
      {
          out.print("No data has been loaded. \n");
      }
      else{
      String x = player.toLowerCase();
      int i = 1;
      while(i < data.length)
      {
          try{
            String t = data[i][0].toLowerCase();
            if (t.contains(x))
            {
              for (int j = 0; j < data[i].length; j++)
              {
                 out.printf("%21s: %s\n", data[0][j], data[i][j]);
              }
              out.print("\n");
            }
          }
          catch(Exception e)
          {
              out.print("\n");
              i = i + 1;
          }
          i = i + 1;
      }
      }
      out.close();
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
  
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        while (true)
        {
            System.out.printf("\nEnter the name of a file to read: ");
            String input_name = in.next();
            System.out.printf("\nEnter the name of the output file: ");
            String output_name = in.next();
            String[][] data = readSpreadsheet(input_name);
            System.out.printf("\nEnter part of a player's name (or q to quit): ");
            String player = in.next();
            if (player.equals("q"))
            {
                System.out.printf("Exiting...\n");
                System.exit(0);
            }
            savePlayerInfo(data, player, output_name);
        }
    }
}