//REKIB UDDIN AHMED(ELD13016)
//PRASENJIT DAS(ELD13017)
//KAKOLI DAS(ELD13018)

#include<stdio.h>
#include<conio.h>
#include<math.h>
struct node
{
	int C;
	int X;
	int Y;
};
struct node mod[10];
int i,n,k;
float temp,force[50];
void getdata(int );
void calculate(int);
void process1();
void process2();
void display();
void main()
{
	int j;
	float avg;
	printf("how many modules?; ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
	getdata(i);
	}

	printf("\ninitial placement:\n");
	display();

	for(i=0;i<n;i++)
	{
	calculate(i);
	}

	avg=2.0;
	while(avg>1.0)
	{
	process1();
	process2();
	for(i=0;i<n;i++)
	{
	calculate(i);
	}
	avg=0.0;
	for(i=0;i<n;i++)
	{
	 avg=avg+abs(force[i]);
	}
	}

	for(i=0;i<n;i++)
	{
	if(mod[i].X==mod[i+1].X)
	{
	if(mod[i].Y==mod[i+1].Y)
	{
	mod[i].X=i;
	}
	}
	}
	printf("\n\nfinal placement:\n");
	display();

getch();
}

void getdata(int i)
{
	printf("\n");
	printf("module %d\n",i+1);
	printf("enter netlist =");
	scanf("%d",&mod[i].C);
	printf("enter coordinate x =");
	scanf("%d",&mod[i].X);
	printf("enter coordinate y =");
	scanf("%d",&mod[i].Y);
}

void calculate(int i)
{
	int j,x,y,c;
	float sum,f;
	sum=0;
	for(j=0;j<n;j++)
	{
	x=mod[i].X-mod[j].X;
	y=mod[i].Y-mod[j].Y;
	c=mod[i].C+mod[j].C;
	f=-c*(x+y);
	sum=sum+f;
	}
	force[i]=sum;
	printf("\nnet force acting on module %d = %f",i+1,sum);
}

void process1()
{
	int j;
	k=0;
	temp=fabs(force[0]);
	for(j=0;j<n;j++)
	{
	if(fabs(force[j])>=temp)
	{
	temp=fabs(force[j]);
	k=j;
	}
	}
	printf("\n\nmaximum force acting on module %d ie %f",k+1,temp);
}

void process2()
{
	int j,c;
	float y;
	y=0;
	c=0;
	for(j=0;j<n;j++)
	{
	if(j!=k)
	{
	y=y+((mod[k].C+mod[j].C)*(mod[j].X+mod[j].Y-k));
	}
	}
	for(j=0;j<n;j++)
	{
	if(j!=k)
	{
	c=c+(mod[k].C+mod[j].C);
	}
	}
	mod[k].X=k;
	mod[k].Y=ceil(y/c);
	printf("\ncoordinate assigned to module %d :x =%d,y =%d\n",k+1,mod[k].X,mod[k].Y);

}
void display()
{
	printf("module \tx \ty\n");
	printf("------ \t- \t-");
	for(i=0;i<n;i++)
	{
	printf("\n%d\t%d\t%d",i+1,mod[i].X,mod[i].Y);
	}
	printf("\n");
}
