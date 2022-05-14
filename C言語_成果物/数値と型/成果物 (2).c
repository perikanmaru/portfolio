#include<stdio.h>

int main(void)
{
	int i;
	
	char a[][5]={"LISP","C","Ada"};
	
	char *p[]={"PAUL","X","MAC"};
	
	int arraynumber = sizeof a / sizeof a[0];
	
	for(i=0;i<arraynumber;i++){
		printf("a[%d]=\"%s\"\n",i,a[i]);
	}
	
	for(i=0;i<arraynumber;i++){
		printf("p[%d]=\"%s\"\n",i,p[i]);
	}
	
	return 0;
}