#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "Component.h"

class Entity
{
private:
    int m_id;
    std::vector<Component*> m_components;

public:
    Entity() {};
    void addComponent(Component* c) { m_components.push_back(c); }
    void removeComponent(Component* c) {}
    std::vector<Component*>& components() { return m_components; }
    bool operator==(const Entity& other){return m_id == other.m_id;}
};

#endif 