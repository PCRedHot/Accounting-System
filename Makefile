account.o:account.cpp account.h
	g++ -c $<

accountlib.o:accountlib.cpp accountlib.h
	g++ -c $<

transaction.o:transaction.cpp transaction.h
	g++ -c $<

tranlib.o:tranlib.cpp tranlib.h
	g++ -c $<

run.o:run.cpp accountlib.h tranlib.h
	g++ -c $<

run:run.o accout.o accountlib.o transaction.o tranlib.o
	g++ $^ -o $@

clean:
	rm run *.o

.PHONY:clean
