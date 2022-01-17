import java.util.Scanner;
public class LeapYear {

    public static boolean isLeapyear(int x)
    {
      if ((x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0))) return true;
      else return false;
    }
    public static int userInteger(String message)
    {
        int result;
        Scanner in = new Scanner(System.in);
        while (true)
        {
            System.out.printf(message);
            String s = in.next();
            if (s.toLowerCase().equals("q"))
            {
                System.out.print("Exiting...\n");
                System.exit(0);
            }
            try{
                result = Integer.parseInt(s);
            }
            catch(Exception e)
            {
                System.out.printf("%s is not a valid integer.\n\n", s);
                continue;
            }
            if (result < 0 || result == 0)
            {
                System.out.printf("%s is not >= 1.\n\n", s);
                continue;
            }
            return result;
        }
    }
    
    public static void main(String[] args) 
    {
        while (true)
        {
            int year = userInteger("Please enter a year >= 1, or q to quit: ");
            boolean result = isLeapyear(year);
            if (result == true) 
            {
                System.out.printf("Yes, %d is a leap year.\n\n", year);
            }
            else 
            {
                System.out.printf("No, %d is not a leap year.\n\n",year);
            }
        }
    }
    
}
