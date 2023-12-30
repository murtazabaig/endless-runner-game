#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include <fstream>

using namespace std;

const int width = 50;
const int height = 15;
const int ground = height - 2;
const int gravity = 1;

int posx = 0;
int posy = ground;
int velx = 0;
int vely = 0; 
int speed_inc =1;
int score = 0; 
int max_score=0;
int life = 5;
bool game = true;

void initializeGameScreen(string game_sc[]) {
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (i == ground) {
                game_sc[i] += "=";
            }
            else {
                game_sc[i] += " ";
            }
        }
    }
}

void updateGameScreen(string game_sc[]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == posx && i == posy) {
                game_sc[i][j] = '^';
            }
            else if (i == ground + 1 && j == width - 1) {
                game_sc[i][j] = ' ';
                if (rand() % 8 == 0) {
                    game_sc[i-1][j - 1] = '#';
                }
                else if (rand() % 10 == 0) {
                    game_sc[i-1][j - 1] = '$';
                }
            }
            else if (game_sc[i][j] == '#' && j > 0) {
                game_sc[i][j - 1] = '#';
                game_sc[i][j] = ' ';
            }
            else if (game_sc[i][j] == '$' && j > 0) {
                game_sc[i][j - 1] = '$';
                game_sc[i][j] = ' ';
            }
            else if (i == 6) {
                game_sc[i][j] = '/';
            }
            else if (i == ground + 1) {
                game_sc[i][j] = '//';
            }
            else {
                game_sc[i][j] = ' ';
            }
        }
    }
}

void printGameScreen(string game_sc[]) {
    for (int y = 0; y < height; y++) {
        cout << game_sc[y];
        cout << endl;
    }
}

void handleInput() {
    if (GetAsyncKeyState(VK_LEFT)) {
        velx = -1;
    }
    else if (GetAsyncKeyState(VK_RIGHT)) {
        velx = 1;
    }
    else {
        velx = 0;
    }

    vely += gravity;
    if (GetAsyncKeyState(VK_SPACE) && posy == ground) {
        vely = -2;
    }
    else if (GetAsyncKeyState(VK_DOWN)) {
        posy = ground;
    }
}

void checkForCollision(string game_sc[]) {
    if (game_sc[posy][posx] == '#') {
        life--;
    }
    else if (game_sc[posy][posx] == '$') {
        score += 10;
        game_sc[posy][posx] = ' ';
    }
    else {
        score++;
        if (score % 10 == 0 && score > 0) {
            velx += speed_inc;
        }
    }
}

void saveScore(string name) {
    ifstream inFile;
    inFile.open("scores.txt", ios::out);
    inFile >> max_score ;
    inFile.close();

    if(max_score<score){
        ofstream outFile;
        outFile.open("scores.txt", ios::in);
        outFile << score << endl;
        outFile.close();
    }
}

void playGame() {
    string game_sc[height];
    string name;
    initializeGameScreen(game_sc);
    while (life > 0) {
        handleInput();
        posx += velx;
        posy += vely;
        if (posx >= width) {
            posx = width - 1;
        }
        if (posx < 0) {
            posx = 0;
        }
        if (posy >= ground) {
            posy = ground;
        }
        updateGameScreen(game_sc);
        printGameScreen(game_sc);
        checkForCollision(game_sc);
        cout << "Score: " << score << endl;
        cout << "Life: " << life << endl;
        Sleep(90);
        system("cls");
    }
    saveScore(name);
    cout << "Game Over! Your score is: " << score << endl;
}

int main() {
    string name; 
    cout << "Enter your name: ";
    cin >> name;

    playGame();

    return 0;


const int width = 50;
const int height = 15;
const int ground = height - 2;
const int gravity = 1;
{
int posx = 0;
int posy = ground;
srand(time(NULL));

int velx = 0;
int vely = 0; 
int speed_inc =1;
int score = 0;
int max_score=0;
int life = 5;
bool game = true;
ifstream inFile;
inFile.open("scores.txt", ios::out);
//outFile << "Name: " << name << "  ";
inFile >> max_score ;
inFile.close();
cout<<"highest score yet"<<max_score;
string game_sc[height];
string name;
cout << "enter your name: ";
cin >> name;
for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
        if (i == ground) {
            game_sc[i] += "=";
        }
        else {
            game_sc[i] += " ";
        }
    }
}

system("cls");
while (life > 0) {
    if (GetAsyncKeyState(VK_LEFT)) {
        velx = -1;
    }
    else if (GetAsyncKeyState(VK_RIGHT)) {
        velx = 1;
    }
    else {
        velx = 0;
    }


    vely += gravity;
    if (GetAsyncKeyState(VK_SPACE) && posy == ground) {
        vely = -2;
    }
    else if (GetAsyncKeyState(VK_DOWN)) {
        posy = ground;
    }

    posx += velx;
    posy += vely;
	if (score % 10 == 0 && score > 0) {
	velx += speed_inc;
	}

    if (posx >= width) {
        posx = width - 1;

    }
    if (posx < 0) {
        posx = 0;
    }
    if (posy >= ground) {
        posy = ground;
    }

    // Update game screen
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == posx && i == posy) {
                game_sc[i][j] = '^';
            }
            else if (i == ground + 1 && j == width - 1) {
                game_sc[i][j] = ' ';
                if (rand() % 8 == 0) {
                    game_sc[i-1][j - 1] = '#';
                }
            }
            else if (game_sc[i][j] == '#' && j > 0) {
                game_sc[i][j - 1] = '#';
                game_sc[i][j] = ' ';
            }
            else if (i == 6) {
                game_sc[i][j] = '/';
            }
            else if (i == ground + 1) {
                game_sc[i][j] = '//';
            }
            else {
                game_sc[i][j] = ' ';
            }
        }
    }
    // Print game screen
    for (int y = 0; y < height; y++) {
        cout << game_sc[y];
        cout << endl;
    }
    
    // Check for collision with obstacles
  if (game_sc[posy][posx] == '#') {
    life--;
}
else 
    score++;
// else if (posx == width - 3) {
    // Increment score if obstacle is avoided
   // score++;
    
  

    // Print score
    cout << "Score: " << score << endl;
    cout << "Life: " << life << endl;
    Sleep(90);
    system("cls");
}
if(max_score<score){

ofstream outFile;
outFile.open("scores.txt", ios::in);
//outFile << "Name: " << name << "  ";
outFile << score << endl;
outFile.close();
}
cout << "Game Over! Your score is: " << score << endl;

return 0;
}
}

