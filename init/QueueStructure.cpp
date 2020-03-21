# include <amqpConnect.h>
# include <iostream>
using namespace std;  

int main()
{
    char exchange_name[100]="header_exhange";
    
    char header_key[100]="t_nms";
    string data = "Hello";
    MyConnectionHandler handler;
    AMQP::Table argumnets;
    argumnets["x-match"] = "any";
    argumnets["monitoring"] = "snmp";
    argumnets["discovery"] ="icmp";
    argumnets["x-dead-letter-exchange"]= exchange_name;
    handler.connect_to_endpoint("127.0.0.1",15672);
    AMQP::Connection connection(&handler, AMQP::Login("guest","guest"), "/");
    AMQP::Channel channel(&connection);
    
    char  binding_key[100] = "amqp.snmp";
    channel.declareExchange(exchange_name,AMQP::headers);
    channel.declareQueue("snmp");
    channel.bindQueue(exchange_name,"snmp",header_key,argumnets);
    handler.startEventLoop();
    return 0 ;
}