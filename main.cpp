#include <iostream>
using namespace std;

/*
This function simulates the Monty Hall game.
iteration: Amount of cycles that the game should run 
keep_choice: Indicates whether to stay with the initial choice of door, true means stay, false means switch
options: Number of doors, usually 3
*/
double MontyGame(int iteration, bool keep_choice, int options)
{
    int door_open;
    int new_choice;
    int count = 0;
    for (int i = 0; i < iteration; i++) { 
        int prize_door = 1 + rand() % options;
        int initial_choice = 1 + rand() % options;
        do {
            door_open = 1 + rand() % options;
        }
        while(door_open == initial_choice or door_open == prize_door);
    
        if (keep_choice == true)
        {
            new_choice = initial_choice;
            
        }
        else if (keep_choice == false)
        {
            do {
                new_choice = 1 + rand() % options;
            }
            while(new_choice == initial_choice or new_choice == door_open);
        }
    
        if (new_choice == prize_door)
        {
            count += 1;
        }

    }
    double result = (double)count / iteration;
    return result;
}   

int main()
{
    int iteration = 5000;
    int options = 3;
    bool keep_choice;
    double prob_stay = MontyGame(iteration, keep_choice = true, options);
    double prob_switch = MontyGame(iteration, keep_choice = false, options);
    cout << "The probablity of getting prize when staying with the initial choice is " << prob_stay << "\n"; 
    cout << "The probablity of getting prize when switching to new choice is " << prob_switch << "\n"; 

    return 0;
}

