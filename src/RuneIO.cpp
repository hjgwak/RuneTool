//
// Created by Kelvin on 27/01/2017.
//

#include "RuneIO.h"
#include "Error.h"

using namespace std;

/*
 * RuneDB file format
 * tab delimited
 *     1. Rune ID
 *     2. Rune type
 *     3. Rune position
 *     4. star
 *     5. main option (if rune position is odd, main opt is '-')
 *     6. option description
 *         Opt1:value1,Opt2:value2....
 *     7. monster (if rune is not set, it will be "Free")
 */

static vector<string> tokenizer(string& line, char delim) {
    istringstream ss(line);
    vector<string> tokens;
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

vector<Rune> ReadRune(const string& file_name) {
    ifstream rune_f(file_name, ifstream::in);
    if (!rune_f.is_open()) {
        Error("[RuneIO][ReadRune] " + file_name + " was open failed.");
        exit(-1);
    }

    vector<Rune> runes;
    string line;

    while (getline(rune_f, line)) {
        vector<string> tokens = tokenizer(line, '\t');
        Rune* new_rune;
        for (int cnt = 0; cnt < tokens.size(); ++cnt) {
            RuneType type;
            int position, star, id;
            OptType main;
            string monster;

            if (cnt == 0) {
                id = stoi(tokens[cnt]);
            } else if (cnt == 1) {
                type = Rune::convertTypeString(tokens[cnt]);
            } else if (cnt == 2) {
                position = stoi(tokens[cnt]);
            } else if (cnt == 3) {
                star = stoi(tokens[cnt]);
            } else if (cnt == 4) {
                main = Rune::convertOptString(tokens[cnt]);
                new_rune = new Rune(id, star, position, type, main);
            } else if (cnt == 5) {
                vector<string> optValuePairs = tokenizer(tokens[cnt], ',');
                for (int i = 0; i < optValuePairs.size(); ++i) {
                    istringstream ss(optValuePairs[i]);
                    string temp;
                    getline(ss, temp, ':');
                    OptType opt = Rune::convertOptString(temp);
                    getline(ss, temp, ':');
                    int value = stoi(temp);

                    new_rune->setOpt(opt, value);
                }
                if (main != OptType::none) new_rune->setOpt(main, 0, true);
            } else if (cnt == 6) {
                monster = tokens[cnt];
                new_rune->setMonster(monster);
            }
        }
        runes.push_back(*new_rune);
        delete new_rune;
    }

    rune_f.close();

    return runes;
}

void WriteRune(const vector<Rune>& runes, ostream& os) {
    vector<Rune>::const_iterator v_it = runes.begin();
    for (; v_it != runes.end(); ++v_it) {
        os << v_it->getID() << "\t";
        os << v_it->getTypeString() << "\t";
        os << v_it->getPosition() << "\t";
        os << v_it->getStar() << "\t";
        os << v_it->getMainString() << "\t";

        vector<OptType> keys = v_it->getKey();
        vector<OptType>::iterator v_it2 = keys.begin();
        for (; v_it2 != keys.end(); ++v_it2) {
            if (v_it2 != keys.begin()) os << ",";
            os << Rune::getOptString(*v_it2) << ":" << v_it->getOpt(*v_it2);
        }
        os << "\t";

        os << v_it->getMonster() << endl;
    }
}