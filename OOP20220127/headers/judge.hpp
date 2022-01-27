#pragma once

#include "hand.hpp"

namespace rps {

/**
 * @brief Singleton class of the referee of the match.
 * 
 */
class judge_t {
public:
	/**
	 * @brief Types of the judgment.
	 * 
	 */
	enum class judgment_t {
		Tie, Left, Right
	};

private:
	judge_t() = default;
	
public:
	judge_t(const judge_t&) = delete;

	/**
	 * @brief Get one of the judge object.
	 * 
	 * @return judge_t& 
	 */
	static judge_t& instance() {
		static judge_t* _judge_ptr = nullptr;
		if(!_judge_ptr) _judge_ptr = new judge_t;
		return *_judge_ptr;
	}
	
	/**
	 * @brief Free the judge.
	 * 
	 */
	static void destroy() {
		delete &instance();
	}

	/**
	 * @brief The judge decides which of the two hands wins.
	 * 
	 * @param left Left player.
	 * @param right Right player.
	 * @return judgment_t Rock vs. Paper vs. Scissors
	 */
	judgment_t decide(const hand_t left, const hand_t right) const {
		return static_cast<judgment_t>((static_cast<int>(left.state()) - static_cast<int>(right.state()) + 3) % 3);
	}
};

}