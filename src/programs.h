//
// Created by Kelvin on 28/01/2017.
//

#ifndef RUNETOOL_PROGRAMS_H
#define RUNETOOL_PROGRAMS_H

#include "Rune.h"
#include <string>

void writeRunes(const std::string& file_name = "RuneDB.txt", bool multi = true);
void showRune(const std::vector<int>& id, const RuneType type = RuneType::none,
              const int num = -1, const int star = -1, const std::string& file_name = "RuneDB.txt");
void removeRune(const std::vector<int>& ids, const std::string& file_name = "RuneDB.txt");
void combination(const std::vector<RuneType>& sets, const std::map<OptType, int>& filter, const std::string& file_name = "RuneDB.txt");

#endif //RUNETOOL_PROGRAMS_H