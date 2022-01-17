import java.util.Scanner;
public class LastThreeLetters {

    
    public static void main(String[] args) {
       System.out.print("Please enter a string, at least 3 letters long: ");
       Scanner str = new Scanner(System.in);
       String s = str.nextLine();
       String ending = s.substring(s.length() - 3, s.length());
       System.out.printf("The last three letters are %s.\n",ending);
    }
    
}
