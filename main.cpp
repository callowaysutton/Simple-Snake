//Include necessary libs
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

//Init game over boolean
bool gameOver;

//Screen height and width
const int width = 20;
const int height = 20;

//Init the game vars
int x,y,fruitX,fruitY,score;

//Setting up input
enum Direction { stop = 0, left, right, up, down};
Direction dir;

//Function to randomly place fruit
void ranFruit() {
    fruitX = rand() % width;
    fruitY = rand() % height;
}

//Cross-platform sleep function
#ifdef _WIN32
    #include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

//Cross-platform clear screen function
#ifdef _WIN32
    void clearScreen() {
        system("cls");
    }
#else 
    void clearScreen() {
        Linux: system("clear");
    }
#endif

//Setup function that sets up all the vars for the game
void Setup() {
    gameOver = false;
    dir = stop;
    
    x = width / 2;
    y = height / 2;

    ranFruit();

    score = 0;
}

//Draws each 'frame' for the game
void Draw() {
    //Clear the Screen
    //clearScreen();

    //Make top wall
    for(int i = 0; i < width+1; i++) { //Need extra characters because we are using one character as an newline
        std::cout << "#";
    }
    std::cout << std::endl;
    
    //Make side Walls
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j == 0)
                std::cout << "#";

            if(i == y && j == x) {
                std::cout << "O"; //Display player
            } else if(i == fruitY && j == fruitX){
                std::cout << "F"; //Display fruit
            } else {
                std::cout << " ";
            } 

            if (j==width-1)
                std::cout << "#"; // Display walls
        }
    std::cout << std::endl;;
    }

    //Make bottom wall
    for(int i = 0; i < width+1; i++) { //Need extra characters since we are using one to go to the next line
        std::cout << "#";
    }
    std::cout << std::endl;
    
    //Print the score
    std::cout << "Score: " << score << std::flush;
}

//Gets input for game
void Input() {
    //Control handler
    if(_kbhit()){
       switch(_getch()){
        case 'a':
            dir = left;
            break;
        case 'd':
            dir = right;
            break;
        case 's':
            dir = down;
            break;
        case 'w':
            dir = up;
            break;
        case 'q':
            gameOver = true;
            break;
       } 
    }
    
}

//Does the logistics for the input and game
void Logic() {
    //Converts the key inputs into coordinates
    switch(dir) {
        case left:
            x--;
            break;
        case right:
            x++;
            break;
        case up:
            y--;
            break;
        case down:
            y++;
            break;
        default:
            break;
    }

    //Adds death
    if(x > width || x < 0 || y > height || y < 0) {
        gameOver = true;
    }

    //Adds fruit logic and scoring
    if(x==fruitX && y == fruitY) {
        score += 10;
        ranFruit();
    }
}

//Start of program
int main() {
    //Sets up the environment for the game
    Setup();
    
    //Starts game loop until gameover
    while(!gameOver) {
        Draw();
        Input();
        Logic();
        sleep(5);
        clearScreen();
    }
    return 0;
}