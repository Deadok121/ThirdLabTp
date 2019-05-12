#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h"
#include "Typograph.h"
#include "stdlib.h"

using namespace std;


void printChoices();

void createTypoObject(vector<unique_ptr<Typograph>> &typografObjects);

vector<unique_ptr<Typograph>> getTypographObjects(char *path);

int main() {
    vector<unique_ptr<Typograph>> typografObjects;
    cout << "Enter file path" << endl;
    string file;
    cin >> file;
    char *path = const_cast<char *>(file.c_str());
    printChoices();
    int choice;
    do {
        cout << "Enter your choice : " << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                for (auto &typografObject :  getTypographObjects(path)) {
                    typografObject->display();
                    cout << endl;
                }
                for (auto &typografObject : typografObjects) {
                    typografObject->display();
                    cout << endl;
                }
                break;
            }
            case 2: {
                cout << "Enter type of typograph, 1-book, 2-journal, 3-manual, 4-cancel : " << endl;
                createTypoObject(typografObjects);
                break;
            }
            case 3: {
                for (auto &typografObject : typografObjects) {
                    typografObject->writeByPath(path);
                }
                break;
            }
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 3);
    return 0;
}

