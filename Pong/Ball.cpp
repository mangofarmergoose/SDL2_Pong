#include "Ball.hpp"
#include "Sound.hpp"
Ball::Ball(SDL_Renderer* renderer, int movementspeed){
    this->InitRenderer(renderer);
    this->m_movementspeed = 3;
    m_ballXDirection = -1;
    m_ballYDirection = -1;
    m_Score1 = 0;
    m_Score2 = 0;
    m_CollisionSound = new Sound("/sounds/collide.wav");
    m_CollisionSound->SetupDevice();

}

Ball::~Ball(){

}

void Ball::InitBall(std::string filepath, int x, int y, int w, int h){
    this->AddTexturedRectComponent("./images/ball.bmp");
    this->AddCollider2D();
    this->GetTexturedRect().SetPosition(x, y);
    this->GetTexturedRect().SetDimension(w, h);
    this->m_ballX = x;
    this->m_ballY = y;
}

void Ball::Move(){
    m_ballX = this->GetTexturedRect().GetPositionX();
    m_ballY = this->GetTexturedRect().GetPositionY();
    if(m_ballXDirection == 1){
        m_ballX+=m_movementspeed;
    }
    else{
        m_ballX-=m_movementspeed;
    }

    if(m_ballYDirection == 1){
        m_ballY+=m_movementspeed;
    }
    else{
        m_ballY-=m_movementspeed;
    }

    if(m_ballY > 470){
        m_ballYDirection = -1;
    }
    else if(m_ballY < 0){
        m_ballYDirection = 1;
    }
    //reset ball to center
    if(m_ballX > 640){
        m_Score1++;
        m_ballX = 310;
        m_ballY = 230;
    }
    else if(m_ballX < -20){
        m_Score2++;
        m_ballX = 310;
        m_ballY = 230;
    }

    this->GetTexturedRect().SetPosition(m_ballX, m_ballY);
}

void Ball::HandleCollision(Collider2D collider, Paddle* paddle){

    if(m_ballXDirection == -1 && this->GetCollider2D(0).IsColliding(paddle->GetCollider2D(0)) && m_ballX<=20){
        m_ballXDirection = 1;
        m_CollisionSound->PlaySound();
    }
    else if(m_ballXDirection == 1 && this->GetCollider2D(0).IsColliding(paddle->GetCollider2D(0)) && m_ballX>=600){
        m_ballXDirection = -1;
        m_CollisionSound->PlaySound();
    }

}

