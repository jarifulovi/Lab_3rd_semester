import java.util.List;
import java.util.Arrays;
import java.util.Collections;
public class Sort1 {
    private static final String[] suits={"Hearts","Spades","Clubs","Diamonds"};

    public void printElements(){
        List<String> list=Arrays.asList(suits);
        System.out.println("Unsorted array elements:\n"+list);
        Collections.sort(list);
        System.out.println("Sorted array elements:\n"+list);
    }

    public static void main(String[] args){
        Sort1 sort1=new Sort1();
        sort1.printElements();
    }
}
