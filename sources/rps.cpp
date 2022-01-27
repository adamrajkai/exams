#include <iostream>
#include <string>
#include "../headers/match.hpp"
#include "../headers/player.hpp"
#include "../headers/player_factory.hpp"

void print_menu(){
	std::cout << "0. exit\n";
	std::cout << "1. player with robot\n";
	std::cout << "2. player with player\n";
	std::cout << "3. robot with robot\n";
}

int game() {
	std::cout << "Menu: \n\n";
	print_menu();
	
	int choiced = getchar() - 48;
	
	if(choiced == EXIT_SUCCESS) exit(EXIT_SUCCESS);
	
	std::string 
		player1_name = "robot1",
		player2_name = "robot2"
	;
	
	rps::player_factory::player_type 
		player1_type = rps::player_factory::player_type::Robot, 
		player2_type = rps::player_factory::player_type::Robot
	;
	
	if(choiced < 3){
		const std::string texts[] = {
			"Please enter your name: ",
			"Frist player\'s name? ",
			"Second player\'s name? "
		};
		
		player1_type = rps::player_factory::player_type::Manual;
		std::cout << texts[choiced-1];
		std::cin.get();
		std::getline(std::cin, player1_name);
		
		if(choiced == 2){
			player2_type = rps::player_factory::player_type::Manual;
			std::cout << texts[choiced];
			std::getline(std::cin, player2_name);
		}
	}
	
	rps::player_t& player1 = rps::player_factory::create(player1_type, player1_name, 3);
	rps::player_t& player2 = rps::player_factory::create(player2_type, player2_name, 3);
	
	rps::match_t match(player1, player2);
	
	bool end = false;
	do{
		do{
			std::cout << match << '\n';
			match.round();
		}while(!match.has_finished());
		
		std::cout << "The winner: " << match.winner();

		std::cout << "\nOne more match? (Y/N)\n";
		if(std::tolower(getchar()) == 'n') 
			end = true;
		else {
			const char* command = "cls";
#ifdef LINUX
			command = "clear";
#endif
			system(command);
		}
	}while(!end);

	return 0;
}