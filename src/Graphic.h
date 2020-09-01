//
// Created by xMellox on 31-Aug-20.
//

#ifndef OTUS_C___05_GRAPHIC_H
#define OTUS_C___05_GRAPHIC_H

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

struct Graphic
{
    virtual ~Graphic() = default;
    virtual void Draw() = 0;
    virtual void Add(const std::shared_ptr<Graphic>& Graphic) { throw std::logic_error("Can't add Graphic to Leaf"); };
    virtual void Remove(const Graphic* Graphic) { throw std::logic_error("Can't remove graphic from Leaf");};
    virtual std::string GetContent() const = 0;
};

struct Canvas : Graphic
{

};

struct Square : Graphic
{

};

struct Circle : Graphic
{

};

struct Rectangle : Graphic
{

};

struct WinCanvas : Canvas
{
    void Draw() override
    {
        for(auto& i : leafs)
        {
            i->Draw();
        }
    }

    void Add(const std::shared_ptr<Graphic>& Graphic) override
    {
        leafs.push_back(Graphic);
    }

    void Remove(const Graphic* graphic) override
    {
        auto it = std::find_if(leafs.begin(),leafs.end(),[graphic]
        (const std::shared_ptr<Graphic>& graphic_member)
        {
            return graphic_member.get() == graphic;
        });

        if(it != std::end(leafs))
        {
            leafs.erase(it);
        }
    }

    std::string GetContent() const override
    {
        std::string r;

        for(const auto & i : leafs)
        {
            r += i->GetContent();
            r += '\n';
        }

        return r;
    }

private:
    std::vector<std::shared_ptr<Graphic>> leafs;
};

struct WinSquare : Square
{
    void Draw() override
    {
        std::cout << "WinSquare draw\n";
    }

    std::string GetContent() const override
    {
        return "WinSquare Content\n";
    }
};

struct WinCircle : Circle
{
    void Draw() override
    {
        std::cout << "WinCircle draw\n";
    }

    std::string GetContent() const override
    {
        return "WinCircle Content\n";
    }
};

struct WinRectangle : Rectangle
{
    void Draw() override
    {
        std::cout << "WinRectangle draw\n";
    }

    std::string GetContent() const override
    {
        return "WinRectangle Content\n";
    }
};

struct KDECanvas : Canvas
{
    void Draw() override
    {
        //Go through leafs collection and draw them
    }

    void Add(const std::shared_ptr<Graphic>& Graphic) override
    {
        //Add graphic to collection
    }

    void Remove(const Graphic* graphic) override
    {
        //Remove Graphic from collection
    }

    std::string GetContent() const override
    {
        //Get content from leafs
        std::string Content;

        return Content;
    }
};

struct KDESquare : Square
{
    void Draw() override
    {
        std::cout << "KDESquare draw\n";
    }

    std::string GetContent() const override
    {
        return "KDESquare Content\n";
    }
};

struct KDECircle : Circle
{
    void Draw() override
    {
        std::cout << "KDECircle draw\n";
    }

    std::string GetContent() const override
    {
        return "KDECircle Content\n";
    }
};

struct KDERectangle : Rectangle
{
    void Draw() override
    {
        std::cout << "KDERectangle draw\n";
    }

    std::string GetContent() const override
    {
        return "KDERectangle Content\n";
    }
};


#endif //OTUS_C___05_GRAPHIC_H
