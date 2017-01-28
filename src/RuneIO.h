//
// Created by Kelvin on 27/01/2017.
//

#ifndef RUNETOOL_RUNEIO_H
#define RUNETOOL_RUNEIO_H

#include "Rune.h"
#include <vector>
#include <fstream>
#include <sstream>

std::vector<Rune> ReadRune(const std::string& file_name = "RuneDB.txt");
void WriteRune(const std::vector<Rune>& runes, std::ostream& file_name);
void WriteOneRuneToFile(const Rune& rune, const std::string& file_name);

#endif //RUNETOOL_RUNEIO_H
