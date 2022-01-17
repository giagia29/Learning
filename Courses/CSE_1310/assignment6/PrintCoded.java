import java.util.Scanner;
public class PrintCoded 
{
    public static void printCoded(String word, String sources, String targets)
    {
        String s = "";
        String x = "";
        String t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < word.length(); i++)
        {
            for (int p = 0; p < t.length(); p++)
            {
                if (word.charAt(i) == t.charAt(p)) x = x + word.charAt(i);
            }
            for (int j = 0; j < sources.length(); j++)
            {
                if (word.charAt(i) == sources.charAt(j))
                {
                    s = s + targets.charAt(j);
                }
            }
        }
        System.out.printf("%s",x + s);
    }
    
    
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        String sources = "abcdefghijklmnopqrstuvwxyz";
        String targets = "bcdefghijklmnopqrstuvwxyza";
        while (true)
        {
            System.out.printf("Enter some word, or q to quit: ");
            String word = in.next();
            if (word.equals("q"))
            {
                System.out.printf("Exiting...\n");
                System.exit(0);
            }
            printCoded(word, sources, targets);
            System.out.printf("\n\n");
        }
    }
    
}
