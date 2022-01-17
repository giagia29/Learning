import java.util.Scanner;
public class WordStart {

    public static void main(String[] args) {
        System.out.print("Please enter a word: ");
        Scanner str = new Scanner(System.in);
        String s = str.next();
        char c = s.charAt(0);
        int temp = (int) c;
        if ((temp >= 0 && temp < 65) || (temp > 90 && temp < 97) || (temp > 122 && temp < 128)) 
        System.out.printf("%s starts with neither a vowel nor a consonant.",s);
        else
        {
            switch(c)
            {
                case 'A':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'a':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'E':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'e':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'I':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'i':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'O':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'o':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'U':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                case 'u':
                    System.out.printf("%s starts with a vowel.",s);
                    break;
                default:
                    System.out.printf("%s starts with a consonant.",s);
            }
        }
    }
}
