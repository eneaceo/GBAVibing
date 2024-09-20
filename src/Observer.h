#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void UpdateSelectedOption() = 0;
    virtual void UpdateAutoPlay() = 0;
};

#endif