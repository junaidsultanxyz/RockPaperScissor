#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// FUNCTION PROTOTYPE
bool checkpresent(string a[], int size, string key);
int random(int x);

// VARIABLES 
string rps[3] = {"rock", "paper", "scissor"}; //computer take input from here | we compare our input with this for errors check
string start, playagain, c_choose;
bool check, again = true;
int player= 0, bot= 0; //for score count
int game;

//MAIN BODY
int main() {
 
    //                      COMPUTER BOT
    while (again == true){  //For playing again and again
        system("cls"); //clear screen after every play again for clean console

        cout << " _____________ROCK PAPER SCISSOR_____________"<<endl;
        cout << "|                                            |"<<endl;
        cout << "|    PLAYER : "<<player<<"       |      BOT : "<<bot<<"\t     |"<<endl;
        cout << "|____________________________________________|"<<endl;

        string compinput = rps[random(3)]; //takes random index from array for random input
        char compare = compinput.at(0); //takes first alphabet so we can use in switch

        while (true){
            
            cout << "\nrock, paper or scissor ? : " ;
            getline(cin, start); //getline function for any space input error in string
            cout << endl;

            transform(start.begin(), start.end(), start.begin(), [](unsigned char c) {return tolower(c);});
            //transform converts the input to lowercase

            check = checkpresent(rps, 3, start); //to check if the input is correct that user types

            if (check == false){
                cout << "please give valid input" <<endl;
                continue;
            }else{
                break;  
            }
        }
        switch(compare){ //compares the computer input to user input
            case 'r': 
                //SHORT HAND IF ELSE
                // (start == compinput) ? cout << "DRAW , hence no one won !" <<endl : (start == "paper") ? cout << "you WON !" <<endl : cout << "you LOST! " <<endl;
                
                //NORMAL IF ELSE
                if (start == compinput){
                    cout << "draw , hence no one won !" << endl;
                }else if (start == "paper"){
                    cout << "you WON !" << endl;
                    player++;
                }else{
                    cout << "you LOST ! " << endl;
                    bot++;
                }
                break;

            case 'p':
                // (start == compinput) ? cout << "DRAW , hence no one won !" <<endl : (start == "scissor") ? cout << "you WON !" <<endl : cout << "you LOST! " <<endl;
                if (start == compinput){
                    cout << "draw , hence no one won !" << endl;
                }else if (start == "scissors"){
                    cout << "you WON !" << endl;
                    player++;
                }else{
                    cout << "you LOST ! " << endl;
                    bot++;
                }
                break;

            case 's':
                // (start == compinput) ? cout << "DRAW , hence no one won !" <<endl : (start == "rock") ? cout << "you WON !" <<endl : cout << "you LOST! " <<endl;
                if (start == compinput){
                    cout << "draw , hence no one won !" << endl;
                }else if (start == "rock"){
                    cout << "you WON !" << endl;
                    player++;
                }else{
                    cout << "you LOST ! "  << endl;
                    bot++;
                }
                break;
        }

        cout << "computer chose : " << compinput << endl;

        while (true){
            cout << endl;
            cout << "play again ? (yes or no): " ;
            getline(cin, playagain);

            transform(playagain.begin(), playagain.end(), playagain.begin(), [](unsigned char c) {return tolower(c);});
            
            if (playagain == "yes"){
                break;
            }else if (playagain == "no"){
                cout << "\nty for playing :3 " << endl;
                again=false;
                break;
            }else{
                cout << "\nplease enter valid response !\n" << endl;
                continue;
            }
        }
    }
}

//FUNCTIONS
bool checkpresent(string a[], int size, string key){
    for (int i = 0 ; i < size ; i++){
        if(key == a[i]){
            return true;
        }
    }
    return false;
}

int random(int x){
    x = x;
    srand(time(0));
    return (rand()%3);
}
