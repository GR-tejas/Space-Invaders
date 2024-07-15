#include "../../Header/UI/MainMenu/MainMenuUIContoller.h"
#include "../../Header/Main/GameServices.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicsServices.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace EventSpace;

        MainMenuUIController::MainMenuUIController() { game_window = nullptr; }

        void MainMenuUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
        }

        void MainMenuUIController::update()
        {
        }

        void MainMenuUIController::render()
        {
        }

    }
}