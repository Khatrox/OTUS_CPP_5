//
// Created by xMellox on 31-Aug-20.
//

#ifndef OTUS_C___05_FILEMANAGER_H
#define OTUS_C___05_FILEMANAGER_H

#include "Document.h"

struct FileManager
{
    std::unique_ptr<Document> OpenDoc(const std::string& DocPath)
    {
        // Open File on Path with Windows rules, Got some content
        std::string Content;
        auto Doc = std::make_unique<Document>(Content);

        return Doc;
    }

    void SaveDoc(const std::string& DocPath, const std::string& DocContent)
    {
        //Check that DocPath exist, and if so write there this DocContent
    }
    
};


#endif //OTUS_C___05_FILEMANAGER_H
