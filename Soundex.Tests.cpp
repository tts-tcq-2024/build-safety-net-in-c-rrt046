#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 ASSERT_STREQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
 //AAA
  char soundex[5];
  generateSoundex("A", soundex);
  ASSERT_STREQ(soundex,"A000");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
 //AAA
  char soundex[5];
  generateSoundex("A@1b", soundex);
  //ASSERT_STREQ(soundex,"A000");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_4) {
 //AAA
  char soundex[5];
  generateSoundex("12121", soundex);
  //ASSERT_STREQ(soundex,"A000");
}

TEST(SoundexTestsuite, AddSoundexCodeFalseBranchCodeIsZero) {
    char soundex[5] = "A0";
    int sIndex = 1;
    addSoundexCode('0', soundex, &sIndex); 
    ASSERT_EQ(sIndex, 1);                  
    ASSERT_EQ(soundex[1], '0');            
}

TEST(SoundexTestsuite, AddSoundexCodeFalseBranchCodeIsSame) {
    char soundex[5] = "A2";
    int sIndex = 2;
    addSoundexCode('2', soundex, &sIndex); 
    ASSERT_EQ(sIndex, 2);                  
    ASSERT_EQ(soundex[1], '2');            
}
