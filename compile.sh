#!/usr/bin/env bash
echo "Brew Update";
#brew update;
echo "Done";

echo "brew install SDL2";
brew install sdl2;

#echo "mlx install";
#wget http://files.achedeuzot.me/42/mlx/mlx-macosx-sierra-2016-10-17.tgz;
#tar -xzf mlx-macosx-sierra-2016-10-17.tgz;
#cd minilibx_macos;
#make;
#sudo cp mlx.h /usr/X11/include;
#sudo cp libmlx.a /usr/X11/lib;

echo "make project"
make;