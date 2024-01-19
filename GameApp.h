#pragma once

#include <iostream>
#include <vector>
#include <string>

class GameApp
{
public:

	GameApp( );
	~GameApp( );
	void RunGame( );
	
	

	


private:

	int startRound;
	void TextPrint( std::string s );
	void IntroductionScreen( );
	int CheckWhichRoundToStartAt( );
	void StartRound1( );

	std::vector<std::string> messages_intro;

	enum TextLogs
	{
		WelcomeMessage = 0,
		Rules,
		Explanation,
		Input
	};
};

