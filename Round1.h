#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Dealer.h"
#include <Windows.h>

using namespace std;

class Round1
{
public:
	Round1( );
	~Round1( );
	void Start( );

private:
	int round_number;
	bool PlayerGoesFirst = false;

	enum ItemType
	{
		Beer = 0,
		Cigarette,
		Saw,
		Magnifier,
		Handcuffs
	};

	Player p1;
	Dealer d1;

	vector<vector<int>> BulletLoads;
	

};

