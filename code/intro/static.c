#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define SUM(x,y) ((x)+(y))
void func(void);

static int count = 5;

main () {

  while(count--) {

    func();
  }
  printf("the max is %d\n",SUM(12,23));
}

void func(void) {

    static int i = 5;
    i++;
    printf("i is %d and count is %d\n", i, count);

}
