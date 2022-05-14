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
	printf("現在位置：(%.2f,%.2f)\n",c.pt.x,c.pt.y);
	printf("残りの燃料：%.2f\n",c.fuel);
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
		
		printf("移動しますか？　【YES・・・１/No・・・０】\n");
		scanf("%d",&select);
		
		if(select==0)
		break;
		
		printf("目的地を入力して移動・・・１ / 移動距離を入力して移動・・・２ \n");
		scanf("%d", &select);
        if(select == 1){
            printf("目的地のx座標 : ");   scanf("%lf", &dest.x);
            printf("目的地のy座標 : ");   scanf("%lf", &dest.y);
            if(!move(&mycar, dest)) printf("移動できません\n");
        }else if(select == 2){
            printf("x方向の移動距離 : ");   scanf("%lf", &dest.x);
            printf("y方向の移動距離 : ");   scanf("%lf", &dest.y);
            dest.x += mycar.pt.x;
            dest.y += mycar.pt.y;
            if(!move(&mycar, dest)) 
			printf("移動できません\n");                       
        }
    }
	
	return 0;
}