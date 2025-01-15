#include <gtest/gtest.h>
#include "CentreHeader.h"
#include "StringUtils.h"

TEST(CentreHeaderTest, ValidLength) {
  CommonFormatFile::CentreHeader header {'A', "00000", "40", "AA", "25", "001", "CF24 3QX"};
  std::string result = header.getRow();
  EXPECT_EQ(result.size(), 194);
}

TEST(CentreHeaderTest, ValidContent) {
  CommonFormatFile::CentreHeader header{'A', "00000", "40", "AA", "25", "001", "CF24 3QX"};
  std::string result = header.getRow();
  EXPECT_EQ(result, rpad("A30000040AA25001CF24 3QX"));
}

TEST(CentreHeaderTest, CentreIsSeries) {
  CommonFormatFile::CentreHeader header{'A', "A125B", "40", "AA", "25", "001", "CF24 3QX"};
  std::string result = header.getRow();
  EXPECT_EQ(result, rpad("A3A125B40AA25001CF24 3QX"));
}

TEST(CentreHeaderTest, CentreIsSeriesInvalid) {
  EXPECT_THROW(
               CommonFormatFile::CentreHeader('A', "1A25X", "40", "AA", "25", "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, DataTypeNotAE) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AA", "25",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}
