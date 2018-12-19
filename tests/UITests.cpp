#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../project/includes/UI.hpp"

TEST_CASE("GameState is as intended with Menu") {
    UI ui;

    ui.setGameState(eGameState::Menu);

    std::stringstream stringStream;

    stringStream << ui;

    std::string str = stringStream.str();

    REQUIRE(str.find("Menu"));
}

TEST_CASE("GameState is as intended with Game") {
    UI ui;

    ui.setGameState(eGameState::Game);

    std::stringstream stringStream;

    stringStream << ui;

    std::string str = stringStream.str();

    REQUIRE(str.find("Game"));
}

TEST_CASE("GameState is as intended with Pause") {
    UI ui;

    ui.setGameState(eGameState::Pause);

    std::stringstream stringStream;

    stringStream << ui;

    std::string str = stringStream.str();

    REQUIRE(str.find("Pause"));
}

TEST_CASE("GameState is as intended with GameOver") {
    UI ui;

    ui.setGameState(eGameState::GameOver);

    std::stringstream stringStream;

    stringStream << ui;

    std::string str = stringStream.str();

    REQUIRE(str.find("GameOver"));
}

TEST_CASE("Score is added with correct value") {
    UI ui;

    ui.setScore(0);
    ui.addScore(1);

    REQUIRE(ui.getScore() == 1);
}

TEST_CASE("Score is not added with wrong value") {
    UI ui;

    ui.setScore(0);

    REQUIRE_THROWS_AS(ui.addScore(-1), UI::WrongScoreException);
}

TEST_CASE("Score is not set with wrong value") {
    UI ui;

    REQUIRE_THROWS_AS(ui.setScore(-1), UI::WrongScoreException);
}