#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
// int stat(constt char* filename, struct stat *buf);
// int fstat(int fd, struct stat *buf);

void print_file_meta(const struct stat *);

int main(int argc, char **argv) {

    struct stat file_stat;
    char *type, *readok;
    
    stat(argv[1], &file_stat);
    if (S_ISREG(file_stat.st_mode)) {
        type = "regular";
    } else if (S_ISDIR(file_stat.st_mode)) {
        type = "directory";
    } else {
        type = "other";
    }

    if ((file_stat.st_mode & S_IRUSR)) {

        readok = "yes";
    } else {
        readok = "no";
    }
    print_file_meta(&file_stat);
    printf("type: %s, read: %s\n", type, readok);
}

void print_file_meta(const struct stat *file_meta) {

    if (file_meta) {
      printf("st_mode is %d\n", file_meta->st_mode);
    
    }

}
