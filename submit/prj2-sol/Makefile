all:		nums seq-test

nums:		nums.o
		g++ -g -Wall -std=c++17 nums.o -o nums

nums.o:		nums.cpp seq.hh dlinkseq.hh arrayseq.hh
		g++ -g -Wall -std=c++17 -c nums.cpp seq.hh dlinkseq.hh arrayseq.hh

seq-test:	seq-test.o command.o
		g++ -g -Wall -std=c++17 seq-test.o command.o -o seq-test

command.o:	command.cpp command.hh
seq-test.o:	seq-test.cpp seq.hh dlinkseq.hh arrayseq.hh command.hh

clean:	
		rm -f *~ *.o *.gch nums seq-test
