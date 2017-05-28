#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// int open (char *filename, int flags, mode_t mode);
// the open function transforms the filename to a file descriptor, and return
// the mix file descriptor of the current process. 
// The Argument "flags", tell the function how to access the file.

// O_RDONLY  O_WRONLY   'O_RDWR' means can be read and written.
// O_CREAT : if the file does not exist, system will create a truncated file
// O_TRUNC : if the file exists , system wil truncate it
// O_APPEND: before write, we seek the end of the file.

#define DEF_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define DEF_UMASK S_IWGRP | S_IWOTH

// ssize_t read(int fd, void *buf, size_t n); 
// when success return the num of bytes it read, or return 0 when reach the end of file , or return -1 when error;
// ssize_t write(int fd, const void *buf, size_t n);
// return -1 when error; return the num of bytes it already read;

int main(int argc, char **argv) {

    int src, des;
    umask(DEF_UMASK);
    src = open("foo.txt", O_RDONLY, 0);
    des = open("baz.txt", O_CREAT | O_TRUNC | O_WRONLY, DEF_MODE);


    char c;
    while(read(src, &c, 1) !=0) {  // STDIN_FILENO

        write(des, &c, 1);         // STDOUT_FILENO
    }
    
    close(src);
    close(des);
}
