import java.util.Scanner;
public class DivisibilityTests {

    
    public static void main(String[] args) {
        System.out.print("Please enter an integer: ");
        Scanner number = new Scanner(System.in);
        int x = number.nextInt();
        if (x < 0) System.out.print("The number is negative.");
        else
        {
            if ((x % 2 == 0) && (x % 3 == 0)) System.out.print("the number is even and divisible by 3.");
            if ((x % 2 == 0) && (x % 3 != 0)) System.out.print("the number is even and not divisible by 3.");
            if ((x % 2 != 0) && (x % 3 == 0)) System.out.print("the number is odd and divisible by 3.");
            if ((x % 2 != 0) && (x % 3 != 0)) System.out.print("the number is odd and not divisible by 3.");
        }
    }
    
}
