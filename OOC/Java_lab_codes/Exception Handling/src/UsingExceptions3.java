public class UsingExceptions3 {
    public static void main(String[] args) {
        try{
            method1();
        }
        catch(Exception exception){
            System.out.println(exception.getMessage()+"\n");
            exception.printStackTrace();
            StackTraceElement[] traceElements=exception.getStackTrace();
            System.out.println("\nStack trace from getStackTrace");
            System.out.println("Class\t\t\t\tFile\t\t\t\t\tLine\tMethod");
            for(StackTraceElement element:traceElements){
                System.out.print(element.getClassName()+"\t");
                System.out.print(element.getFileName()+"\t");
                System.out.print(element.getLineNumber()+"\t\t");
                System.out.println(element.getMethodName());
            }
        }
    }
    public static void method1() throws Exception{
        method2();
    }
    public static void method2() throws Exception{
        method3();
    }
    public static void method3() throws Exception{
        throw new Exception("Exception thrown in method3");
    }
}
