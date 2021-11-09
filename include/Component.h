#ifndef COMPONENT_H
#define COMPONENT_H

#include <typeinfo>

class Component
{
private:
    char* m_name;

public:
    Component(char* t_name) : m_name{t_name}
    {
    }
    virtual char* name() { return m_name; }
};

class HealthComponent : public Component
{
private:
    int m_health;

public:
    HealthComponent(char* t_name, int t_health) : Component(t_name), m_health{t_health}
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
    PositionComponent(char* t_name, float t_x, float t_y) : Component(t_name), m_posX(t_x), m_posY(t_y)
    {
    }

    float& x() { return m_posX; }
    float& y() { return m_posY; }
    
};

class InputComponent : public Component
{
private:

public:
    InputComponent(char* t_name) : Component(t_name)
    {
    }
};

#endif