#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <iostream>
#include "Entity.h"

class System
{
    std::vector<Entity> m_entities;
public:
    virtual void addEntity(Entity t_entity) {m_entities.push_back(t_entity);};
    virtual void update() = 0;
    virtual void removeEntity(Entity t_entity)
    {
        std::vector<Entity>::iterator it = m_entities.begin();
        std::vector<Entity>::iterator end = m_entities.end();
        for(; it != end; it++)
        {
            if(*it == t_entity)
            {
                m_entities.erase(it);
                return;
            }
        }
    }
    virtual std::vector<Entity> getEntities();
};

class ControlSystem : public System
{
    std::vector<Entity> m_entities;
public:
    virtual void update()
    {
        printf("Control System\n");

        for(Entity& entity: m_entities)
        {
            for(Component* comp: entity.components())
            {
                InputComponent* inputComp = dynamic_cast<InputComponent*>(comp);

                if(inputComp)
                {
                    //do movement here
                }
            }
        }   
    }
};

class RenderSystem : public System
{
    std::vector<Entity> m_entities;
public:
    virtual void update()
    {
        printf("Render System\n");
    }
};

class AISystem : public System
{
    std::vector<Entity> m_entities;
public:
    virtual void update()
    {
        printf("AI System\n");
    }

};

class HealthSystem : public System
{
    std::vector<Entity> m_entities;
public:
    virtual void update()
    {
        printf("Health System\n");
        for(Entity& entity: m_entities)
        {
            for(Component* comp: entity.components())
            {
                HealthComponent* healthComp = dynamic_cast<HealthComponent*>(comp);

                if(healthComp)
                {
                    std::cout << "Name: " << healthComp->name() << " Health: " << healthComp->health() << std::endl;
                }
            }
        }   
    }
};

#endif