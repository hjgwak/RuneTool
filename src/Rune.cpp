//
// Created by Kelvin on 27/01/2017.
//

#include "Rune.h"

using namespace std;
/*
Energy, Fatal, Blade, Swift, Focus, Guard, Endure,
Shield, Revenge, Will, Nemesis, Vampire, Destroy, Despair, Violent,
Rage, Fight, Determination, Enhance, Accuracy, Tolerance
*/
map<RuneType, int> Rune::runeSetNum = {
        {RuneType::Energy, 2}, {RuneType::Fatal, 4}, {RuneType::Blade, 2},
         {RuneType::Swift, 4}, {RuneType::Focus, 2}, {RuneType::Guard, 2},
         {RuneType::Endure, 2}, {RuneType::Shield, 2}, {RuneType::Revenge, 2},
         {RuneType::Will, 2}, {RuneType::Nemesis, 2}, {RuneType::Vampire, 4},
         {RuneType::Destroy, 2}, {RuneType::Despair, 4}, {RuneType::Violent, 4},
         {RuneType::Rage, 4}, {RuneType::Fight, 2}, {RuneType::Determination, 2},
         {RuneType::Enhance, 2}, {RuneType::Accuracy, 2}, {RuneType::Tolerance, 2}
        };

map<RuneType, pair<OptType, int> > Rune::runeAbility = {
        {RuneType::Energy, make_pair(OptType::HP, 15)},
        {RuneType::Fatal, make_pair(OptType::ATK, 35)},
        {RuneType::Blade, make_pair(OptType::CRI_RATE, 12)},
        {RuneType::Swift, make_pair(OptType::SPD, 25)},
        {RuneType::Focus, make_pair(OptType::ACC, 20)},
        {RuneType::Guard, make_pair(OptType::DEF, 15)},
        {RuneType::Endure, make_pair(OptType::RES, 20)},
        {RuneType::Rage, make_pair(OptType::CRI_DMG, 40)},
        {RuneType::Fight, make_pair(OptType::ATK, 7)},
        {RuneType::Determination, make_pair(OptType::DEF, 7)},
        {RuneType::Enhance, make_pair(OptType::HP, 7)},
        {RuneType::Accuracy, make_pair(OptType::ACC, 10)},
        {RuneType::Tolerance, make_pair(OptType::RES, 10)}
};

static map<OptType, vector<int> > maxValueMap = {
        {OptType::ATK, {18, 19, 38, 43, 51, 63}},
        {OptType::DEF, {18, 19, 38, 43, 51, 63}},
        {OptType::HP, {18, 19, 38, 43, 51, 63}},
        {OptType::SPD, {18, 19, 25, 30, 39, 42}},
        {OptType::CRI_RATE, {18, 19, 37, 42, 47, 58}},
        {OptType::CRI_DMG, {19, 37, 43, 57, 64, 80}},
        {OptType::ACC, {18, 19, 38, 44, 51, 64}},
        {OptType::RES, {18, 19, 38, 44, 51, 64}}
};

// Constructors
Rune::Rune() {

}

Rune::Rune(const int id, const int star, const int position, const RuneType type, const OptType main) {
    this->id = id;
    this->star = star;
    this->position = position;
    this->type = type;
    this->main = main;
    if (this->main != OptType::none) this->setOpt(main, 0, true);
    this->monster = "";
}

Rune::Rune(const Rune& rune) {
    this->id = rune.id;
    this->star = rune.star;
    this->position = rune.position;
    this->type = rune.type;
    this->main = rune.main;
    if (this->main != OptType::none) this->setOpt(main, 0, true);
    this->properties = rune.properties;
    this->monster = rune.monster;
}

Rune& Rune::operator=(const Rune& rune) {
    this->id = rune.id;
    this->star = rune.star;
    this->position = rune.position;
    this->type = rune.type;
    this->main = rune.main;
    if (this->main != OptType::none) this->setOpt(main, 0, true);
    this->properties = rune.properties;
    this->monster = rune.monster;

    return *this;
}

// Setteres
void Rune::setOpt(const OptType opt, const int value, const bool main) {
    this->properties[opt] = (main) ? maxValueMap[opt][this->star - 1] : value;
    if (main) this->main = opt;
}

void Rune::setMonster(const string monster) {
    this->monster = monster;
}

void Rune::setID(const int id) {
    this->id = id;
}

// Getters
int Rune::getOpt(OptType opt) const {
    map<OptType, int>::const_iterator it = this->properties.find(opt);
    return (it == this->properties.end()) ? -1 : this->properties.at(opt);
}

vector<OptType> Rune::getKey() const {
    vector<OptType> keys;

    map<OptType, int>::const_iterator m_it = this->properties.begin();
    for (; m_it != this->properties.end(); ++m_it) {
        keys.push_back(m_it->first);
    }

    return keys;
}

bool Rune::isFree() const {
    return this->monster == "";
}

string Rune::getMonster() const {
    return (this->isFree()) ? "Free" : this->monster;
}

string Rune::getTypeString() const {
    return Rune::getTypeString(this->type);
}

RuneType Rune::getType() const {
    return this->type;
}

int Rune::getPosition() const {
    return this->position;
}

int Rune::getStar() const {
    return this->star;
}

OptType Rune::getMain() const {
    return this->main;
}

std::string Rune::getMainString() const {
    return Rune::getOptString(this->main);
}

int Rune::getID() const {
    return this->id;
}

std::string Rune::getOptString(OptType opt) {
    return (opt == OptType::ATK) ? "ATK" :
           (opt == OptType::DEF) ? "DEF" :
           (opt == OptType::SPD) ? "SPD" :
           (opt == OptType::HP) ? "HP" :
           (opt == OptType::CRI_RATE) ? "CRI_RATE" :
           (opt == OptType::CRI_DMG) ? "CRI_DMG" :
           (opt == OptType::ACC) ? "ACC" :
           (opt == OptType::RES) ? "RES" : "-";
}

std::string Rune::getTypeString(RuneType type) {
    return (type == RuneType::Energy) ? "Energy" :
           (type == RuneType::Fatal) ? "Fatal" :
           (type == RuneType::Blade) ? "Blade" :
           (type == RuneType::Swift) ? "Swift" :
           (type == RuneType::Focus) ? "Focus" :
           (type == RuneType::Guard) ? "Guard" :
           (type == RuneType::Endure) ? "Endure" :
           (type == RuneType::Shield) ? "Shield" :
           (type == RuneType::Revenge) ? "Revenge" :
           (type == RuneType::Will) ? "Will" :
           (type == RuneType::Nemesis) ? "Nemesis" :
           (type == RuneType::Vampire) ? "Vampire" :
           (type == RuneType::Destroy) ? "Destroy" :
           (type == RuneType::Despair) ? "Despair" :
           (type == RuneType::Violent) ? "Violent" :
           (type == RuneType::Rage) ? "Rage" :
           (type == RuneType::Fight) ? "Fight" :
           (type == RuneType::Determination) ? "Determination" :
           (type == RuneType::Enhance) ? "Enhance" :
           (type == RuneType::Accuracy) ? "Accuracy" :
           (type == RuneType::Tolerance) ? "Tolerance" : "";
}

OptType Rune::convertOptString(std::string opt) {
    return (opt == "ATK") ? OptType::ATK :
           (opt == "DEF") ? OptType::DEF :
           (opt == "SPD") ? OptType::SPD :
           (opt == "HP") ? OptType::HP :
           (opt == "CRI_RATE") ? OptType::CRI_RATE :
           (opt == "CRI_DMG") ? OptType::CRI_DMG :
           (opt == "ACC") ? OptType::ACC :
           (opt == "RES") ? OptType::RES : OptType::none;
}

RuneType Rune::convertTypeString(std::string type) {
    return (type == "Energy") ? RuneType::Energy :
           (type == "Fatal") ? RuneType::Fatal :
           (type == "Blade") ? RuneType::Blade :
           (type == "Swift") ? RuneType::Swift :
           (type == "Focus") ? RuneType::Focus :
           (type == "Guard") ? RuneType::Guard :
           (type == "Endure") ? RuneType::Endure :
           (type == "Shield") ? RuneType::Shield :
           (type == "Revenge") ? RuneType::Revenge :
           (type == "Will") ? RuneType::Will :
           (type == "Nemesis") ? RuneType::Nemesis :
           (type == "Vampire") ? RuneType::Vampire :
           (type == "Destroy") ? RuneType::Destroy :
           (type == "Despair") ? RuneType::Despair :
           (type == "Violent") ? RuneType::Violent :
           (type == "Rage") ? RuneType::Rage :
           (type == "Fight") ? RuneType::Fight :
           (type == "Determination") ? RuneType::Determination :
           (type == "Enhance") ? RuneType::Enhance :
           (type == "Accuracy") ? RuneType::Accuracy :
           (type == "Tolerance") ? RuneType::Tolerance : RuneType::none;
}


RuneSet::RuneSet() {
    this->properties[OptType::HP] = 0;
    this->properties[OptType::ATK] = 0;
    this->properties[OptType::DEF] = 0;
    this->properties[OptType::SPD] = 0;
    this->properties[OptType::CRI_RATE] = 15;
    this->properties[OptType::CRI_DMG] = 50;
    this->properties[OptType::ACC] = 0;
    this->properties[OptType::RES] = 0;
    this->set_applied = false;
}

void RuneSet::addRune(const Rune &rune) {
    if (this->rune_map.find(rune.getPosition()) != this->rune_map.end()) {
        this->removeRune(rune.getPosition());
    }

    this->rune_map[rune.getPosition()] = rune;

    vector<OptType> opts = rune.getKey();
    for (vector<OptType>::iterator it = opts.begin(); it != opts.end(); ++it) {
        this->properties[*it] += rune.getOpt(*it);
    }

    if (this->rune_cnt.find(rune.getType()) == this->rune_cnt.end())
        this->rune_cnt[rune.getType()] = 0;
    this->rune_cnt[rune.getType()]++;
}

void RuneSet::removeRune(const int pos) {
    if (this->rune_map.find(pos) != this->rune_map.end()) {
        vector<OptType> opts = this->rune_map[pos].getKey();
        for (vector<OptType>::iterator it = opts.begin(); it != opts.end(); ++it) {
            this->properties[*it] -= this->rune_map[pos].getOpt(*it);
        }

        this->rune_cnt[this->rune_map[pos].getType()]--;
        this->rune_map.erase(pos);
    }
}

int RuneSet::getOpt(const OptType opt) const {
    map<OptType, int>::const_iterator it = this->properties.find(opt);
    return (it == this->properties.end()) ? -1 : this->properties.at(opt);
}

void RuneSet::applySet() {
    if (!this->set_applied) {
        map<RuneType, int>::iterator m_it = this->rune_cnt.begin();
        for (; m_it != this->rune_cnt.end(); ++m_it) {
            if (m_it->second >= Rune::runeSetNum[m_it->first]) {
                if (Rune::runeAbility.find(m_it->first) != Rune::runeAbility.end()) {
                    this->properties[Rune::runeAbility[m_it->first].first] +=
                            Rune::runeAbility[m_it->first].second;
                }
            }
        }
        this->set_applied = true;
    }
}

void RuneSet::cancelSet() {
    if (this->set_applied) {
        map<RuneType, int>::iterator m_it = this->rune_cnt.begin();
        for (; m_it != this->rune_cnt.end(); ++m_it) {
            if (m_it->second >= Rune::runeSetNum[m_it->first]) {
                if (Rune::runeAbility.find(m_it->first) != Rune::runeAbility.end()) {
                    this->properties[Rune::runeAbility[m_it->first].first] -=
                            Rune::runeAbility[m_it->first].second;
                }
            }
        }
        this->set_applied = false;
    }
}











