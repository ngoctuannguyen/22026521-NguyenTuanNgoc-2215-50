#pragma once
#include <vector>
#include "background.h"

class Scrolling {
private:
	std::vector<std::pair<Background, float>> backgrounds;

public:

	Scrolling(const std::vector<std::pair<Background, float>> backgrounds);
	std::vector<std::pair<Background, float>> getBackgrounds();
	void move(const float& xCord, const float& limit, const float& resetValue);
};
