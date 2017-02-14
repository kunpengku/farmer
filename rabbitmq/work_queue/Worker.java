/**
 * Created by yuan on 2017/2/13.
 */
import com.rabbitmq.client.*;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class Worker {
    private final static String QUEUE_NAME = "task_queuefp";

    public static void main(String[] argv)
            throws IOException,
            InterruptedException {

        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("10.60.0.63");
        factory.setPort(5555);
        Connection connection = null;
        try {
            connection = factory.newConnection();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
        final Channel channel = connection.createChannel();
        boolean durable = true;
        channel.queueDeclare(QUEUE_NAME, durable, false, false, null);

        channel.basicQos(1);
        System.out.println(" [*] Waiting for messages. To exit press CTRL+C");

        Consumer consumer = new DefaultConsumer(channel) {
            //@Override
            public void handleDelivery(String consumerTag, Envelope envelope, AMQP.BasicProperties properties, byte[] body)
                    throws IOException {
                String message = new String(body, "UTF-8");
                System.out.println(" [x] Received '" + message + "'");
                //
                channel.basicAck(envelope.getDeliveryTag(), false);
            }
        };
        //确认ack
        boolean autoAck = false;
        channel.basicConsume(QUEUE_NAME, autoAck, consumer);

    }
}
