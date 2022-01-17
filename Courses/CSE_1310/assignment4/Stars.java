import java.util.Scanner;
public class Stars {

        public static void main(String[] args) {
        System.out.print("Enter a positive integer N > 0: ");
        Scanner number = new Scanner(System.in);
        int n = number.nextInt();
        String s = "*";
        if (n > 0)
        {
            System.out.printf("%s \n", s);
            for (int i = 1; i <= n - 1; i++)
            {
                s = s + "*";
                System.out.printf("%s \n",s);
            }
            System.out.print("Exiting...");
        }
        else System.out.print("Exiting...");
    }
    
}
