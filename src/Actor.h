#ifndef ACTOR_H
#define ACTOR_H

class Actor
{
public:
    virtual ~Actor() = default;
    virtual void Update() = 0;
};

#endif
