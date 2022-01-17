import java.util.Scanner;
public class CountMultiples {

   
    public static void main(String[] args) {
        int count = 0;
        System.out.print("Enter an integer M: ");
        Scanner first = new Scanner(System.in);
        int m = first.nextInt();
        System.out.print("Enter an integer N: ");
        Scanner second = new Scanner(System.in);
        int n = second.nextInt();
        for (int i = m; i <= n; i++)
        {
            if (i % 11 == 0) count = count + 1;
        }
        if (count > 0) 
        {
            System.out.printf("%d numbers between %d and %d are multiples of 11.",count,m,n);
            System.out.print("Exiting...\n");
        }
        if (m > n || m < 0 || n < 0)
        {
            System.out.printf("0 numbers between %d and %d are multiples of 11. \n",m,n);
            System.out.print("Exiting...\n");
            System.exit(0);
        }
    }
    
}
