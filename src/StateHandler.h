#ifndef STATEHANDLER_H
#define STATEHANDLER_H

class StateBase;
class TextGenerator;
class ImageHandler;
class MusicHandler;

class StateHandler
{
public:

    enum STATES
    {
        MENU,
        ALBUM,
        CREDITS
    };

    static StateHandler& GetInstance()
    {
        static StateHandler instance;
        return instance;
    }

    void Update();
    void initialize(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler);
    void SetState(int aState);
    StateBase *GetCurrentState() { return CurrentState; }

private:
    StateHandler() = default;
    ~StateHandler() = default;
    StateHandler(const StateHandler&) = delete;
    StateHandler& operator=(const StateHandler&) = delete;

    StateBase *CurrentState = nullptr;
    TextGenerator *CurrentTextGenerator = nullptr;
    ImageHandler *CurrentImageHandler = nullptr;
    MusicHandler *CurrentMusicHandler = nullptr;
};

#endif