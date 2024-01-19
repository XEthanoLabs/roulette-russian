#pragma once
#include <iostream>
#include "Item.h"
#include <vector>
class Player
{
public:
	void SetPlayerHealth( int n );
	int GetPlayerHealth( );
	void AddToPlayerHealth( int n );

private:
	int health;
	std::vector<Item> Player_Items;
};

