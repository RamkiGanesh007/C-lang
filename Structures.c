/* Create a structure to store and display details of institute, course and student
Example:
Enter institute details:10                                                                                              
KMIT                                                                                                                    
Enter details of course 1:100                                                                                           
C                                                                                                                       
Enter details of course 2:101                                                                                           
JAVA                                                                                                                    
Enter details of student 1:100                                                                                          
501                                                                                                                     
RAM                                                                                                                     
95                                                                                                                      
Enter details of student 2:101                                                                                          
502                                                                                                                     
SAM                                                                                                                     
78                                                                                                                      
Enter details of student 3:100                                                                                          
503                                                                                                                     
ANU                                                                                                                     
98                                                                                                                      
Institute details:10 KMIT                                                                                               
Course details:100 C                                                                                                    
101 JAVA                                                                                                                
Student details:100 501 RAM 95                                                                                          
101 502 SAM 78                                                                                                          
100 503 ANU 98*/

#include<stdio.h>
#define LOOP 3
void main()
{
    
 struct institute
 {
     int instid;
   char name[20];
 };
struct student
{
    int courseid;
    char name[20];
    int rollno;
    int marks;
};
struct course
{
  int courseid;
  char course[20];
};
    struct institute ins[3];
    struct student stu[3];
    struct course co[3];
    int i;
    printf("Enter institute details:");
 for(i=0;i<1;i++) //institute loop
 {
     scanf("%d %s",&ins[i].instid,ins[i].name);
 }
 for(i=0;i<2;i++) //course loop
 {
 printf("Enter details of course %d:",i+1);
 scanf("%d %s",&co[i].courseid,co[i].course);
 }
 for(i=0;i<LOOP;i++) //student loop
 {
 printf("Enter details of student %d:",i+1);
 scanf("%d %d %s %d",&stu[i].courseid,&stu[i].rollno,stu[i].name,&stu[i].marks);
 }
 
 
 //printing...
 printf("Institute details:");
 for(i=0;i<1;i++) //institute loop print
 {
     printf("%d %s",ins[i].instid,ins[i].name);
 }
 //course
 printf("\nCourse details:");
 for(i=0;i<2;i++) //course loop print
 {
 printf("%d %s\n",co[i].courseid,co[i].course);
 }
 
 //Student
 printf("Student details:");
 for(i=0;i<LOOP;i++) //student loop print
 {
 printf("%d %d %s %d\n",stu[i].courseid,stu[i].rollno,stu[i].name,stu[i].marks);
 }
 
}
