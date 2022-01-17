import java.util.Scanner;
public class FirstSecondNext {

    
    public static void main(String[] args) {
        System.out.print("Please enter a string, at least 5 letters long: ");
        Scanner str = new Scanner(System.in);
        String s = str.next();
        char first = s.charAt(0);
        char second = s.charAt(1);
        String next = s.substring(2,5);
        System.out.printf("The first letter of s is %c. \n",first);
        System.out.printf("The second letter of s is %c. \n",second);
        System.out.printf("The third, fourth, and fifth letters are %s.",next);
    }
}
