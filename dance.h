void dance1(int x)
{
	switch(x)
	{
		case 0:
		{
			system("cls");
			printf("|----------------------------------\n");
			printf("|  / LETS BEGIN THE FUN            \n");
			printf("| /                                \n");
			printf("|/                                 \n");
			printf("|                                  \n");
			printf("|                 ---              \n");
			printf("|                /   \\            \n");
			printf("|    HANGMAN    |     |            \n");
			printf("|                \\   /            \n");
			printf("|                 ---              \n");
			printf("|                  |\\             \n");
			printf("|                  |  \\           \n");
			printf("|  PLEASE SAVE ME! |\\  \\         \n");
			printf("|                  | \\            \n");
			printf("|                  |  \\  HANGMAN  \n");
			printf("|                  |               \n");
			printf("|                  |\\             \n");
			printf("|                    \\            \n");
			printf("|                     \\           \n");
			printf("Press any enter to continue\n");
			break;
		}
		case 1:
		{
		
			system("cls");
			printf("|----------------------------------\n");
			printf("|  / LETS BEGIN THE FUN            \n");
			printf("| /                                \n");
			printf("|/                                 \n");
			printf("|                                  \n");
			printf("|                 ---              \n");
			printf("|                /   \\ HANGMAN    \n");
			printf("|               |     |            \n");
			printf("|                \\   /            \n");
			printf("|                 ---              \n");
			printf("|                 /|               \n");
			printf("|                / |               \n");
			printf("|               / /|PLEASE SAVE ME!\n");
			printf("|                / |               \n");
			printf("|               /  |               \n");
			printf("|      HANGMAN     |               \n");
			printf("|                 /|               \n");
			printf("|                /                 \n");
			printf("|               /                  \n");
			printf("Press any enter to continue\n");
			break;
		}
	}
}
void dance()
{
	int c=1;
	char k;
	while(c>0 )
	{
		
	
   	
		dance1(0);
		Sleep(200);
		dance1(1);
		Sleep(200);
		
		if (kbhit())
		{
			k=getch();
	  		c=0;
		}
	}
}
