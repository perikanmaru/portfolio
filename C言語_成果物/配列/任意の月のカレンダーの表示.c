#include<stdio.h>

enum calendar{Iti,Ni,San,Yon,Go,Roku,Nana,Hati,Kyu,Jyu,Jyuiti,Jyuni,Invalid};

void iti(void)
{
	puts("January");
}

void ni(void)
{
	puts("February");
}

void san(void)
{
	puts("March");
}
 void yon(void)
 {
 	puts("April");
 }
 
 void go(void)
 {
 	puts("May");
 }
 
 void roku(void)
 {
 	puts("June");
 }
 
 void nana(void)
 {
 	puts("July");
 }
 
 void hati(void)
 {
 	puts("August");
 }
 
 void kyu(void)
 {
 	puts("September");
 }
 
 void jyu(void)
 {
 	puts("October");
 }
 
 void jyuiti(void)
 {
 	puts("January");
 }
 
 void jyuni(void)
 {
 	puts("December");
 }
 
 enum calendar select(void)
 {
 	int tmp;
	do{
		printf("0�c1�� �P�c2�� �Q�c3�� �R�c4�� �S�c5�� 5�c6��\n�U�c7�� �V�c8�� �W�c9�� �X�c10�� 10�c11�� 11�c12�� 12�c�I��\n");
		scanf("%d",&tmp);
	}while(tmp<Iti||tmp>Invalid);
	return (enum calendar)tmp;
 }
 
 int main(void)
 {
 	enum calendar selected;
	
	do{
		switch(selected = select()){
			
			case Iti : iti(); break;
			case Ni : ni(); break;
			case San : san(); break;
			case Yon : yon(); break;
			case Go : go(); break;
			case Roku : roku(); break;
			case Nana : nana(); break;
			case Hati : hati(); break;
			case Kyu : kyu(); break;
			case Jyu : jyu(); break;
			case Jyuiti : jyuiti(); break;
			case Jyuni : jyuni(); break;
			
		}
	}while(selected != Invalid);
	
	return 0;
 }