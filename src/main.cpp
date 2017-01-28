#include "Rune.h"
#include "RuneIO.h"
#include "programs.h"
#include <iostream>

using namespace std;

static vector<string> tokenizer(string& line, char delim) {
    istringstream ss(line);
    vector<string> tokens;
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

static void printUSAGE() {
    cout << "USAGE: ./RuneTool [program] [opts]" << endl;
    cout << "    program:" << endl;
    cout << "        write (file_name, default RuneDB.txt)" << endl;
    cout << "        show (opts) (file_name, default RuneDB.txt)" << endl;
    cout << "            -id #, show rune which has given ID" << endl;
    cout << "                   multiple ids can be given by using ',' character to delimiter" << endl;
    cout << "            -rune_type RuneType, show runes which have given RuneType" << endl;
    cout << "            -rune_num #, show runes which have given rune_number" << endl;
    cout << "            -star #, show runes which have given star" << endl;
    cout << "        remove (opts) (file_name, default RuneDB.txt)" << endl;
    cout << "            -id #, remove rune which has given ID" << endl;
    cout << "                   multiple ids can be given by using ',' character to delimiter" << endl;
    cout << "        combination (opts) (file_name, default RuneDB.txt)" << endl;
    cout << "            -set RuneType, combinations must include RuneType" << endl;
    cout << "                           multiple RuneTypes can be given by using ',' character to delimiter" << endl;
    cout << "            -filter OptType:value, combinations which have larger value of given OpyType then given value" << endl;
    cout << "                                   multiple filter can be given by using ',' character to delimiter" << endl;
    cout << "                    OptTypes: ATK, DEF, SPD, HP, CRI_RATE, CRI_DMG, ACC, RES" << endl;
}

static int getOpt(int argc, char* argv[], string opt) {
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
            writeRunes(argv[2]);
        } else {
            writeRunes();
        }
    } else if (strcmp(argv[1], "show") == 0) {
        if (argc > 9) {
            printUSAGE();
        } else if (argc == 2) {
            showRune({});
        } else {
            int pos;
            string id = ((pos = getOpt(argc, argv, "-id")) == -1) ? "-1" : argv[pos + 1];
            vector<string> tokens = tokenizer(id, ',');
            vector<int> ids;
            for (int i = 0; i < tokens.size(); ++i) ids.push_back(stoi(tokens[i]));
            RuneType type = ((pos = getOpt(argc, argv, "-rune_type")) == -1) ? RuneType::none : Rune::convertTypeString(argv[pos + 1]);
            int num = ((pos = getOpt(argc, argv, "-rune_num")) == -1) ? -1 : stoi(argv[pos + 1]);
            int star = ((pos = getOpt(argc, argv, "-star")) == -1) ? -1 : stoi(argv[pos + 1]);
            string file_name = (argc % 2 == 0) ? "RuneDB.txt" : argv[argc - 1];

            showRune(ids, type, num, star, file_name);
        }
    } else if (strcmp(argv[1], "remove") == 0) {
        if (argc > 5 || argc < 4) {
            printUSAGE();
        } else {
            int pos;
            if ((pos = getOpt(argc, argv, "-id")) == -1) {
                printUSAGE();
            } else {
                string temp = argv[pos + 1];
                vector<string> tokens = tokenizer(temp, ',');
                vector<int> ids;
                for (vector<string>::iterator v_it = tokens.begin();
                        v_it != tokens.end(); ++v_it) {
                    ids.push_back(stoi(*v_it));
                }

                string file_name = (argc == 5) ? argv[argc - 1] : "RuneDB.txt";
                removeRune(ids, file_name);
            }
        }
    } else if (strcmp(argv[1], "combination") == 0) {
        if (argc > 7) {
            printUSAGE();
        } else {
            int pos;
            string set_string = ((pos = getOpt(argc, argv, "-set")) == -1) ? "" : argv[pos + 1];
            vector<string> tokens = tokenizer(set_string, ',');
            if (tokens.size() > 3) {
                cerr << "Maximum 3 kinds of RuneType could be set" << endl;
                return -1;
            }
            vector<RuneType> sets;
            for (int i = 0; i < tokens.size(); ++i) sets.push_back(Rune::convertTypeString(tokens[i]));

            string filter_string = ((pos = getOpt(argc, argv, "-filter")) == -1) ? "" : argv[pos + 1];
            tokens = tokenizer(filter_string, ',');
            map<OptType, int> filter;
            for (int i = 0; i < tokens.size(); ++i) {
                vector<string> temp = tokenizer(tokens[i], ':');
                filter[Rune::convertOptString(temp[0])] = stoi(temp[1]);
            }
            string file_name = (argc % 2 == 0) ? "RuneDB.txt" : argv[argc - 1];

            combination(sets, filter, file_name);
        }
    }

    return 0;
}