#include "CompRenderer.hpp"

using namespace components;

CompRenderer::CompRenderer(std::string strName, models::GameObject* pOwner) : Component(strName, EnumComponentType::RENDERER, pOwner){
    this->pDrawable = pOwner->getDrawable();
}

void CompRenderer::assignOnDraw(sf::RenderWindow *pWindow, sf::RenderStates CTransform){
    this->pWindow = pWindow;
    this->CTransform = CTransform;
}

void CompRenderer::perform(){
    this->pWindow->draw(*this->pDrawable, this->CTransform);
}