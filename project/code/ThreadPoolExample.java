package os.project.code;

// by @moctran - code up again by myself for understanding
import java.util.concurrent.*;
public class ThreadPoolExample {
    private static final int TASK_COUNT = 20;
    private static final int THREAD_POOL_SIZE = 4;

    public static void main(String[] args) {
        // conventional approach
        long startC = System.currentTimeMillis();
        runConventionalTasks();
        long endC = System.currentTimeMillis();
        System.out.println("Conventional approach runtime: " + (endC - startC));
        
        // using thread pool approach
        long startTP = System.currentTimeMillis();
        runThreadPoolTasks();
        long endTP = System.currentTimeMillis();
        System.out.println("Thread pool approach runtime: " + (endTP - startTP));
    }

    private static void runConventionalTasks() {
        for (int i = 0; i < TASK_COUNT; i++) {
            performTaskWithDelay(i);
        }
    }
    private static void runThreadPoolTasks() {
        // create a fixed size thread pool
        ExecutorService executorService = Executors.newFixedThreadPool(THREAD_POOL_SIZE);
        // submit task to the thread pool
        for (int i = 0; i < TASK_COUNT; i++) {
            final int taskNumber = i;   // needed for lambda expression
            executorService.submit(() -> performTaskWithDelay(taskNumber));
        }
        // shut down the thread pool, wait for termination
        executorService.shutdown();
        try {
            // wait for all threads in ExecutorService to terminate
            // 'Long.MAX_VALUE' is used as timeout, indicates an effectively infinite timeout
            // 'TimeUnit.NANOSECONDS' specifies time unit for the timeout
            executorService.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        } catch (InterruptedException e) {
            // handle the InterruptedException by catching and immediately restore the interrupted status of current thread
            Thread.currentThread().interrupt();
        }
    }

    // simulate a task with delay
    private static void performTaskWithDelay(int taskNumber) {
        System.out.println("Task " + taskNumber + " started by thread: " + Thread.currentThread().getName());
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        System.out.println("Task " + taskNumber + " completed by thread: " + Thread.currentThread().getName());
    }
}