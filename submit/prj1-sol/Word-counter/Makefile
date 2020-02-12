wordcounts:	wordcounts.o
		g++ -g -Wall -std=c++17 wordcounts.o -o wordcounts

wordcounts.o:	wordcounts.cpp
		g++ -g -Wall -std=c++17 -c wordcounts.cpp

clean:	
		rm -f *~ *.o wordcounts
