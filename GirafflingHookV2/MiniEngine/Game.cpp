#include "Game.h"

Game::Game() :
	toExit_{ false }
{
}

Game::~Game()
{
}

void Game::Exit()
{
	running_->toExit_ = true;
}

Game* Game::running_{ nullptr };
