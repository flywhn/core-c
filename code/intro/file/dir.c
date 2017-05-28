#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
void test(const char *name);

void show_char( const char *name) {

    while (*name != '\0') {

        printf(" %c", *(name++));
    }
    printf("\n");

}

void show_int (const int **);
int main(int argc, char **argv) {

   char *name = "hello";
   test(name);
   show_char(name);
   
  
}

void test(const char *name) {

    name = name + 2;

}

void show_int (const int **p) {

    


}
