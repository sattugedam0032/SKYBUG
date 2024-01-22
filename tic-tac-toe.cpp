
#include<bits/stdc++.h>
using namespace std;

// Global declaration of variables.
char play_ground[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row,column;
char turn = 'X';                
bool draw = false;



void display_ground(){      // virtual playground 

    cout<<"     |     |     \n";
    cout<<"  "<<play_ground[0][0]<<"  | "<<play_ground[0][1]<<"   | "<<play_ground[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<play_ground[1][0]<<"  | "<<play_ground[1][1]<<"   | "<<play_ground[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<play_ground[2][0]<<"  | "<<play_ground[2][1]<<"   | "<<play_ground[2][2]<<" \n";
    cout<<"     |     |     \n";
}

// function for game play.
void player_turn() {
    if (turn == 'X') {
        cout << "Player - 1 [X] turn : ";
    } else if (turn == 'O') {
        cout << "Player - 2 [O] turn : ";
    }

    
    cin >> choice;

    // Mapping the choice to row and column indices
    int mapping[9][2] = {{0, 0}, {0, 1}, {0, 2},
                         {1, 0}, {1, 1}, {1, 2},
                         {2, 0}, {2, 1}, {2, 2}};

    // Validate the user's choice
    if (choice >= 1 && choice <= 9) {
        row = mapping[choice - 1][0];
        column = mapping[choice - 1][1];
    } else {
        cout << "Invalid Move";
        return;
    }

    if (turn == 'X' && play_ground[row][column] != 'X' && play_ground[row][column] != 'O') {
        play_ground[row][column] = 'X';
        turn = 'O';
    } else if (turn == 'O' && play_ground[row][column] != 'X' && play_ground[row][column] != 'O') {
        play_ground[row][column] = 'O';
        turn = 'X';
    } else {
        std::cout << "Box already filled!\nPlease choose another!!";
        player_turn();
    }

    display_ground();
}


bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(play_ground[i][0] == play_ground[i][1] && play_ground[i][0] == play_ground[i][2] || play_ground[0][i] == play_ground[1][i] && play_ground[0][i] == play_ground[2][i])
    return false;

    //checking the win for both diagonal

    if(play_ground[0][0] == play_ground[1][1] && play_ground[0][0] == play_ground[2][2] || play_ground[0][2] == play_ground[1][1] && play_ground[0][2] == play_ground[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(play_ground[i][j] != 'X' && play_ground[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}



int main(){

    while(gameover()){
        display_ground();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"Hola!Player with 'O' has won!!";
    }
    else if(turn == 'O' && draw == false){
        cout<<"Hola!Player with 'X' has won!!";
    }
    else
    cout<<"GAME DRAW!!!";
} 