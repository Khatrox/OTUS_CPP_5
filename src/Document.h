//
// Created by xMellox on 31-Aug-20.
//

#ifndef OTUS_C___05_DOCUMENT_H
#define OTUS_C___05_DOCUMENT_H

#include "Graphic.h"

struct Document
{
    Document();
    explicit Document(const std::string& Content);

    void SetName(const std::string& NewName);
    void SetDescription(const std::string& NewDescription);
    void SetStorePath(const std::string& NewStorePath);

    std::string GetName() const;
    std::string GetDescription() const;
    std::string GetStorePath() const;
    Graphic* GetComponent() const;
    void Save();

private:

    std::string Name;
    std::string Description;
    std::string StorePath;
    std::unique_ptr<Graphic> graphic;

};


#endif //OTUS_C___05_DOCUMENT_H
