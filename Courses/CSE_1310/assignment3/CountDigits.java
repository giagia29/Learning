import java.util.Scanner;
public class CountDigits {

     public static void main(String[] args) {
        System.out.print("Please enter an integer: ");
        Scanner d = new Scanner(System.in);
        int x = d.nextInt();
        int t, count = 0;
        int n = x;
        if (x < 0) System.out.printf("%d is negative.",x);
        if (x == 0) System.out.printf("%d has one digit.",x);
        if (x > 0 && x < 1000000)
        {
            while (x >= 1)
            {
              t = x % 10;
              x = x / 10;
              count = count + 1;
            }
            System.out.printf("%d has %d digits", n, count);
        }
        else if (x > 1000000) System.out.printf("%d has more than six digits.",x);
    }
    
}
