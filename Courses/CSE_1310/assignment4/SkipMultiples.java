import java.util.Scanner;
public class SkipMultiples {

    
    public static void main(String[] args) {
        System.out.print("Enter low: ");
        Scanner low = new Scanner(System.in);
        int x = low.nextInt();
        System.out.print("Enter high: ");
        Scanner high = new Scanner(System.in);
        int y = high.nextInt();
        for (int i = x; i <= y; i++)
        {
            if (i % 4 != 0) System.out.println(i);
        }
        if (x > y)
        {
            System.out.print("no numbers found");
            System.exit(0);
        }
    }
    
}
