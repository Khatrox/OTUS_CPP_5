//
// Created by xMellox on 31-Aug-20.
//

#include "Document.h"
#include "Global.h"

Document::Document()
:
Graphic{}
{
        Graphic = Global::Get().GetGraphicFactory().GetCanvas();
}

Document::Document(const std::string &Content)
:
Document()
{
    //Extract Content
    //Creates primitives
    //Build Composite based on rules of Content
}

void Document::SetName(const std::string &NewName)
{
    Name = NewName;
}

void Document::SetDescription(const std::string &NewDescription)
{
    Description = NewDescription;
}

void Document::SetStorePath(const std::string &NewStorePath)
{
    StorePath = NewStorePath;
}

std::string Document::GetName() const
{
    return Name;
}

std::string Document::GetDescription() const
{
    return Description;
}

std::string Document::GetStorePath() const
{
    return StorePath;
}

Graphic* Document::GetComponent() const
{
    return Graphic.get();
}

void Document::Save()
{
    auto Content = Graphic->GetContent();
    Global::Get().GetFileManager().SaveDoc(StorePath,Content);
}
