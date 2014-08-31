all():
	clear
	g++ *.h *.cpp -lncurses -Wsign-compare -std=c++0x -lGL -lGLU -lglut
	clear
	./a.out