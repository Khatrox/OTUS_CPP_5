//
// Created by xMellox on 31-Aug-20.
//

#ifndef OTUS_C___05_DOCBUILDER_H
#define OTUS_C___05_DOCBUILDER_H

#include "Document.h"

struct DocBuilder
{
    DocBuilder& WithName(const std::string& ParamName)
    {
        Name = ParamName;
        return *this;
    }

    DocBuilder& WithDescription(const std::string& ParamDescription)
    {
        Description = ParamDescription;
        return *this;
    }

    DocBuilder& WhereToStore(const std::string& ParamPath)
    {
        Path = ParamPath;
        return *this;
    }

    std::unique_ptr<Document> Build() const
    {
        auto Doc = std::make_unique<Document>();
        Doc->SetName(Name);
        Doc->SetDescription(Description);
        const auto DocPath = Path + Name;
        Doc->SetStorePath(DocPath);
        Doc->Save();

        return Doc;
    }

private:
    std::string Name;
    std::string Description;
    std::string Path;
};

#endif //OTUS_C___05_DOCBUILDER_H
