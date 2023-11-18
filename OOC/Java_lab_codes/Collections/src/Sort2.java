import java.util.List;
import java.util.Arrays;
import java.util.Collections;
public class Sort2 {
    private static final String[] suits={"Hearts","Spades","Clubs","Diamonds"};

    public void printElements(){
        List<String> list=Arrays.asList(suits);
        System.out.println("Unsorted array elements:\n"+list);
        Collections.sort(list);
        System.out.println("Sorted array elements: \n"+list);
        Collections.sort(list,Collections.reverseOrder());
        System.out.println("Reversely sorted array elements:\n"+list);
        System.out.println("Min: "+Collections.min(list));
        System.out.println("Max: "+Collections.max(list));
        Collections.fill(list,"Spades");
        System.out.println("After filling:\n"+list);
    }

    public static void main(String[] args){
        Sort2 sort2=new Sort2();
        sort2.printElements();
    }
}
