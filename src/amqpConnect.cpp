# include <amqpConnect.h>
# include <boost/asio.hpp>
# include <iostream> 
# include <streamBuffer.h>
using namespace std;
class DataStreamHandler
{
    public:
        streamBuffer inputBuffer;
        streamBuffer outputBuffer;
        DataStreamHandler():inputBuffer(8*1024*1024),outputBuffer(8*1024*1024)
        {

        }



};
MyConnectionHandler::MyConnectionHandler():ctx(),my_buffer(1*1024*1024,0)
{
    stream_socket = make_shared<boost::asio::ip::tcp::socket>(ctx);
}

void MyConnectionHandler::connect_to_endpoint(string ip , uint64_t port)
{
    boost::asio::ip::tcp::endpoint my_endpoint(
        boost::asio::ip::address::from_string(ip), port
    );

    stream_socket->async_connect(my_endpoint,[&](const error_code &err)
    {

        cout << "Connected " << endl;

    });

    ctx.run();

}

void MyConnectionHandler::onData(AMQP::Connection *connection, const char *data, size_t size)
{
 
    
}

void MyConnectionHandler::onReady(AMQP::Connection *connection)
{
    cout << "ready_to_send_data" << endl;

}

void MyConnectionHandler::onError(AMQP::Connection *connection, const char *message)
{
    
}
void MyConnectionHandler::onClosed(AMQP::Connection *connection)
{
    if(!ctx.stopped())
        ctx.stop();
}

MyConnectionHandler::~MyConnectionHandler()
{

}

void MyConnectionHandler::sendData()
{
    stream_socket->send(buffer(my_buffer,my_buffer.size()));
   
}
void MyConnectionHandler::startEventLoop()
{
    while(true)
    {
        if()
    }
}