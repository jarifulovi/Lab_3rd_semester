public class GenericMethodTest {
    public static <E> void printArray(E[] inputArray){
        for(E element:inputArray){
            System.out.print(element+" ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        Integer[] integerArray={1,2,3,4,5,6};
        Double[] doubleArray={1.1,2.2,3.3,4.4,5.5,6.6};
        Character[] characterArray={'H','E','L','L','O'};
        System.out.println("Array integerArray contains:");
        printArray(integerArray);
        System.out.println("Array doubleArray contains:");
        printArray(doubleArray);
        System.out.println("Array characterArray contains:");
        printArray(characterArray);
    }
}

