//
// Created by Kelvin on 27/01/2017.
//

#ifndef RUNETOOL_RUNE_H
#define RUNETOOL_RUNE_H

#include <map>
#include <string>
#include <vector>

enum class RuneType {Energy, Fatal, Blade, Swift, Focus, Guard, Endure,
    Shield, Revenge, Will, Nemesis, Vampire, Destroy, Despair, Violent,
    Rage, Fight, Determination, Enhance, Accuracy, Tolerance, none};

enum class OptType {ATK, DEF, SPD, HP, CRI_RATE, CRI_DMG, ACC, RES, none};

class Rune {
public:
    //constructors
    Rune();
    Rune(const int id, const int star, const int position, const RuneType type, const OptType main);
    Rune(const Rune& rune);
    Rune& operator= (const Rune& rune);

    //Setters
    void setOpt(const OptType opt, const int value, const bool main = false);
    void setMonster(const std::string monster);
    void setID(const int id);

    //Getters
    int getOpt(OptType opt) const;
    std::vector<OptType> getKey() const;
    bool isFree() const;
    std::string getMonster() const;
    RuneType getType() const;
    std::string getTypeString() const;
    int getPosition() const;
    int getStar() const;
    OptType getMain() const;
    std::string getMainString() const;
    int getID() const;

    static std::string getOptString(OptType opt);
    static std::string getTypeString(RuneType type);
    static OptType convertOptString(std::string opt);
    static RuneType convertTypeString(std::string type);

    static std::map<RuneType, int> runeSetNum;
    static std::map<RuneType, std::pair<OptType, int> > runeAbility;
private:
    int id;
    int star;
    int position;
    RuneType type;
    OptType main;
    std::map<OptType, int> properties;
    std::string monster;
};

class RuneSet {
    // Constructors
    RuneSet();

    // Setters
    void addRune(const Rune& rune);
    void removeRune(const int pos);
    void applySet();
    void cancelSet();

    // Getters;
    int getOpt(const OptType opt) const;
private:
    bool set_applied;
    std::map<int, Rune> rune_map;
    std::map<OptType, int> properties;
    std::map<RuneType, int> rune_cnt;
};


#endif //RUNETOOL_RUNE_H
