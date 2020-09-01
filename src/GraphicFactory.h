//
// Created by xMellox on 31-Aug-20.
//

#ifndef OTUS_C___05_GRAPHICFACTORY_H
#define OTUS_C___05_GRAPHICFACTORY_H

#include "Graphic.h"

struct GraphicFactory
{
    virtual ~GraphicFactory() = default;
    virtual std::unique_ptr<Square> GetSquare() const = 0;
    virtual std::unique_ptr<Circle> GetCircle() const = 0;
    virtual std::unique_ptr<Rectangle> GetRectangle() const = 0;
    virtual std::unique_ptr<Canvas> GetCanvas() const = 0;
};

struct WindowsFactory : GraphicFactory
{
    std::unique_ptr<Square> GetSquare() const override
    {
        return std::make_unique<WinSquare>();
    }

    std::unique_ptr<Circle> GetCircle() const override
    {
        return std::make_unique<WinCircle>();
    }

    std::unique_ptr<Rectangle> GetRectangle() const override
    {
        return std::make_unique<WinRectangle>();
    }

    std::unique_ptr<Canvas> GetCanvas() const override
    {
        return std::make_unique<WinCanvas>();
    }
};

struct KDEFactory : GraphicFactory
{
    std::unique_ptr<Square> GetSquare() const override
    {
        return std::make_unique<KDESquare>();
    }

    std::unique_ptr<Circle> GetCircle() const override
    {
        return std::make_unique<KDECircle>();
    }

    std::unique_ptr<Rectangle> GetRectangle() const override
    {
        return std::make_unique<KDERectangle>();
    }

    std::unique_ptr<Canvas> GetCanvas() const override
    {
        return std::make_unique<KDECanvas>();
    }
};



#endif //OTUS_C___05_GRAPHICFACTORY_H
