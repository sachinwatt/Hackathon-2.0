#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <conio.h>
void displayscore(int*,int*,int,char*);
void generate_board(int*);
void display_blink(int *);
void display(int*);
int check_win(int*);
int player_play(int*,int*);
void cpu_play(int*,int*);
void get_available(int*,int*);
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void gotoxy(int anubhaw, int y)
{
  COORD c;
  c.X = anubhaw;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int maingame(int toss,char *name)
  {
  	int a[5][5],b[5][5],turn,win=2,i,j;
  	generate_board(a[0]);
  	generate_board(b[0]);
  	for(turn=toss;;turn++)
  	  {
  	    
  	    display(b[0]);
  	    
  	  	if(check_win(a[0])>=5 && check_win(b[0])<5)
  	  	  {
  	  	  	win=1;
  	  	  	break;
  	      }
  	    if(check_win(b[0])>=5 && check_win(a[0])<5)
  	      {
  	      	win=0;
  	      	break;
  	      }
  	    if(check_win(a[0])>=5 && check_win(b[0])>=5)
  	      {
  	      	win=2;
  	      	break;
  	      }
		if(turn%2==1)
		  {
  	  	    int h=player_play(a[0],b[0]);
  	  	    if(h==99)
  	  	      {
  	  	      	turn=0;
  	  	      	continue;
  	  	      }
  	  	  }
  	  	else
    	  cpu_play(a[0],b[0]);
    	gotoxy(8,17);
  	    printf("Score : %d",check_win(b[0]));
      }
    system("cls");
  	gotoxy(45,2);
  	printf("------------------");
  	gotoxy(45,3);
  	printf("      BINGO");
  	gotoxy(45,4);
  	printf("------------------");
  	gotoxy(44,2);
  	printf("|");
  	gotoxy(44,3);
  	printf("|");
  	gotoxy(44,4);
  	printf("|");
  	gotoxy(63,2);
  	printf("|");
  	gotoxy(63,3);
  	printf("|");
  	gotoxy(63,4);
  	printf("|");
  	for(i=0;i<6;i++)
  	  {
  	  	gotoxy(5,11+(2*i));
  	  	printf("-------------------------------");
  	  }
  	for(i=0;i<4;i++)
  	  {
  	  	for(j=10;j<23;j++)
  	  	  {
  	  	  	gotoxy(10+(6*i),j);
  	  	  	printf("|");
  	      }
  	  }
  	for(i=0;i<6;i++)
  	  {
  	  	gotoxy(60,11+(2*i));
  	  	printf("-------------------------------");
  	  }
  	for(i=0;i<4;i++)
  	  {
  	  	for(j=9;j<23;j++)
  	  	  {
  	  	  	gotoxy(65+(6*i),j);
  	  	  	printf("|");
  	      }
  	  }
  	displayscore(a[0],b[0],win,name);
  	
    return win;
  }
void displayscore(int *a,int *b,int win,char *name)
  {
  	int i,j,k;
  	gotoxy(18,7);
  	printf("%s",name);
  	gotoxy(70,7);
  	printf("CPU");
  	gotoxy(40,26);
  	if(win==1)
  	  printf("YOU LOSE");
  	else if(win==0)
  	  printf("YOU WIN");
  	  else
  	  printf("DRAW");
	for(k=0;;k++)
  	{
	for(i=0;i<5;i++)
  	  {
		for(j=0;j<5;j++)
  	  	  {
  	  	  	
  	  	  	if(*(b+(5*i)+j)==0)
  	  	  	  {
  	  	  	  	if(k%2==0)
  	  	  	  	{
  	  	  	  	gotoxy(5+(6*j),12+(2*i));
				printf("%4  XX");
			    }
			    else
			    {
  	  	  	  	gotoxy(5+(6*j),12+(2*i));
				printf("%4    ");
			    }
			  }
		    else
  	  	  	  {
  	  	        gotoxy(5+(6*j),12+(2*i));
				printf("%4d",*(b+(5*i)+j));;
			  }
  	      }
  	  }
  	gotoxy(8,26);
  	printf("Score : %d",check_win(b));
  	gotoxy(63,26);
  	printf("Score : %d",check_win(a));
  	for(i=0;i<5;i++)
  	  {
		for(j=0;j<5;j++)
  	  	  {
  	  	  	
  	  	  	if(*(a+(5*i)+j)==0)
  	  	  	  {
  	  	  	  	if(k%2==0)
  	  	  	  	{
  	  	  	  	gotoxy(60+(6*j),12+(2*i));
				printf("%4  XX");
			    }
			    else
			    {
  	  	  	  	gotoxy(60+(6*j),12+(2*i));
				printf("%4    ");
			    }
			  }
		    else
  	  	  	  {
  	  	        gotoxy(60+(6*j),12+(2*i));
				printf("%4d",*(a+(5*i)+j));
			  }
  	      }
  	  }
  	delay(500);
  }
}
void generate_board(int *x)
  {
  	int num[25];
  	int i,j,c=0,n,k;
  	for(i=0;i<5;i++)
	  {
	    for(j=0;j<5;j++)
		  {
		  	int z=0;
		  	while(z==0)
		      {
			    n=(rand()%25)+1;
				for(k=0;k<c;k++)
				  {
		 	    	if(num[k]==n)
		 	    	  break;
		 	      }
			    if(k==c)
		 	      {
		 	        num[c]=n;
		 	        c++;
		 	        z=1;
		 	        *(x+(5*i)+j)=n;
		          }
		      }
	      }
      }
  }
void display(int *a)
  {
  	char xx[2]={'X','X'};
  	int k,i,j,c=0;
  	for(k=0;k<7;k++)
  	{
  	for(i=0;i<5;i++)
  	  {
		for(j=0;j<5;j++)
  	  	  {
  	  	  	
  	  	  	if(*(a+(5*i)+j)==0)
  	  	  	  {
  	  	  	  	c=1;
  	  	  	  	if(k%2==0)
				  {
				    gotoxy(38+(6*j),10+(2*i));
				    printf("%4  XX");
			      }
			    else
			      {
			      	gotoxy(38+(6*j),10+(2*i));
				    printf("%4    ");
				  }
			  }
  	  	  	else
  	  	  	{
  	  	      gotoxy(38+(6*j),10+(2*i));
				printf("%4d",*(a+(5*i)+j));
			}
  	      }
  	  }
  	//if(c==1)
  	//delay(500);
  }
  
  }
int check_win(int *x)
  {
  	int i,j,r,c,d=0,d1=0,z=0;
  	for(i=0;i<5;i++)
  	  {
  	  	r=0;
  	  	c=0;
		for(j=0;j<5;j++)
  	  	  {
  	  	  	if(*(x+(5*i)+j)==0)
  	  	  	  r++;
  	  	  	if(*(x+(5*j)+i)==0)
  	  	  	  c++;
  	  	  	if(i+j==4 && *(x+(5*i)+j)==0)
  	  	  	  d1++;
		  }
		
  	    if(c==5)
  	      z++;
  	    if(r==5)
  	      z++;
  	    if(*(x+(5*i)+i)==0)
  	      d++;
      }
    if(d==5)
      z++;
    if(d1==5)
	  z++;  
	return z;
  }
void cpu_play(int *a,int *b)
  {
  	int i,j,c=0,d=0,n,k;
  	gotoxy(8,14);
  	printf("                                 ");
  	gotoxy(12,14);
  	printf("Please Wait");
  	gotoxy(84,14);
  	printf("                          ");
  	/*for(i=1;i<6;i++)
  	  {
  	  	gotoxy(89,14);
  	  	if(i%4==1)
  	  	  printf("/ ");
  	  	if(i%4==2)
  	  	  printf("--");
  	    if(i%4==3)
  	  	  printf("\\ ");
  	  	if(i%4==0)
  	  	  printf("| ");
  	  	delay(200);
  	  }
  	  
  	gotoxy(89,12);
  	printf("    ");
  	
	 
  	  	  */
  	for(k=4;k>=0;k--)
  	  {
  	  	c=0;
  	  	for(j=0;j<5;j++)
  	  	  {
  	  	  	if(*(a+(5*j)+j)==0)
  	  	  	  c++;
  	      }
  	    if(c==k)
  	      {
			for(j=0;j<5;j++)
  	  	      {
  	  	  	    if(*(a+(5*j)+j)!=0)
  	  	  	      {
  	  	  	      	n=*(a+(5*j)+j);
					*(a+(5*j)+j)=0;
  	  	  	      	break;
  	  	  	      }
  	          } 
  	        break;
  	      }
  	      
  	    c=0;
  	    for(j=0;j<5;j++)
  	  	  {
  	  	  	if(*(a+(5*j)+(4-j))==0)
  	  	  	  c++;
  	      }
  	    if(c==k)
  	      {
			for(j=0;j<5;j++)
  	  	      {
  	  	  	    if(*(a+(5*j)+(4-j))!=0)
  	  	  	      {
  	  	  	      	n=*(a+(5*j)+(4-j));
					*(a+(5*j)+(4-j))=0;
  	  	  	      	break;
  	  	  	      }
  	          } 
  	        break;
  	      }
  	      

  	    for(i=0;i<5;i++)
  	      {
  	      	c=0;
			for(j=0;j<5;j++)
  	      	  {
  	      	  	if(*(a+(5*i)+j)==0)
  	      	  	  c++;
  	          }
  	        if(c==k)
  	          {
			    for(j=0;j<5;j++)
  	      	      {
  	                if(*(a+(5*i)+j)!=0)
  	                  {
						n=*(a+(5*i)+j);
						*(a+(5*i)+j)=0;
						d=1; 
					    break;
					  }
  	              }
  	            break;
  	          }
  	      }
  	    if(d==1)
  	        break;
  	      
  	
  	    for(i=0;i<5;i++)
  	      {
  	      	c=0;
			for(j=0;j<5;j++)
  	      	  {
  	      	  	if(*(a+(5*j)+i)==0)
  	      	  	  c++;
  	          }
  	        if(c==k)
  	          {
			    for(j=0;j<5;j++)
  	      	      {
  	                if(*(a+(5*j)+i)!=0)
  	                  {
						n=*(a+(5*j)+i);
						*(a+(5*j)+i)=0;
  	                    d=1;  
					    break;
					  }
  	              }
  	            break;
  	          }
  	      }
  	    if(d==1)
  	      break;  
  	  }
  	gotoxy(30,12);
  	for(i=0;i<5;i++)
  	  {
  	  	for(j=0;j<5;j++)
  	  	  {
  	  	  	if(*(b+(5*i)+j)==n)
  	  	  	  {
  	  	  	    *(b+(5*i)+j)=0;
  	  	  	    break;
  	  	  	  }
  	      }
      }
    gotoxy(84,14); 
	printf("CPU's Move - %d",n);
  }
  	    
    
int player_play(int *a,int *b)
  {
  	int n,i,j,c=1;
  	
  	gotoxy(8,15);
  	printf("Enter '99' to see 'X'");
  	gotoxy(8,14);
  	printf("                       ");
	gotoxy(8,14);
  	printf("Make your move  -  ");
  	scanf("%d",&n);
  	fflush(stdin);
  	if(n==99)
  	  {
  	  	display_blink(b);
  	  	return 99;
  	  }
  	while(n<=0 || n>25)
  	  {
  	    gotoxy(8,14);
  	    printf("                           ");
  	    gotoxy(8,14);
  	    printf("Make valid move - ");
		scanf("%d",&n);
	}
    while(c==1)
      {
      	if(n>0 && n<26)
  	    {
  	  	for(i=0;i<5;i++)
  	  	  {
  	  	  	for(j=0;j<5;j++)
  	  	  	  {
  	  	  	  	if(*(b+(5*i)+j)==n)
  	  	  	  	  break;
  	  	  	  }
  	  	  	if(j<5)
  	  	  	  break;
  	  	  }
  	  	if(j==5)
  	  	  {
  	  	  	gotoxy(8,14);
  	  	  	printf("                     ");
  	  	  	gotoxy(8,14);
  	  	  	printf("Make valid move - ");
  	  	  	c=1;
  	  	  	scanf("%d",&n);
  	  	  }
  	  	else
  	  	  c=0;
  	  }
  }
  	
  	for(i=0;i<5;i++)
  	  {
  	  	for(j=0;j<5;j++)
  	  	  {
  	  	  	if(*(a+(5*i)+j)==n)
  	  	  	  {
  	  	  	    *(a+(5*i)+j)=0;
  	  	  	    break;
  	  	  	  }
  	      }
      }
    for(i=0;i<5;i++)
  	  {
  	  	for(j=0;j<5;j++)
  	  	  {
  	  	  	if(*(b+(5*i)+j)==n)
  	  	  	  {
  	  	  	    *(b+(5*i)+j)=0;
  	  	  	    break;
  	  	  	  }
  	      }
      }
  }
void display_blink(int *a)
  {
  	char xx[2]={'X','X'};
  	int k,i,j,c=0;
  	for(k=0;k<7;k++)
  	{
  	for(i=0;i<5;i++)
  	  {
		for(j=0;j<5;j++)
  	  	  {
  	  	  	
  	  	  	if(*(a+(5*i)+j)==0)
  	  	  	  {
  	  	  	  	c=1;
  	  	  	  	if(k%2==0)
				  {
				    gotoxy(38+(6*j),10+(2*i));
				    printf("%4  XX");
			      }
			    else
			      {
			      	gotoxy(38+(6*j),10+(2*i));
				    printf("%4    ");
				  }
			  }
  	  	  	else
  	  	  	{
  	  	      gotoxy(38+(6*j),10+(2*i));
				printf("%4d",*(a+(5*i)+j));
			}
  	      }
  	  }
  	if(c==1)
  	delay(500);
  }
}
int main(int argc, char const *argv[]) 
  {
  	int toss,i,j;
  	char *jj,name[20];
  	gotoxy(45,2);
  	printf("------------------");
  	gotoxy(45,3);
  	printf("      BINGO");
  	gotoxy(45,4);
  	printf("------------------");
  	gotoxy(44,2);
  	printf("|");
  	gotoxy(44,3);
  	printf("|");
  	gotoxy(44,4);
  	printf("|");
  	gotoxy(63,2);
  	printf("|");
  	gotoxy(63,3);
  	printf("|");
  	gotoxy(63,4);
  	printf("|");
  	gotoxy(46,8);
  	printf("Enter your name");
  	gotoxy(43,9);
  	printf("---------------------");
  	gotoxy(43,12);
  	printf("-------------------");
  	gotoxy(43,14);
  	printf("-------------------");
  	for(i=12;i<=14;i++)
  	  {
  	  	gotoxy(43,i);
  	  	printf("|");
  	  }
  	for(i=12;i<=14;i++)
  	  {
  	  	gotoxy(62,i);
  	  	printf("|");
  	  }
  	gotoxy(44,13);
  	gets(name);
  	system("cls");
  	gotoxy(45,2);
  	printf("------------------");
  	gotoxy(45,3);
  	printf("      BINGO");
  	gotoxy(45,4);
  	printf("------------------");
  	gotoxy(44,2);
  	printf("|");
  	gotoxy(44,3);
  	printf("|");
  	gotoxy(44,4);
  	printf("|");
  	gotoxy(63,2);
  	printf("|");
  	gotoxy(63,3);
  	printf("|");
  	gotoxy(63,4);
  	printf("|");
  	gotoxy(46,8);
  	gotoxy(44,8);
    printf("Press enter to toss");
    getch();
    srand(time(NULL));
    toss=rand()%2;
    gotoxy(46,11);
    if(toss==0)
      printf("You lose the toss\n");
    else
      printf("You won the toss\n");
    gotoxy(42,10);
    printf("------------------------");
    gotoxy(42,12);
    printf("------------------------");
    for(i=10;i<=12;i++)
      {
      	gotoxy(42,i);
      	printf("|");
      }
    for(i=10;i<=12;i++)
      {
      	gotoxy(65,i);
      	printf("|");
      }
    gotoxy(43,15);
    printf("Press Enter to continue");
    getch();
  	system("cls");
  	gotoxy(45,2);
  	printf("------------------");
  	gotoxy(45,3);
  	printf("      BINGO");
  	gotoxy(45,4);
  	printf("------------------");
  	gotoxy(44,2);
  	printf("|");
  	gotoxy(44,3);
  	printf("|");
  	gotoxy(44,4);
  	printf("|");
  	gotoxy(63,2);
  	printf("|");
  	gotoxy(63,3);
  	printf("|");
  	gotoxy(63,4);
  	printf("|");
  	for(i=0;i<6;i++)
  	  {
  	  	gotoxy(38,9+(2*i));
  	  	printf("-------------------------------");
  	  }
  	for(i=0;i<4;i++)
  	  {
  	  	for(j=8;j<21;j++)
  	  	  {
  	  	  	gotoxy(43+(6*i),j);
  	  	  	printf("|");
  	      }
  	  }
  	gotoxy(15,10);
    strupr(name);
	puts(name);
  	gotoxy(12,9);
  	printf("------------");
  	gotoxy(12,11);
  	printf("------------");
  	for(i=9;i<=11;i++)
  	  {
  	  	gotoxy(12,i);
  	  	printf("|");
  	  }
  	for(i=9;i<=11;i++)
  	  {
  	  	gotoxy(24,i);
  	  	printf("|");
  	  }  
  	
  	gotoxy(87,10);
  	printf(" CPU");
  	gotoxy(84,9);
  	printf("------------");
  	gotoxy(84,11);
  	printf("------------");
  	for(i=9;i<=11;i++)
  	  {
  	  	gotoxy(84,i);
  	  	printf("|");
  	  }
  	for(i=9;i<=11;i++)
  	  {
  	  	gotoxy(95,i);
  	  	printf("|");
  	  }  
  	int win=maingame(toss,name);
  	
  }

