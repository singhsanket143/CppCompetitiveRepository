# include<iostream>
# include<ncurses.h>
#include<unistd.h>  
using namespace std;
int R;
int C;
	
//Init the N-Curses System
WINDOW *mainWin;

void startScreen(){

	mainWin = initscr();
	start_color(); /*Init Colors*/

	if(has_colors()){
		init_pair(1,COLOR_RED,COLOR_RED);
		init_pair(2,COLOR_WHITE,COLOR_RED);
		init_pair(3,COLOR_YELLOW,COLOR_YELLOW);
		init_pair(5,COLOR_BLUE,COLOR_BLUE);
		init_pair(4,COLOR_WHITE,COLOR_WHITE);
		init_pair(6,COLOR_GREEN,COLOR_GREEN);
	}
}
void endScreen(){
	refresh();
	sleep(13);
	delwin(mainWin);
	endwin();
	refresh();
}

int getColorId(char ch){

	switch(ch){
		case 'r': return 1;
		case 'w':return 4;
		case 'y':return 3;
		case 'b': return 5;
		default:return 2;
	}
}

void printColoredMatrix(char input[][50]){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			int color_id = getColorId(input[i][j]);
			color_set(color_id,NULL);
			if(input[i][j]<'A'||input[i][j]>='Z'){
				mvaddstr(i,j," ");
			}
			else{
				mvaddch(i,j,input[i][j]);
			}
		}
		cout<<endl;
	}
}


// W,N,E,S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};




void printMat(char input[][50]){

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<input[i][j];
		}
		cout<<endl;
	}

}

//ch is the character to be replaced
//color is the character to be added
void floodFill(char mat[][50],int i,int j,char ch,char color){
	//cout<<"In flood fill"<<endl;

	if(i<0||j<0||i>=R||j>=C){
		return;
	}

	if(mat[i][j]!=ch){
		return;
	}

	printMat(mat);
	cout<<endl;

	mat[i][j] = color;

	for(int k=0;k<4;k++){
		floodFill(mat,i+dx[k],j+dy[k],ch,color);
	}

}



int main(){

	cin>>R>>C;

	char input[15][50];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>input[i][j];
		}
	}

	printMat(input);

	floodFill(input,8,13,'.','r');
	floodFill(input,6,2,'#','b');
	floodFill(input,0,0,'.','w');
	floodFill(input,2,16,'.','y');

	printMat(input);

	startScreen();

	printColoredMatrix(input);

	endScreen();


	return 0;
}