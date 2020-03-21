# include <amqpConnect.h>
# include <iostream>
using namespace std;  

int main()
{
   
    MyConnectionHandler handler;
    handler.connect_to_endpoint("127.0.0.1",15672);
    AMQP::Connection connection(&handler, AMQP::Login("guest","guest"), "/");
    AMQP::Channel channel(&connection);
    channel.consume("snmp",AMQP::noack).onReceived(
        [&](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered)
    {
        cout << message.headers() << endl;


    });
    
    handler.startEventLoop();
    return 0 ;
}