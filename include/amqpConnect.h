# ifndef MY_CONNECTION_H
# define MY_CONNECTION_H
# include <boost/asio.hpp>
# include <iostream>
using namespace boost::asio;
using namespace std;
#include <amqpcpp.h>
namespace MyConnectionHandler
{
    class MyConnectionHandler : public AMQP::ConnectionHandler
    {
    public:

        virtual auto onData(AMQP::Connection *connection, const char *data, size_t size)->void override;
        virtual auto onReady(AMQP::Connection *connection)->void override; 
        virtual auto onError(AMQP::Connection *connection, const char *message)->void override;
        virtual auto onClosed(AMQP::Connection *connection)->void override;


    };
}

# endif