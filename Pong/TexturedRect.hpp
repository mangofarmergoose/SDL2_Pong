#ifndef TEXTUREDRECT_HPP
#define TEXTUREDRECT_HPP
#include <string>
#include "SDL.h"

class TexturedRect
{
public:
    // constructor
    TexturedRect(SDL_Renderer *renderer, std::string filepath);
    TexturedRect(SDL_Renderer *renderer, std::string filepath, int r, int g, int b);
    void InitDefaults();
    // destructor
    ~TexturedRect();
    void SetPosition(int x, int y);
    void SetDimension(int w, int h);
    SDL_bool IsColliding(TexturedRect &obj);
    void Update();
    void Render(SDL_Renderer *renderer);
    int GetPositionX();
    int GetPositionY();
    int GetWidth();
    int GetHeight();
    
private:
    SDL_Rect m_rect;
    SDL_Texture *m_texture;
    inline SDL_Rect GetRect() const { return m_rect; };
    int m_redcolorkey;
    int m_greencolorkey;
    int m_bluecolorkey;

};
#endif