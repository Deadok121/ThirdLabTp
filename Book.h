//
// Created by Roman Oborin on 2019-05-11.
//

#ifndef LAB3_TYPOGRAPHEXTENSIONS_H
#define LAB3_TYPOGRAPHEXTENSIONS_H

#include <iostream>
#include "Typograph.h"

class Book : public Typograph {
public:
    Book() { type = "Book"; }

    ~Book() override = default;;

    void display() override;

    Book(const Book &object){};
};
#endif //LAB3_TYPOGRAPHEXTENSIONS_H
