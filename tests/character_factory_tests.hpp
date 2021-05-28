#ifndef __CHARACTER_FACTORY_TESTS_HPP
#define __CHARACTER_FACTORY_TESTS_HPP


#include "gtest/gtest.h"

#include "../header/CharacterFactory.hpp"

TEST(Generate_Enemy_Tests, Generate_Race1_Stat1){
	CharacterFactory* fact=new CharacterFactory();
	Character* test = fact->getEnemy(0);
	EXPECT_EQ(test->getDamage(),20);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Stat2){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0);
	EXPECT_EQ(test->getProtection(),10);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Stat3){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0);
        EXPECT_EQ(test->getMaxHP(), 100);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Stat4){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0);
        EXPECT_EQ(test->getCurHP(), 100);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Stat5){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0);
        EXPECT_EQ(test->getExperience(), 10);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Stat1){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1);
        EXPECT_EQ(test->getDamage(),22);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Stat2){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1);
        EXPECT_EQ(test->getProtection(),15);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Stat3){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1);
        EXPECT_EQ(test->getMaxHP(), 80);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Stat4){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1);
        EXPECT_EQ(test->getCurHP(), 80);;
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Stat5){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1);
        EXPECT_EQ(test->getExperience(), 10);;
        delete test;
        delete fact;}



#endif
