import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Algorithms1 {
    private Character[] letters={'P','C','M'};
    private Character[] lettersCopy;
    private List<Character> list;
    private List<Character> copyList;
    public Algorithms1(){
        list= Arrays.asList(letters);
        lettersCopy=new Character[3];
        copyList=Arrays.asList(lettersCopy);
        System.out.println("Initial list: ");
        output(list);
        Collections.reverse(list);
        System.out.println("\nAfter calling reverse: ");
        output(list);
        Collections.copy(copyList,list);
        System.out.println("\nAfter copying: ");
        output(copyList);
        Collections.fill(list,'R');
        System.out.println("\nAfter filling: ");
        output(list);
    }
    private void output(List<Character> listRef){
        System.out.print("The list is: ");
        for(Character element:listRef){
            System.out.printf("%s ",element);
        }
        System.out.printf("\nMax: %s",Collections.max(listRef));
        System.out.printf("\nMin: %s",Collections.min(listRef));
    }

    public static void main(String[] args) {
        new Algorithms1();
    }
}
