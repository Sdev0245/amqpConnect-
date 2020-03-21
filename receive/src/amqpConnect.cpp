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
    streamHandler = new DataStreamHandler();
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
    cout << data << endl;
    this->amqpConnection =connection;
    size_t bytes_written = streamHandler->outputBuffer.copy_from_buffer(data,size);
    if(bytes_written !=size )
    {
        cout << "bytes written " << bytes_written << endl;
        this->sendData();
        streamHandler->outputBuffer.copy_from_buffer(data+bytes_written,size-bytes_written);
    }

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
    stream_socket->send(buffer(streamHandler->outputBuffer.get_data(),streamHandler->outputBuffer.available_bytes()));
    streamHandler->outputBuffer.drain_buffer();
    
}
void MyConnectionHandler::startEventLoop()
{
    while(1)
    {
        if(stream_socket->available() > 0)
        {
            cout << "heelo"<< endl;
            int bytes = stream_socket->available();
            if(my_buffer.size() < bytes)
                my_buffer.resize(bytes,0);
            size_t received = stream_socket->receive(buffer(my_buffer,bytes));
            streamHandler->inputBuffer.copy_from_buffer(&my_buffer[0],received);
            
            
        }
        if(streamHandler->inputBuffer.available_bytes()>0)
        {
            size_t parsed_bytes = amqpConnection->parse(streamHandler->inputBuffer.get_data(),
            streamHandler->inputBuffer.available_bytes());
            if(parsed_bytes == streamHandler->inputBuffer.available_bytes())
                streamHandler->inputBuffer.drain_buffer();
            else if(parsed_bytes > 0 )
            {
                streamHandler->inputBuffer.amqp_parse_next_bytes(parsed_bytes);
            }
            
        }

        this->sendData();
        this_thread::sleep_for(std::chrono::milliseconds(10));

    }
}