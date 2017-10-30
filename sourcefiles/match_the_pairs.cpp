#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<math.h>

time_t now, later;
 
void sleep(int delay)
{
 now=time(NULL);
 later=now+delay;
 while(now<=later)now=time(NULL);
}

void gotoxy(int x, int y)
	{
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}


int main()
{
	int pp,mm,vv,num[6][6],zz=0; char ch[18] = {33,36,37,38,42,43,47,58,59,60,61,62,63,91,92,93,123,125}; char ch1[6][6]; int move1,a,y,x1,counterfinal,temporary,moveulta,counter,prevscore,tempscore,i,j,n,p,q,temp,k,r,z,c,x,pos,n1,gamover,n2,r1,c1,r2,c2,move,score,count; n=1;
	char dd=0;
	moveulta=0; counter=0; counterfinal=0; gamover=0; prevscore=0;
	FILE *fp;
	char ch2;
	fp=fopen("text1.txt","r");
	pp=1;
	while(1)
	  {
	  	ch2=fgetc(fp);
	  	if(ch2==EOF)
		  break;
		vv=ch2-48;
		zz=(vv*pp)+zz;
		pp*=10;
	  }
	fclose(fp);
	
	if(zz==0)
	  {
	  	mm=1234;
	  	fp=fopen("text1.txt","w");
	  	while(mm!=0)
	  	  {
	  	  	dd=(mm%10)+48;
	  	  	putc(dd,fp);
	  	  	mm=mm/10;
	  	  }
	  	  	fclose(fp);
	  }

	gotoxy(1,10);
	prevscore=zz;
	printf("High Score : %d",prevscore);
	
	srand(time(NULL));
	gotoxy(1,2);
	printf("Made by : Kaushal Kishor");
	gotoxy(54,1);
	printf("--------------------");
	gotoxy(54,2);
	printf("|");
	gotoxy(56,2);
	printf(" MATCH THE PAIRS");
	gotoxy(73,2);
	printf("|");
	gotoxy(54,3);
	printf("--------------------");
	for(j=0;j<6;j++)
	{
		for(i=0;i<6;i++)
		{
			num[j][i]=n;
			n++;
		}
	}
	for(j=0;j<6;j++)
	{
		for(i=0;i<6;i++)
		{
			ch1[j][i]=0;
		}
	}
	count=0;
	for(j=0;j<6;j++)
	{
		gotoxy(50,5+count);
		for(i=0;i<6;i++)
		{
			printf("%3d ",num[j][i]);
			if(i==5)
			{
				break;
			}
			printf("|");
		}
		count++;
		printf("\n");
		if(j!=5)
		{
		gotoxy(50,5+count);
		printf("-----------------------------");
		}
		z=1;x=0;
		for(q=0;q<5;q++)
		{
			if(q==0)
			{
			gotoxy(50+4*z,5+count);
			printf("|");
			}
			else
			{
			gotoxy(50+(4*z)+x,5+count);
			printf("|");
			}
			z++;
			x++;
		}
		printf("\n");
		count++;
	}
	
	for(j=0;j<18;j++)
	{
		k=0;i=0;
		while(i<2)
		{
			p=(rand()%36)+1;
			if(p%6==0)
			{
				r=p/6;
				c=6;
			}
			else
			{
			r=(p/6)+1;
			c=(p%6);
			}
			if(ch1[r-1][c-1]==0)
			{
				ch1[r-1][c-1]=ch[j];
				k++;
			}
			i=k;
		}
	}
	for(j=0;j<6;j++)
	{
		for(i=0;i<6;i++)
		{
			printf("%3c ",ch1[j][i]);
		}
		printf("\n");
	}

	move=0;
	for(i=1;i>=0;i++)
	{
		printf("\n");
		gotoxy(1,25);
		printf("Enter the position : ");
		scanf("%d",&pos);
		if(pos<1 || pos>36)
		{
			printf("\nInvalid Entry");
			continue;
		}
		n1=pos;
		if(pos%6==0)
			{
				r=pos/6;
				c=6;
			}
			else
			{
			r=(pos/6)+1;
			c=(pos%6);
			}
			r1=r; c1=c;
			gotoxy(50+(4*(c-1)+c-1),5+r-1+r-1);
			printf("%3c",ch1[r-1][c-1]);
			temp=ch1[r-1][c-1];
			gotoxy(1,25);
		printf("Enter the position : ");
		printf("  ");
		scanf("%d",&pos);
		gotoxy(24,25);
		printf("  ");
		if(pos<1 || pos>36)
		{
			printf("\nInvalid Entry");
			continue;
		}
		move++;
		n2=pos;	
		if(pos%6==0)
			{
				r=pos/6;
				c=6;
			}
			else
			{
			r=(pos/6)+1;
			c=(pos%6);
			}
			r2=r; c2=c;
		if(ch1[r-1][c-1]!=temp)
		{
			gotoxy(50+(4*(c-1)+c-1),5+r-1+r-1);
			printf("%3c",ch1[r-1][c-1]);
			sleep(2);
			gotoxy(50+(4*(c1-1)+c1-1),5+r1-1+r1-1);
			printf("%3d",n1);
			gotoxy(50+(4*(c2-1)+c2-1),5+r2-1+r2-1);
			printf("%3d",n2);
		}
		else
		{
			gotoxy(50+(4*(c2-1)+c-1),5+r2-1+r2-1);
			printf("%3c",ch1[r-1][c-1]);
			gamover++;
		}
		gotoxy(1,27);
		printf("No. of Moves = %d",move);
		if(gamover==18)
		{
			gotoxy(1,28);
			printf("\n G A M E    O V E R ");
	if(move<prevscore)
	{
	gotoxy(1,10);
	printf("New High Score : %d  ",move);
	move1=move;
	for(y=1;y>=0;y++)
	{
		move=move/10;
		counterfinal++;
		if(move==0)
		{
			break;
		}
	}
	move=move1;
	fp= fopen("text1.txt","w+");
	for(a=1;a<=counterfinal;a++)
	{
		temporary=move%10;
		ch2=temporary+48;
		fputc(ch2,fp);
		move=move/10;
	}
	fclose(fp);
	}

			break;
		}
		
	}
		
	return 0;

}
