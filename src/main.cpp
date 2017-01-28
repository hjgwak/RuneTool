#include "Rune.h"
#include "RuneIO.h"
#include "programs.h"
#include <iostream>

using namespace std;

void printUSAGE() {
    cout << "USAGE: ./RuneTool [program] [opts]" << endl;
    cout << "    program:" << endl;
    cout << "        write (file_name, default RuneDB.txt)" << endl;
    cout << "        show (opts) (file_name, default RuneDB.txt)" << endl;
    cout << "            -id #, show rune which has given ID" << endl;
    cout << "            -rune_type RuneType, show runes which have given RuneType" << endl;
    cout << "            -rune_num #, show runes which have given rune_number"<< endl;
    cout << "            -star #, show runes which have given star" << endl;
}

int getOpt(int argc, char* argv[], string opt) {
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], opt.c_str()) == 0) return i;
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc < 2 || getOpt(argc, argv, "-h") != -1) {
        printUSAGE();
        return -1;
    }

    if (strcmp(argv[1], "write") == 0) {
        if (argc > 3) {
            printUSAGE();
        } else if (argc == 3) {
            writeOneRune(argv[2]);
        } else {
            writeOneRune();
        }
    } else if (strcmp(argv[1], "show") == 0) {
        if (argc > 9) {
            printUSAGE();
        } else if (argc == 2) {
            showRune();
        } else {
            int pos;
            int id = ((pos = getOpt(argc, argv, "-id")) == -1) ? -1 : stoi(argv[pos + 1]);
            RuneType type = ((pos = getOpt(argc, argv, "-rune_type")) == -1) ? RuneType::none : Rune::convertTypeString(argv[pos + 1]);
            int num = ((pos = getOpt(argc, argv, "-rune_num")) == -1) ? -1 : stoi(argv[pos + 1]);
            int star = ((pos = getOpt(argc, argv, "-star")) == -1) ? -1 : stoi(argv[pos + 1]);
            string file_name = (argc % 2 == 0) ? "RuneDB.txt" : argv[argc - 1];

            showRune(id, type, num, star, file_name);
        }
    }

    return 0;
}