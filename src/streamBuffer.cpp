# include <streamBuffer.h>
# include <iostream>
# include <cstring>
using namespace std; 

streamBuffer::streamBuffer(size_t size):under_use(size) , Buffer(size,0)
{

}

size_t streamBuffer::copy_from_buffer(const char* data,size_t size)
{

    if(under_use == Buffer.size())
        return 0 ;
    size_t total_len  = size+under_use;
    size_t cp_len = total_len < Buffer.size()?size:Buffer.size()-under_use;

    mempcpy(Buffer.data()+under_use,data,cp_len);
    under_use = under_use+cp_len;

    return cp_len;
}

void streamBuffer::drain_buffer()
{
    under_use = 0 ;
    this->Buffer.clear();
}

const char* streamBuffer::get_data()
{
    return Buffer.data();

}

size_t streamBuffer::available_bytes()
{
    return under_use;
}