compile:
	g++ -o gltest.out main.cpp -lsfml-window -lsfml-system -lGLEW -lGL -std=c++11
#http://www.sfml-dev.org/tutorials/2.1/start-linux.php
#-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
#http://glew.sourceforge.net/install.html
#-lGLEW -lGLU -lGL

run:
	clear
	./gltest.out

compile_run: compile run

clean:
	rm *.out
