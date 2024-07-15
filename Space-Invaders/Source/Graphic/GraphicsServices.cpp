#include "../../Header/Graphic/GraphicsServices.h"
#include <SFML/Graphics.hpp>
#include <iostream>


namespace Graphic
{
	using namespace sf;
	GraphicsService::GraphicsService()
	{
		video_mode = nullptr;
		gameWindow = nullptr;
	}

	GraphicsService::~GraphicsService()
	{
		onDestroy();
	}

	void GraphicsService::initialize()
	{
		gameWindow = createGameWindow();
	}

	RenderWindow* GraphicsService::createGameWindow()
	{
		setVideoMode();
		return new RenderWindow(*video_mode, gameWindowTitle, Style::Fullscreen);
	}

	void GraphicsService::setVideoMode()
	{
		video_mode = new VideoMode(windowWidth, windowHight, VideoMode::getDesktopMode().bitsPerPixel);
	}

	void GraphicsService::onDestroy()
	{
		delete(video_mode);
		delete(gameWindow);
	}

	void GraphicsService::render()
	{

	}

	void GraphicsService::update()
	{

	}

	RenderWindow* GraphicsService::getGameWindow()
	{
		return gameWindow;
	}

	bool GraphicsService::isGameWindowOpen()
	{
		return gameWindow->isOpen();
	}

	Color GraphicsService::getWindowColor()
	{
		return windowColor;
	}
}