# include<stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <conio.h>
# include "dance.h"
# include "displayhang.h"
char keyboard[27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int no_of_lines(int a);
int randnum(int line);
char* takename(int r,int x);
void keydisplay();
int game(int,char a[],char b[],int x);
void p2array(char *p ,char a[]);
void MakeItSame();
int main()
{
	dance();
	int x,a,i,r,arr_len,total=0;
	const char s[2] = "-";
	int level=0,count=0;
	char again;
	char real[50],hint[50];
	system("cls");
	printf("Enter level\nPress 1 for easy mode\nPress 2 for medium mode\nPress 3 for hard mode\n");
	do
	{
		count=0;
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default :
				{
					count++;
					printf("Wrong option\n");
				}
		}
	}while(count!=0);
	do
	{
		i=no_of_lines(x);
		r=randnum(i);
		
		char *p=takename(r,x);
		char name1[50];
		p2array(p,name1);
		
	    char *tk1 = strtok(name1, s);
	    p2array(tk1,real);
	    arr_len=strlen(real);
	    
		char *tk2 = strtok(NULL, s);
		p2array(tk2,hint);
		level++;
		total=total+game(arr_len,real,hint,x);
		system("cls");
		printf("Want to play again?????\nIf yes then press Y \nIf want to end press any other character\n");
		scanf(" %c",&again);
		again=toupper(again);
		MakeItSame();
		if(level>=10)
		{
			if(x<3)
				x++;
		}
	}while(again=='Y');
	system("cls");
	printf("Game Finshedddddddddd  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Your Total Score is %d\n",total);
	printf("Thank you For Playing\n");
}
void MakeItSame()
{
	char inc='A';
	int i;
	for(i=0; i<26; i++)
	{
		keyboard[i]=inc;
		inc++;
	}
}
void p2array(char *p ,char a[])
{
	int k=0;
	while(*(p+k) != '\0')
	{
		a[k] = *(p+k);
		k++;
	}	
	a[k] = '\0';
}
void keydisplay()
{
	printf("\n\n");
	int i;
	for(i=0;i<26;i++)
	{
		printf("%c ", keyboard[i]);
		if(i==6||i==13||i==20)
			printf("\n");
	}
}
int no_of_lines(int a)
{
	char num[50];
	FILE *fptr;
	if(a==1)
	{
		fptr=fopen("Easy.txt","r");
		int i=0;
		while(!feof(fptr))
		{
			fscanf(fptr,"%s", &num);
			i++;
		}
		fclose(fptr);
		return i;
	}
	else if (a==2)
	{
		fptr=fopen("Medium.txt","r");
		int i=0;
		while(!feof(fptr))
		{
			fscanf(fptr,"%s", &num);
			i++;
		}
		fclose(fptr);
		return i;
	}
	else if (a==3)
	{
		fptr=fopen("Hard.txt","r");
		int i=0;
		while(!feof(fptr))
		{
			fscanf(fptr,"%s", &num);
			i++;
		}
		fclose(fptr);
		return i;
	}
	
}
int randnum(int line)
{
	int r;
	srand(time(NULL));
	r= (rand()%(line+1));
	return r;
}
char* takename(int r,int x)
{
	switch(x)
	{
		case 1:
			{
				char name[50];
				FILE *fptr;
				fptr=fopen("Easy.txt","r");
				int i=0;
				while(!feof(fptr))
					{
						fscanf(fptr,"%s", &name);
						if(i==r)
							break;
						i++;	
					}
				fclose(fptr);

				return name;
				break;
			}
		case 2:
			{
				char name[50];
				FILE *fptr;
				fptr=fopen("Medium.txt","r");
				int i=0;
				while(!feof(fptr))
					{
						fscanf(fptr,"%s", &name);
						if(i==r)
							break;
						i++;	
					}
				fclose(fptr);

				return name;
				break;
			}
			case 3:
			{
				char name[50];
				FILE *fptr;
				fptr=fopen("Hard.txt","r");
				int i=0;
				while(!feof(fptr))
					{
						fscanf(fptr,"%s", &name);
						if(i==r)
							break;
						i++;	
					}
				fclose(fptr);

				return name;
				break;
			}
	}
}
int game(int len, char a[],char b[],int x)
{
	int score=0;
	int i,asc,key;
	char check;
	char guess[50];
	for(i=0;i<len;i++)
	{
		guess[i]='?';
	}
	guess[i]='\0';
	int hang=0,count=0;
	displayhang(hang,x);
	printf("HINT : %s\n",b);
	printf("\n%s\n",guess);
	keydisplay();
	int count1=1;
	int k;
	for(k=0;k<len||hang<8;k++)
	{
		count=0;
		check=getch();
		check=toupper(check);
		int l;
		for(l=0;l<len;l++)
		{
			if(check==a[l])
			{
				guess[l]=check;
				asc=check;
				key=asc-65;
				keyboard[key]='.';
				displayhang(hang,x);
				printf("HINT : %s\n",b);
				printf("%s",guess);
				keydisplay();
				count++;
				count1=strcmp(guess,a);
				if(count1==0)
				{
					displayhang(9,x);
					printf("%s",guess);
					keydisplay();
					if (x==1)
						score++;
					else if(x==2)
						score=score+2;
					else if(x==3)
						score=score+5;
					printf("\nPress any key to continue\n");	
					getch();
					return score;
				}
			}
		}
		if(count==0)
		{
			asc=check;
			key=asc-65;
			keyboard[key]=' ';
			hang++;
			displayhang(hang,x);
			printf("HINT : %s\n",b);
			printf("%s",guess);
			keydisplay();
			if (hang==8)
			{
				printf("\nThe actual word was %s",a);
				printf("\nPress any key to continue\n");
				getch();
				return score;
			}
		}	
	}
}
