# ifndef MY_CONNECTION_H
# define MY_CONNECTION_H
# include <boost/asio.hpp>
# include <iostream>
# include <vector>
using namespace boost::asio;
using namespace std;
#include <amqpcpp.h>

class DataStreamHandler;
class MyConnectionHandler : public AMQP::ConnectionHandler
    {
    public:
        MyConnectionHandler();
        virtual auto onData(AMQP::Connection *connection, const char *data, size_t size)->typename enable_if<true,void>::type override;
        virtual auto onReady(AMQP::Connection *connection)->typename enable_if<true,void>::type override; 
        virtual auto onError(AMQP::Connection *connection, const char *message)->typename enable_if<true,void>::type override;
        virtual auto onClosed(AMQP::Connection *connection)->typename enable_if<true,void>::type override;
        auto connect_to_endpoint(string Ip ,uint64_t port)->typename enable_if<true,void>::type ;
        virtual ~MyConnectionHandler();
        void sendData() ;
        auto startEventLoop()->void;
    private:
        shared_ptr<ip::tcp::socket> stream_socket;
        io_context ctx;
        AMQP::Connection *amqpConnection;
        vector <char> my_buffer;
        DataStreamHandler *buff;


    };


# endif