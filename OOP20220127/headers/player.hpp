#pragma once

#include "../headers/hand.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <exception>

namespace rps {
/**
 * @brief Abstract base class for players.
 */
class player_t {
public:
	/**
	 * @brief Construct a new player_t object.
	 * 
	 * @param name The player's name.
	 * @param num_of_lives The number of lives of the player.
	 */
	player_t(const std::string& name, uint8_t num_of_lives) 
		: _hand{hand_t::state_t::None}, _name(name), _num_of_lives{num_of_lives}
	{}
	
	/**
	 * @brief Destroy the player_t object.
	 * 
	 */
	virtual ~player_t() = default;

	/**
	 * @brief Getter for the player's hand.
	 * 
	 * @return hand_t Player's hand.
	 */
	hand_t hand() const noexcept { return _hand; 			 }

	/**
	 * @brief Getter for the player's name.
	 * 
	 * @return std::string Player's name.
	 */
	std::string name() const noexcept { return _name;			 }

	/**
	 * @brief We can ask the player is still alive.
	 * 
	 * @return true Player is alive.
	 * @return false Player has losed.
	 */
	bool is_alive() const noexcept { return _num_of_lives > 0; }

	/**
	 * @brief Decrement the player's number of lives.
	 * 
	 */
	void decrement() noexcept {
		if(_num_of_lives > 0)
			--_num_of_lives;
	}

	/**
	 * @brief Player is getting ready. Random state of hand computation.
	 * 
	 */
	virtual void prepare() = 0;
	
	/**
	 * @brief Extern operator function for default player_t object print out.
	 * 
	 * @return std::ostream& Modified output datastream.
	 */
	friend std::ostream& operator<<(std::ostream&, const player_t&);

protected:
	hand_t 		_hand;

private:
	std::string _name;
	uint8_t 	_num_of_lives;
};

/**
 * @brief Operator function for default player_t object print out. Only the player's name has written.
 * 
 * @param out Arbitrary output datastream.
 * @param player Type of player_t object.
 * @return std::ostream& Modified output datastream.
 */
inline
std::ostream& operator<<(std::ostream& out, const player_t& player) {
	return out << player._name;
}

/**
 * @brief Real person as a player representation class. Inherited from player_t abstract class.
 * 
 */
class manual_player_t : public player_t {
public:
	/**
	 * @brief Construct a new manual_player_t object.
	 * 
	 * @param name The player's name.
	 * @param num_of_lives The number of lives of the player.
	 */
	manual_player_t(const std::string& name, uint8_t num_of_lives) 
		: player_t(name, num_of_lives) {}

	/**
	 * @brief Preparation for the player. Read in a hand state code and set up.
	 * 
	 */
	void prepare() override {
		// std::cin >> _hand;
		int x;
		std::cin >> x;
		if(1 <= x && x <= 3){
			_hand = static_cast<hand_t::state_t>(x);
		}else{
			throw std::range_error{"Out of range."};
		}
	}
	
};

/**
 * @brief Robot player representation class. Inherited from the player_t abstract class.
 * 
 */
class robot_player_t : public player_t {
public:
	/**
	 * @brief Construct a new robot player object.
	 * 
	 * @param name The robot player's name.
	 * @param num_of_lives The number of lives of the robot.
	 */
	robot_player_t(const std::string& name, uint8_t num_of_lives) 
		: player_t(name, num_of_lives) {}
	
	/**
	 * @brief Preparation for the robot. Random generated hand state code and set up.
	 * 
	 */
	void prepare() override {
		static std::random_device rd;
		static std::seed_seq ssq{rd()};
		static std::mt19937 gen{ssq};
		static std::uniform_int_distribution distr{1, 3};

		_hand = static_cast<hand_t::state_t>(distr(gen));
	}

};

}