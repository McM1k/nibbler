#!/usr/bin/env bash
#echo "Brew Update";
#brew update;
#echo "Done";

#echo "brew install SDL2";
#brew install sdl2;

echo "download openGLUT"
curl -L "https://sourceforge.net/projects/openglut/files/development/OpenGLUT-0.6.3/OpenGLUT-win32-i386-0.6.3.zip" > glut.zip
echo "unzip openGLUT"
tar -vxf glut.zip -C openGL_library/includes/
rm glut.zip

#echo "mlx install";
#wget http://files.achedeuzot.me/42/mlx/mlx-macosx-sierra-2016-10-17.tgz;
#tar -xzf mlx-macosx-sierra-2016-10-17.tgz;
#cd minilibx_macos;
#make;
#sudo cp mlx.h /usr/X11/include;
#sudo cp libmlx.a /usr/X11/lib;

echo "make project"
make;