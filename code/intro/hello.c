#include <stdio.h>
// difference between #include <filename.h> and #include "filename.h"

// <stdio.h> searches in standard C library locations (System's include directory),
// whereas "stdio.h"
// firstly, searches in the current directory (Your own application's include directory).
// then, if it can't be found, look in the system's include directory.

// Ideally, you would use <...> for standard C libraries and "..." for libraries
// that you write and are present in the current directory.

#define N 10

static char static_str[] = "static global var";//TODO

void show_char(char *p); //TODO we should declare a function before we use it;  return_type name argument_list;

int main(int argc, char **argv)
{
    printf("the num of arguments from command line is %d\n",argc);
    
    if (argc < 2) {
        fprintf(stderr, "usage: %s <lack of string>\n", argv[0]);
    }
  
    int i;

    for (i = 1;i < argc;i++) {
        show_char(*(argv + i));
    }
    
    for (i = 1;i < argc;i++) {
        show_char(*argv+i);
    }
   
    return 0;
}


void show_char(char *p) {

    while ( *p != '\0' ) {
        printf("%c",*p++);
    }
    printf("\n");
}


