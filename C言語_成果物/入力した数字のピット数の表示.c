#include<stdio.h>

int count_bits(unsigned x)
{
	int bits=0;
	while(x){
		if(x&1U)
		bits++;
		x>>=1;
	}
	return bits;
}

int int_bits(void)
{
	return count_bits(~0U);
}

void print_bits(unsigned x)
{
	int i;
	
	for(i=int_bits()-1;i>=0;i--){
		
		putchar(((x>>i)&1U)?'1':'0');
	}
}

int main(void)
{
	unsigned a,b;
	
	printf("0ˆÈã‚Ì®”‚ğ“ü—Í‚µ‚Ä‰º‚³‚¢\n");
	printf("a:");
	scanf("%u",&a);
	printf("b:");
	scanf("%u",&b);
	
	printf("\na(2) =");print_bits(a);
	printf("\na(16)=");printf("%X",a);
	
	printf("\n");
	
	printf("\nb(2)=");print_bits(b);
	printf("\nb(16)=");printf("%X",b);
	
	printf("\n");
	
	printf("\na&b(2)=");print_bits(a&b);
	printf("\na&b(16)");printf("%X",a&b);
	
	printf("\n");
	
	printf("\na|b(2)=");print_bits(a);
	printf("\na|b(16)=");printf("%X",a|b);
	
	printf("\n");
	
	printf("\na^b(2)=");print_bits(a^b);
	printf("\na^b(16)=");printf("%X",a^b);
	
	printf("\n");
	
	printf("\na~a(2)=");print_bits(~a);
	printf("\n~a(16)");printf("%X",~a);
	
	printf("\n");
	
	printf("\n~b(2)=");print_bits(~b);
	printf("\n~b(16)=");printf("%X",~b);
	
	putchar('\n');
	
	
	return 0;
}