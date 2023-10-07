import java.io.EOFException;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;


public class ReadSequentialFile {
    private ObjectInputStream input;
    public void openFile() {
        try // open file
        {
            input = new ObjectInputStream(
                    new FileInputStream( "clients.ser" ) );
        } // end try
        catch ( IOException ioException ) {
            System.err.println( "Error opening file." );
        } // end catch
    } // end method openFile
    public void readRecords() {
        AccountRecordSerializable record;
        System.out.printf( "%-10s%-12s%-12s%10s\n", "Account",
                 "First Name", "Last Name", "Balance" );

        try // input the values from the file
        {
            while ( true ){
                record = ( AccountRecordSerializable ) input.readObject();

                // display record contents
                System.out.printf( "%-10d%-12s%-12s%10.2f\n",
                        record.getAccount(), record.getFirstName(),
                        record.getLastName(), record.getBalance() );
            } // end while
        } // end try
        catch ( EOFException endOfFileException )
        {
            return; // end of file was reached
        } // end catch
        catch ( ClassNotFoundException classNotFoundException ) {
            System.err.println( "Unable to create object." );
            } // end catch
        catch ( IOException ioException ) {
            System.err.println( "Error during read from file." );
            } // end catch
    } // end method readRecord
    public void closeFile() {
        try {
            if ( input != null )
                input.close();
            } // end try
        catch ( IOException ioException ){
            System.err.println( "Error closing file." );
            System.exit( 1 );
            } // end catch
    } // end method closeFile
}
class ReadSequentialFileTest {
        public static void main( String args[] )
        {
        ReadSequentialFile application = new ReadSequentialFile();

        application.openFile();
        application.readRecords();
        application.closeFile();
        } // end main
} // end class ReadSequentialFileTes
