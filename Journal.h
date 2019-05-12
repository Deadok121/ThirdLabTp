//
// Created by Roman Oborin on 2019-05-12.
//

#ifndef LAB3_JOURNAL_H
#define LAB3_JOURNAL_H

#include "Typograph.h"

class Journal : public Typograph {
public:
    Journal() { type = "Journal"; }

    ~Journal() override = default;;

    void display() override;

    Journal(const Journal &object) {};
};

#endif //LAB3_JOURNAL_H
