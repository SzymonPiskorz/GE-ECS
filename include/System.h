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
    virtual std::vector<Entity> getEntities(){return m_entities;}
};

class ControlSystem : public System
{
    std::vector<Entity> m_entities;
public:
    virtual void update()
    {
        for(Entity& entity: m_entities)
        {
            for(Component* comp: entity.components())
            {
                InputComponent* inputComp{dynamic_cast<InputComponent*>(comp)};
                PositionComponent* posComp{dynamic_cast<PositionComponent*>(comp)};

                if(inputComp && posComp)
                {
                    if(inputComp->event().type == SDL_KEYDOWN)
                    {
                        if(inputComp->event().key.keysym.sym == SDLK_d)
                        {
                            posComp->addX(2.5f);
                        }
                        if(inputComp->event().key.keysym.sym == SDLK_a)
                        {
                            posComp->addX(-2.5f);
                        }
                        if(inputComp->event().key.keysym.sym == SDLK_w)
                        {
                            posComp->addY(-2.5f);
                        }
                        if(inputComp->event().key.keysym.sym == SDLK_s)
                        {
                            posComp->addY(2.5f);
                        }
                    }
                }
            }
        }   
    }
};

class RenderSystem : public System
{
    std::vector<Entity> m_entities;
    SDL_FRect* rect;
public:
    void update(){}
    virtual void render(SDL_Renderer* renderer)
    {
        for(Entity& entity: m_entities)
        {
            for(Component* comp: entity.components())
            {
                PositionComponent* posComp{dynamic_cast<PositionComponent*>(comp)};

                if(posComp)
                {
                    rect->x = posComp->x();
                    rect->y = posComp->y();
                    rect->w = 100;
                    rect->h = 100;
                    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
                    SDL_RenderDrawRectF(renderer, rect);
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                }
            }
        }
    }
};

class AISystem : public System
{
    std::vector<Entity> m_entities;
    float xVel, yVel;

public:
    virtual void update()
    {
        for(Entity& entity: m_entities)
        {
            for(Component* comp: entity.components())
            {
                PositionComponent* posComp{dynamic_cast<PositionComponent*>(comp)};

                if(posComp)
                {
                    std::cout << "Entity id: " << entity.entityID() << " X pos: " << posComp->x() << " Y pos: " << posComp->y() << std::endl;

                    posComp->addX(xVel);
                    posComp->addY(yVel);

                    if(posComp->x() > 800)
                    {
                        posComp->setX(0);
                    }
                    else if(posComp->x() < 0)
                    {
                        posComp->setX(800);
                    }
                    if(posComp->y() > 600)
                    {
                        posComp->setY(0);
                    }
                    else if(posComp->y() < 0)
                    {
                        posComp->setY(600);
                    }
                }
            }
        }   
    }

};

class HealthSystem : public System
{
    std::vector<Entity> m_entities;
public:
    virtual void update()
    {
        for(Entity& entity: m_entities)
        {
            for(Component* comp: entity.components())
            {
                HealthComponent* healthComp{dynamic_cast<HealthComponent*>(comp)};

                if(healthComp)
                {
                    std::cout << "Entity id: " << entity.entityID() << " Health: " << healthComp->health() << std::endl;
                }
            }
        }   
    }
};

#endif