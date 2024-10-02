#include "StateBase.h"
#include "TextGenerator.h"
#include "ImageHandler.h"
#include "MusicHandler.h"

StateBase::StateBase(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler)
    : TextGeneratorPTR(aTextGenerator), ImageHandlerPTR(aImageHandler), MusicHandlerPTR(aMusicHandler)
{
}