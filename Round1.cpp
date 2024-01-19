#include "Round1.h"

Round1::Round1( )
{
	p1.SetPlayerHealth( 3 );
	d1.SetDealerHealth( 3 );

	std::cout << "Player and dealer both have 3 hit points" << std::endl;
	std::cout << "Round 1 has started" << std::endl;
	round_number = 1;

	BulletLoads.push_back( {1,1,0,0} );
	cout << "The gun is now being loaded. There are 2 live shells, and 2 blanks\n\n";
	for ( int i = 0; i < 10; i++ )
	{
		int j = rand( ) % 4;
		int k = rand( ) % 4;
		int temp = BulletLoads[0][j];
		BulletLoads[0][j] = BulletLoads[0][k];
		BulletLoads[0][k] = temp;
	}
	BulletLoads.push_back( { 1,0,0 } );
}

Round1::~Round1( )
{
}

void Round1::Start( )
{
	int coin = rand( ) % 2;
	if ( coin == 0 )
	{
		PlayerGoesFirst = true;
		cout << "You won the coin toss! you get to have the first strike\n";
	}
	else
	{
		PlayerGoesFirst = false;
		cout << "You lost the coin toss. Dealer gets to have the first strike\n";
	}

	

	int bulletRack = 0;
	int bulletSize1 = 3;

	while ( true )
	{
		if ( PlayerGoesFirst == true )
		{
			cout << "Players Health: " << p1.GetPlayerHealth( ) << endl << "Dealers Health: " << d1.GetDealerHealth( ) << endl;
			cout << "Players turn\n\n";
			string move;
			cin >> move;
			
			int IsLiveRound = BulletLoads[bulletRack][bulletSize1];
			bulletSize1 -= 1;

			if ( move == "dealer")
			{
				if ( IsLiveRound == 1 )
				{
					cout << "You shoot the dealer backwards into the darkness. He remerges, with a hit point missing\n";
					d1.AddToDealerHealth( -1 );
				}
				else
				{
					cout << "You miss, a blank. How unlucky\n\n";
				}
			}

			if ( move == "myself" )
			{
				if ( IsLiveRound )
				{
					cout << "You point the gun towards your neck, and blast yourself into oblivion. You awake a second later back at the table with a hit point missing\n";
					p1.AddToPlayerHealth( -1 );
				}
				else
				{
					cout << "You miss, a blank. How fortunate!\n\n";
					continue;
				}
			}


			PlayerGoesFirst = false;
		}

		if ( d1.GetDealerHealth() == 0 || p1.GetPlayerHealth( ) == 0 )
		{
			break;
		}

		if ( bulletSize1 < 0 )
		{
			bulletRack += 1;
			if ( bulletRack > BulletLoads.size() - 1 )
			{
				break;
			}
			cout << "reloading the gun\n\n";
			bulletSize1 = BulletLoads[bulletRack].size( ) - 1;
		}

		system( "pause" );
		system( "cls" );
		Sleep( 100 );


		//========================== dealers turn ====================================

		if ( PlayerGoesFirst == false )
		{
			int IsLiveRound = BulletLoads[bulletRack][bulletSize1];
			bulletSize1 -= 1;

			cout << "Players Health: " << p1.GetPlayerHealth( ) << endl << "Dealers Health: " << d1.GetDealerHealth( ) << endl;
			cout << "Dealers turn\n\n";

			int odds = rand( ) % 10;
			if ( odds < 6 )
			{
				
				if ( IsLiveRound == 1 )
				{
					cout << "The Dealer fires at you in a blur of light, you awake a second later back at the table with a hit point missing\n";
					p1.AddToPlayerHealth( -1 );
				}
				else
				{
					cout << "The Dealer misses, thank goodness\n\n";
				}
				
			}
			else
			{
				if ( IsLiveRound == 1 )
				{
					cout << "The Dealer fires at himself, pushing him into the darkness, he remerges with 1 less hit point\n";
					d1.AddToDealerHealth( -1 );
				}
				else
				{
					cout << "The Dealer fires at himself. Bad luck, the dealer gets to go again\n\n";
					continue;
				}
			}


			PlayerGoesFirst = true;
		}

		if ( d1.GetDealerHealth( ) == 0 || p1.GetPlayerHealth( ) == 0 )
		{
			break;
		}

		if ( bulletSize1 < 0 )
		{
			bulletRack += 1;
			if ( bulletRack > BulletLoads.size( ) - 1 )
			{
				break;
			}
			cout << "reloading the gun\n\n";
			bulletSize1 = BulletLoads[bulletRack].size( ) - 1;
		}

		system( "pause" );
		system( "cls" );
		Sleep( 10 );
		
	}

	if ( d1.GetDealerHealth( ) == 0 )
	{
		cout << "You won round 1!\n\n";
	}

	if ( p1.GetPlayerHealth( ) == 0 )
	{
		cout << "You have died at the hands of the dealer, but you have one more chance to retry";
	}

	cout << "you are outside of the loop";
}
