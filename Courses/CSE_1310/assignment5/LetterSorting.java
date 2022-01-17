import java.util.Scanner;
public class LetterSorting 
{
    public static String sortLetters(String text)
    {
      String x = "abcdefghijklmnopqrstuvwxyz";
      String result = " ";
      String s = text.toLowerCase();
      for (int i = 0 ; i < x.length(); i++)
      {
          for (int j = 0; j < s.length(); j++)
          {
              if (s.charAt(j) == x.charAt(i)) result = result + s.charAt(j);
          }
      }
      return result;
    }
    
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        while (true)
        {
            System.out.printf("Enter some text, or q to quit: ");
            String text = in.nextLine();
            if (text.toLowerCase().equals("q"))
            {
                System.out.printf("Exiting...\n");
                System.exit(0);
            }
            String result = sortLetters(text);
            System.out.printf("Result: %s.\n\n", result);
        }
    }
    
}
