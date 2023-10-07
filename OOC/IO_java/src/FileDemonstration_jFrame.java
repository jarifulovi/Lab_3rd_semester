import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class FileDemonstration_jFrame extends JFrame {
    private JTextArea outputArea;
    private JScrollPane scrollPane;
    public void FileDemonstration() {
        //super( "Testing class File" );
        outputArea = new JTextArea();
        // add outputArea to scrollPane
        scrollPane = new JScrollPane( outputArea );
        add( scrollPane, BorderLayout.CENTER );
        setSize( 400, 400 ); // set GUI size
        setVisible( true ); // display GUI
        analyzePath2(); // create and analyze File object
    } // end FileDemonstration constructor
    private File getFile() {
        // display file dialog, so user can choose file to open
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
        int result = fileChooser.showOpenDialog(this);
        if (result == JFileChooser.CANCEL_OPTION)
            System.exit(1);
        File fileName = fileChooser.getSelectedFile(); // get selected file
        // display error if invalid
        if ((fileName == null) || (fileName.getName().equals(""))) {
            JOptionPane.showMessageDialog(this, "Invalid File Name",
                    "Invalid File Name", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        } // end if
        return fileName;
    }
    public void analyzePath2() {
        // create File object based on user input
        File name = getFile();
        if ( name.exists() ) // if name exists, output information about it
            {
            // display file (or directory) information
            outputArea.setText( String.format(
                    "%s%s\n%s\n%s\n%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s",
                     name.getName(), " exists",
                    ( name.isFile() ? "is a file" : "is not a file" ),
                     ( name.isDirectory() ? "is a directory" :
                     "is not a directory" ), ( name.isAbsolute() ? "is absolute path" :
                     "is not absolute path" ), "Last modified: ",
                     name.lastModified(), "Length: ", name.length(),
                    "Path: ", name.getPath(), "Absolute path: ",
                    name.getAbsolutePath(), "Parent: ", name.getParent() ) );
                if ( name.isDirectory() ) // output directory listing 80
                {
                String directory[] = name.list();
                outputArea.append( "\n\nDirectory contents:\n" );
                for ( String directoryName : directory )
                     outputArea.append( directoryName + "\n" );
                } // end else
            } // end outer if
        else // not file or directory, output error message
        {
            JOptionPane.showMessageDialog( this, name +
                    " does not exist.", "ERROR", JOptionPane.ERROR_MESSAGE );
            } // end else
        } // end method analyzePath
} // end class FileDemonstration
class FileDemonstrationTest2 {
        public static void main( String args[] )
        {
        FileDemonstration_jFrame application = new FileDemonstration_jFrame();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        } // end main
} // end class FileDemonstrationTest