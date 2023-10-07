import  java.util.InputMismatchException;
import  java.util.Scanner;
public class DivideByZeroExceptionHandling {
    public static int quotient(int numerator, int denominator) throws ArithmeticException {
        return numerator / denominator;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean continueloop = true;

        do {
            try {
                System.out.println("Please enter an integer numerator");
                int numerator = scanner.nextInt();
                System.out.println("Please enter an integer denominator");
                int denominator = scanner.nextInt();
                int result = quotient(numerator, denominator);
                System.out.printf("\nResult : %d / %d = %d\n", numerator, denominator, result);
                continueloop = false;
            } catch (InputMismatchException inputMismatchException) {
                System.err.printf("\nException : %s\n", inputMismatchException);
                scanner.nextLine();
                System.out.println("You must enter integers");
            } catch (ArithmeticException arithmeticException) {
                System.err.printf("\nException : %s\n",arithmeticException);
                System.out.println("Cannot divided by zero");
            }
        }while(continueloop);
    }
}
