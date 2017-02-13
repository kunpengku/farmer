import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import java.util.concurrent.TimeoutException;

/**
 * Created by yuan on 2017/2/13.
 */


public class Send {
    private final static String QUEUE_NAME = "hellofp";

    public static void main(String[] argv)
            throws java.io.IOException {

        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("10.60.0.444");
        factory.setPort(5555);
        Connection connection = null;
        try {
            connection = factory.newConnection();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
        Channel channel = connection.createChannel();

        channel.queueDeclare(QUEUE_NAME, false, false, false, null);
        String message = "Hello World! +++  0213";
        channel.basicPublish("", QUEUE_NAME, null, message.getBytes());
        System.out.println(" [x] Sent '" + message + "'");
        try {
            channel.close();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
        connection.close();
    }
}
