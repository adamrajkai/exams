#pragma once

#include <iostream>
#include "player.hpp"
#include "judge.hpp"

namespace rps {

/**
 * @brief A rock-paper-scissors game match between two players.
 * 
 */
class match_t {
public:
	/**
	 * @brief Construct a new match_t object.
	 * 
	 * @param player1 Left player.
	 * @param player2 Right player.
	 */
	match_t(player_t& player1, player_t& player2);
	
	/**
	 * @brief Destroy the match_t object. Free players and judge.
	 * 
	 */
	~match_t();
	
	/**
	 * @brief We can ask the numbers of rounds.
	 * 
	 * @return uint8_t 
	 */
	uint8_t rounds() const { return _round; }

	/**
	 * @brief We can ask left player's score.
	 * 
	 * @return uint8_t 
	 */
	uint8_t score1() const { return _score1; }

	/**
	 * @brief We can ask right player's score.
	 * 
	 * @return uint8_t 
	 */
	uint8_t score2() const { return _score2; }
	
	/**
	 * @brief A rock-paper-scissors round between two players.
	 * 
	 */
	void round();
	
	/**
	 * @brief The match goes to end when one of the players is not alive.
	 * 
	 * @return true The match has finished.
	 */
	bool has_finished() const;
	
	/**
	 * @brief We can get the winner player.
	 * 
	 * @return player_t& 
	 */
	player_t& winner() const;
	
	/**
	 * @brief Print out a match to optional output stream.
	 * 
	 * @param out Output stream.
	 * @param match Actual match.
	 * @return std::ostream& Modified output stream.
	 */
	friend std::ostream& operator<<(std::ostream&, const match_t&);
	
private:
	player_t& _player1;
	player_t& _player2;
	uint8_t   _score1;
	uint8_t   _score2;
	judge_t&  _judge;
	uint8_t   _round;
};

std::ostream& operator<<(std::ostream&, const match_t&);

}
