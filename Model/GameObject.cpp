#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(sf::Texture* pTexture, std::string strName, GameObject* pParent, float fX, float fY){
    this->strName = strName;

    sf::Sprite* pSprite = new sf::Sprite(*pTexture);
    pSprite->setOrigin(pTexture->getSize().x/2.f, pTexture->getSize().y/2.f);
    pSprite->setPosition(fX, fY);

    this->pDrawable = pSprite;
    this->eType = EnumObjTypes::SPRITE;

    if (pParent){
        pParent->vecChildren.push_back(this);
        this->pParent = pParent;
        this->initialize();
    }
}

void GameObject::initialize(){
    this->bEnabled = true;
    
    
    CompRenderer *pRenderer = new CompRenderer(this->strName, this);
    this->vecComponents.push_back(pRenderer);
    std::cout << "INITIALIZE SUCCESS";
}


void GameObject::draw(sf::RenderWindow* pWindow) {
    CompRenderer* pRenderer;
    sf::RenderStates CTransform = sf::RenderStates::Default;

    for (Component* pComp : this->getComponents(EnumComponentType::RENDERER)){
        pRenderer = (CompRenderer*) pComp;
        pRenderer->assignOnDraw(pWindow, CTransform);
        pRenderer->perform();
    }
    

    CTransform.transform = this->getSprite()->getTransform() * CTransform.transform;
    for (Component* pComp : this->getChildrenComponents(EnumComponentType::RENDERER)){
        pRenderer = (CompRenderer*) pComp;
        pRenderer->assignOnDraw(pWindow, CTransform);
        pRenderer->perform();
    }
}

std::vector <Component*> GameObject::getComponents(EnumComponentType EType){
    std::vector <Component*> vecFound;

    for (auto itr : this->vecComponents){
        if (itr->getType() == EType){
            vecFound.push_back(itr);
        }
    }
    return vecFound;
}
std::vector <Component*> GameObject::getChildrenComponents(EnumComponentType EType){
    std::vector <Component*> vecFound;

    for (GameObject* pChild : this->vecChildren){
        std::vector <Component*> vecChildComp = (pChild->getComponents(EType));
        vecFound.insert(vecFound.end(), vecChildComp.begin(), vecChildComp.end());
    }
    return vecFound;
}


sf::Drawable* GameObject::getDrawable(){
    if (pDrawable == NULL){
        std::cout << this->strName << " HAS NO DRAWABLE SET";
        throw "NO DRAWABLE SET";
    }
    return this->pDrawable;
}

sf::Sprite* GameObject::getSprite(){
    if (this->eType == EnumObjTypes::SPRITE)
        return static_cast <sf::Sprite*> (this->pDrawable);
    else{ 
        std::cout << std::endl << this->strName << "::getSprite() DRAWABLE TYPE MISMATCH: NOT A SPRITE\n";
        throw "GAMEOBJECT DRAWABLE IS NOT SPRITE";
    }
}
