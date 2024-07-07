#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 ASSERT_STREQ(soundex,"A200");
}

TEST(SoundexTestsuite, InitialCharacterAndPadding) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, IgnoreVowelsAndNonMappedCharacters) {
    char soundex[5];
    generateSoundex("AEIOU", soundex);
    ASSERT_STREQ(soundex, "A000");
}

