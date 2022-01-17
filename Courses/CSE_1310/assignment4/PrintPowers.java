import java.util.Scanner;
public class PrintPowers {

    
    public static void main(String[] args) {
      System.out.print("Enter a positive integer N > 1: ");
      Scanner number = new Scanner(System.in);
      int x = number.nextInt();
      if (x > 0)
      {
        for (int i = 0; i <= 20; i++)
        {  
          if (Math.pow(x, i) <= 40000) System.out.println((int) Math.pow(x,i));
        }
        System.out.print("Exiting...");
      }
      else System.out.print("Exiting...");
    }
    
}
