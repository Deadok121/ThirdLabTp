#include <sys/mount.h>
#include <vector>
#include "Book.h"
#include "Journal.h"
#include "Manual.h"
#include "Typograph.h"

#include <fstream>
//
// Created by Roman Oborin on 2019-05-11.
//

void Manual::display() {
    cout << "Book name : " << name << endl;
    cout << "Book annotaion : " << annotation << endl;
    cout << "Page count : " << pageCount << endl;
    cout << "Book year : " << year << endl;
}

void Journal::display() {
    cout << "Book name : " << name << endl;
    cout << "Book annotaion : " << annotation << endl;
    cout << "Page count : " << pageCount << endl;
    cout << "Book year : " << year << endl;
}

void Book::display() {
    cout << "Book name : " << name << endl;
    cout << "Book annotaion : " << annotation << endl;
    cout << "Page count : " << pageCount << endl;
    cout << "Book year : " << year << endl;
}

void Typograph::writeByPath(char *path) {
    ofstream outdata;
    outdata.open(path, std::ios::app);
    outdata << type << endl;
    outdata << year << endl;
    outdata << pageCount << endl;
    outdata << name.c_str() << endl;
    outdata << annotation.c_str() << endl;
    outdata.close();
}

Typograph * Typograph::setPropsValues(ifstream& myfile) {
    string year;
    getline(myfile, year);
    this->setYear(std::stoi(year));
    string pageCount;
    getline(myfile, pageCount);
    this->setPageCount(std::stoi(pageCount));
    string name;
    getline(myfile, name);
    this->setName(name);
    string annotation;
    getline(myfile, annotation);
    this->setAnnotation(annotation);
    return this;
};

void createTypoObject(vector<unique_ptr<Typograph>> &typografObjects) {
    int choice;
    cin >> choice;
    auto setProps = [](Typograph *typo) {
        int year;
        cout << "Enter year :";
        cin >> year;
        typo->setYear(year);
        int pageCount;
        cout << "Enter page count :";
        cin >> pageCount;
        typo->setPageCount(pageCount);
        string name;
        cout << "Enter name :";
        cin >> name;
        typo->setName(name);
        string annotation;
        cout << "Enter annotation :";
        cin >> annotation;
        typo->setAnnotation(annotation);
        return typo;
    };
    switch (choice) {
        case 1: {
            auto book = new Book();
            setProps(book);
            typografObjects.emplace_back(book);
            break;
        }
        case 2: {
            auto *journal = new Journal();
            setProps(journal);
            typografObjects.emplace_back(journal);
            break;
        }
        case 3: {
            auto *manual = new Manual();
            setProps(manual);
            typografObjects.emplace_back(manual);
            break;
        }
        case 4:
            break;
        default:
            break;
    }
}

vector<unique_ptr<Typograph>> getTypographObjects(char *path) {
    vector<unique_ptr<Typograph>> result;
    string line;
    ifstream myfile(path);
    while (getline(myfile, line)) {
        if (line == "Book") {
            auto *book = new Book();
            book->setPropsValues(myfile);
            result.emplace_back(book);
        }
        if (line == "Journal") {
            auto *journal = new Journal();
            journal->setPropsValues(myfile);
            result.emplace_back(journal);
        }
        if (line == "Manual") {
            auto *manual = new Manual();
            manual->setPropsValues(myfile);
            result.emplace_back(manual);
        }
    }
    myfile.close();
    return result;
}

void printChoices() {
    cout << "1.Display all typographs" << endl;
    cout << "2.Add new typograph" << endl;
    cout << "3.Save and exit" << endl;
}