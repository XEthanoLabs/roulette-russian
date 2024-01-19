#include "Player.h"

void Player::SetPlayerHealth( int n )
{
	health = n;
}

int Player::GetPlayerHealth( )
{
	return health;
}

void Player::AddToPlayerHealth( int n )
{
	health += n;
}
