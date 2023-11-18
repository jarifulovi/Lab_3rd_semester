public class UsingExceptions2 {
    public static void main(String[] args) {
        try{
            throwException();
        }
        catch(Exception exception){
            System.out.println("Exception handled in main");
        }
    }
    public static void throwException() throws Exception{
        try{
            System.out.println("Method throwException");
            throw new Exception();
        }
        catch(RuntimeException runtimeException){
            System.out.println("Exception handled in method throwException");
        }
        finally{
            System.out.println("Finally is always executed");
        }
    }
}
