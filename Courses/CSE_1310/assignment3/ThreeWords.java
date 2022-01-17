import java.util.Scanner;
public class ThreeWords {
    public static void main(String[] args) {
       System.out.print("Please enter an integer N: ");
       Scanner x = new Scanner(System.in);
       int n = x.nextInt();
       System.out.printf("Please enter a word with at least %d and at most 20 letters: ",n);
       Scanner s = new Scanner(System.in);
       String first = s.next();
       System.out.printf("Please enter a word with at least %d and at most 20 letters: ",n);
       Scanner t = new Scanner(System.in);
       String second = t.next();
       System.out.printf("Please enter a word with at least %d and at most 20 letters: ",n);
       Scanner r = new Scanner(System.in);
       String third = r.next();
       String f = first.substring(0,n);
       String e = second.substring(0,n);
       String i = third.substring(0,n);
       System.out.printf("%20s starts with %s \n", first,f);
       System.out.printf("%20s starts with %s \n", second,e);
       System.out.printf("%20s starts with %s \n", third,i);
       
    }
}
