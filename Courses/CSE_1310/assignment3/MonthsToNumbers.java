import java.util.Scanner;
public class MonthsToNumbers {

    
    public static void main(String[] args) {
       System.out.print("Please enter the name of a month: ");
       Scanner month = new Scanner(System.in);
       String m = month.next();
       String x = m.toUpperCase();
       if (x.compareTo("JANUARY") == 0) 
       {
           System.out.print("January is the first month.");
       }
       else if (x.compareTo("FEBRUARY") == 0)
       {
           System.out.print("February is the second month.");
       }
       else if (x.compareTo("MARCH") == 0)
       {
           System.out.print("March is the third month.");
       }
       else if (x.compareTo("APRIL") == 0)
       {
           System.out.print("April is the fourth month.");
       }
       else if (x.compareTo("MAY") == 0)
       {
           System.out.print("May is the fifth month.");
       }
       else if (x.compareTo("JUNE") == 0)
       {
           System.out.print("June is the sixth month.");
       }
       else if (x.compareTo("JULY") == 0)
       {
           System.out.print("July is the seventh month.");
       }
       else if (x.compareTo("AUGUST") == 0)
       {
           System.out.print("August is the eighth month.");
       }
       else if (x.compareTo("SEPTEMBER") == 0)
       {
           System.out.print("September is the ninth month.");
       }
       else if (x.compareTo("OCTOBER") == 0)
       {
           System.out.print("October is the tenth month.");
       }
       else if (x.compareTo("NOVEMBER") == 0)
       {
           System.out.print("November is the eleventh month.");
       }
       else if (x.compareTo("DECEMBER") == 0)
       {
           System.out.print("December is the twelveth month.");
       }
       else System.out.printf("Unknown month: %s",m);
       
       
    }        
    
}
