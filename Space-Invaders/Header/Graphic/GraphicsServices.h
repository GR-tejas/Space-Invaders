#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

namespace Graphic
{
	class GraphicsService
	{
	private:
		const string gameWindowTitle = "Space Defenders";
		const int windowHight = 1920, windowWidth = 1080;
		const Color windowColor = Color::Blue;

		VideoMode* video_mode;
		RenderWindow* gameWindow;

		void setVideoMode();
		void onDestroy();

	public:
		GraphicsService();
		~GraphicsService();

		RenderWindow* createGameWindow();

		void initialize();
		void update();
		void render();
		bool isGameWindowOpen();

		RenderWindow* getGameWindow();
		Color getWindowColor();
	};
}