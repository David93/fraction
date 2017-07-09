all: fraction.cpp
	g++ -o fraction fraction.cpp

clean:
	rm -f fraction