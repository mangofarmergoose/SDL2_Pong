#ifndef BALL_HPP
#define BALL_HPP
#include "GameEntity.hpp"
#include "SDL.h"
#include "Paddle.hpp"
#include "Sound.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>


class Ball:public GameEntity{
public:
    Ball(SDL_Renderer* renderer, int movementspeed);
    ~Ball();
    void InitBall(std::string filepath, int x, int y, int w, int h);
    void Move();
    void HandleCollision(Collider2D collider, Paddle* paddle);
    int m_Score1;
    int m_Score2;

private:
    int m_movementspeed;
    int m_ballX;
    int m_ballY;
    int m_ballXDirection;
    int m_ballYDirection;
    Sound* m_CollisionSound;
};
#endif