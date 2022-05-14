#include<stdio.h>
#include<math.h>

#define sqr(n) ((n)*(n))

typedef struct{
	double x;
	double y;
}point;

typedef struct{
	point pt;
	double fuel;
}car;

double distance(point pa,point pb)
{
	return sqrt(sqr(pa.x-pb.x)+sqr(pa.y-pb.y));
}

void info(car c)
{
	printf("���݈ʒu�F(%.2f,%.2f)\n",c.pt.x,c.pt.y);
	printf("�c��̔R���F%.2f\n",c.fuel);
}

int move(car *c,point dest)
{
	double d=distance(c->pt,dest);
	
	if(d>c->fuel)
	return 0;
	
	c->pt=dest;
	c->fuel-=d;
	
	return 1;
}

int main(void)
{
	car mycar={0.0,0.0,90.0};
	
	while (1){
		int select;
		point dest;
		
		info(mycar);
		
		printf("�ړ����܂����H�@�yYES�E�E�E�P/No�E�E�E�O�z\n");
		scanf("%d",&select);
		
		if(select==0)
		break;
		
		printf("�ړI�n����͂��Ĉړ��E�E�E�P / �ړ���������͂��Ĉړ��E�E�E�Q \n");
		scanf("%d", &select);
        if(select == 1){
            printf("�ړI�n��x���W : ");   scanf("%lf", &dest.x);
            printf("�ړI�n��y���W : ");   scanf("%lf", &dest.y);
            if(!move(&mycar, dest)) printf("�ړ��ł��܂���\n");
        }else if(select == 2){
            printf("x�����̈ړ����� : ");   scanf("%lf", &dest.x);
            printf("y�����̈ړ����� : ");   scanf("%lf", &dest.y);
            dest.x += mycar.pt.x;
            dest.y += mycar.pt.y;
            if(!move(&mycar, dest)) 
			printf("�ړ��ł��܂���\n");                       
        }
    }
	
	return 0;
}