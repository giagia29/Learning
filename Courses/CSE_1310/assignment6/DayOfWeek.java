import java.util.Scanner;
public class DayOfWeek
{
    public static int yearDays(int year)
    {
        if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) return 366;
        else return 365;
    }
    
    public static int monthDays(int year, int month)
    {
        if (month == 2)
        {
            if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) return 29;
            else return 28;
        }
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
        return 30;
    }
    
    public static int daysPassed(int year, int month, int day)
    {
        int sum = 0;
        int x = 0;
        for (int i = 1000; i < year; i++)
        {
            sum = sum + yearDays(i);
        }
        for (int t = 1; t < month; t++)
        {
            x = x + monthDays(year, t);
        }
        return x + sum + day;
    }
    
    public static String dayOfWeek(int year, int month, int day)
    {
        int remainder = 0;
        remainder = daysPassed(year, month, day) % 7;
        if (remainder == 0)
        {
            return "Tuesday";
        }
        else if (remainder == 1)
        {
            return "Wednesday";
        }
        else if (remainder == 2)
        {
            return "Thursday";
        }
        else if (remainder == 3)
        {
            return "Friday";
        }
        else if (remainder == 4)
        {
            return "Saturday";
        }
        else if (remainder == 5)
        {
            return "Sunday";
        }
        else return "Monday";
    }
    
    public static int userInteger(String message)
    {
        Scanner in = new Scanner(System.in);
        int result;
        while (true)
        {
            System.out.printf(message);
            String s = in.next();
            if (s.equals("q"))
            {
               System.out.printf("Exiting...\n");
               System.exit(0);
            }
            try
            {
                result = Integer.parseInt(s);
            } 
            catch (Exception e)
            {
                System.out.printf("%s is not a valid number, try again.\n\n", s);
                continue;
            }
            if (result <= 0)
            {
                System.out.printf("%s is <= 0, try again.\n\n", s);
                continue;
            }
            return result;
        }
    }
  
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        while (true)
        {
            int year = userInteger("Enter a year (must be >= 1000): ");      
            if (year < 1000)
            {
                System.out.printf("Invalid year.\n\n");
                continue;
            }
            int month = userInteger("Enter a month(must be between 1 and 12): ");
            if (month > 12)
            {
                System.out.printf("Invalid month.\n\n");
                continue;
            }
            int day = userInteger("Enter a day: ");
            int result = daysPassed(year, month, day);
            System.out.printf("%d days have passed from 12/31/999 to %d/%d/%d.\n", result, month, day, year);
            String day_name = dayOfWeek(year, month, day);
            System.out.printf("%d/%d/%d is a %s.\n\n", month, day, year, day_name);
        }
    }
}
