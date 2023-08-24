#include<iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include<cwchar>
#include<time.h>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition; 
void gotoXY(int,int); 
void newgame();
void loadfunc();
void game1();
void game2();
void game3();
void game4();
bool rowcheck(int r,int num,int arr[9][9]);
bool colcheck(int c,int num,int arr[9][9]);
bool blocksearch(int r,int c,int num,int arr[9][9]);
	bool flag=true,flag1=true,block=false;
bool loop=true;
	int tot_num=0;
	int rand1=0,rand2=0,rand3=0,rand4=0;
	int x=0,y=0;
	int row_num,col_num,num;
	int game_prog=0;
	int empty;
	int terminator1=0,terminator2=0,terminator3=0;
void	consoleoutput(int arr[9][9]);
void savegame(int arr[9][9]);
void game1save(int arr[9][9]);
void game2save(int arr[9][9]);
void game3save(int arr[9][9]);
void game4save(int arr[9][9]);
int main()
{
	system("Color F4");
	gotoXY(18, 7); cout << "->";
	int running = 1, menu_item = 0;;
	while (running)
	{
		gotoXY(20, 7);  cout << "1) New Game";
		gotoXY(20, 8);  cout << "2) load games";
		gotoXY(20, 9);  cout << "3) Instruction Manual";
		gotoXY(20, 10); cout << "4) Credits";
		gotoXY(20, 11); cout << "5) Quit Program";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && menu_item < 4) //down button pressed
		{
			gotoXY(18, 7 + menu_item); cout << "  ";
			menu_item++;
			gotoXY(18, 7 + menu_item); cout << "->";
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && menu_item > 0) //up button pressed
		{
			gotoXY(18, 7 + menu_item); cout << "  ";
			menu_item--;
			gotoXY(18, 7 + menu_item); cout << "->";
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) // Enter key pressed
		{
			gotoXY(18, 7 + menu_item); cout << "  ";
			switch (menu_item)
			{
			case 0: {
				gotoXY(20, 16);
				newgame();
				break;
			}

			case 1: {
				gotoXY(20, 16);
				loadfunc();
				break;
			}

			case 2: {
				system("CLS");
				
				gotoXY(5, 20);
				system("Color 06");
				cout << "\nSudoku is played on a grid of 9 x 9 spaces." << endl << "Within the rows and columns are 9 squares (made up of 3 x 3 spaces)."
					<< endl << "Each row, column and square (9 spaces each) needs to be filled out\n" << "with the numbers 1-9,without repeating any numbers within\n"
					<< "the row, column or square\n";
				break;
			}

			case 3: {
				system("CLS");
				gotoXY(20, 16);
				system("Color 04");
				cout << " \nFaraz Iftikhar" << endl << "BS SE(1-C)" << endl << "PF Final Project" << endl;
				break;
			}

			case 4: {
				gotoXY(20, 16);
				cout << "Thank You for Playing!";
				running = false;
				break;
			}
			}
		}
	}

	gotoXY(20, 21);
	system("pause");
	return 0;
}
void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}
void newgame()
{
	system("CLS");

	int arr[9][9]={0};
		HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	tot_num=rand()%81+1;
			if(tot_num<18)
			{
			tot_num+=20;
			}
	for(int i=0;i<81;i++){
		x=rand()%9+1;
		y=rand()%9+1;
		 rand2=rand()%9+1;
		flag= rowcheck(x,rand2,arr);
		flag1= colcheck(y,rand2,arr);
		block=blocksearch(x,y, rand2,arr);
		if(flag==false||flag1==false||block==true)
		{
				x=rand()%9+1;
				y=rand()%9+1;
				flag= rowcheck(x,rand2,arr);
		        flag1= colcheck(y,rand2,arr);
				block=blocksearch(x,y, rand2,arr);
		}
		else if(flag==true&&flag1==true&&block==false)
		 	 arr[x][y]=rand2;
	}
	consoleoutput(arr);

}
void consoleoutput(int arr[9][9])
{
		system("CLS");
		while(loop)
	{
		 	
		float count=0.0;
		system("Color 0C");
	
	SetConsoleTextAttribute(a,4);	
		cout<<"                   SUDOKU\n"<<"                   Good Luck!";
SetConsoleTextAttribute(a,1);				
		cout<<endl;
				cout<<endl;
				cout<<"       ";
SetConsoleTextAttribute(a,6);	
				for( int i=0;i<9;i++)
				{					if(i==6||i==3)
					cout<<" ";
					cout << i+1<<"   ";
				}
				cout<<endl;
				SetConsoleTextAttribute(a,1);
cout<<"     ";
				for(int i=0;i<35;i++)
{
cout<<char(196);
if(i==10||i==22)
	cout<<char(194);
if(i==0)
		cout<<char(218);
			if(i==34)
		cout<<char(191);
				}
				cout<<endl;
	for(int i=0;i<9;i++){
		SetConsoleTextAttribute(a,6);
		cout<<"  "<<i+1<<"   ";

	SetConsoleTextAttribute(a,1);
		cout<<char(179);
		for(int j=0;j<9;j++)
		{ 
			if(arr[i][j]==0)
			{
			cout<<"_ ";
			}
			else
			{
		
			cout<<arr[i][j]<<" ";
			}
			if(j==2||j==5||j==8)
		cout<<char(179);
			
		cout<<"  ";
		}	
	cout<<endl;
	char c;
	if(i==2||i==5)
	{
		 c=196;
		cout << "      ";
		cout << char(195);
			for(int i=0;i<34;i++)
	{	cout << c;
			if (i==9||i==21)
				cout<<char(197);
/*	if(i==35)
		cout<<char(217);*/}
			c=180;
			cout << c;
			cout << endl;

	}
	//cout<<"      _____________________________________\n";
	
	}
	char c=196;
	cout << "      ";
	for(int i=0;i<32;i++)
		{
			cout << c;
			if(i==0)
				cout<<char(196)&&cout<<char(196)&&cout<<char(196);
			if(i==31)
				cout<<char(217);
	if(i==7||i==19)
		cout<<char(193);
	}
	//cout<<"      _____________________________________\n";
	for(int i=0;i<9;i++)
	{
	for(int j=0;j<9;j++)
	{
	if(arr[i][j]!=0)
		count=count+1;
	}
	}
int	empty=81-count;

	/*SetConsoleTextAttribute(a,7);*/
	cout<<endl<<endl;	
	SetConsoleTextAttribute(a,6);	
	cout<<"- - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - \n";
		SetConsoleTextAttribute(a,1);	
	cout<<"Empty slots are:"<<empty<<endl;
	cout<<"Filled slots are:"<<count;cout<< "       Type -1 and press Enter to save the game\n";
	SetConsoleTextAttribute(a,1);             
	game_prog=(count*100)/81;
	SetConsoleTextAttribute(a,4);	
	cout<<"Game progress:"<<game_prog<<" % \n";
SetConsoleTextAttribute(a,6);
cout<<"- - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - \n";
			SetConsoleTextAttribute(a,4);
	if(empty==0&&count==1)
			{
			cout<<"Congratulations! You Win!!!!\n";
			}
SetConsoleTextAttribute(a,7);
numb:
cout<<"\nEnter Row number:";
	while (!(cin >> row_num))
	{
		if(terminator1==0)
cout << "Sorry only integer values are Accepted,Enter again:";
		cin.clear();
		cin.ignore();
		terminator1++;

	}
			if(row_num==-1)
	{
	savegame(arr);
	}
			else if (row_num>9||row_num<-1)
	{
		cout<<"Number is not valid , Enter again: "<<endl;
goto numb;
}
cout<<"Enter Column number:";
	while (!(cin >> col_num))
	{
		if(terminator2==0)
		cout << "Sorry only integer values are Accepted,Enter again:";
		cin.clear();
		cin.ignore();
		terminator2++;

	}
		if(col_num==-1)
	{
	savegame(arr);
	}
		else if (col_num>9||col_num<0)
	{
		cout<<"Number is not valid , Enter again: "<<endl;
goto numb;
}
numb1:
cout<<"Enter the number for row "<<row_num<<" and column "<<col_num<<" :";
		while (!(cin >> num))
	{
		if(terminator3==0)
	cout << "Sorry only integer values are Accepted,Enter again:";
		cin.clear();
		cin.ignore();
		terminator3++;

	}
if(num>9||num<0)
	{
		cout<<"Number is not valid , Enter again: "<<endl;
goto numb1;
}
if(arr[row_num-1][col_num-1]==0)
{
flag= rowcheck(row_num-1,num,arr);
flag1= colcheck(col_num-1,num,arr);
block=blocksearch(row_num-1,col_num-1,num,arr);
if(flag==false||flag1==false||block==true)
{
cout<<"Sorry this number is already occupied , Enter again:\n";
	goto numb1;
}
else if(flag1==true&&flag==true&&block==false)
	arr[row_num-1][col_num-1]=num;
system("CLS");
continue;
}
else
	cout<<"Enter the number again this is already filled:";
goto numb;
	}

}
bool rowcheck(int r,int num,int arr[9][9])
{
	bool flag=true;
for(int i=0;i<9;i++)
{ 
	if(arr[r][i]==num)
		flag= false;
}

return flag;
}
bool colcheck(int c,int num,int arr[9][9])
{
	bool flag=true;
for(int i=0;i<9;i++)
{ 
	if(arr[i][c]==num)
		flag= false;
}
return flag;
}
bool blocksearch(int r,int c,int num,int arr[9][9])
{
	bool block=false;
if(r<=2&&r>=0)
{
	if(c<=2&&c>=0)
	{
	for(int i=0;i<=2;i++)
	{
	for(int j=0;j<=2;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}

		if(c<=5&&c>=3)
	{
	for(int i=0;i<=2;i++)
	{
	for(int j=3;j<=5;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}

	if(c<=8&&c>=6)
	{
	for(int i=0;i<=2;i++)
	{
	for(int j=6;j<=8;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}
}






if(r<=5&&r>=3)
{
	if(c<=2&&c>=0)
	{
	for(int i=3;i<=5;i++)
	{
	for(int j=0;j<=2;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}

		if(c<=5&&c>=3)
	{
	for(int i=3;i<=5;i++)
	{
	for(int j=3;j<=5;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}

	if(c<=8&&c>=6)
	{
	for(int i=3;i<=5;i++)
	{
	for(int j=6;j<=8;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}
}










if(r<=8&&r>=6)
{
	if(c<=2&&c>=0)
	{
	for(int i=6;i<=8;i++)
	{
	for(int j=0;j<=2;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}

		if(c<=5&&c>=3)
	{
	for(int i=6;i<=8;i++)
	{
	for(int j=3;j<=5;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}

	if(c<=8&&c>=6)
	{
	for(int i=6;i<=8;i++)
	{
	for(int j=6;j<=8;j++)
	{
	if(arr[i][j]==num)
	{
	block=true;
		break;
	}
	}
	}
	return block;
	}
}
}
void loadfunc()
{
	system("Color 0D");
	int item=0, run2, x=7;
	bool run_1 = true;
	system("CLS");
		gotoXY(18,5); cout << "Main Menu";
	gotoXY(18,7); cout << "->";
	
	while(run_1)
	{
                gotoXY(20,7);  cout << "1) Game 1";
		gotoXY(20,8);  cout << "2) Game 2";
		gotoXY(20,9);  cout << "3) Game 3";
		gotoXY(20,10); cout << "4) Game 4";
		gotoXY(20,11); cout << "Back to main menu";

		system("pause>nul"); 
		
		if(GetAsyncKeyState(VK_DOWN) && x != 11) 
			{ 
				system("CLS");
					gotoXY(18,5); cout << "SAVED GAMES";
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) 
			{	gotoXY(18,5); cout << "SAVED GAMES";
				system("CLS");
	gotoXY(18,5); cout << "SAVED GAMES";
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ 
				gotoXY(18,5); cout << "SAVED GAMES";
			system("CLS");
				gotoXY(18,5); cout << "SAVED GAMES";
			switch(item){
				
				case 0: {
					
					gotoXY(20,16);
					game1();
					break;
				}
					
					
				case 1: {
					gotoXY(20,16);
					game2();
					break;
				}
					
				case 2: {
					gotoXY(20,16);
					game1();
					break;
				}
					
				case 3: {
					gotoXY(20,16);
					game4();
					break;
				}
					
				case 4: {
					gotoXY(20,16);
					cout << "Thank You!";
					run_1 = false;
				}
				
			}
				
		}		
		
	}
	
	gotoXY(20,21);
}
void game1()
{
int arr1[9][9];
ifstream fr("game1.txt");
for(int i=0;i<9;i++)
{
	for(int j=0;j<9;j++){
	fr>>arr1[i][j];
	}
}
consoleoutput(arr1);
}
void game2()
{
int arr2[9][9];
ifstream fr("game2.txt");
for(int i=0;i<9;i++)
{ 
	for(int j=0;j<9;j++){
	fr>>arr2[i][j];
	}
}
consoleoutput(arr2);
}
void game3()
{
int arr3[9][9];
ifstream fr("game3.txt");
for(int i=0;i<9;i++)
{
	for(int j=0;j<9;j++){
	fr>>arr3[i][j];
	}
}
consoleoutput(arr3);
}
void game4()
{
int arr3[9][9];
ifstream fr("game4.txt");
for(int i=0;i<9;i++)
{
	for(int j=0;j<9;j++){
	fr>>arr3[i][j];
	}
}
consoleoutput(arr3);
}
void savegame(int arr[9][9])
{ system("CLS");
SetConsoleTextAttribute(a,11);	
		int menu_item=0, run, x=7;
	bool running = true;
		while(running)
	{
       gotoXY(20,7);  cout << "1) SLOT 1";
		gotoXY(20,8);  cout << "2) SLOT 2";
		gotoXY(20,9);  cout << "3) SLOT 3";
		gotoXY(20,10); cout << "4) SLOT 4";
		gotoXY(20,11); cout << "LOAD GAME";

		system("pause>nul"); 
		
		if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
			{system("CLS");
		gotoXY(18,5); cout << "Save Games";
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
        system("CLS");
				gotoXY(18,5); cout << "Save Games";
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
				gotoXY(18,5); cout << "SAVE GAME";
			switch(menu_item){
				
				case 0: {
					
					gotoXY(20,16);
					system("CLS");
					game1save( arr );
					break;
				}
					
					
				case 1: {
					gotoXY(20,16);
					system("CLS");
					game2save( arr );
					break;
				}
					
				case 2: {
					gotoXY(15,15);
						game3save( arr );
							system("CLS");
				
					break;
						}
					
				case 3: {
					game4save( arr );
					gotoXY(30,8);
					system("CLS");
					
					break;
				}
				system("CLS");	
				case 4: {
					gotoXY(20,16);
				loadfunc();
				break;
					running = false;
				}
				
			}
				
		}		
		
	}
	
	gotoXY(20,21);
}

void game1save(int arr[9][9])
{
ofstream fw("game1.txt");
for(int i=0;i<9;i++)
{
	for(int j=0;j<9;j++){
	fw<<arr[i][j]<<" ";
	}
}
cout<<endl;
}
void game2save(int arr[9][9])
{
ofstream fw("game2.txt");
for(int i=0;i<9;i++)
{
	for(int j=0;j<9;j++){
	fw<<arr[i][j]<<" ";
	}
cout<<endl;
}
}
void game3save(int arr[9][9])
{
ofstream fw("game3.txt");
for(int i=0;i<9;i++)
{
	for(int j=0;j<9;j++){
	fw<<arr[i][j]<<" ";
	}
cout<<endl;
}
}
void game4save(int arr[9][9])
{
ofstream fw("game4.txt");
for(int i=0;i<9;i++)
{
	for(int j=0;j<9;j++){
	fw<<arr[i][j]<<" ";
	}
cout<<endl;
}
}
