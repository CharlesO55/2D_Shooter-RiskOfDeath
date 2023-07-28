#ifndef VIEWS_BUTTON_HPP
#define VIEWS_BUTTON_HPP

#include "../Model/Enum/EnumButtonState.hpp"

#include "../Model/AnimatedTexture.hpp"
#include "../Model/GameObject.hpp"

#include "../Model/Component/Input/ButtonInput.hpp"
#include "../Model/Component/Renderer/Renderer.hpp"

#include "../View/Interface/ButtonListener.hpp"

#include "../../../Controller/System/ViewManager.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace views {
    using namespace components;
    using namespace listeners;
    using namespace models;

    class Button : public GameObject {
        private:
            ButtonListener* pListener;
            sf::Text* pText;    //ALTERNATIVE FOR TEXT BUTTONS

        public:
            Button(std::string strName, AnimatedTexture* pTexture);
            Button(std::string strName, sf::Text* pText);
            ~Button();

        public:
            void initialize();
            void changeState(ButtonState EState);

        public:
            sf::FloatRect getGlobalBounds();

            void setListener(ButtonListener* pListener);
    };
}

#endif