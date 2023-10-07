import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a = 10;
        Scanner in = new Scanner(System.in);
        try{
            int b = in.nextInt();
            System.out.println(a/b);
        }
        catch (InputMismatchException | ArithmeticException e){
            System.out.println(e);
        }
    }
}