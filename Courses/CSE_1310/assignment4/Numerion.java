import java.util.Scanner;
public class Numerion {

    
    public static void main(String[] args) {
        boolean check = false;
       System.out.print("Please enter a number: ");
       Scanner number = new Scanner(System.in);
       int x = number.nextInt();
       for (int i = 1; i < x; i++)
       {
           if (x == (i*i+i))
           {
               check = true;
               break;
           }
           else check = false;
       }
       if (check == true) 
       {
           System.out.printf("%d is a holy number in Numerion. \n",x);
           System.out.print("Exiting...");
       }
       else 
       {
           System.out.printf("%d is not a holy number in Numerion.\n", x);
           System.out.print("Exiting...");
       }
    }
    
}
