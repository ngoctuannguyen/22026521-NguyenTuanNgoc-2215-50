#include "header/scroll.h"
#include <iostream>

Scrolling::Scrolling(const std::vector<std::pair<Background, float>> backgrounds) 
	: backgrounds(backgrounds)
{}

std::vector<std::pair<Background, float>> Scrolling::getBackgrounds()
{
	return backgrounds;
}

void Scrolling::move(const float& xCord, const float& limit, const float& resetValue)
{	
	//if (backgrounds.size() != 0)
		// std::cout << "OK" << std::endl;
	// std::cout << "Background: " <<  backgrounds.size() << std::endl;
	for(auto& background : backgrounds)
	{	
		//std::cout << background.second << std::endl;
		if(background.second - xCord <= limit)
		{	
			std::cout << "reset" << std::endl;
			background.second = resetValue;
			background.first.resetHeight();
		}
		else {
			background.second -= xCord;
			//std::cout << background.second << std::endl;
		}
	}
}