import java.util.Scanner;
public class Middles {

    public static double pickMiddle(double first, double second, double third)
    {
           if ((first == second) && (second == third))
           {
               return second;
           }
           else if ((first == second) && (second != third))
           {
               return first;
           }
           else if ((second == third) && (third != first))
           {
               return second;
           }
           else if ((third == first) && (first != second))
           {
               return third;
           }
           else if ((first < second) && (second < third)) 
           {
               return second;
           }
           else if ((third < first) && (first < second)) 
           {
               return first;
           }
           else if ((first < third) && (third < second)) 
           {
               return third;
           }
           else if ((first > second) && (second < third) && (first < third))
           {
               return first;
           }
           else 
           {
               return second;
           }
    }
    
    public static double userDouble(String message)
    {
        double number;
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
                number = Double.parseDouble(s);
            }
            catch(Exception e)
            {
                System.out.printf("%s is not a valid double.\n", s);
                System.out.print("\n");
                continue;
            }
            return number;
        }
    }
    
    
    
    public static void main(String[] args) {
        while(true)
        {
            double first = userDouble("please enter the first number, or q to quit: ");
            double second = userDouble("please enter the second number, or q to quit: ");
            double third = userDouble("please enter the third number, or q to quit: ");
            double middle = pickMiddle(first,second,third);
            System.out.printf("the middle value is %.1f \n", middle);
            System.out.print("\n");
        }
    }
    
}
