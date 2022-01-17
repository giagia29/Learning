import java.util.Scanner;
public class Binary {
    
    public static int findOperatorPosition(String text)
    {
        int count = 0;
        for (int i = 0; i < text.length(); i++)
        {
            if ((text.charAt(i) == '+') || (text.charAt(i) == '-'))
            {
                count = i;
            }
        }
        return count;
    }
    public static char findOperatorSymbol(String text)
    {
        char c = ' ';
        for (int i = 0; i < text.length(); i++)
        {
            if ((text.charAt(i) == '+') || (text.charAt(i) == '-'))
            {
                c = text.charAt(i);
            }
        }
        return c;
    }
    
    public static String getFirstNumber(String text)
    {
        String s = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (((text.charAt(i) == '+') || (text.charAt(i) == '-')) && (checkValid(text)))
            {
                s = text.substring(0, i);
                break;
            }
        }
        return s;
    }
     
    public static String getSecondNumber(String text)
    {
        String x = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (((text.charAt(i) == '+') || (text.charAt(i) == '-')) && (checkValid(text)))
            {
                x = text.substring(i + 1, text.length());
                break;
            }
        }
        return x;
    }
    
    public static String computeBinaryOperation(String text)
    {
        String result = "";
        int x = binaryToDecimal(getFirstNumber(text));
        int y = binaryToDecimal(getSecondNumber(text));
        if (findOperatorSymbol(text) == '+') result = decimalToBinary(x + y);
        if (findOperatorSymbol(text) == '-') result = decimalToBinary(x - y);
        return result;
    }
    
    public static String decimalToBinary(int number)
    {
        String start = "";
        if (number < 0)
        {
            start = "-";
            number = -number;
        }
        String result = "";
        while(true)
        {
            int remainder = number % 2;
            String digit = Integer.toString(remainder);
            result = digit + result;
            number = number / 2;
            if (number == 0)
            {
                break;
            }
        }
        result = start + result;
        return result;
    }

    
    public static boolean checkValid(String text)
    {
        if (text.length() == 0)
        {
            return false;
        }
        int counter = 0; 
        for (int i = 0; i < text.length(); i++)
        {
            char c = text.charAt(i);
            if ("01+-".indexOf(c) < 0)
            {
                return false;
            }      
            if ("+-".indexOf(c) >= 0)
            {
                counter++;
            }
        }
        if (counter != 1)
        {
            return false;
        }
        char start = text.charAt(0);
        char end = text.charAt(text.length() - 1);
        if ("01".indexOf(start) < 0)
        {
            return false;
        }
        if ("01".indexOf(end) < 0)
        {
            return false;
        }
        return true;
    }

    public static int binaryToDecimal(String text)
    {
        int sign = 1;
        if (text.charAt(0) == '-')
        {
            sign = -1;
            text = text.substring(1);
        }
        int result = 0;
        String digits = "01";
        for (int i = 0; i < text.length(); i++)
        {
            String c = text.substring(i, i+1);
            int digit = digits.indexOf(c);
            if (digit == -1)
            {
                System.out.printf("Error: invalid binary number %s, exiting...\n", text);
                System.exit(0);
            }
            int power = (int) (Math.pow(2, text.length() - i - 1));
            result = result + digit * power;
        }
        result = sign * result;
        return result;
    }
    
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        while (true)
        {
            System.out.printf("Please enter your input, or q to quit: ");
            String text = in.nextLine();      
            if (text.toLowerCase().equals("q"))
            {
                break;
            }
            if (checkValid(text) == false)
            {
                System.out.printf("Error: invalid input, please try again.\n\n");
                continue;
            }
            int position = findOperatorPosition(text);
            char symbol = findOperatorSymbol(text);
            String first = getFirstNumber(text);
            String second = getSecondNumber(text);
            String result = computeBinaryOperation(text);
            System.out.printf("operator position = %d\n", position);
            System.out.printf("operation = %c\n", symbol);
            System.out.printf("the first number is %s\n", first);
            System.out.printf("the second number is %s\n", second);
            System.out.printf("result = %s\n\n", result);
        }
        System.out.println("Exiting...");
    }
    
}
