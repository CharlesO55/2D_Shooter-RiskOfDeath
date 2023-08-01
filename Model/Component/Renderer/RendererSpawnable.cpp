#include "RendererSpawnable.hpp"

using namespace components;
using namespace systems;

RendererSpawnable::RendererSpawnable(std::string strName) : Renderer(strName){}

RendererSpawnable::~RendererSpawnable() {}

void RendererSpawnable::perform(){
    //OVERRIDES THE CURRENT RENDER STATES (RENDERSTATES::DEFAULT) TO MATCH FRONTVIEW FOR SCALING
    if (ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->isEnabled()){
        this->CRenderStates = ViewManager::getInstance()->getView(ViewTag::FRONTVIEW_SCREEN)->getBackground()->getSprite()->getTransform();
    }
    // this->pOwner->getSprite()->setColor(sf::Color::Red);
    Renderer::perform();
}