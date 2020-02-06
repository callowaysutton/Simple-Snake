//Include necessary libs
#include <iostream>

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

//Setup function that sets up all the vars for the game
void Setup() {
    gameOver = false;
    dir = stop;
    
    x = width / 2;
    y = height / 2;

    fruitX = rand() % width;
    fruitY = rand() % height;

    score = 0;
}

//Draws each 'frame' for the game
void Draw() {
    //Clear the Screen
    system("cls"); //Linux: system("clear");

    //Make top wall
    for(int i = 0; i < width+2; i++) { //Need extra characters because we are using one character as an newline
        std::cout << "#";
    }
    std::cout << std::endl;
    
    //Make side Walls
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j == 0)
                std::cout << "#";
            else
                std::cout << " ";

            if (j==width-1)
                std::cout << "#";
        }
    std::cout << std::endl;
    }

    //Make bottom wall
    for(int i = 0; i < width+2; i++) { //Need extra characters since we are using one to go to the next line
        std::cout << "#";
    }
    std::cout << std::endl;
}

//Gets input for game
void Input() {
    
}

//Does the logistics for the input and game
void Logic() {
    
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
        //Sleep();
    }
    return 0;
}