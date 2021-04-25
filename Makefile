#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x
LIBS = -lpthread

__start__: obroty_2D
	./obroty_2D prostokat.dat

obroty_2D: obj obj/main.o obj/Prostokat.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/gnuplot.o
	g++ -Wall -pedantic -std=c++0x -o obroty_2D obj/main.o obj/Wektor2D.o\
                        obj/Macierz2x2.o obj/Prostokat.o obj/gnuplot.o ${LIBS}

obj:
	mkdir obj

obj/gnuplot.o: inc/gnuplot.hpp src/gnuplot.cpp
	g++ -c ${CXXFLAGS} -o obj/gnuplot.o src/gnuplot.cpp

obj/main.o: src/main.cpp inc/Prostokat.hpp inc/Macierz2x2.hpp inc/Wektor2D.hpp inc/gnuplot.hpp
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostokat.o: src/Prostokat.cpp inc/Prostokat.hpp
	g++ -c ${CXXFLAGS} -o obj/Prostokat.o src/Prostokat.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hpp
	g++ -c ${CXXFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hpp
	g++ -c ${CXXFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp

clean:
	rm -f obj/*.o obroty_2D