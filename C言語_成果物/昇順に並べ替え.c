#include<stdio.h>
#include<string.h>

#define NUMBER 5
#define NAME_LEN 64

typedef struct{
	char name[NAME_LEN];
	int height;
}student;

void swap_student(student *x,student *y){
	
	student temp=*x;
	*x=*y;
	*y=temp;
}

void sort(student a[],int n){
	
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(a[j-1].height>a[j].height){
				swap_student(&a[j-1],&a[j]);
			}
		}
	}
}

int main(void){
	int i;
	
	student menber[]={
		{"Sato",178},
		{"Sanaka",175},
		{"Takao",173},
		{"Mike",165},
		{"Masaki",179},
	};
	
	for(i=0;i<NUMBER;i++)
	printf("%-8s%6d\n",menber[i].name,menber[i].height);
	
	sort(menber,NUMBER);
	
	puts("\ng’·‡‚É•À‚×‘Ö‚¦‚Ü‚µ‚½B");
	for(i=0;i<NUMBER;i++)
	printf("%-8s%6d\n",menber[i].name,menber[i].height);
	
	return 0;
}