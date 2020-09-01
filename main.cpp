
#include "DocBuilder.h"
#include "Global.h"

int main()
{
    DocBuilder docBuilder;
    docBuilder
            .WithName("StartMenu")
            .WithDescription("StartMenu of Bla bla bla game")
            .WhereToStore("C:/Documents/");

    auto doc = docBuilder.Build();
    auto Canvas = doc->GetComponent();

    auto StartGame = Global::Get().GetGraphicFactory()->GetRectangle();
    auto Settings = Global::Get().GetGraphicFactory()->GetRectangle();
    auto ExitGame = Global::Get().GetGraphicFactory()->GetRectangle();

    Canvas->Add(std::move(StartGame));
    Canvas->Add(std::move(Settings));
    Canvas->Add(std::move(ExitGame));
    doc->Save();

    return 0;
}