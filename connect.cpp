# include <amqpConnect.h>
# include <iostream>
using namespace std;  

int main()
{
    MyConnectionHandler handler;
    handler.connect_to_endpoint("127.0.0.1",15672);
    AMQP::Connection connection(&handler, AMQP::Login("guest","guest"), "/");
    AMQP::Channel channel(&connection);
    handler.startEventLoop();
    return 0 ;
}