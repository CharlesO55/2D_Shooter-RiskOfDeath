#ifndef VIEWS_TEXT_HPP
#define VIEWS_TEXT_HPP

#include "../Model/GameObject.hpp"
#include "../Model/Component/Renderer/Renderer.hpp"

#include "../Controller/Singleton/FontManager.hpp"

#   ifndef DISABLE_INTELLISENSE_INCLUDES
#   include <SFML/Graphics.hpp>
#   endif

namespace views {
    using namespace components;
    using namespace models;

    class Text : public GameObject {
        private:
            sf::Text* pText;
            
        public:
            Text(std::string strName, std::string strText, sf::Vector2f vecPos, FontType EFont = FontType::DEFAULT, int nSize = DEFAULT_TEXT_SIZE, bool bCenterAlign = false, sf::Color CColor = sf::Color::White);

        public:
            void initialize();
            void centerTextOrigin();

        public:
            sf::Text* getText();
            void setText(std::string strText);
    };
}

#endif