import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;
public class InsertBeforeLonger {

    public static int findMaximumLength(ArrayList<String> A)
  {
      int x = 0, max = 1;
      if (A.size() == 0) return -1;
      for (int i = 0; i < A.size(); i++)
      {
          if (max < A.get(i).length())
          {
              max = A.get(i).length();
              x = i;
          }
      }
      return x;
  }  
    
    public static void insertBeforeLonger(ArrayList<String> A, String x)
    {
        int t = 0;
        if (A.size() == 0) A.add(x);
        else{
            for (int i = 0; i < A.size(); i++)
            {
                if (A.get(i).length() > x.length())
                {
                    A.add(i, x);
                    break;
                }
                t = findMaximumLength(A);
                if (x.length() > A.get(t).length())
                {
                    A.add(t + 1, x);
                    break;
                }
            }
        }
    }
    
    
    public static ArrayList<String> readFile(String filename)
    {
        
        File temp = new File(filename);
        Scanner input_file;
        try{
            input_file = new Scanner(temp);
        }
        catch(Exception e)
        {
            System.out.printf("Failed to open file %s\n", filename);
            return null;
        }
        
        ArrayList<String> result = new ArrayList<String>();
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
        ArrayList<String> output_list = new ArrayList<String>();
        for (int i = 0; i < input_list.size(); i++)
        {
            String item = input_list.get(i);
            insertBeforeLonger(output_list, item);
            System.out.println(output_list);
        }  
    }
    
}
