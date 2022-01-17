import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;
import java.io.PrintWriter;
public class CheckPrimes {

    public static void checkPrimes(String in_file, String out_file)
    {
        File open = new File(in_file);
        Scanner input;
        try{
            input = new Scanner(open);
        }
        catch(Exception e)
        {
            System.out.print("Error in opening file for reading. \n");
            return;
        }
        
        File close = new File(out_file);
        PrintWriter out = null;
        try{
            out = new PrintWriter(close);
        }
        catch (Exception e){
            System.out.print("Error in opening file for writing. \n");
            return;
        }
        int t = 0;
        ArrayList<Integer> result = new ArrayList<>();
        boolean check = true;
        while (input.hasNextLine())
        {
            String x = input.nextLine();
            try{
                t = Integer.parseInt(x);
            }
            catch(Exception e)
            {
                System.out.print("cannot convert.");
                continue;
            }
            if (t != 2)
            {
                for (int i = 2; i <= Math.sqrt(t); i++)
                {
                    if (t % i == 0)
                    {
                        check = false;
                        break;
                    }
                    else check = true;
                }
                if (check == true) out.printf("%d is prime \r\n", t);
                else out.printf("%d is not prime \r\n", t);
            }
            else 
            {
                out.printf("%d is prime \r\n", t);
            }
        }
        input.close();
        out.close();
        
    }
    public static void main(String[] args) {
        checkPrimes("in4.txt", "out4.txt");
        System.out.printf("Exiting...\n");
    }
    
}
