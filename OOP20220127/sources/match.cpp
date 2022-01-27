#include <iostream>
#include "../headers/match.hpp"
#include "../headers/player.hpp"
#include "../headers/judge.hpp"

rps::match_t::match_t(player_t& player1, player_t& player2) 
	: _player1{player1}, 
	_player2{player2}, 
	_score1{0},
	_score2{0},
	_judge{judge_t::instance()},
	_round{0}
{}

rps::match_t::~match_t() { 
	delete &_player1;
	delete &_player2;
	judge_t::destroy();
}

void rps::match_t::round() { 
	++_round;
	bool err{false};
	do{
		try{
			dynamic_cast<manual_player_t&>(_player1);
			std::cout << _player1.name() << " choice: ";
			std::cout << "\n\t1. Rock\n\t2. Paper\n\t3. Scissors\n";
			_player1.prepare();
		}catch(const std::bad_cast& e) {}
		catch(const std::range_error& e) { err = true; }
	}while(!err);

	err = false;
	do{
		try{
			dynamic_cast<manual_player_t&>(_player2);
			std::cout << _player2.name() << " choice: ";
			std::cout << "\n\t1. Rock\n\t2. Paper\n\t3. Scissors\n";
			_player2.prepare();
		}catch(const std::bad_cast& e) {}
		catch(const std::range_error& e) { err = true; }
	}while(!err);

	judge_t::judgment_t judgment = _judge.decide(_player1.hand(), _player2.hand());

	switch(judgment){
		case judge_t::judgment_t::Tie 	: break;
		case judge_t::judgment_t::Left  : 
			_player2.decrement();
			++_score1;
			break;
		case judge_t::judgment_t::Right : 
			_player1.decrement();
			++_score2;
			break;
	}
}

bool rps::match_t::has_finished() const { 
	return !(_player1.is_alive() && _player2.is_alive()); 
}

rps::player_t& rps::match_t::winner() const { 
	player_t* w = nullptr;
	if(has_finished()){
		if(_player1.is_alive()) w = &_player1;
		if(_player2.is_alive()) w = &_player2;
	}
	return *w;
}

std::ostream& rps::operator<<(std::ostream& out, const rps::match_t& match) {	
	out << "Round " << static_cast<int>(match.rounds()+1) << ".";
	out << '\t' << match._player1.name() << " score: " << static_cast<int>(match._score1);
	out << '\t' << match._player2.name() << " score: " << static_cast<int>(match._score2);
	return out;
}
