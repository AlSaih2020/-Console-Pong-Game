#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
bool gameover=true;
int bar1X=20,bar2X=29;  //____bars properties___//
int ballX=69,ballY=16;  //____ball properties___//
int mapheight=20,mapwidth=70;   //___map properties___//
int score1=0,score2=0;  //___ball properties___//
enum balldirection { onbar=0,down,downleft,downright,up,upright,upleft,onbar2 }; //___ball directions___//
balldirection balldir;

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void random1(){
srand(time(0));
switch((rand()%3)+1){
case 3:
balldir=down;	
	break;
case 1:
balldir=downright;
    break;
case 2:
balldir=downleft;
break;			
}	
}

void random2(){
srand(time(0));
switch((rand()%3)+1){
case 3:
balldir=up;	
	break;
case 1:
balldir=upright;
    break;
case 2:
balldir=upleft;
break;			
}	
}



void draw()
{
for(int i=0;i<=bar1X;i++){
if(i<bar1X){
	cout<<" ";
}	
else if(i==bar1X){
	cout<<"<><><><><>";
}	
}

for(int i=0;i<=mapheight;i++){
	
	for(int a=0;a<=mapwidth;a++){
	if( (a==mapwidth && i!=0 && i!=mapheight) || (a==0 && i!=0 && i!=mapheight ) ){
		cout<<"|";
	}
	if(i==ballY && a==ballX && i<mapwidth)
	cout<<"O";
	else if(bar2X==a && i==mapheight){
		cout<<"<><><><><>";
		
	}
	
	else{cout<<" ";}
	}
	
	cout<<endl;
}



}
void input()
{
if(_kbhit()){
	
switch(_getch())
{
case 'a':
	bar1X-=4;
	break;
case 'd':
	bar1X+=4;
	break;
case 'j':
	bar2X-=4;
	break;
case 'l':
    bar2X+=4;
    break;
case 'x':
	balldir=onbar;
	break;
    case 'n':
	balldir=up;	
	break;
	case 'c':
	balldir=down;
	break;
    case 'z':
	gameover=false;
	score1=0;
	score2=0;
	balldir=onbar;
	break;	
    
}	

}
	
}
void logic()
{
	
switch(balldir){

	case down:
		ballY+=1;
	break;
		case onbar:
		ballY=19;
		ballX=bar2X+4;
		break;
	case downleft:
		ballY+=1;
		ballX-=1;
		break;
	case downright:	
	ballY+=1;
		ballX+=1;
		break;
	case up:
		ballY-=1;
	break;
	case upleft:
		ballY-=1;
		ballX-=1;
		break;
	case upright:	
	ballY-=1;
		ballX+=1;
		break;
    case onbar2:
	ballY=1;
	ballX=bar1X+4; 
}
if(ballY==2 && (ballX==bar1X|| ballX==bar1X-1 || ballX==bar1X+1||ballX==bar1X+2||ballX==bar1X+3||ballX==bar1X+4||ballX==bar1X+5||ballX==bar1X+6||ballX==bar1X+7||ballX==bar1X+8||ballX==bar1X+9) ){
	random1();}
if(ballY==19 && (ballX==bar2X|| ballX==bar2X-1 || ballX==bar2X+1||ballX==bar2X+2||ballX==bar2X+3||ballX==bar2X+4||ballX==bar2X+5||ballX==bar2X+6||ballX==bar2X+7||ballX==bar2X+8||ballX==bar2X+9) && (balldir==down || balldir==downright || balldir==downleft) ){
	random2();
}	
if(ballX==69 && balldir==downright)
balldir=downleft;
if(ballX==69 && balldir==upright)
balldir=upleft;
if(ballX==3 && balldir==downleft)
balldir=downright;
if(ballX==3 && balldir==upleft)
balldir=upright;
if(ballY==21){
score1+=10;
balldir=onbar2;}
if(ballY==0){
score2+=10;
balldir=onbar;}

}
int main() {
	while(gameover)
	{input();clearScreen();
cout<<"PLAYER 1 CONTROLS ARE [A],[D],[c]PLAYER 2 CONTROLS ARE [J],[L],[n]/NTO START THE GAME TO RESET PRESS [Z]";
    }
	while(!gameover){
		clearScreen();
		hidecursor();
	cout<<score1;
		draw();
		input();
		logic();
		cout<<score2<<endl;
		
	}
	return 0;
}

