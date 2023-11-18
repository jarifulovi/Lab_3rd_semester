import java.sql.SQLOutput;
import java.util.InputMismatchException;
import java.util.Scanner;
public class DividedByZeroWithExceptionHandling {
    public static int quotient (int numerator,int denominator) throws ArithmeticException{
        return numerator/denominator;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        boolean continueLoop=true;
        do{
            try{
                System.out.print("Please enter an integer numerator: ");
                int numerator=scanner.nextInt();
                System.out.print("Please enter an integer denominator: ");
                int denominator=scanner.nextInt();
                int result=quotient(numerator,denominator);
                System.out.println("Result: "+numerator+"/"+denominator+" = "+result);
                continueLoop=false;
            }
            catch(InputMismatchException inputMismatchException){
                System.out.println("\nException: "+inputMismatchException);
                scanner.nextLine();
                System.out.println("You must enter integers. Please try again\n");
            }
            catch(ArithmeticException arithmeticException){
                System.out.println("\nException: "+arithmeticException);
                System.out.println("Zero is an invalid denominator. PLease try again.\n");
            }
        }while(continueLoop);
    }
}
