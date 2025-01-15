#include <gtest/gtest.h>
#include "FileTrailer.h"
#include <string>
#include "StringUtils.h"

TEST(FileTrailerTest, ValidLength) {
  CommonFormatFile::FileTrailer trailer{'A', "00000", "0000001", "0000001"};
  std::string result = trailer.getRow();
  EXPECT_EQ(result.size(), 194);
}

TEST(FileTrailerTest, ValidContent) {
  CommonFormatFile::FileTrailer trailer{'A', "00000", "0000001", "0000001"};
  std::string result = trailer.getRow();
  EXPECT_EQ(result, rpad("A90000000000010000001"));
}

TEST(FileTrailerTest, RecordsTooShort) {
  EXPECT_THROW(
               CommonFormatFile::FileTrailer('A', "00000", "000000", "0000001"),
               std::invalid_argument
               );
}

TEST(FileTrailerTest, RecordsToolONG) {
  EXPECT_THROW(CommonFormatFile::FileTrailer('A', "00000", "00000001", "0000001"),
               std::invalid_argument);
}
