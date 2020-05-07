#include <iostream>
#include <stdlib.h>
#include <ctime>


int main()
{
	//Initialize random number generator
	srand((unsigned) time(0));

	//Generate a random number between 0-99
	int rand_number =  rand() % 100;
	// user input
	int input_from_usr;


	do {

		std::cout << "Plz enter your guess (0-99): " << std::endl;
		// get the input from user
		std::cin >> input_from_usr;
		// guessed number is bigger than random one
		if (input_from_usr > rand_number){
			std::cout << "Too big! Try it again." << std::endl;
		}
		// guessed number is smaller than random one
		else if (input_from_usr < rand_number){
			std::cout << "Too small! Try it again." << std::endl;	
		}
		else{
			// You nailed it :)
			std::cout << "You found it :)" << std::endl;
			break;
		}
	}
	while(1);
	
	return 0;
}