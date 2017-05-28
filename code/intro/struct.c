#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
#define M 2

typedef struct course {
   char *course_name;
   double score;

} course;

typedef struct student {
    char *name;
    int age;
    course *courses[M];
} student;




void show(student *stu) {
   printf("student's name is %s, age is %d",stu->name, stu->age);
   printf("\n");
} 
int main() {

   course *cour1, *cour2;
   //courses = (course)malloc(M*sizeof(course*));
   cour1 = (course*)malloc(sizeof(course));
   cour2 = (course*)malloc(sizeof(course));

   cour1->score = 85;
   cour2->score = 95;

     
   strcpy(cour1->course_name, "mathe");
   strcpy(cour2->course_name, "english");  

   student *stu[2], *stu1, *stu2;
   stu1 = (student*)malloc(sizeof(student));
   stu2 = (student*)malloc(sizeof(student));

   strcpy(stu1->name, "hainan");
   strcpy(stu2->name, "zhongnan");
 
   stu1->age = 22;
   stu2->age = 33;
   
   stu1->courses[0] = cour1;
   stu1->courses[1] = cour2;
//   show(stu1);

 
   return 0;
}
