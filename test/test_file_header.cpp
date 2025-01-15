#include <gtest/gtest.h>
#include <string>
#include "FileHeader.h"
#include "StringUtils.h"

TEST(FileHeaderTest, ValidLength) {
  CommonFormatFile::FileHeader header {'A', "00000", "40", "AA", "25", 'S'};
  std::string result = header.getRow();
  EXPECT_EQ(result.size(), 194);
}

TEST(FileHeaderTest, ValidContent) {
  CommonFormatFile::FileHeader header {'A', "00000", "40", "AA", "25", 'S'};
  std::string result = header.getRow();
  EXPECT_EQ(result, rpad("A10000040AA25SQTCXX  0114"));
}
