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

TEST(CentreHeaderTest, CentreIsSeriesUnderscore) {
  CommonFormatFile::CentreHeader header{'A', "A125_", "40", "AA", "25", "001", "CF24 3QX"};
  std::string result = header.getRow();
  EXPECT_EQ(result, rpad("A3A125_40AA25001CF24 3QX"));
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

TEST(CentreHeaderTest, AoHasAlpha) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "4A", "AA", "25",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, AoShortLength) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "0", "AA", "25",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, AoLongLength) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "4000", "AA", "25",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, ExamSeriesTooLong) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AAA", "25",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, ExamSeriesTooShort) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "A", "25",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, ExamSeriesInvalidChar) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "0A", "25",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, YearShortLength) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AA", "2",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, YearLongLength) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AA", "250",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, YearHasAlpha) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AA", "2a",
                                              "001", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, SequenceTooShort) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AA", "25",
                                              "01", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, SequenceTooLong) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AA", "25",
                                              "0010", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, SequenceHasAlpha) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AA", "25",
                                              "00A", "CF24 3QX"),
               std::invalid_argument);
}

TEST(CentreHeaderTest, PostCodeTooLong) {
  EXPECT_THROW(CommonFormatFile::CentreHeader('X', "00000", "40", "AA", "25",
                                              "001", "CF24 3QX   "),
               std::invalid_argument);
}
