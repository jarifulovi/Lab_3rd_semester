import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;

enum MenuOption{
    ZERO_BALANCE(1),
    CREDIT_BALANCE(2),
    DEBIT_BALANCE(3),
    END(4);
    private final int value;
    MenuOption(int valueOption){
        value = valueOption;
    }
    public int getValue(){
        return value;
    }
}

public class CreditInquiry {
    private MenuOption accountType;
    private Scanner input;
    private MenuOption[] choices = {MenuOption.ZERO_BALANCE,MenuOption.CREDIT_BALANCE,
    MenuOption.DEBIT_BALANCE,MenuOption.END};

    private void readRecords(){
        AccountRecord record = new AccountRecord();
        try{
            input = new Scanner(new File("clients.txt"));
            while(input.hasNext()){
                record.setAccount(input.nextInt());
                record.setFirstName(input.next());
                record.setLastName(input.next());
                record.setBalance(input.nextDouble());
                if(shouldLDisplay(record.getBalance())){
                    System.out.printf("%-10s%-12s%-12s%s-12s\n",record.getAccount(),
                            record.getFirstName(),record.getLastName(),record.getBalance());

                }
            }
        }
        catch(NoSuchElementException elementException){
            System.err.println("File improperly formed");
            input.close();
            System.exit(1);
        }
        catch (IllegalStateException illegalStateException){
            System.err.println("Error reading from file.");
            System.exit(1);
        }
        catch (FileNotFoundException fileNotFoundException){
            System.err.println("File cannot be found.");
            System.exit(1);
        }
        finally {
            if(input!=null) input.close();
        }
    }
    private boolean shouldLDisplay(double balance){
        if((accountType == MenuOption.CREDIT_BALANCE)&&(balance < 0)) return true;
        else if((accountType==MenuOption.DEBIT_BALANCE)&&(balance>0)) return true;
        else if((accountType==MenuOption.ZERO_BALANCE)&&(balance==0)) return true;
        return false;
    }
    private MenuOption getRequest(){
        Scanner textIn = new Scanner(System.in);

        System.out.printf("\n%s\n%s\n%s\n%s\n%s\n","Enter request",
                "1 - List accounts with zero balances",
                "2 - List accounts with credit balances",
                "3 - List accounts with debit balances","4 - End of run");
        int request = 1;
        try{
            do{
                System.out.print("\n?");
                request = Integer.parseInt(textIn.next());
            }while((request < 1)||( request > 4));
        }
        catch (NoSuchElementException elementException){
            System.err.println("Invalid input.");
            System.exit(1);
        }
        return choices[request-1];
    }
    public void processRequests(){
        accountType = getRequest();
        while(accountType != MenuOption.END){
            switch (accountType){
                case ZERO_BALANCE :
                    System.out.println("\nAccounts with zero balance: ");
                    break;
                case CREDIT_BALANCE:
                    System.out.println("\nAccounts with credit balances: ");
                    break;
                case DEBIT_BALANCE:
                    System.out.println("\nAccounts with debit balances: ");
                    break;
            }
        }
        readRecords();
        accountType = getRequest();
    }
}
class CreditInquiryTest{
    public static void main(String[] args) {
        CreditInquiry application = new CreditInquiry();
        application.processRequests();
    }
}
