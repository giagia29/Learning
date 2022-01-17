import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
public class CountVowels {

    public static void countVowels(String in_file)
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
        String s = "";
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        while(input.hasNextLine())
        {
            String lines = input.nextLine();
            s = lines.toLowerCase();
            for (int t = 0; t < s.length(); t++)
            {
                if (s.charAt(t) == 'a') a = a + 1;
                if (s.charAt(t) == 'i') i = i + 1;
                if (s.charAt(t) == 'e') e = e + 1;
                if (s.charAt(t) == 'o') o = o + 1;
                if (s.charAt(t) == 'u') u = u + 1;
            }
        }        
        System.out.printf("a: %d times \r\n", a);
        System.out.printf("e: %d times \r\n" , e);
        System.out.printf("i: %d times \r\n", i);
        System.out.printf("o: %d times \r\n", o);
        System.out.printf("u: %d times \r\n", u);
        
        input.close();
    }
    
    public static void main(String[] args) {
           countVowels("in5.txt"); 
    }
    
}
