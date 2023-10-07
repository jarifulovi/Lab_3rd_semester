import java.io.File;
import java.util.Scanner;

public class FileDemonstration {
    public void analyzPath(String path){
        File name = new File(path);
        if(name.exists()){
            System.out.printf("%s %s\n%s\n%s\n%s\n%s%s\n%s %s\n%s %s\n%s %s\n",
                    name.getName(),"exists",(name.isFile())?"is a file" : "is not a file",
                    (name.isDirectory())? "is a directory": "is not a directory",
                    (name.isAbsolute())? "is absolute": "is not absolute",
                    "Last modified : ",name.lastModified(),"Path : ",name.getPath(),"Absolute Path : ",name.getAbsolutePath(),
                    "Parent : ",name.getParent());
            if(name.isDirectory()){
                String[] directory = name.list();
                System.out.println("\n\nDirectory : ");
                for(String directoryName : directory != null ? directory : new String[0]){
                    System.out.printf("%s\n",directoryName);
                }
            }
        }
        else {
            System.out.printf("%s %s",path,"does not exist.");
        }
    }
}
class FileDemonstrationTest{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        FileDemonstration application = new FileDemonstration();
        System.out.println("Enter file of directory name here : ");
        application.analyzPath(input.nextLine());
    }
}