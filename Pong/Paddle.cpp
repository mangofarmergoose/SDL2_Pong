#include "Paddle.hpp"

Paddle::Paddle(SDL_Renderer* renderer, float movementspeed){
    this->InitRenderer(renderer);
    this->m_movementSpeed = 5;
}

Paddle::~Paddle(){
    
}

void Paddle::InitPaddle(std::string filepath, int x, int y, int w, int h){
    this->AddTexturedRectComponent("./images/paddle.bmp");
    this->AddCollider2D();
    this->GetTexturedRect().SetPosition(x, y);
    this->GetTexturedRect().SetDimension(w, h);
    this->m_paddleX = x;
    this->m_paddleY = y;
}

void Paddle::Move(SDL_Scancode key1, SDL_Scancode key2){
    const Uint8* state = SDL_GetKeyboardState(NULL);
    this->m_paddleX = this->GetTexturedRect().GetPositionX();
    this->m_paddleY = this->GetTexturedRect().GetPositionY();
    if(state[key1] == true){
        m_paddleY -= m_movementSpeed;
    }
    else if(state[key2] == true){
        m_paddleY += m_movementSpeed;
    }
    this->GetTexturedRect().SetPosition(m_paddleX, m_paddleY);
}


