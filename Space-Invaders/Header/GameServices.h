#pragma once
class GameService
{
private:
	void initialize();
	void destroy();

public:
	GameService();
	~GameService();

	void start();
	void update();
	void render();
	bool isRunning();
};