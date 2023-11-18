import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.RejectedExecutionException;

public class TaskExecutor {
    public static void main(String[] args) {
        PrintTask task1=new PrintTask("task1");
        PrintTask task2=new PrintTask("task2");
        PrintTask task3=new PrintTask("task3");
        PrintTask task4=new PrintTask("task4");
        System.out.println("Starting executor");
        ExecutorService threadExecutor= Executors.newCachedThreadPool();
        threadExecutor.execute(task1);
        threadExecutor.execute(task2);
        threadExecutor.execute(task3);
        threadExecutor.shutdown();
//        try{
//            threadExecutor.execute(task4);
//        }
//        catch(RejectedExecutionException exception){
//            System.out.printf("%s",exception);
//        }
        System.out.println("Tasks started, main ends.\n");
    }
}
