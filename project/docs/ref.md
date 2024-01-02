# References 📚

### [Yellow Code Books](https://yellowcodebooks.com/2019/07/25/java-bai-48-thread-pool-tap-1-lam-quen-voi-thread-pool/)
![](https://i0.wp.com/yellowcodebooks.com/wp-content/uploads/2019/07/ThreadPoolExecutor.png?w=1234&ssl=1)
`ThreadPoolExecutor` là một lớp được xây dựng sẵn trong Java, nó giúp bạn quản lý các Thread một cách hiệu quả hơn. Để sử dụng nó, bạn cần khai báo một đối tượng ThreadPoolExecutor như sau:
```java
ThreadPoolExecutor executor = new ThreadPoolExecutor(
    corePoolSize, // số lượng Thread tối thiểu trong Pool
    maxPoolSize, // số lượng Thread tối đa trong Pool
    keepAliveTime, // thời gian mà Thread vẫn còn sống sau khi không được sử dụng
    TimeUnit, // đơn vị thời gian của tham số trên
    BlockingQueue, // hàng đợi chứa các Runnable
    ThreadFactory, // tạo Thread
    RejectedExecutionHandler // xử lý khi có nhiều Runnable hơn số lượng Thread tối đa
);
```
Lớp này đã xây dựng sẵn cho bạn một hàng đợi có tên là Task Queue, và một Pool trong đó. Khi bạn có quá nhiều Thread (chính là các Runnable trong Application như hình), thì thay vì cứ start chúng thành các Thread, bạn cứ “quăng” tất cả Runnable vào trong ThreadPoolExecutor đã khai báo. Tất cả các Runnable này sau đó được ThreadPoolExecutor để vào trong Task Queue. Và sẽ chỉ lấy ra đủ số lượng Runnable mà bạn đã chỉ định, để thực thi chúng thành các Thread. 

### [Java Thread Pool](https://www.baeldung.com/thread-pool-java-and-guava)

