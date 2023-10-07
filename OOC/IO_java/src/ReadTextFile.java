import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.io.File;
public class ReadTextFile {
    private Scanner input;
    public void openFile(){
        try{
            input = new Scanner(new File("clients.txt"));
        }
        catch (FileNotFoundException fileNotFoundException){
            System.err.println("Error opening file");
            System.exit(1);
        }
    }
    public void addRecords(){
        AccountRecord record = new AccountRecord();
        System.out.printf("%-10s%-12s%-12s%s-12s\n","First name","Last name",
                "Balance","Account number");
        try{
            while(input.hasNext()){
                record.setAccount(input.nextInt());
                record.setFirstName(input.nextLine());
                record.setFirstName(input.nextLine());
                record.setBalance(input.nextDouble());
                System.out.printf("%s-10d%-12S%-12s%10.2f\n",
                        record.getAccount(),record.getFirstName(),
                        record.getLastName(),record.getBalance());
            }
        }
        catch (NoSuchElementException elementException){
            System.err.println("File improperly formed");
            input.close();
            System.exit(1);
        }
        catch (IllegalStateException illegalStateException){
            System.err.println("Error reading from file.");
            System.exit(1);
        }
    }
    public void closeFile(){
        if(input!=null) input.close();
    }
}
class ReadTextFileTest{
    public static void main(String[] args) {
        ReadTextFile application = new ReadTextFile();

        application.openFile();
        application.addRecords();
        application.closeFile();
    }
}