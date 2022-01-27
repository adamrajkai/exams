// #include "../headers/player_factory.hpp"
// #include "../headers/player.hpp"

// static rps::player_t& rps::player_factory::create(rps::player_factory::player_type type, const std::string& name, uint8_t num_of_lives) {
// 	rps::player_t* player_ptr = nullptr;
// 	switch(type){
// 	case rps::player_factory::player_type::Manual: player_ptr = new rps::manual_player_t{name, num_of_lives}; break;
// 	case rps::player_factory::player_type::Robot : player_ptr = new rps::robot_player_t{name, num_of_lives};  break;
// 	}
// 	return *player_ptr;
// }