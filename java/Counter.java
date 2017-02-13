import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by yuan on 2017/2/13.
 */
public class Counter {
    private static int count = 0;

    public synchronized static void inc() {

        //这里延迟1毫秒，使得结果明显
        try {
            Thread.sleep(1);
        } catch (InterruptedException e) {
        }
        count++;
    }

    public static void main(String[] args) {
        final Lock lock = new ReentrantLock();
        //同时启动1000个线程，去进行i++计算，看看实际结果
        for (int i = 0; i < 1000; i++) {
            new Thread(new Runnable() {
                //@Override
                public void run() {
                    inc();
                }
            }).start();
        }

        //这里等待1s 为 等待 到 那1000个线程都跑完了，再打印出运行结果来。
        // 相当于join的作用
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        //这里每次运行的值都有可能不同,可能为1000
        System.out.println("运行结果:Counter.count=" + count);
    }


}
