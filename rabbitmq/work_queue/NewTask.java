import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.MessageProperties;

import java.util.concurrent.TimeoutException;

/**
 * Created by yuan on 2017/2/13.
 */


public class NewTask {
    private final static String QUEUE_NAME = "task_queuefp";

    public static void main(String[] argv)
            throws java.io.IOException {

        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("10.60.0.63");
        factory.setPort(5555);
        Connection connection = null;
        try {
            connection = factory.newConnection();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
        Channel channel = connection.createChannel();
        boolean durable = true;
        channel.queueDeclare(QUEUE_NAME, durable, false, false, null);
        for (int i = 0; i <10; i++) {
            String message = "H new YYY +++  " + i;
            channel.basicPublish("", QUEUE_NAME, MessageProperties.PERSISTENT_TEXT_PLAIN, message.getBytes());
            System.out.println(" [x] Sent '" + message + "'");
        }

        try {
            channel.close();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
        connection.close();
    }
}
