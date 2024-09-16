#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
    
}

void MainMenuState::Update()
{
    TextManager->Update();
    for (uint8_t Option = 0; Option < MenuTexts.size(); ++Option)
    {
        if (Option != SelectedOption)
        {
            TextManager->GenerateText(0, TextSeparation * Option, MenuTexts[Option]);
        }
        else
        {
            TextManager->GenerateSelectedText(0, TextSeparation * Option, MenuTexts[Option]);
        }
    }
}

void MainMenuState::Enter()
{
    TextManager->GenerateStaticText(0, -40, TextBandName);
    TextManager->GenerateStaticText(0, -30, TextAlbumName);
}

void MainMenuState::Exit()
{
}

void MainMenuState::ChangeSelectedOption(bool aChangeSelectedOption)
{
    (void)aChangeSelectedOption;
    SelectedOption = 1 - SelectedOption;
}

void MainMenuState::Select()
{
}

void MainMenuState::Back()
{
}

void MainMenuState::MenuUp()
{
}

void MainMenuState::MenuDown()
{
}