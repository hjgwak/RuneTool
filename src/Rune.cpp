//
// Created by Kelvin on 27/01/2017.
//

#include "Rune.h"

using namespace std;

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
























