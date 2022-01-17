import java.util.Scanner;
public class CountWords 
{

    public static int countWords(String text)
    {
        int counter = 0;
        if (text.compareTo(" ") == 0) return 0;
        for (int i = 0; i < text.length(); i++)
        {
            if ((text.charAt(i) == ' ') && (text.charAt(i) != text.charAt(i+1)))
            {
                counter = counter + 1;
            }    
        }
        counter = counter + 1;
        return counter;
    }
    
    
    public static void main(String[] args) 
    {
       Scanner in = new Scanner(System.in);
       while (true)
      {   
          System.out.printf("Enter some text, or q to quit: ");
          String text = in.nextLine();
          if (text.equals("q"))
          {
            System.out.printf("Exiting...\n");
            break;
          }
          int result = countWords(text);
          System.out.printf("Counted %d words.\n\n", result);
      }
   }
    
}
