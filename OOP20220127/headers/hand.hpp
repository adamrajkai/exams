#pragma once

#include <iostream>

namespace rps {
/**
 * @brief An arbitary player's hand.
 * 
 */
class hand_t {
public:
	/**
	 * @brief Strongly typed enum class representing the possible states of the hand.
	 * 
	 */
	enum class state_t {
		None, Rock, Paper, Scissors
	};
	
	friend std::istream& operator>>(std::istream&, hand_t&);
	friend std::ostream& operator<<(std::ostream&, const hand_t);

	/**
	 * @brief Construct a new hand_t object.
	 * 
	 * @param state The hand state (Rock, Paper, Scissors).
	 */
	hand_t(const state_t state=state_t::None) : _state{state} {}

	/**
	 * @brief We can get for the hand's actual state.
	 * 
	 * @return state_t 
	 */
	state_t state() const { return _state; }

	/**
	 * @brief Convert the hand of state to string.
	 * 
	 * @return std::string 
	 */
	std::string to_string() const {
		switch (_state){
		case state_t::Rock		: return "Rock"; 	 break;
		case state_t::Paper		: return "Paper";  	 break;
		case state_t::Scissors	: return "Scissors"; break;
		default					: return "None"; 	 break;
		}
	}

private:
	state_t _state;
};

/**
 * @brief Read hand state from arbitrary input datastream.
 * 
 * @param in Input datastream.
 * @param state 
 * @return std::istream&
 */
inline
std::istream& operator>>(std::istream& in, hand_t::state_t& state) {
	int x;
	in >> x;
	state = static_cast<hand_t::state_t>(x);
	return in;
}

/**
 * @brief Read state of hand to hand from optional input datastream.
 * 
 * @param in Input datastream.
 * @param hand 
 * @return std::istream& 
 */
inline
std::istream& operator>>(std::istream& in, hand_t& hand) {
	return in >> hand._state;
}

/**
 * @brief Operator function for hand object print out.
 * 
 * @param out Output datastream.
 * @param hand 
 * @return std::ostream& 
 */
inline
std::ostream& operator<<(std::ostream& out, const hand_t hand) {
	return out << hand.to_string();
}

}