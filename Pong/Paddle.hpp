#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "GameEntity.hpp"
#include "SDL.h"
#include "SDLApp.hpp"
#include <string>
#include <iostream>

class Paddle:public GameEntity{
public:
    Paddle(SDL_Renderer* renderer, float movementspeed);
    ~Paddle();
    void InitPaddle(std::string filepath, int x, int y, int w, int h);
    void Move(SDL_Scancode key1, SDL_Scancode key2);

private:
    int m_paddleX;
    int m_paddleY;
    float m_movementSpeed;
};
#endif