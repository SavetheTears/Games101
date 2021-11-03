CPPFLAGS = -std=c++11
all: a.exe

a.exe: pa.o
	g++ -o $@ $(CPPFLAGS) main.o


pa.o: pa.cpp
	g++ $(CPPFLAGS) -I "F:\graphics\101\eigen-3.4.0" -c $< -o $@ 

clean:
	del *.o, *.exe