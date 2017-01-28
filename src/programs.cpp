//
// Created by Kelvin on 28/01/2017.
//

#include "programs.h"
#include "RuneIO.h"
#include "Rune.h"
#include <iostream>
#include <algorithm>

using namespace std;

static vector<string> getPossibleOpts(int position) {
    vector<string> opts;
    if (position % 2 == 0) {
        opts.push_back("ATK");
        opts.push_back("DEF");
        opts.push_back("HP");
        if (position == 2) {
            opts.push_back("SPD");
        } else if (position == 4) {
            opts.push_back("CRI_RATE");
            opts.push_back("CRI_DMG");
        } else if (position == 6) {
            opts.push_back("ACC");
            opts.push_back("RES");
        }
    }
    opts.push_back("-");

    return opts;
}

static vector<string> getSubOptions(int position) {
    vector<string> opts;
    if (position != 3) {
        opts.push_back("ATK");
    }
    if (position != 1) {
        opts.push_back("DEF");
    }
    opts.push_back("HP");
    opts.push_back("SPD");
    opts.push_back("CRI_RATE");
    opts.push_back("CRI_DMG");
    opts.push_back("ACC");
    opts.push_back("RES");

    return opts;
}

static string join(vector<string>& opts) {
    string str = "";
    vector<string>::iterator v_it = opts.begin();
    for (; v_it != opts.end(); ++v_it) {
        if (v_it != opts.begin()) str += ", ";
        str += *v_it;
    }
    return str;
}

static void remove(vector<string>& opts, const string& opt) {
    if (opt == "-") return;
    vector<string>::iterator pos = find(opts.begin(), opts.end(), opt);
    opts.erase(pos);
}

static vector<int> getRemainIDs(const string& file_name) {
    vector<int> ids;

    ifstream r_id_f("." + file_name, ifstream::in);
    if (r_id_f.is_open()) {
        string temp;
        while (getline(r_id_f, temp)) {
            int id = stoi(temp);
            ids.push_back(id);
        }
        r_id_f.close();
    }

    return ids;
}

static void writeRemainIDs(const vector<int>& r_ids, const string& file_name) {
    vector<int> ids(r_ids);
    sort(ids.begin(), ids.end());

    ofstream r_id_f("." + file_name, ofstream::out);
    vector<int>::const_iterator v_it = ids.begin();
    for (; v_it != ids.end(); ++v_it) {
        r_id_f << *v_it << endl;
    }
    r_id_f.close();
}

void writeOneRune(const string& file_name) {
    string temp;
    int star, position;
    RuneType type;
    OptType main;

    vector<int> ids = getRemainIDs(file_name);
    int id;
    if (ids.empty()) {
        id = 1;
    } else {
        id = ids[0];
        ids.erase(ids.begin());
    }

    cout << "Star (1 ~ 6): ";
    getline(cin, temp);
    star = stoi(temp);

    cout << "Position (1 ~ 6): ";
    getline(cin, temp);
    position = stoi(temp);

    cout << "RuneType" << endl;
    cout << "    Energy, Fatal, Blade, Swift, Focus, Guard, Endure, Shield" << endl;
    cout << "    Revenge, Will, Nemesis, Vampire, Destroy, Despair, Violent," << endl;
    cout << "    Rage, Fight, Determination, Enhance, Accuracy, Tolerance" << endl;
    cout << ": ";
    getline(cin, temp);
    type = Rune::convertTypeString(temp);

    cout << "Main Option" << endl;
    vector<string> opts = getPossibleOpts(position);
    cout << "    " << join(opts) << endl;
    cout << ": ";
    getline(cin, temp);
    main = Rune::convertOptString(temp);

    Rune new_rune(id, star, position, type, main);

    cout << "Additional Options,value" << endl;
    opts = getSubOptions(position);
    remove(opts, temp);
    for (int i = 0; i < 4; ++i) {
        cout << "OptionType (END = input -1 or input 4 options)";
        cout << "    " << join(opts);
        cout << ": ";
        getline(cin, temp);
        if (temp == "-1") break;
        remove(opts, temp);
        OptType opt = Rune::convertOptString(temp);
        cout << "value: ";
        getline(cin, temp);
        int value = stoi(temp);
        new_rune.setOpt(opt, value);
    }

    cout << "Monster (if none, type -): ";
    getline(cin, temp);
    if (temp != "-") {
        new_rune.setMonster(temp);
    }

    if (ids.empty()) {
        ids.push_back(id + 1);
    }

    WriteOneRuneToFile(new_rune, file_name);
    writeRemainIDs(ids, file_name);
}

void showRune(const int id, const RuneType type, const int num, const int star, const string& file_name) {
    vector<Rune> runes = ReadRune(file_name);
    vector<Rune> toWrite;

    vector<Rune>::iterator v_it = runes.begin();
    for (; v_it != runes.end(); ++v_it) {
        if (id != -1 && v_it->getID() != id) continue;
        if (type != RuneType::none && v_it->getType() != type) continue;
        if (num != -1 && v_it->getPosition() != num) continue;
        if (star != -1 && v_it->getStar() != star) continue;
        toWrite.push_back(*v_it);
    }

    WriteRune(toWrite, cout);
}

