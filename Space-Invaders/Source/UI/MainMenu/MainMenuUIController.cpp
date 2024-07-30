#include "../../Header/UI/MainMenu/MainMenuUIContoller.h"
#include "../../Header/Main/GameServices.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicsServices.h"
#include "../../Header/Global/Config.h"
#include"../../Header/Sound/SoundService.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace EventSpace;
        using namespace SoundSpace;
        using namespace UIElement;

        MainMenuUIController::MainMenuUIController()
        {
            createImage();
            createButtons();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            destroy();
        }

        void MainMenuUIController::initialize()
        {
            registerButtonCallback();
            initializeBackgroundImage();
            initializeButtons();
        }

        void MainMenuUIController::createImage()
        {
            background_image = new ImageView();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void MainMenuUIController::scaleBackgroundImage()
        {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::registerButtonCallback()
        {
            play_button->registerCallbackFuntion(std::bind(&MainMenuUIController::playButtonCallback, this));
            instructions_button->registerCallbackFuntion(std::bind(&MainMenuUIController::instructionsButtonCallback, this));
            quit_button->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
        }

        void MainMenuUIController::playButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::initializeButtons()
        {
            play_button->initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(0, play_button_y_position));
            instructions_button->initialize("Instructions Button", Config::instructions_button_texture_path, button_width, button_height, sf::Vector2f(0, instructions_button_y_position));
            quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

            play_button->setCentreAlinged();
            instructions_button->setCentreAlinged();
            quit_button->setCentreAlinged();
        }

        void MainMenuUIController::instructionsButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
        }

        void MainMenuUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        bool MainMenuUIController::loadButtonTexturesFromFile()
        {
            return play_button_texture.loadFromFile(play_button_texture_path) &&
                instructions_button_texture.loadFromFile(instructions_button_texture_path) &&
                quit_button_texture.loadFromFile(quit_button_texture_path);
        }
        
        void MainMenuUIController::update()
        {
            background_image->update();
            play_button->update();
            instructions_button->update();
            quit_button->update
        }

        void MainMenuUIController::render()
        {
            background_image->render();
            play_button->render();
            instructions_button->render();
            quit_button->render();
        }

        void MainMenuUIController::show()
        {
            background_image->show();
            play_button->show();
            instructions_button->show();
            quit_button->show();

            ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
        }

        void MainMenuUIController::destroy()
        {
            delete (play_button);
            delete (instructions_button);
            delete (quit_button);
            delete (background_image);
        }
    }
}