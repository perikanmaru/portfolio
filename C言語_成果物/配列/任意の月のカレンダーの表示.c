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
		printf("0…1月 １…2月 ２…3月 ３…4月 ４…5月 5…6月\n６…7月 ７…8月 ８…9月 ９…10月 10…11月 11…12月 12…終了\n");
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