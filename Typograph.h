//
// Created by Roman Oborin on 2019-05-11.
//Определить абстрактный базовый класс «Печатное издание», для которого
//существует наименование, год издания, наименование издательства, количество страниц,
//аннотация; определить метод вывода на экран. Определить наследников: журнал, учебник,
//книга. Для каждого наследника переопределить вывод на экран.
#include "string"

#ifndef LAB3_TYPOGRAPH_H
#define LAB3_TYPOGRAPH_H
using namespace std;

class Typograph {
protected:
    int year;
    string type;
    int pageCount;
    string name;
    string annotation;
public:
    Typograph() = default;;

    virtual ~Typograph() = default;;

    virtual void display() = 0;

    Typograph * setPropsValues(ifstream& myfile);

    int getYear() {
        return year;
    }

    void setYear(int year) {
        Typograph::year = year;
    }

    void setPageCount(int pageCount) {
        Typograph::pageCount = pageCount;
    }

    void setName(const string &name) {
        Typograph::name = name;
    }

    void setAnnotation(const string &annotation) {
        Typograph::annotation = annotation;
    }

    int getPageCount() {
        return pageCount;
    }

    string getName() {
        return name;
    }

    string getAnnotaion() {
        return annotation;
    }

    void writeByPath(char* path);
};


#endif //LAB3_TYPOGRAPH_H
