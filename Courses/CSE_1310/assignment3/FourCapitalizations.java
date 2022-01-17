import java.util.Scanner;
public class FourCapitalizations {

    public static void main(String[] args) {
        System.out.print("Please enter a string: ");
        Scanner str = new Scanner(System.in);
        String s = str.next();
        int temp;
        String second = s.toUpperCase();
        String third = s.toLowerCase();
        String fourth = (s.substring(1,s.length())).toLowerCase();
        char c = s.charAt(0);
        int C = (int) c - 32;
        char x = (char) C;
        System.out.printf("1st version: %s \n", s);
        System.out.printf("2nd version: %s \n", second);
        System.out.printf("3rd version: %s \n", third);
        System.out.printf("4th version: %c%s \n", x, fourth);
       
        
        
        
    }
    
}
