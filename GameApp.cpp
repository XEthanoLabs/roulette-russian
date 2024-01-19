#include "GameApp.h"
#include <Windows.h>
#include "Round1.h"

GameApp::GameApp( )
{
	startRound = CheckWhichRoundToStartAt( );

	messages_intro.push_back( "Welcome to a unique version of Russian Roulette. \nThis particular version of roulette involves 2 players:\n- A dealer\n- You" );
	messages_intro.push_back( "The Rules are simple.\nEach player has a chance to shoot the gun, which may contain a blank bullet, or a live one.\nThe chances are entirely random\n" 
	"The amount of blank and live bullets will be random, and their order of insertion into the gun will be a secret.\n\nBoth players alternate their turns, they have a choice to turn the gun towards their opponent, or themselves.\n"
	"If either player shoots themselves with a blank, the opposite players turn is skipped. Count your odds carefully..");
	messages_intro.push_back( "The game progresses slowly, each round will be completed when you lower all of your opponents health.\nEach player is assigned a certain number of hits they can sustain before death in each round.\n"
	"There are 3 rounds total:\nwin them all and receive a prize. However, should you lose - it will be hell for you.\n\nItems will be presented to you and the dealer each, randomly given, they will each assist you in some unique way to winning the round\n"
	"The items can be one of the following:\n\n- A beer (Racks the shotgun and empties the current shell loaded)\n- Cigarettes (Smoking them will regain one of your hitpoints)\n- A saw (The next shot you take will do double the damage)\n"
	"- Handcuffs (The opposing player is forced to skip their next turn)\n- A magnifying glass (You are able to check the state of the shell loaded in the chamber)\n\nYou will receive random amounts of random objects as the game progresses..\n");
}

GameApp::~GameApp( )
{
	std::cout << "Inside destructor";
}

void GameApp::RunGame( )
{
	if ( startRound == 1 )
	{
		IntroductionScreen( );
	}
	StartRound1();
	

}

void GameApp::TextPrint( std::string s )
{
	for ( int i = 0; i < s.length(); i++ )
	{
		std::cout << s[i];
		if ( s[i] =='\n' )
		{
			Sleep( 700 );
		}
		else
		{
			Sleep( 90 );
		}
		
	}
	std::cout << std::endl << std::endl;
}

void GameApp::IntroductionScreen( )
{
	TextPrint( messages_intro[WelcomeMessage] );
	Sleep( 500 );
	TextPrint( messages_intro[Rules] );
	Sleep( 500 );
	TextPrint( messages_intro[Explanation] );
	system( "pause" );
	system( "cls" );
	TextPrint( "====================Loading====================" );
	Sleep( 500 );
	system( "cls" );
	
}

int GameApp::CheckWhichRoundToStartAt( )
{
	return 1;
}

void GameApp::StartRound1( )
{
	Round1 r1;
	r1.Start( );
}
