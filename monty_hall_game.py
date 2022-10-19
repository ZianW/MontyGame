import random

def MontyGame(iteration, num_options, keep_choice):
    '''
    This function simulates the Monty Hall game.
    iteration: Amount of cycles that the game should run 
    keep_choice: Indicates whether to stay with the initial choice of door
    num_options: Number of doors, usually 3
    '''
    assert isinstance(iteration, int)
    assert isinstance(num_options, int)
    assert isinstance(keep_choice, bool)
    assert iteration > 0
    assert num_options > 2
    count = 0
    options = list(range(1,num_options+1))
    for i in range(iteration):
        prize_door = random.choice(options)
        initial_choice = random.choice(options)
        door_open = random.choice([number for number in options if number != initial_choice and number != prize_door])
        if keep_choice == True:
            new_choice = initial_choice
        elif keep_choice == False:
            new_choice = random.choice([number for number in options if number != initial_choice and number != door_open])
        if new_choice == prize_door:
            count += 1
    return(count/iteration)


num_options = 3
iteration = 5000
prob_stay = MontyGame(iteration,num_options,keep_choice = True)
prob_switch = MontyGame(iteration,num_options,keep_choice = False)
print('\n The probablity of getting prize when staying with the initial choice is', prob_stay)
print('\n The probablity of getting prize when switching to new choice is', prob_switch)