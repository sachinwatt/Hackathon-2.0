#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void generate_board(int*);
void display(int*);
void write_new_no(int);
int i_play(int*);
int check_win(int*);
int get_new_no();
void display_final(int,int*);
void other_play(int*,int);
void display_bingo();
FILE *ft;
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
  	int i,j,n=get_new_no(),a[5][5],turn,win;
  	int m=n;
  	generate_board(a[0]);
  	system("cls");
  	gotoxy(13,11);
    puts(name);
    gotoxy(5,10);
    printf("-----------------------");
    gotoxy(5,12);
    printf("-----------------------");
    for(i=10;i<=12;i++)
      {
      	gotoxy(5,i);
      	printf("|");
	  }
	for(i=10;i<=12;i++)
      {
      	gotoxy(27,i);
      	printf("|");
	  }
  	display_bingo();
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
  	
  
  	for(turn=toss;;turn++)
  	  {
  	  	
  	  	gotoxy(8,17);
  	  	printf("Score : %d",check_win(a[0]));
  	  	display(a[0]);
  	  	if(check_win(a[0])>=5)
  	  	  {
  	  	  	write_new_no(27);
  	  	  	win=1;
  	  	  	break;
  	  	  }
  	  	
  	  	
  	  	  
  	  	  	
  	  	if(turn%2==1)
  	  	  {
  	  	    m=i_play(a[0]);
  	  	    if(m==99)
  	  	      {
  	  	        turn=0;
  	  	        continue;
  	  	      }
  	  	    if(m==50)
  	  	      {
  	  	      	turn=0;
  	  	      	continue;
  	  	      }
  	  	    if(check_win(a[0])>=5)
  	  	      {
  	  	        write_new_no(27);
  	  	        win=1;
  	  	        break;
  	  	      }
  	  	    write_new_no(m);
  	  	    n=m;
  	  	  }
  	  	else
  	  	  {
  	  	    while(n==m)
			  {
			    n=get_new_no();
			    for(i=1;i<6;i++)
  	  			  {
  	  				gotoxy(34,14);
  	  				if(i%4==1)
  	  	  			  printf("/ ");
  	  				if(i%4==2)
  	  	  			  printf("--");
  	    			if(i%4==3)
  	  	  			  printf("\\ ");
  	  				if(i%4==0)
  	  	  			  printf("| ");
  	  				delay(100);
  	  			  }
  	  			gotoxy(4,14);
  	            printf("                           ");
			    
			    
			  }
			if(n!=28)
			  other_play(a[0],n);
			else
			  {
			    win=0;
			    break;
			  }
  	  	  }
  	  }
  	
  	display_final(win,a[0]);

  }
  	  	  	
void display_final(int win,int *a)
  {
  	char xx[2]={'X','X'};
  	int k,i,j,c=0;
  	system("cls");
    display_bingo();
  	for(i=0;i<6;i++)
  	  {
  	  	gotoxy(20,12+(2*i));
  	  	printf("-------------------------------");
  	  }
  	for(i=0;i<4;i++)
  	  {
  	  	for(j=11;j<24;j++)
  	  	  {
  	  	  	gotoxy(25+(6*i),j);
  	  	  	printf("|");
  	      }
  	  }
  	gotoxy(67,14);
  	printf("---------------------");
  	gotoxy(67,17);
  	printf("---------------------");
  	for(i=14;i<=17;i++)
  	  {
  	  	gotoxy(67,i);
  	  	printf("|");
  	  	gotoxy(67+20,i);
  	  	printf("|");
      }
    
  	gotoxy(73,15);
  	printf("GAME OVER");
  	gotoxy(73,16);
  	win==0?printf("YOU LOSE"):(printf("YOU WIN"));
  	gotoxy(73,19);
  	printf("Final Score : %d",check_win(a));
  	for(k=0;;k++)
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
				    gotoxy(20+(6*j),13+(2*i));
				    printf("%4  XX");
			      }
			    else
			      {
			      	gotoxy(20+(6*j),13+(2*i));
				    printf("%4    ");
				  }
			  }
  	  	  	else
  	  	  	{
  	  	      gotoxy(20+(6*j),13+(2*i));
				printf("%4d",*(a+(5*i)+j));
			}
  	      }
  	  }
  	if(c==1)
  	delay(500);
}
}
  	
int i_play(int *a)
  {
  	int n,i,j;
  	gotoxy(8,15);
  	printf("(Enter 99 to see 'X')");
  	gotoxy(4,14);
  	printf("                               ");
  	gotoxy(8,14);
  	printf("Make your move -  ");
  	scanf("%d",&n);
  	if(n==99)
  	  {
  	  	return 99;
  	  }
  	 	  	
  	fflush(stdin);
  	
  	while(n<=0 || n>25)
  	  {
  	    gotoxy(4,14);
  	    printf("                            ");
  	    gotoxy(8,15);
  	    printf("Make valid move - ");
		scanf("%d",&n);
	  }
	if(n>0 && n<26)
  	  {
  	  	for(i=0;i<5;i++)
  	  	  {
  	  	  	for(j=0;j<5;j++)
  	  	  	  {
  	  	  	  	if(*(a+(5*i)+j)==n)
  	  	  	  	  break;
  	  	  	  }
  	  	  	if(j<5)
  	  	  	  break;
  	  	  }
  	  	if(j==5)
  	  	  {
  	  	  	gotoxy(4,14);
  	        printf("                            ");
  	  	  	gotoxy(8,14);
  	  	  	printf("Make valid move - ");
  	  	  	return(50);
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
    
    return n;
  }
void write_new_no(int m)
  {
  	ft=fopen("C:\\Users\\DELL\\Dropbox\\score.txt","w");
    while(m!=0)
      {
      	char d=(m%10)+48;
      	m=m/10;
		fputc(d,ft);
	  }
    fclose(ft);
  }
int get_new_no()
  {
  	
	ft=fopen("C:\\Users\\DELL\\Dropbox\\score.txt","r");
	gotoxy(4,14);
  	printf("                            ");
  	gotoxy(4,14);
  	printf("Fetching data...please wait");
  	int p=1,m=0;
  	while(1)
  	  {
  	  	char ch=fgetc(ft);
  	  	if(ch==EOF)
  	  	  break;
  	  	int d=ch-48;
  	  	m=(d*p)+m;
  	  	
  	  	
  	  	p*=10;
  	  }
  	  fclose(ft);
  	  //gotoxy(0,0);
  	  //printf("%d",m );
  	  
  	return m;
  }
void other_play(int *a,int n)
  {
  	int i,j;
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
  	if(c==1)
  	delay(500);
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
void display_bingo()
{
	gotoxy(0,0);
	printf("Made By - Anubhaw Bhalotia");
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
  }
int main()
  {
  	int toss,i;
  	char name[20];
  	display_bingo();
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
  	strupr(name);
  	system("cls");
  	display_bingo();
  	srand(time(NULL));
  	gotoxy(44,8);
  	printf("Press enter to toss");
    getch();
  	toss=rand()%2;
    gotoxy(46,11);
    if(toss==0)
      printf("You lose the toss\n");
    else
      printf("You won the toss\n");
    write_new_no(toss+29);
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
    
    maingame(toss,name);
    
}
