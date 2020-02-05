//Include necessary libs
#include <iostream>

//Init game over boolean
bool gameOver;

//Screen height and width
const int width = 640;
const int height = 480;

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
    system("cls"); //Linux: system("clear");
    for(int i=0;i<width; i++)
        std::cout << "#";
    std::cout << std::endl;

    for (int i=0; i<height; i++){
        for(int j; j < width; j++) {
            if(j==0)
                std::cout << "X";
            else
                std::cout << " ";
            if (j==width-1) {
                std::cout << "#";
            }
        }
    }
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
