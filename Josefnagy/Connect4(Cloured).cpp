#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
bool menu(int play);
void welcomescreen();
void howtoplay();
void players(string player[2]);
void gameboard(string arrgameboard[8][8], string player[2], int score[2], int color);
void intialize_arr(string arrgameboard[8][8]);
void gameplay(string arrgameboard[8][8], string player[2], string symbols[2],int turn,bool& win, int score[2],int color);
void check(int playernum, string symbols[2], string arrgameboard[8][8], string player[2],bool& win,int score[2]);
void congrats();
void bye();
int main(){
	int color;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); srand(time(NULL)); //coloring
	SetConsoleTextAttribute(hConsole,color= rand() % 3 + 1);//coloring
	ofstream out_file; //game history
	out_file.open("output.txt"); //game history
	bool play=0;
	string player[2];
	while (play = menu(play) )
	{ //play==1==true
		int score[2] = { 0,0 };
		if (play)
		{
			players(player); 
		}
		while (play) {
			

			string symbols[2] = {  "X","O" }; // player [0]== player1  score[0]  symbol[0]  ' a '==64561a

			string arrgameboard[8][8];
			bool win = false;

			intialize_arr(arrgameboard);
			gameboard(arrgameboard, player, score,color);
			for (int turn = 1; turn <= 33; turn++) {
				if (win == true) { congrats();  cout << endl << "\t\t\t" << player[0] << " score : " << score[0] << "\t\t\t\t" << player[1] << " score : " << score[1] << endl<<endl;  break;
				}
				if (turn == 33) { cout << "No One Wins" << endl; break;
				cout << endl << "\t\t\t" << player[0] << " score : " << score[0] << "\t\t\t\t" << player[1] << " score : " << score[1] << endl;
				}
				gameplay(arrgameboard, player, symbols, turn, win, score,color);
			}
			cout << "Do you want to play again???!!!(Press 'y' or 'Y' for Yes OR 'n' or 'N' for No)" << endl;
			string choice;
			cin.ignore(); getline(cin, choice);
			if (choice == "y" || choice == "Y") {
				system("cls"); welcomescreen(); continue; ;
			}
			else {
				system("cls");
				break; }
		}
	}

	{ system("cls");

	cout<<"\t\t\t\t\tGoodBye. I hope you enjoyed our game :) :D"<<endl; }
	
	bye();
	
	
	system("Pause");
}
void welcomescreen() {
	cout << "              #####################################################################################" << endl;
	cout << "              #   ______   ______  .__   __..__   __. _______   ______ .___________.      _  _    #" << endl;
	cout << "              #  /      | /  __  \\ |  \\ |  ||  \\ |  ||   ____| /      ||           |     | || |   #" << endl;
	cout << "              # |  ,----'|  |  |  ||   \\|  ||   \\|  ||  |__   |  ,----'`---|  |----`     | || |_  #" << endl;
	cout << "              # |  |     |  |  |  ||  . `  ||  . `  ||   __|  |  |         |  |          |__   _| #" << endl;
	cout << "              # |  `----.|  `--'  ||  |\\   ||  |\\   ||  |____ |  `----.    |  |             | |   #" << endl;
	cout << "              #  \\______| \\______/ |__| \\__||__| \\__||_______| \\______|    |__|             |_|   #" << endl;
	cout << "              #####################################################################################" << endl;
	cout << "   " << endl;

		
}
void players(string player[2]) {
	welcomescreen();
	cout << "Enter first Player Name: ";
	cin.clear(); cin.ignore(10000, '\n');
	getline(cin, player[0]); 
	cout << "Enter second Player Name: ";
	getline(cin, player[1]);
	system("cls");
	welcomescreen();
}
void intialize_arr(string arrgameboard[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			arrgameboard[i][j] =".";
		}
	}
}
void gameboard(string arrgameboard[8][8], string player[2],int score[2], int color) {
	int l1, l2, l3,l4;
	
	cout <<endl<<"\t\t\t"<< player[0] << " score : " << score[0] <<"\t\t\t\t" << player[1] << " score : " << score[1]<<endl<<endl;

	cout << "\t\t\t\t\tChoose a column Number!"<<endl;
	for (l1 = 0; l1 < 8; l1++) {
		cout << "\t\t\t";
		for ( l2 = 0; l2 < 8; l2++) {
			cout << " ___\t"; // celling
		}cout << endl; cout << "\t\t\t";
		for ( l3 = 0; l3 < 8; l3++) {
			cout << "| ";
			/* cout << arrgameboard[l1][l3];*/
			
					if (arrgameboard[l1][l3] == "X")
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); cout << arrgameboard[l1][l3];
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
					}
					else if (arrgameboard[l1][l3] == "O")
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout << arrgameboard[l1][l3];
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

					}
					else { cout << arrgameboard[l1][l3]; }
			                                    
			cout  << " |\t";
		}cout << endl; 
	}
	cout << "\t\t\t";
	for (l4 = 1; l4 < 9; l4++) {
		cout << "--"<<l4<<"--\t";
	}
	cout << endl;

}
void gameplay(string arrgameboard[8][8], string player[2], string symbols[2],int turn,bool&win, int score[2],int color) {
	int playernum;
	for ( playernum = 0; playernum <= 1; playernum++) {
		if (win == true) { break; } 
		bool again = false;
		do {
			again = false;
			
			int column;
			do {
				cout << "\t" << player[playernum] << "'s turn "<<'('<<symbols[playernum]<<") : ";
				 if ((!(cin >> column))||(column <1 ||column>8)) {
					 cout << "Please enter a number between 1 and 8." << endl;
					 cin.clear(); cin.ignore(10000, '\n');  //patch bug ---> idsgifuge kugewydf
				 }
				 else { break; }
			
			} while (true); 
			for (int row = 7; row >= -1; row--) { //Drop
				if (row == -1) {
					cout << "Unavaliable Move! choose another Column"<<endl; again = true; break;
				}// column =1
				else if (arrgameboard[row][column - 1] == ".") { arrgameboard[row][column - 1] = symbols[playernum]; break; }
				else if (arrgameboard[row][column - 1] != ".") { continue; }
				
			}

			system("cls");
			welcomescreen();
			gameboard(arrgameboard, player, score,color);
			if (turn > 3) {
				check(playernum, symbols,arrgameboard,player,win,score);
			}

		} while (again==true);

	}
	

}
void check(int playernum, string symbols[2], string arrgameboard[8][8], string player[2],bool& win,int score[2]) {
	int counter_columns = 0, counter_rows = 0, counter_diagonal1 = 0, counter_diagonal2 = 0, counter_diagonal3 = 0, counter_diagonal4 = 0;
	//cout <<"Before Looping"<< counter_columns << "  " << counter_rows << "  " << counter_diagonal1 << "  " << counter_diagonal2 << "  " << counter_diagonal3 << "  " << counter_diagonal4<<endl;

	for (int check_rows1 = 0; check_rows1 <=7; check_rows1++) {
		counter_rows = 0;
		for (int check_rows2 = 0; check_rows2 <8; check_rows2++) {
			if (symbols[playernum] == arrgameboard[check_rows1][check_rows2]) {
				counter_rows++;                    //0             //7
				if (counter_rows == 4) { cout <<endl<<"\t\t\t\t\t"<< player[playernum] << "'s the winner"<<endl; win = true;
				score[playernum]++;break;
				}
			}
			
			else { counter_rows = 0; }

		}
	}
	for (int check_columns1 = 0; check_columns1 < 8; check_columns1++) {
		counter_columns = 0;
		for (int check_columns2 = 7; check_columns2 >= 0; check_columns2--) {
			if (symbols[playernum] == arrgameboard[check_columns2][check_columns1]) {
				counter_columns++;                       //7,6          //0
				if (counter_columns == 4) { cout << endl << "\t\t\t\t\t" << player[playernum] << "'s the winner" << endl; win = true;
				score[playernum]++;break;
				}
			}
			
			else { counter_columns = 0; }
		}
	}

	for (int diagonal_leftdown = 0; diagonal_leftdown < 5; diagonal_leftdown++) {
		counter_diagonal1 = 0;
		for (int dia1 = 7, dia2 = diagonal_leftdown; dia1 >= 0; dia1--, dia2++) {
			if (symbols[playernum] == arrgameboard[dia1][dia2]) {
				counter_diagonal1++;
				if (counter_diagonal1 == 4) { cout << endl << "\t\t\t\t\t" << player[playernum] << "'s the winner" << endl; win = true;
				score[playernum]++;break;
				}
			}
			else { counter_diagonal1 = 0; }

		}
	}
	counter_diagonal2 = 0;
	for (int diagonal_rightup = 6; diagonal_rightup > 2; diagonal_rightup--) {
		counter_diagonal2 = 0;
		for (int dia1 = 0, dia2 = diagonal_rightup; dia1 <= 6; dia1++, dia2--) {
			if (symbols[playernum] == arrgameboard[dia1][dia2]) {
				counter_diagonal2++;
				if (counter_diagonal2 == 4) { cout << endl << "\t\t\t\t\t" << player[playernum] << "'s the winner" << endl; win = true;
				score[playernum]++;break;
				}
			}
			else { counter_diagonal2 = 0; }

		}
	}
	counter_diagonal3 = 0;
	for (int diagonal_rightdown = 7; diagonal_rightdown > 2; diagonal_rightdown--) {
		counter_diagonal3 = 0;
		for (int dia1 = 7, dia2 = diagonal_rightdown; dia1 >= 0; dia1--, dia2--) {
			if (symbols[playernum] == arrgameboard[dia1][dia2]) {
				counter_diagonal3++;
				if (counter_diagonal3 == 4) { cout << endl << "\t\t\t\t\t" << player[playernum] << "'s the winner" << endl; win = true;
				score[playernum]++;break;
				}
			}
			else { counter_diagonal3 = 0; }

		}
	}
	counter_diagonal4 = 0;
	for (int diagonal_leftup = 1; diagonal_leftup < 5; diagonal_leftup++) {
		counter_diagonal4 = 0;
		for (int dia1 = 0, dia2 = diagonal_leftup; dia1 <= 6; dia1++, dia2--) {
			if (symbols[playernum] == arrgameboard[dia1][dia2]) {
				counter_diagonal4++;
				if (counter_diagonal4 == 4) { cout << endl << "\t\t\t\t\t" << player[playernum] << "'s the winner" << endl;  win = true;
				score[playernum]++;break;
				}
			}
			else { counter_diagonal4 = 0; }

		}
	}
	//cout <<"After Looping: "<< counter_columns << "  " << counter_rows << "  " << counter_diagonal1 << "  " << counter_diagonal2 << "  " << counter_diagonal3 << "  " << counter_diagonal4<<endl;
	counter_columns = 0, counter_rows = 0, counter_diagonal1 = 0, counter_diagonal2 = 0, counter_diagonal3 = 0, counter_diagonal4 = 0;
	

}

void congrats() {
	cout << "\t\t  ______   ______  .__   __.  _______ .______           ___     .___________.     _______." << endl;
	cout << "\t\t /      | /  __  \\ |  \\ |  | /  _____||   _  \\         /   \\    |           |    /       |" << endl;
	cout << "\t\t|  ,----'|  |  |  ||   \\|  ||  |  __  |  |_)  |       /  ^  \\   `---|  |----`   |   (----`" << endl;
	cout << "\t\t|  |     |  |  |  ||  . `  ||  | |_ | |      /       /  /_\\  \\      |  |         \\   \\    " << endl;
	cout << "\t\t|  `----.|  `--'  ||  |\\   ||  |__| | |  |\\  \\----. /  _____  \\     |  |     .----)   |   " << endl;
	cout << "\t\t \\______| \\______/ |__| \\__| \\______| | _| `._____|/__/     \\__\\    |__|     |_______/    " << endl;
	cout << "" << endl;

}

void bye() {
	cout << "\t\t\t\t\t.______  ____    ____ _______ " << endl;
	cout << "\t\t\t\t\t|   _  \\ \\   \\  /   /|   ____|" << endl;
	cout << "\t\t\t\t\t|  |_)  | \\   \\/   / |  |__   " << endl;
	cout << "\t\t\t\t\t|   _  <   \\_    _/  |   __|  " << endl;
	cout << "\t\t\t\t\t|  |_)  |    |  |    |  |____ " << endl;
	cout << "\t\t\t\t\t|______/     |__|    |_______|" << endl;
	cout << "" << endl;

}
bool menu(int play) {
	while (true) {
	
		welcomescreen();
		cout << endl << endl << endl;
		cout << "\t\t\t" << "1- PLAY"<<"\t\t\t" << "2-How To Play"<<"\t\t\t" << "3- EXIT" << endl << endl;
		cout << "\t\t\t\t\t\t" << "  Choice: ";

		cin >> play;
		if (play == 1) { system("cls"); return 1; } // play==true //1- PLAY
		else if (play == 2) { 
			howtoplay(); system("Pause"); system("cls"); //2-How To Play
		}
		else if (play == 3) { system("cls"); return 0; } // play==false 3- EXIT
		else {
			cout << "Wrong Choice!"; cout << endl; system("Pause"); system("cls");
		}
	}

}
void howtoplay() {

	cout << "The Rules Are Simple :" << endl;
	cout << "----------------------"<<endl;
	cout <<"The Connect 4 Board Game Rules are easy to understand.In fact, it is in the name.To win Connect Four, all you have to do is connect four of your colored checker pieces in a row, much the same as tic tac toe.This can be done horizontally, vertically or diagonally.Each player will drop in one checker piece at a time by selecting the column number.This will give you a chance to either build your row, or stop your opponent from getting four in a row." << endl;
	cout << "The game is over either when you or your friend reaches four in a row, or when all forty two slots are filled, ending in a stalemate.If you and your friend decide to play again, the loser typically goes first.Cleaning up the game is very easy.The bottom of the vertical game board has a switch that you slide to make the pieces drop out of the board.This is a great opportunity to put the box underneath the game board to collect all of checker pieces together." << endl;
	cout << "The rules of the game are easy to learn, but difficult to master.That is the beauty of Connect Four.Now that you know the Connect 4 board game rules, now is the time to challenge everyone you know.No matter their age or skill level, they can play this game with you.Now that you understand the rules, share Connect Four with everyone around you.You will be glad you did." << endl<<endl;
	 

}
