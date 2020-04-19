#include "Player.h"

int Player::high_score = 0;

Player::Player() :
	position(PLAYER_START_POSITION),
	speed(PLAYER_SPEED),
	jump_span(PLAYER_JUMP_SPAN),
	score(0)
{
}

int Player::GetPosition()
{
	return position;
}

int Player::GetJumpSpan()
{
	return jump_span;
}

void Player::Run()
{
	position += speed;
	SetScore(position);
}

void Player::Jump()
{
	position += jump_span;
}

int Player::GetScore()
{
	return score;
}

void Player::SetScore(int score)
{
	this->score = score;
	high_score = (high_score > score)? high_score : score;
}

int Player::GetHighScore()
{
	return high_score;
}

Player::~Player()
{
}

