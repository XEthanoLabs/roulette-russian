#pragma once
#include <iostream>
#include "Item.h"
#include <vector>

class Dealer
{
public:
	void SetDealerHealth( int n );
	int GetDealerHealth( );
	void AddToDealerHealth( int n );

private:
	int health;
	std::vector<Item> Dealer_Items;
};

