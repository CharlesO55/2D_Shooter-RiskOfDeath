#pragma once

#include "../../Model/GameObject.hpp"

#include "../../Model/Component/InputButton.hpp"


namespace ui {
    using namespace models;

    class TextButton : public GameObject {
        private:
            sf::Text* pText;
            bool bClicked = false;
            
            sf::Color CColorNormal;
            sf::Color CColorHighlight;
            bool bHighlight = false;

        public:
            TextButton(std::string strName, std::string strText, GameObject* pParent = NULL, float fX = 0.f, float fY = 0.f);

        public:
            void initialize();
            void update(sf::Time CTime);


        public:
            void setClicked(bool bTOF) {this->bClicked = bTOF;};
            bool isClicked() {return this->bClicked;};
            void resetClick() {this->bClicked = true;};
            void setHighlight(bool bTOF);

    };
}