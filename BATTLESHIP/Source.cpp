#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;
const int s= 12;
int game_forPlayer1[s][s] = {};
int ship1_length4 = 0;
int ship1_length3 = 0;
int ship2_length3 = 0;
int ship1_length2 = 0;
int ship2_length2 = 0;
int ship3_length2 = 0;
int ship1_length1= 0;
int ship2_length1= 0;
int ship3_length1= 0;
int ship4_length1= 0;
//player2
int game_forPlayer2[s][s] = {};
int ship1_length4_forPlayer2 = 0;
int ship1_length3_forPlayer2 = 0;
int ship2_length3_forPlayer2 = 0;
int ship1_length2_forPlayer2 = 0;
int ship2_length2_forPlayer2 = 0;
int ship3_length2_forPlayer2 = 0;
int ship1_length1_forPlayer2 = 0;
int ship2_length1_forPlayer2 = 0;
int ship3_length1_forPlayer2 = 0;
int ship4_length1_forPlayer2 = 0;
void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}
#define bold_start "[1m" 
#define bold_end "[0m"
int  Choice() {
	cout << endl << endl << endl;
	mysetcolor(11, 0);
	cout << "\t\t\t\t\tM A N U A L - - - -> [0]" << endl;
	cout << endl;
	mysetcolor(14, 0);
	cout << "\t\t\t\t\tR A N D O M - - - -> [1]" << endl;
	cout << endl << endl << endl;
	mysetcolor(7, 0);
	int choice = 0;
	char esc_char = 27;
	cout << esc_char << bold_start << "\t\t\t\t\tenter choice : " << esc_char << bold_end ;
	cin >> choice;
	cout << endl;
	return choice;
}
void ShowGame(int P2orP1) {
	if (P2orP1 == 1) {
		for (size_t i = 0; i < s; i++)
		{
			for (size_t k = 0; k < s; k++) {
				cout << game_forPlayer1[i][k] << " ";
			}
			cout << endl;
		}

	}
	else {
		for (size_t i = 0; i < s; i++)
		{
			for (size_t k = 0; k < s; k++) {
				cout << game_forPlayer2[i][k] << " ";
			}
			cout << endl;
		}
	}
}
//Y=y+1
//X=x-64
void ShowCoordinates() {
	system("cls");
	
	char symbol = 254;
	cout << endl;
	cout << "\t\t\t\t\t   0 1 2 3 4 5 6 7 8 9" << endl;
	for (size_t i = 1; i < s - 1; i++) {
		cout << "\t\t\t\t\t " << (char)(65 + i - 1) << " ";
		for (size_t k = 1; k < s - 1; k++)
		{
			if (game_forPlayer1[i][k] == 0) {
				mysetcolor(8, 0);
				cout << symbol << " ";
				mysetcolor(7, 0);
			}
			else if (game_forPlayer1[i][k] == 2) {
				mysetcolor(14, 0);
				cout << symbol << " ";
				mysetcolor(7, 0);
			}
			else if (game_forPlayer1[i][k] == 1) {
				mysetcolor(10, 0);
				cout << char(30) << " ";
				mysetcolor(7, 0);
			}
		}
		cout << endl;
	}
	cout << endl;
}
void ShowAllGame() {
	system("cls");
	//ShowCoordinates();
	//ShowGame(2);
	mysetcolor(11, 0);
	cout << "\t\t   P L A Y E R 1\t\t\t\t    P L A Y E R 2" << endl;
	mysetcolor(7, 0);
	char symbol = 254;
	cout << endl;
	cout << "\t\t  0 1 2 3 4 5 6 7 8 9\t\t\t\t   0 1 2 3 4 5 6 7 8 9" << endl;
	for (size_t i = 1; i < s - 1; i++) {
		cout  << "\t\t"<<(char)(65 + i - 1) << " ";
		for (size_t k = 1; k < s - 1; k++)
		{
			if (game_forPlayer1[i][k] == 0 || game_forPlayer1[i][k] == 2) {
				mysetcolor(8, 0);
				cout << symbol << " ";
				mysetcolor(7, 0);
			}
			else if (game_forPlayer1[i][k] == 9) {
				mysetcolor(12, 0);
				cout << "X" << " ";
			
				mysetcolor(7, 0);
			}
			else if (game_forPlayer1[i][k] == 1) {
				mysetcolor(10, 0);
				cout << char(30) << " ";
				mysetcolor(7, 0);
			}
			else if (game_forPlayer1[i][k] == 3) {
				mysetcolor(15, 0);
				cout << symbol << " ";
				mysetcolor(7, 0);
			}
		}
		cout << "\t\t\t\t " << (char)(65 + i - 1) << " ";
		for (size_t k = 1; k < s - 1; k++) {
			if (game_forPlayer2[i][k] == 0 || game_forPlayer2[i][k] == 2|| game_forPlayer2[i][k] == 1) {
				mysetcolor(8, 0);
				cout << symbol << " ";
				mysetcolor(7, 0);
			}
			else if (game_forPlayer2[i][k] == 9) {
				mysetcolor(12, 0);
				cout << "X" << " ";
				
				mysetcolor(7, 0);
			}
			/*else if (game_forPlayer2[i][k] == 1) {
				mysetcolor(10, 0);
				cout << char(30) << " ";
				mysetcolor(7, 0);
			}*/
			else if (game_forPlayer2[i][k] == 3) {
				mysetcolor(15, 0);
				cout << symbol << " ";
				mysetcolor(7, 0);
			}
		}
		cout << endl;
	}
}
void PlaceFrames(int X, int Y, int length_ship, char VerticalOrHorizontal,int P1orP2) {
	if (VerticalOrHorizontal == 'V') {
		for (size_t i = Y - 1; i < Y + 2; i++) {//up & down sides
			if (P1orP2 == 1) {
				game_forPlayer1[X - 1][i] = 2;
				game_forPlayer1[X + length_ship][i] = 2;
			}
			else {
				game_forPlayer2[X - 1][i] = 2;
				game_forPlayer2[X + length_ship][i] = 2;
			}
		}	
	for (size_t i = X; i < X + length_ship; i++) {//right & left sides
		if (P1orP2 == 1) {		
			game_forPlayer1[i][Y - 1] = 2;
			game_forPlayer1[i][Y + 1] = 2;
		}
		else {
			game_forPlayer2[i][Y - 1] = 2;
			game_forPlayer2[i][Y + 1] = 2;
		}
	}
}
	else if (VerticalOrHorizontal == 'H') {
		for (size_t i = Y - 1; i < Y + length_ship + 1; i++){//up & down sides
			if (P1orP2 == 1) {
				game_forPlayer1[X - 1][i] = 2;
				game_forPlayer1[X + 1][i] = 2;
			}
			else {
				game_forPlayer2[X - 1][i] = 2;
				game_forPlayer2[X + 1][i] = 2;
			};
		}
		for (size_t i = X; i < X + 1; i++) {//right & left sides
			if (P1orP2 == 1) {
				game_forPlayer1[i][Y - 1] = 2;
				game_forPlayer1[i][Y + length_ship] = 2;
			}
			else {
				game_forPlayer2[i][Y - 1] = 2;
				game_forPlayer2[i][Y + length_ship] = 2;
			}
		}
	}
}
bool hasFrame(int X,int Y,int length_ship, char VerticalOrHorizontal,int P1orP2) {
	bool false_true = true;
	if (VerticalOrHorizontal == 'V') {
		 for (size_t i = Y-1; i < Y + 2; i++)//up & down sides
		 {
			 if (P1orP2 == 1) {
				 if (game_forPlayer1[X - 1][i] != 0 && game_forPlayer1[X + length_ship][i] != 0 && game_forPlayer1[X - 1][i] != 2 && game_forPlayer1[X + length_ship][i] != 2) {
					 return false;
				 }
			 }
			 else {
				 if (game_forPlayer2[X - 1][i] != 0 && game_forPlayer2[X + length_ship][i] != 0 && game_forPlayer2[X - 1][i] != 2 && game_forPlayer2[X + length_ship][i] != 2) {
					 return false;
				 }
			 }
		 }
		 for (size_t i = X; i < X + length_ship; i++) {//right & left sides
			 if (P1orP2 == 1) {
					if (game_forPlayer1[i][Y - 1] != 0 && game_forPlayer1[i][Y + 1] != 0 && game_forPlayer1[i][Y - 1] != 2 && game_forPlayer1[i][Y + 1] != 2) {
									return false;
					 }
			 }
			 else {
				 if (game_forPlayer2[i][Y - 1] != 0 && game_forPlayer2[i][Y + 1] != 0 && game_forPlayer2[i][Y - 1] != 2 && game_forPlayer2[i][Y + 1] != 2) {
					 return false;
				 }
			 }
			 
		 }		 
	}
	else if (VerticalOrHorizontal == 'H') {
		for (size_t i = Y-1 ; i < Y + length_ship+1; i++)//up & down sides
		{
			if (P1orP2 == 1) {
				if (game_forPlayer1[X - 1][i] != 0 && game_forPlayer1[X + 1][i] != 0 && game_forPlayer1[X - 1][i] != 2 && game_forPlayer1[X + 1][i] != 2) {
					return  false;
				}
			}
			else {
				if (game_forPlayer2[X - 1][i] != 0 && game_forPlayer2[X + 1][i] != 0 && game_forPlayer2[X - 1][i] != 2 && game_forPlayer2[X + 1][i] != 2) {
					return  false;
				}
			}
		}
		for (size_t i = X; i < X + 1; i++) {//right & left sides
			if (P1orP2==1) {
				if (game_forPlayer1[i][Y - 1] != 0 && game_forPlayer1[i][Y + 1] != 0 && game_forPlayer1[i][Y - 1] != 2 && game_forPlayer1[i][Y + 1] != 2) {
					return  false;
				}
			}
			else {
				if (game_forPlayer2[i][Y - 1] != 0 && game_forPlayer2[i][Y + 1] != 0 && game_forPlayer2[i][Y - 1] != 2 && game_forPlayer2[i][Y + 1] != 2) {
					return  false;
				}
			}
		}
	}
	return true;
}
bool GetOkayToPlace(int X, int Y, int length_ship, int side,int P1orP2) {
	bool false_true = 0;
	if (side == 1 && hasFrame(X -length_ship+1,Y,length_ship,'V',P1orP2)) {//Up
		for (size_t i = X; i > X - length_ship; i--) {
			if (P1orP2 == 1) {
				if (game_forPlayer1[i][Y] == 0) {
					false_true = 1;
				}
				else {
					false_true = 0;
					return false_true;
				}
			}
			else {
				if (game_forPlayer2[i][Y] == 0) {
					false_true = 1;
				}
				else {
					false_true = 0;
					return false_true;
				}
			}
		}

	}
	else if (side == 2 && X + length_ship <=s-1 && hasFrame(X, Y, length_ship,'V',P1orP2)) {//down
		for (size_t i = X ; i < X  + length_ship; i++) {
			if (P1orP2 == 1) {
				if (game_forPlayer1[i][Y] == 0) {
					false_true = 1;
				}
				else {
					false_true = 0;
					return false_true;
				}
			}
			else {
				if (game_forPlayer2[i][Y] == 0) {
					false_true = 1;
				}
				else {
					false_true = 0;
					return false_true;
				}
			}
		}
	}
	else if (side == 3 && Y+ length_ship <s && hasFrame(X,Y,length_ship,'H', P1orP2)) {//right
		for (size_t i = Y; i < Y + length_ship ; i++) {
			if (P1orP2 == 1) {
				if (game_forPlayer1[X][i] == 0) {
					false_true = 1;
				}
				else {
					false_true = 0;
					return false_true;
				}
			}
			else {
				if (game_forPlayer2[X][i] == 0) {
					false_true = 1;
				}
				else {
					false_true = 0;
					return false_true;
				}
			}
		}
	}
	else if (side==4 && hasFrame(X, Y - length_ship + 1,length_ship,'H', P1orP2)) {//left
		for (size_t i = Y; i > Y - length_ship; i--) {
			if (P1orP2 == 1) {
				if (game_forPlayer1[X][i] == 0) {
					false_true = 1;
				}
				else {
					false_true = 0;
					return false_true;
				}
			}
			else {
				if (game_forPlayer2[X][i] == 0) {
					false_true = 1;
				}
				else {
					false_true = 0;
					return false_true;
				}
			}
		}
	}
	return false_true;
}
bool hasFinished() {
	bool true_false;
	for (size_t i = 0; i < s; i++)
	{
		for (size_t k = 0; k < s; k++) {
			if (game_forPlayer1[i][k] == 1) {
				return false;
			}
		}
	}
	return true;
}
bool hasFinished2() {
	bool true_false;
	for (size_t i = 0; i < s; i++)
	{
		for (size_t k = 0; k < s; k++) {
			if (game_forPlayer2[i][k] == 1) {
				return false;
			}
		}
	}
	return true;
}
bool Finish() {
	if (hasFinished()) {
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\tP L A Y E R 2  i s  W I N N E R !" << endl;
		return true;
	}
	if (hasFinished2()) {
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\tP L A Y E R 1  i s  W I N N E R !" << endl;
		return true;
	}
	return false;
}
void PlaceShips(int X, int Y, int length_ship, int side,int & Ship,int P1orP2) {
	if (side == 1) {
		PlaceFrames(X - length_ship + 1, Y, length_ship, 'V',P1orP2);
		for (size_t i = X ; i >X  - length_ship; i--) {			
			if (P1orP2 == 1) {
				game_forPlayer1[i][Y] = 1;
			}
			else {
				game_forPlayer2[i][Y] = 1;
			}
		}
		Ship = 1;
	}
	else if (side == 2 ) {
		PlaceFrames(X, Y, length_ship, 'V', P1orP2);
		for (size_t i = X ; i < X  + length_ship; i++) {		
			if (P1orP2 == 1) {
				game_forPlayer1[i][Y] = 1;
			}
			else {
				game_forPlayer2[i][Y] = 1;
			}
		}
		Ship = 1;
	}
	else if (side == 3) {
		PlaceFrames(X, Y, length_ship, 'H', P1orP2);
		for (size_t i = Y; i < Y + length_ship; i++) {
			if (P1orP2 == 1) {
				game_forPlayer1[X][i] = 1;
			}
			else {
				game_forPlayer2[X][i] = 1;
			}
		}
		Ship = 1;
	}
	else if (side == 4) {
		PlaceFrames(X, Y - length_ship + 1, length_ship, 'H', P1orP2);
		for (size_t i = Y; i > Y - length_ship; i--) {
			if (P1orP2 == 1) {
				game_forPlayer1[X][i] = 1;
			}
			else {
				game_forPlayer2[X][i] = 1;
			}
		}
		Ship = 1;
	}
}
void GetCoordinatesForManual(int &Ship,int &length_ship,int P1orP2=1) {
	char coordinate_X = 0;
	int coordinate_Y = 0;
	bool okay = false;
	int choiceUDLR = 0;
	ShowCoordinates( );
		mysetcolor(3, 0);
		cout << "SHIP length --> " << length_ship << endl;
		mysetcolor(7, 0);
		cout << "Enter coordinate X & Y to place (Ex: A1) : ";
		cin >> coordinate_X;
		if (coordinate_X < 65 || coordinate_X>74) {
			mysetcolor(12, 0);
			cout << "\t\t\t\t\tIt is not a coordinate!  " << endl << endl;
			mysetcolor(7, 0);
			Sleep(1000);
		}
		cin >> coordinate_Y;
		if (coordinate_Y < 0 || coordinate_Y>9) {
			mysetcolor(12, 0);
			cout << "\t\t\t\t\tIt is not a coordinate!  " << endl << endl;
			mysetcolor(7, 0);
			Sleep(1000);
		}
		cout << endl;
		mysetcolor(11, 0);
		cout << "UP     [1]" << endl;
		mysetcolor(10, 0);
		cout << "DOWN   [2]" << endl;
		mysetcolor(14, 0);
		cout << "RIGHT  [3]" << endl;
		mysetcolor(12, 0);
		cout << "LEFT   [4]" << endl;
		mysetcolor(7, 0);
		cout << "enter : ";
		cin >> choiceUDLR;
		okay = GetOkayToPlace(coordinate_X-64, coordinate_Y+1, length_ship, choiceUDLR,P1orP2);
		if (okay) {
			PlaceShips(coordinate_X - 64, coordinate_Y + 1, length_ship, choiceUDLR, Ship, P1orP2);
		}
		else {
			mysetcolor(4, 0);
			cout << "T h i s    p l a c e    i s     f u l l !" << endl;
			mysetcolor(7, 0);
			Sleep(1000);
			cout << endl;
	}	
}

void GetCoordinatesForRandom(int& Ship, int length_ship,int P1orP2=1) {
	{
		srand(time(0));
		int min = 0;
		int max = 9;
		bool okay = 0;
		int coordinate_X = (min) + rand() % (max   - (min ) + 1);
		int coordinate_Y = min + rand() % (max - min + 1);
		int choiceUDLR = 1 + rand() % (4);
		okay = GetOkayToPlace(coordinate_X +1, coordinate_Y + 1, length_ship, choiceUDLR,P1orP2);
		if (okay) {
			PlaceShips(coordinate_X +1, coordinate_Y + 1, length_ship, choiceUDLR, Ship, P1orP2);
			ShowCoordinates();
		}
	}
}
void SetTillPlaced(int&ship,int length_ship,char &RandomOrManual,int P1orP2=1){
	if (RandomOrManual == 'M') {
		while (ship == 0) {
			GetCoordinatesForManual(ship, length_ship);
		}
	}
	else {
		while (ship == 0) {
			GetCoordinatesForRandom(ship, length_ship,P1orP2);
		}	
	}
}
void RandomOrManual(char randomOrmanual) {
	SetTillPlaced(ship1_length4, 4,randomOrmanual);
	SetTillPlaced(ship1_length3, 3,randomOrmanual);
	SetTillPlaced(ship2_length3, 3,randomOrmanual);
	SetTillPlaced(ship1_length2, 2,randomOrmanual);
	SetTillPlaced(ship2_length2, 2,randomOrmanual);
	SetTillPlaced(ship3_length2, 2,randomOrmanual);
	SetTillPlaced(ship1_length1, 1,randomOrmanual);
	SetTillPlaced(ship2_length1, 1,randomOrmanual);
	SetTillPlaced(ship3_length1, 1,randomOrmanual);
	SetTillPlaced(ship4_length1, 1,randomOrmanual);
	
}
void RandomForPlayer2(char random) {
	SetTillPlaced(ship1_length4_forPlayer2, 4, random,2);
	SetTillPlaced(ship1_length3_forPlayer2, 3, random,2);
	SetTillPlaced(ship2_length3_forPlayer2, 3, random,2);
	SetTillPlaced(ship1_length2_forPlayer2, 2, random,2);
	SetTillPlaced(ship2_length2_forPlayer2, 2, random,2);
	SetTillPlaced(ship3_length2_forPlayer2, 2, random,2);
	SetTillPlaced(ship1_length1_forPlayer2, 1, random,2);
	SetTillPlaced(ship2_length1_forPlayer2, 1, random,2);
	SetTillPlaced(ship3_length1_forPlayer2, 1, random,2);
	SetTillPlaced(ship4_length1_forPlayer2, 1, random,2);
}

void SetPlayer2() {
	RandomForPlayer2('R');
}

void SetCoordinateStage() {
	system("cls");
	int choice = Choice();
	if (choice < 2) {
		if (choice == 1) {
			RandomOrManual('R');
		}
		else {
			RandomOrManual('M');
			Sleep(1500);
		}
	}
	else {
		mysetcolor(12, 0);
		cout <<  "\t\t\t\t\tIt is not a choice!  " << endl<<endl;
		mysetcolor(7, 0);
	}
	SetPlayer2();
	//ShowCoordinates();
}
void Show_Text(string text,int fg,int bg=0,int Time = 50)
{
	for (int i = 0; i < text.length(); i++)
	{
		mysetcolor(fg, bg);
		cout << text[i];
		Sleep(Time);
	}cout << endl;
	mysetcolor(7, 0);
}
void StartStage() {
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t\t\t\tS t a r t  G A M E --->[1] " << endl<<endl;
	cout << "\t\t\t\t\tA b o u t  G A M E --->[2] " << endl<<endl;
	cout << "\t\t\t\t\tenter : ";
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		SetCoordinateStage();
	}
	else {
		system("cls");
		cout << endl << endl << endl;
		
		Show_Text("\tS y m b o l s ",15,9);
		char symb = 254;
		mysetcolor(8, 0);
		cout << endl;
		cout <<"\t"<< symb;		
		Show_Text(" - Empty coordinate  ", 7, 0);
		mysetcolor(2, 0);
		cout << endl;
		cout << "\t" << (char)30;
		Show_Text(" - Ship coordinate  ", 7, 0);
		mysetcolor(15, 0);
		cout << endl;
		cout << "\t" << symb;
		Show_Text(" - Shooted empty coordinate  ", 7, 0);
		mysetcolor(4, 0);
		cout << endl;
		cout << "\t" << (char)30;
		Show_Text(" - Shooted ship coordinate  ", 7, 0);
		cout << endl << endl;;
		cout << "\tS t a r t  G A M E --->[1]  "<<endl;
		int choice;
		cout << "\tenter : ";
		cin >> choice;
		if (choice == 1) {
			SetCoordinateStage();
		}
		//Show_Text();
	}
}
bool IsShipCoordinateForPlayer2(int ShootedX, int ShootedY) {
	if (game_forPlayer1[ShootedX][ShootedY] == 1|| game_forPlayer1[ShootedX][ShootedY] == 9) {
		return true;
	}
	return false;
}
bool IsShipCoordinateForPlayer1( int ShootedX, int ShootedY) {
			if (game_forPlayer2[ShootedX][ShootedY] == 1|| game_forPlayer2[ShootedX][ShootedY] == 9) {
				return true;
			}			
			return false;
}
void Shoot( int ShootedX,int ShootedY,int P1orP2) {
	if (P1orP2 == 1) {
		if(IsShipCoordinateForPlayer1(ShootedX, ShootedY)) {
		        game_forPlayer2[ShootedX][ShootedY] = 9;
	     }
		else {
			game_forPlayer2[ShootedX][ShootedY] = 3;
		}
	}
	else if(P1orP2 == 2 ) {
		if (IsShipCoordinateForPlayer2(ShootedX, ShootedY)) {
			game_forPlayer1[ShootedX][ShootedY] = 9;
		}
		else {
			game_forPlayer1[ShootedX][ShootedY] = 3;
		}
	}
}
int GetRandom() {
	
	int min = 0;
	int max = 9;
	int coordinate = (min)+rand() % (max - (min)+1);
	return coordinate;
}
bool HasSank(int ShootedX, int ShootedY, int P1orP2) {
	if (P1orP2 == 1) {
		for (size_t i = ShootedX - 1; i < ShootedX + 2; i++) {
			for (size_t k = ShootedY - 1; k < ShootedY + 2; k++)
			{
				if (i == ShootedX && k == ShootedY) {					
				}
				else {
					if (game_forPlayer2[i][k] == 1) {
						return false;
					}
				}
			}
		}
	}
	else {
		for (size_t i = ShootedX - 1; i < ShootedX + 2; i++) {
			for (size_t k = ShootedY - 1; k < ShootedY + 2; k++)
			{
				if (i == ShootedX && k == ShootedY) {
				}
				else {
					if (game_forPlayer1[i][k] == 1) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
bool IsEmpty(int ShootedX, int ShootedY, int P1orP2) {
	bool false_true = true;
	if (P1orP2 == 1) {
		
		for (size_t i = ShootedX - 1; i < ShootedX + 2; i++) {
			for (size_t k = ShootedY - 1; k < ShootedY + 2; k++)
			{
				if (game_forPlayer2[i][k] ==9 ) {
					return true;
				}
			}			
		}
	}
	else {
		for (size_t i = ShootedX - 1; i < ShootedX + 2; i++) {
			for (size_t k = ShootedY - 1; k < ShootedY + 2; k++)
			{
				if (game_forPlayer1[i][k] == 9) {
					return true;
				}
			}
		}
	}
	return false;
}
void ShootFrames(int ShootedX, int ShootedY, int P1orP2) {
	if (P1orP2 == 1) {
		for (size_t i = ShootedX - 1; i < ShootedX + 2; i++) {
			for (size_t k = ShootedY - 1; k < ShootedY + 2; k++)
			{
				if (game_forPlayer2[i][k] == 2) {
					game_forPlayer2[i][k] = 3;
				}
			}
		}
	}
	else {
		for (size_t i = ShootedX - 1; i < ShootedX + 2; i++) {
			for (size_t k = ShootedY - 1; k < ShootedY + 2; k++)
			{
				if (game_forPlayer1[i][k] == 2) {
					game_forPlayer1[i][k] = 3;
				}
			}
		}
	}
}
char HorizontalOrVertical(int ShootedX, int ShootedY, int P1orP2) {
	if (P1orP2 == 1) {
		if(game_forPlayer2[ShootedX][ShootedY]==9 && game_forPlayer2[ShootedX][ShootedY-1] == 9
			|| game_forPlayer2[ShootedX][ShootedY] == 9&& game_forPlayer2[ShootedX][ShootedY +1] == 9
			)
		{
			return 'H';
		}
		else {
			return 'V';
		}
	}
	else if (P1orP2 == 2) {
		if (game_forPlayer1[ShootedX][ShootedY] == 9 && game_forPlayer1[ShootedX][ShootedY - 1] == 9
			|| game_forPlayer1[ShootedX][ShootedY] == 9 && game_forPlayer1[ShootedX][ShootedY + 1] == 9
			)
		{
			return 'H';
		}
		else {
			return 'V';
		}
	}
}
int GetEnd(int ShootedX, int ShootedY, int P1orP2, char HorizontalOrVertical) {
	int end = 0;
	if (P1orP2 == 1) {
		if (HorizontalOrVertical == 'V') {
			end = ShootedX;
			while (true) {
				if (game_forPlayer2[end + 1][ShootedY] == 9) {
					end++;
				}
				else {
					break;
				}
			}
		}
			else {
				end = ShootedY;
				while (true) {
				if (game_forPlayer2[ShootedX][end + 1] == 9) {
					end++;
				}
				else {
					break;
				}
			}			
		}		
	}
	else if (P1orP2 == 2) {
		if (HorizontalOrVertical == 'V') {
			end = ShootedX;
			while (true) {
				if (game_forPlayer1[end + 1][ShootedY] == 9) {
					end++;
				}
				else {
					break;
				}
			}
		}
		else {
			end = ShootedY;
			while (true) {
				if (game_forPlayer1[ShootedX][end + 1] == 9) {
					end++;
				}
				else {
					break;
				}
			}
		}
	}
	return end;
}
int GetStart(int ShootedX, int ShootedY, int P1orP2, char HorizontalOrVertical) {
	int start = 0;
	if (P1orP2 == 1) {
		if (HorizontalOrVertical == 'V') {
			start = ShootedX;
			while(true){

				if (game_forPlayer2[start - 1][ShootedY] == 9) {
					start--;
				}
				else {
					break;
				}
			}
		}
		else {
				start = ShootedY;
				while (true) {
					if (game_forPlayer2[ShootedX][start - 1] == 9) {
						start--;
					}
					else {
						break;
					}
				}
			}
		}
	else if (P1orP2 == 2) {
		if (HorizontalOrVertical == 'V') {
			start = ShootedX;
			while (true) {

				if (game_forPlayer1[start - 1][ShootedY] == 9) {
					start--;
				}
				else {
					break;
				}
			}
		}
		else {
			start = ShootedY;
			while (true) {
				if (game_forPlayer1[ShootedX][start - 1] == 9) {
					start--;
				}
				else {
					break;
				}
			}
		}
	}
	
	return start;
}
char HorizontalOrVertical2(int X,int Y) {
	if (game_forPlayer1[X][Y] == 1 && game_forPlayer1[X][Y - 1] == 1
		|| game_forPlayer1[X][Y] == 1 && game_forPlayer1[X][Y + 1] == 1
		)
	{
		return 'H';
	}
	else {
		return 'V';
	}
}
void GameStage() {
	while(true  &&!Finish()) {
	ShowAllGame();
	cout << endl;
	cout << "Enter coordinate to shoot (Ex : A1) : ";
	char coordinate_X = '  ';
	cin >> coordinate_X;	
	if (coordinate_X< 65 || coordinate_X>74) {
		mysetcolor(12, 0);
		cout << "\t\t\t\t\tIt is not a coordinate!  " << endl ;
		mysetcolor(7, 0);		
		Sleep(1000);
		cin.ignore();
	    cin.clear();
		continue;
	}
	int coordinate_Y = 0;
	cin >> coordinate_Y;
	if (coordinate_Y < 0 || coordinate_Y>9) {
		mysetcolor(12, 0);
		cout << "\t\t\t\t\tIt is not a coordinate!  " << endl << endl;
		mysetcolor(7, 0);
		Sleep(1000);
		continue;
	}
	cout << endl;
	if (game_forPlayer2[coordinate_X - 64][coordinate_Y + 1] == 3 || game_forPlayer2[coordinate_X - 64][coordinate_Y + 1] == 9) {
		mysetcolor(12, 0);
		cout << "\t\t\t\t\tCoordinate has already been shooted ! " << endl << endl;
		mysetcolor(7, 0);
		Sleep(1000);
		continue;
	}
	if (IsShipCoordinateForPlayer1(coordinate_X - 64, coordinate_Y + 1)) {
		Shoot(coordinate_X - 64, coordinate_Y + 1, 1);
		if (Finish()) {
			return;
		}
		ShowAllGame();
		if (IsEmpty(coordinate_X - 64, coordinate_Y + 1, 1)&&!Finish()) {
			if (HasSank(coordinate_X - 64, coordinate_Y + 1, 1)) {
				mysetcolor(12, 0);
				auto horizontalOrVertical= HorizontalOrVertical(coordinate_X - 64, coordinate_Y + 1, 1);
				int end = GetEnd(coordinate_X - 64, coordinate_Y + 1, 1, horizontalOrVertical);
				int start = GetStart(coordinate_X - 64, coordinate_Y + 1, 1, horizontalOrVertical);

				if (horizontalOrVertical == 'V') {
					for (size_t i = start; i < end+1; i++)
					{
						ShootFrames(i, coordinate_Y + 1, 1);
					}
				}
				else if (horizontalOrVertical == 'H') {
					for (size_t i = start; i < end+1; i++)
					{
						ShootFrames(coordinate_X - 64, i, 1);
					}
				}
				 if (start==end) {
					ShootFrames(coordinate_X - 64, coordinate_Y + 1, 1);
				}		
				cout << "\t\t\t\t\t T h e    s h i p   S A N K " << endl;				
				mysetcolor(7, 0);				
				Sleep(1500);
			}
		}
		continue;
	}
	else {
		Shoot(coordinate_X - 64, coordinate_Y + 1, 1);
		if (Finish()) {
			return;
		}
		ShowAllGame();
		if (IsEmpty(coordinate_X - 64, coordinate_Y + 1, 1)) {
			if (HasSank(coordinate_X - 64, coordinate_Y + 1, 1)) {
				mysetcolor(12, 0);
				auto horizontalOrVertical = HorizontalOrVertical(coordinate_X - 64, coordinate_Y + 1, 1);
				int end = GetEnd(coordinate_X - 64, coordinate_Y + 1, 1, horizontalOrVertical);
				int start = GetStart(coordinate_X - 64, coordinate_Y + 1, 1, horizontalOrVertical);
				if (horizontalOrVertical == 'V') {
					for (size_t i = start; i < end + 1; i++)
					{
						ShootFrames(i, coordinate_Y + 1, 1);
					}
				}
				else if (horizontalOrVertical == 'H') {
					for (size_t i = start; i < end + 1; i++)
					{
						ShootFrames(coordinate_X - 64, i, 1);
					}
				}
				if (start == end) {
					ShootFrames(coordinate_X - 64, coordinate_Y + 1, 1);
				}
				cout << "\t\t\t\t\t T h e    s h i p   S A N K " << endl;
				mysetcolor(7, 0);
				Sleep(1500);
			}
		}
	 }	
	srand(time(0));
	coordinate_X = GetRandom()+1;
	coordinate_Y = GetRandom()+1;	
	while (game_forPlayer1[coordinate_X ][coordinate_Y ] == 3 || game_forPlayer1[coordinate_X ][coordinate_Y ] == 9) {
		srand(time(0));
		coordinate_X = GetRandom()+1;
		coordinate_Y = GetRandom()+1;		
	}
	Shoot(coordinate_X , coordinate_Y , 2);
	if (Finish()) {
		return;
	}
		ShowAllGame();
	/*cout << "X-->" << (int)coordinate_X << endl;
	cout << "Y-->" << coordinate_Y << endl;
	cout << "X-->" << (int)coordinate_X +1<< endl;
	cout << "Y-->" << coordinate_Y +1<< endl;
	Sleep(2500);*/

	while (IsShipCoordinateForPlayer2(coordinate_X , coordinate_Y ) && !Finish()) {
		srand(time(0));
		int temp = coordinate_Y;
		int temp1 = coordinate_X;
		auto horizontalOrVertical = HorizontalOrVertical2(coordinate_X , coordinate_Y );			
			if (horizontalOrVertical == 'H') {
				while (!HasSank(coordinate_X , coordinate_Y , 2) && !Finish()) {
					if (game_forPlayer1[coordinate_X ][coordinate_Y + 1] == 1) {
						coordinate_Y ++;
					}
					else if (game_forPlayer1[coordinate_X][--temp] == 1) {
						coordinate_Y =temp;
					}
					else {
						
						Shoot(coordinate_X, coordinate_Y, 2);
						if (Finish()) {
							return;
						}
						ShowAllGame();
						break;
					}
					Shoot(coordinate_X, coordinate_Y, 2);
					if (Finish()) {
						return;
					}
					ShowAllGame();
				}
			}
			else if (horizontalOrVertical == 'V') {
				while (!HasSank(coordinate_X , coordinate_Y , 2)&&!Finish()) {
				if (game_forPlayer1[coordinate_X + 1][coordinate_Y ] == 1) {
					coordinate_X += 1;
				}
				else if (game_forPlayer1[--temp1][coordinate_Y] == 1) {
					coordinate_X = temp1;
				}
				else {
					Shoot(coordinate_X, coordinate_Y, 2);
					if (Finish()) {
						return;
					}
					ShowAllGame();
					break;
				}
				Shoot(coordinate_X, coordinate_Y, 2);
				if (Finish()) {
					return;
				}
				ShowAllGame();
			}
			while (game_forPlayer1[coordinate_X ][coordinate_Y] == 3 || game_forPlayer1[coordinate_X ][coordinate_Y] == 9) {
				srand(time(0));
				coordinate_X = GetRandom()+1;
				coordinate_Y = GetRandom()+1;
				
			}
			Shoot(coordinate_X, coordinate_Y, 2);
			if (Finish()) {
				return;
			}
			ShowAllGame();
		}
	}
	}
}
void main() {
	StartStage();
	
	GameStage();
}
//coordinates
//Ship -->1
// Ship frame-->2
//empty-->0