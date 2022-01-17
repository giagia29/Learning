import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
import java.io.PrintWriter;
public class phonebook
{
    public static ArrayList<String> readFile()
    {
        File temp = new File("phonebook.txt");
        Scanner input_file;
        try
        {
            input_file = new Scanner(temp);
        }
        catch (Exception e)
        {
            System.out.printf("Failed to open file \n");
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
  
    public static String[][] readPhonebook()
    {
        ArrayList<String> lines = readFile();
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
    
    public static void savePhonebook(String[][] data, String new_name, String new_number)
    {
        PrintWriter out;
        try{
            out = new PrintWriter("phonebook.txt");
            int i = 0;
            while(i < data.length)
            {
                out.printf("%s", data[i][0]);
                out.printf(",");
                out.printf("%s", data[i][1]);
                out.printf("\n");
                i = i + 1;
            }
            out.printf("%s,%s", new_name, new_number);
        }
        catch(Exception e)
        {
            return;
        }
        out.close();
   
    }
    
    public static void searchData(String[][] data)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter part of the name: ");
        String s = in.nextLine();
        String x = s.toLowerCase();
        int i = 0;
        while(i < data.length)
        {
            int j = 0;
            String t = data[i][0].toLowerCase();
            if(t.indexOf(x) != -1)
            {
                System.out.printf("%20s: %s", data[i][j], data[i][j + 1]);
                System.out.print("\n");
            }
            i = i + 1;
        }
    }

    public static String[][] inputNewEntry(String[][] data)
    {
        Scanner in = new Scanner(System.in);
    
        System.out.printf("\nEnter a name: ");
        String name = in.nextLine();
        System.out.printf("\nEnter a number: ");
        String number = in.nextLine();
        savePhonebook(data, name, number);
        data = readPhonebook();
        return data;
    }  
  
    public static void printSpreadsheet(String[][] data)
    {
        int i = 0;
        while(i < data.length)
        {
            System.out.printf("%d: ", i);
            System.out.printf("%20s", data[i][0]);
            System.out.printf(", ");
            System.out.printf("%s", data[i][1]);
            System.out.printf("\n");
            i = i + 1;
        }
    }
    
    public static String[][] processOption(String[][] data, String option)
    {
        if (option.equals("1"))
        {
            printSpreadsheet(data);
        }
        else if (option.equals("2"))
        {
            data = inputNewEntry(data);
        }
        else if (option.equals("3"))
        {
            searchData(data);
        }
        else if (option.equals("q"))
        {
            System.out.printf("Exiting...\n");
            System.exit(0);
        }
        else
        {   
            System.out.printf("Unrecognized option %s.\n", option);
        }
        return data;
    }
  
    public static String askOption()
    {
        Scanner in = new Scanner(System.in);
        System.out.printf("\n1: Print phonebook.\n");
        System.out.printf("2: Input a new entry.\n");
        System.out.printf("3: Search by name.\n");
        System.out.printf("q: Quit program.\n");
        System.out.printf("Please enter an option: ");
        String option = in.next();
        return option;
    }

    public static void main(String[] args)
    {
        String[][] data = readPhonebook();
        printSpreadsheet(data);

        while(true)
        {
            String option = askOption();
            data = processOption(data, option);
        }
    }
  
}
