compile:
	g++ -o test.out test.cpp -lsfml-window -lsfml-system -lGLEW
#http://www.sfml-dev.org/tutorials/2.1/start-linux.php
#-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
#http://glew.sourceforge.net/install.html
#-lGLEW -lGLU -lGL

run:
	clear
	./test.out

clean:
	rm *.out