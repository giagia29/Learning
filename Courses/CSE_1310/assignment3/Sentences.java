import java.util.Scanner;
public class Sentences {
    
    public static void main(String[] args) {
        System.out.print("Enter the first noun: ");
        Scanner f = new Scanner(System.in);
        String first_noun = f.nextLine();
        System.out.print("Enter the second noun: ");
        Scanner s = new Scanner(System.in);
        String second_noun = s.nextLine();
        System.out.print("Enter a verb: ");
        Scanner v = new Scanner(System.in);
        String verb = v.nextLine();
        System.out.printf("The %s %s over the %s", first_noun, verb, second_noun);
    }
    
}
