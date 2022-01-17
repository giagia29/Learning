import java.util.Scanner;
public class CountSeconds {

    
    public static void main(String[] args) {
        System.out.print("Please specify the number of seconds (between 1 and 86400): ");
        Scanner a = new Scanner(System.in);
        int n = a.nextInt();
        int hours;
        int min;
        int second;
        int first_remainder;
        if (1 < n && n <= 86400)
        {
            hours = n / 3600;
            first_remainder = n % 3600;
            min = first_remainder / 60;
            second = first_remainder % 60;
            System.out.printf("%d seconds correspond to %d hours, %d minutes, %d seconds.", n, hours, min, second);
        }
        else System.out.print("The number of second must be between 1 and 86400.");
    
    }
}
