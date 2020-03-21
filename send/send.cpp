# include <amqpConnect.h>
# include <iostream>
using namespace std;  

int main()
{
    string data = "Hello";
    MyConnectionHandler handler;
    AMQP::Table argumnets;
    char header_key[100] ="t_nms";
    argumnets["monitoring"] = "temp";
    argumnets["discovery"] ="icmp";
    AMQP::Envelope envelop(data.c_str(),data.size());
    handler.connect_to_endpoint("127.0.0.1",15672);
    AMQP::Connection connection(&handler, AMQP::Login("guest","guest"), "/");
    char exchange_name[100]="header_exhange";
    char  binding_key[100] = "amqp.snmp";
    AMQP::Channel channel(&connection);
    envelop.setHeaders(argumnets);
    channel.declareQueue("snmp");
    channel.publish(exchange_name,header_key,envelop);



    handler.startEventLoop();
    return 0 ;
}