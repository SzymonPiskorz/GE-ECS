#ifndef COMPONENT_H
#define COMPONENT_H

#include <typeinfo>
#include <SDL.h>

class Component
{
public:
    Component(){}
    virtual ~Component() = default;
};

class HealthComponent : public Component
{
private:
    int m_health;

public:
    HealthComponent(int t_health) : m_health{t_health}
    {
    }

    int health() { return m_health; }
    void setHealth(int t_health) { m_health = t_health; }
};

class PositionComponent : public Component
{
private:
    float m_posX;
    float m_posY;

public:
    PositionComponent(float t_x, float t_y) : m_posX(t_x), m_posY(t_y)
    {
    }
    void addX(float t_x) {m_posX += t_x;}
    void addY(float t_y) {m_posY += t_y;}
    void setX(float t_x) {m_posX = t_x;}
    void setY(float t_y) {m_posY = t_y;}
    float& x() { return m_posX; }
    float& y() { return m_posY; }
    
};

class InputComponent : public Component
{
private:
    SDL_Event m_event;
public:
    InputComponent(SDL_Event t_event) : m_event(t_event){}
    SDL_Event event() { return m_event; }
};

#endif