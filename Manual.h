//
// Created by Roman Oborin on 2019-05-12.
//

#ifndef LAB3_MANUAL_H
#define LAB3_MANUAL_H


#include "Typograph.h"

class Manual : public Typograph {
public:
    Manual() { type = "Manual"; }

    ~Manual() override = default;;

    void display() override;

    Manual(const Manual &object) {};
};

#endif //LAB3_MANUAL_H
