#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Game systems
int rule(char p, char c){
    if (p == c){
        return 0;
    }

    if (p == 'r' && c == 'p'){
        return -1;
    }
    else if (p == 's' && c == 'p'){
        return 1;
    }
    else if (p == 'p' && c == 'r'){
        return 1;
    }
    else if (p == 's' && c == 'r'){
        return -1;
    }
    else if (p == 'r' && c == 's'){
        return 1;
    }
    else if (p == 'p' && c == 's'){
        return -1;
    }
    else if (p != 'p' || p != 's' || p != 'r'){
    	return -2;
	}
}// If -1 then lose, If 1 then won, if -2 draw

int main(){
	int scorePlayer = 0;
	int scoreComputer = 0;
    char computer;
    char player;
    char playmore;

    // Displays the game title
    cout << "\t\t\t\t";
    for(int i = 0; i < 50; i++){
        cout << "-";
    }
    cout << endl;
    cout << "\t\t\t";
    cout << "\t     Welcome to the Rock, Paper, Scissors Game" << endl;
    cout << "\t\t\t\t";
    for(int i = 0; i < 50; i++){
        cout << "-";
    }
    cout << endl;

    // Displays instructions and options for scissors, rock, paper
    cout << "\t\t\t\t";
    cout << "\t Note: " << endl;
    cout << "\t\t\t\t";
    cout << "\t\t r : Rock" << endl << "\t\t\t\t" << "\t\t p : Paper" << endl << "\t\t\t\t" << "\t\t s : scissor" << endl << "\t\t\t\t"<< endl << endl;
    cout << "\t\t\t\t";
    for(int i = 0; i < 50; i++){
        cout << "-";
    }
    cout << endl;

    do {
        int number = 0;

        // Generates a random number between 0 - 99
        srand(time(0));
        number = rand() % 100;

        // Choose computer options based on random numbers
        if (number < 33) {
            computer = 'r';
        } else if (number > 66) {
            computer = 's';
        } else {
            computer = 'p';
        }

        // Requesting Player input
        cout << "\t\t\t\t";
        cout << "Enter your choice: ";
        cin >> player;

        // Call the rule function to determine the result of the game
        int result = rule(player, computer);

        // Displays the results
        if(result == 1){
            cout << "\t\t\t\t";
            cout << "You won! Hurray" << endl;
            //additional score player
            scorePlayer++;
            cout << "\t\t\t\t[Player] : "<<scorePlayer<<" [Computer] : "<<scoreComputer<<endl;
        }
        else if(result == -1){
            cout << "\t\t\t\t";
            cout << "You lose! Bad Luck" << endl;
            //penambahan score computer
            scoreComputer++;
            cout << "\t\t\t\t[Player] : "<<scorePlayer<<" [Computer] : "<<scoreComputer<<endl;
        }
        else if(result == -2){
        	cout << "\t\t\t\t";
            cout << "Can you read bro? (O_o)" << endl;
            
		}
        else{
            cout << "\t\t\t\t";
            cout << "Woah! That's Tie!" << endl;
            cout << "\t\t\t\t[Player] : "<<scorePlayer<<" [Computer] : "<<scoreComputer<<endl;
        }

        // Asks if the player wants to play again

        cout << "\t\t\t\t";
        cout << "Do you want to Play Again?" << endl;
        cout << "\t\t\t\t";
        cout << "Note: Press 'n' to exit! Press 'y' to continue: ";
        cin >> playmore;

        // Displays the separator between game rounds

        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++){
            cout << "-";
        }
        cout << endl;
    } while(playmore != 'n' || playmore == 'y');

    return 0;
}

