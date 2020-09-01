//
// Created by xMellox on 31-Aug-20.
//

#ifndef OTUS_C___05_GLOBAL_H
#define OTUS_C___05_GLOBAL_H

#include "GraphicFactory.h"
#include "FileManager.h"

struct Global
{
    static Global& Get()
    {
        static Global global;
        return global;
    }

    GraphicFactory& GetGraphicFactory() const
    {
        return *graphicFactory;
    }

    FileManager& GetFileManager()
    {
        return fileManager;
    }

private:
    Global()
    {
        //Defines there in what enviroment we are, and set classes based on that
        graphicFactory = std::make_unique<WindowsFactory>();
    }

    Global(const Global&) = delete;
    Global& operator=(const Global&) = delete;

    Global(Global&&) noexcept = delete;
    Global& operator=(Global&&) noexcept = delete;

    std::unique_ptr<GraphicFactory> graphicFactory;
    FileManager fileManager;
};


#endif //OTUS_C___05_GLOBAL_H
