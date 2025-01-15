#pragma once
#include <string>

/**
Righ pads string& 193 spaces by default with ' '
Defaults can be set
 */
inline std::string rpad(const std::string& input, size_t length = 193, char padChar = ' ') {
  if (input.size() >= length) return input;
  return input + std::string(length - input.size(), padChar) + '\n';
}
