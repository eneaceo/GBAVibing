#ifndef STATEBASE_H
#define STATEBASE_H

class TextGenerator;
class ImageHandler;
class MusicHandler;

class StateBase
{
public:
    StateBase(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler);
    virtual ~StateBase() = default;

    virtual void Update() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;

    virtual void Select() {};
    virtual void Back() {};
    virtual void MenuUp() {};
    virtual void MenuDown() {};
    virtual void Auto() {};

protected:
    int SelectedOption = 0;

    TextGenerator *TextGeneratorPTR = nullptr;
    ImageHandler *ImageHandlerPTR = nullptr;
    MusicHandler *MusicHandlerPTR = nullptr;
};

#endif