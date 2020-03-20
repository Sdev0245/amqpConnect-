# ifndef STREMBUFFER_H
# define  STREMBUFFER_H
# include <iostream>
# include <vector>
using namespace std;
class streamBuffer
{
    public:
        streamBuffer(size_t size );
        size_t copy_from_buffer(const char *data ,size_t size);
        void drain();
        const char * get_data();
        void drain_buffer();
        size_t available_bytes();

    private:
        vector <char> Buffer;
        size_t under_use;
        


};


# endif