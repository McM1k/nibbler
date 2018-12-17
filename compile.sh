#!/usr/bin/env bash
echo "Brew Update";
#brew update;
echo "Done";

echo "brew install SDL2";
brew install sdl2;

echo "make project"
make;