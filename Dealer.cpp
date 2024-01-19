#include "Dealer.h"

void Dealer::SetDealerHealth( int n )
{
	health = n;
}

int Dealer::GetDealerHealth( )
{
	return health;
}

void Dealer::AddToDealerHealth( int n )
{
	health += n;
}
