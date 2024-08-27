#ifndef STATESTACK_H
#define STATESTACK_H

#include "bn_vector.h"

#include <memory>

#include "InputHandler.h"
#include "State.h"

#include "bn_bg_palettes.h"
#include "bn_color.h"
#include "Actor.h"

class State;
class InputHandler;
class Command;
class NextStateCommand;
class PreviousStateCommand;
class MenuUpCommand;
class MenuDownCommand;

class StateStack : public Actor
{
public:
    StateStack()
    {
        Push(std::make_unique<MainMenuState>());
        InputManager = std::make_unique<InputHandler>();
        InputManager->BindButton(InputHandler::BUTTONS::A, std::make_unique<NextStateCommand>());
        InputManager->BindButton(InputHandler::BUTTONS::B, std::make_unique<PreviousStateCommand>());
        InputManager->BindButton(InputHandler::BUTTONS::UP, std::make_unique<MenuUpCommand>());
        InputManager->BindButton(InputHandler::BUTTONS::DOWN, std::make_unique<MenuDownCommand>());
    };

    void Update() override
    {
        CurrentState->Update();
        InputManager->HandleInput(*this);
    };

    void AdvanceState()
    {
        bn::bg_palettes::set_transparent_color(bn::color(31, 0, 0));
    };

    void PreviousState()
    {
        bn::bg_palettes::set_transparent_color(bn::color(0, 31, 0));
    };

private:
    std::unique_ptr<InputHandler> InputManager;
    bn::vector<std::unique_ptr<State>, 3> StatesStack;
    State *CurrentState = nullptr;

    void Push(std::unique_ptr<State> aState)
    {
        if (CurrentState)
        {
            CurrentState->Exit();
        }
        StatesStack.push_back(std::move(aState));
        CurrentState = StatesStack.back().get();
        if (CurrentState)
        {
            CurrentState->Enter();
        }
    };

    void Pop()
    {
        if (StatesStack.size() > 1)
        {
            CurrentState->Exit();
            StatesStack.pop_back();
            CurrentState = StatesStack.back().get();
            CurrentState->Enter();
        }
    };
};

#endif