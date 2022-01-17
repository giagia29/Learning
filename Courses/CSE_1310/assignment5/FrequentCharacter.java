import java.util.Scanner;
public class FrequentCharacter {

    public static int countOccurrences(String x, char y)
    {
        int count = 0;
        for (int i = 0; i < x.length(); i++)
        {
            if (x.charAt(i) == y) count = count + 1;
        }
        return count;
    }
    public static char mostFrequentCharacter (String x)
    {
        int max = countOccurrences(x, x.charAt(0));
        char max_char = '0';
        for (int i = 1; i < x.length(); i++)
        {
            int sum = 0;
            sum = countOccurrences(x, x.charAt(i));
            if (max <= sum)
            {
                max_char = x.charAt(i);
            }
        }
        return max_char;
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
                break;
            }
            if (text.length() == 0)
            {
                break;
            }
            char c = mostFrequentCharacter(text);
            int number = countOccurrences(text, c);
            System.out.printf("Most frequent character: '%c'\n", c);
            System.out.printf("Number of occurrences of '%c': %d\n\n", c, number);
        }
        System.out.printf("Exiting...\n");
    }
    
}
