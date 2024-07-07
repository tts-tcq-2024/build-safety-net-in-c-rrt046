#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
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

TEST(SoundexTestsuite, ConsecutiveSameSoundexCodes) {
    char soundex[5];
    generateSoundex("Add", soundex);
    ASSERT_STREQ(soundex, "A300");
}

TEST(SoundexTestsuite, EarlyLoopTermination) {
    char soundex[5];
    generateSoundex("Abcdefghijklmnopqrstuvwxyz", soundex);
    ASSERT_STREQ(soundex, "A123");
}

TEST(SoundexTestsuite, NameWithNonAlphaCharacters) {
    char soundex[5];
    generateSoundex("AB'D", soundex);
    ASSERT_STREQ(soundex, "A130");
}

TEST(SoundexTestsuite, AlphabetsAndNumbers) {
    char soundex[5];
    generateSoundex("Ab234", soundex);
    ASSERT_STREQ(soundex, "A100");
}
