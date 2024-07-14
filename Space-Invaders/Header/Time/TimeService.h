#pragma once
#include<chrono>
using namespace std;

class TimeService
{
	/*TimeService();
	~TimeService();*/

private:
	chrono::time_point<chrono::steady_clock> previous_time;
	float delta_time;

	void updateDeltaTime();
	float calculateDeltaTime();
	void updatePreviousTime();

public:
	void initialize();
	void update();

	float getDeltaTime();
};