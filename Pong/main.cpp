//To Compile
//clang++ -std=c++17 -D MAC *.cpp -I/usr/local/include -o prog `sdl2-config --cflags --libs` -lSDL2_ttf
#include <iostream>
#include <string>
#include <vector>
// Third Party
#include "SDL.h"
#include "SDLApp.hpp"
#include "TexturedRect.hpp"
#include "AnimatedSprite.hpp"
#include "GameEntity.hpp"
#include "Collider2D.hpp"
#include "Sound.hpp"
#include "DynamicText.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
SDLApp *app;
Paddle *leftPaddle;
Paddle *rightPaddle;
Ball *ball;
DynamicText* text1;
DynamicText* text2;

void HandleEvents()
{
    SDL_Event event;
    // (1) Handle Input
    // Start our event loop
    while (SDL_PollEvent(&event))
    {
        // Handle each specific event
        if (event.type == SDL_QUIT)
        {
            app->StopAppLoop();
        }
    }
}

void HandleUpdate(){
    //handle movement
    leftPaddle->Move(SDL_SCANCODE_W, SDL_SCANCODE_S);
    rightPaddle->Move(SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
    ball->Move();
    ball->HandleCollision(leftPaddle->GetCollider2D(0), leftPaddle);
    ball->HandleCollision(rightPaddle->GetCollider2D(0), rightPaddle);
    //Make bounding box follow textured rect
    leftPaddle->Update();
    rightPaddle->Update();
    ball->Update();

}

void HandleRendering()
{
    // Render our objects
    leftPaddle->Render();
    rightPaddle->Render();
    ball->Render();
    //Render Text
    text1 = new DynamicText("./fonts/8bitOperatorPlus8-Regular.ttf", 16);
    text1->DrawText(app->GetRenderer(), "Score: ", 20, 0 ,100, 50, ball->m_Score1);
    delete text1;

    text2 = new DynamicText("./fonts/8bitOperatorPlus8-Regular.ttf", 16);
    text2->DrawText(app->GetRenderer(), "Score: ", 520, 0 ,100, 50, ball->m_Score2);
    delete text2;

}

int main()
{
    // Setup the SDLApp
    const char *title = "New SDL2 Abstraction";
    app = new SDLApp("SDL2", 20, 20, 640, 480);
    app->SetMaxFrameRate(8);
    app->InitAudio();
    app->InitDynamicText();
    
    // Create any objects in our scene

    leftPaddle = new Paddle(app->GetRenderer(), 5);
    rightPaddle = new Paddle(app->GetRenderer(), 5);
    ball = new Ball(app->GetRenderer(), 3);    
    leftPaddle->InitPaddle("./images/paddle.bmp", 0, 0, 20, 100);
    rightPaddle->InitPaddle("./images/paddle.bmp", 620, 0, 20, 100);
    ball->InitBall("./images/ball.bmp", 310, 230, 20, 20);


    // Set callback functions
    app->SetEventCallback(HandleEvents);
    app->SetUpdateCallback(HandleUpdate);
    app->SetRenderCallback(HandleRendering);
    // Run our application until terminated
    app->RunLoop();

    // Clean up our application
    delete app;
    delete leftPaddle;
    delete rightPaddle;
    delete ball;

    return 0;
}
