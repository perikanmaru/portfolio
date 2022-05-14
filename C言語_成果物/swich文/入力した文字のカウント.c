#include<stdio.h>

int main(void)
{
	int i,ch;
	 int count[62]={0};
	 
	 while((ch=getchar())!=EOF){
	 	switch(ch){
			
			case '0' : count[0]++; break;
			case '1' : count[1]++; break;
			case '2' : count[2]++; break;
			case '3' : count[3]++; break;
			case '4' : count[4]++; break;
			case '5' : count[5]++; break;
			case '6' : count[6]++; break;
			case '7' : count[7]++; break;
			case '8' : count[8]++; break;
			case '9' : count[9]++; break;
			
			case 'A' : count[10]++; break;
			case 'B' : count[11]++; break;
			case 'C' : count[12]++; break;
			case 'D' : count[13]++; break;
			case 'E' : count[14]++; break;
			case 'F' : count[15]++; break;
			case 'G' : count[16]++; break;
			case 'H' : count[17]++; break;
			case 'I' : count[18]++; break;
			case 'J' : count[19]++; break;
			case 'K' : count[20]++; break;
			case 'L' : count[21]++; break;
			case 'M' : count[22]++; break;
			case 'N' : count[23]++; break;
			case 'O' : count[24]++; break;
			case 'P' : count[25]++; break;
			case 'Q' : count[26]++; break;
			case 'R' : count[27]++; break;
			case 'S' : count[28]++; break;
			case 'T' : count[29]++; break;
			case 'U' : count[30]++; break;
			case 'V' : count[31]++; break;
			case 'W' : count[32]++; break;
			case 'X' : count[33]++; break;
			case 'Y' : count[34]++; break;
			case 'Z' : count[35]++; break;
			
			case 'a' : count[36]++; break;
			case 'b' : count[37]++; break;
			case 'c' : count[38]++; break;
			case 'd' : count[39]++; break;
			case 'e' : count[40]++; break;
			case 'f' : count[41]++; break;
			case 'g' : count[42]++; break;
			case 'h' : count[43]++; break;
			case 'i' : count[44]++; break;
			case 'j' : count[45]++; break;
			case 'k' : count[46]++; break;
			case 'l' : count[47]++; break;
			case 'm' : count[48]++; break;
			case 'n' : count[49]++; break;
			case 'o' : count[50]++; break;
			case 'p' : count[51]++; break;
			case 'q' : count[52]++; break;
			case 'r' : count[53]++; break;
			case 's' : count[54]++; break;
			case 't' : count[55]++; break;
			case 'u' : count[56]++; break;
			case 'v' : count[57]++; break;
			case 'w' : count[58]++; break;
			case 'x' : count[59]++; break;
			case 'y' : count[60]++; break;
			case 'z' : count[61]++; break;
			}
			}
			
			puts("•¶š‚ÌoŒ»‰ñ”B");
			for(i=0;i<10;i++){
				printf("'%d':%d\n ",i,count[i]);
			}
			for(i=11;i<62;i++){
				printf("'%d':%d\n",i,count[i]);
			}
			
			return 0;
			}
			