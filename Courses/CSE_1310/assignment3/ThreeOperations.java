import java.util.Scanner;
public class ThreeOperations {

    
    public static void main(String[] args) {
        System.out.print("Please enter real number N1: ");
        Scanner a = new Scanner(System.in);
        double N1 = a.nextDouble();
        System.out.print("Please enter real number N2: ");
        Scanner b = new Scanner(System.in);
        double N2 = a.nextDouble();
        double multi = N1 * N2;
        double div = (float) N1 / N2;
        double expo = Math.pow(N1,N2);
        System.out.printf("%f * %f = %.2f \n", N1,N2, multi);
        System.out.printf("%f / %f = %.2f \n", N1,N2, div);
        System.out.printf("%f raised to the power of %f = %.2f", N1,N2, expo);
    }
    
}
