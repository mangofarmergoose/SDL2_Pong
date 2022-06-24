#include "Collider2D.hpp"
#include <iostream>

Collider2D::Collider2D(){
    m_colliderRect = new SDL_Rect;
    m_colliderRect->x = 0;
    m_colliderRect->y = 0;
    m_colliderRect->w = 0;
    m_colliderRect->h = 0;
}

Collider2D::~Collider2D(){

}

SDL_bool Collider2D::IsColliding(Collider2D& collider){
    if(m_colliderRect == nullptr){
        return SDL_FALSE;
    }
    const SDL_Rect* tmp = collider.m_colliderRect;
    if(tmp == nullptr){
        return SDL_FALSE;
    }
    return SDL_HasIntersection(m_colliderRect, tmp);
}

void Collider2D::SetAbsolutePosition(int x, int y){
    m_colliderRect->x = x;
    m_colliderRect->y = y;
}

void Collider2D::SetAbsoluteDimensions(int w, int h){
    m_colliderRect->w = w;
    m_colliderRect->h = h;
}

SDL_Rect& Collider2D::GetColliderBoundingBox(){
    return *m_colliderRect;
}

