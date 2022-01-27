#pragma once

#include <string>
#include "player.hpp"

namespace rps {

namespace player_factory {

	/**
	 * @brief Enum class represent the types of players.
	 * 
	 */
	enum class player_type {
		Manual, Robot
	};
	
	/**
	 * @brief Create a player according to a type of player.
	 * 
	 * @param type The player's type.
	 * @param name The player's name.
	 * @param num_of_lives Number of lives of player.
	 * @return player_t& 
	 */
	static player_t& create(player_type type, const std::string& name, uint8_t num_of_lives) {
		player_t* player_ptr = nullptr;
		switch(type){
		case player_type::Manual: player_ptr = new manual_player_t{name, num_of_lives}; break;
		case player_type::Robot : player_ptr = new robot_player_t{name, num_of_lives};  break;
		}
		return *player_ptr;
	}
}

}