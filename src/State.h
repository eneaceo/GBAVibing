#ifndef STATE_H
#define STATE_H

class State
{
public:
    virtual ~State() = default;
    virtual void Update() {};
    virtual void Enter() {};
    virtual void Exit() {};
};

class MainMenuState : public State
{
public:
    MainMenuState()
    {

    };
};

class AlbumMenuState : public State
{
public:
    AlbumMenuState()
    {

    };
};

#endif