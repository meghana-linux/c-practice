/*
To compile this code oin Linux use -lrt
*/
/*
 Synchonous I/O means that when you want to read or write something, perhaps with a call to a function called Read() or Write(), the function blocks, preventing execution from moving any further until the read or write is finished. This is how plain ol' file reads and writes typically work. You open a file then call read(), which fills a buffer with the data you want, and returns once everything is finished, letting you go on your way with a buffer filled with the data you want.

Asychronous I/O is the opposite. Instead of the read and write functions waiting until the requested operation is finished before they return, asynchronous I/O operations return immediately to your program while the read or write operation continues in the background. 
*/

#include <sys/types.h>
#include <aio.h>
#include <fcntl.h>
#include <errno.h>


const int SIZE_TO_READ = 100;

int main()
{
        // open the file
        int file = open("/tmp/blah.txt", O_RDONLY, 0);

        if (file == -1)
        {
                printf(" Unable to open file!");
                return 1;
        }

        // create the buffer
        char* buffer = malloc(sizeof(char) * SIZE_TO_READ);

        // create the control block structure
        struct aiocb cb;

        memset(&cb, 0, sizeof(struct aiocb));
        cb.aio_nbytes = SIZE_TO_READ;
        cb.aio_fildes = file;
        cb.aio_offset = 0;
        cb.aio_buf = buffer;

        // read!
        if (aio_read(&cb) == -1)
        {
                printf(" Unable to create request!");
                close(file);
        }

        printf(" Request enqueued!");

        // wait until the request has finished
        while(aio_error(&cb) == EINPROGRESS)
        {
                printf(" Working...");
        }

        // success?
        int numBytes = aio_return(&cb);

        if (numBytes != -1)
                printf(" \nSuccess!");
        else
                printf(" Error!");

        // now free up the memory
        free(buffer);
        close(file);

        return 0;
}
        

