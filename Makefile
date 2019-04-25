account.o:account.cpp account.h
	g++ -c $<

accountlib.o:accountlib.cpp accountlib.h account.h
	g++ -c $<

transaction.o:transaction.cpp transaction.h account.h accountlib.h
	g++ -c $<

tranlib.o:tranlib.cpp tranlib.h accountlib.h transaction.h
	g++ -c $<

AccountingSystem.o:AccountingSystem.cpp AccountingSystem.h
	g++ -c $<

run.o:run.cpp accountlib.h tranlib.h
	g++ -c $<

run:run.o account.o accountlib.o transaction.o tranlib.o AccountingSystem.o
	g++ $^ -o $@

clean:
	rm run *.o

clean_store:
	rm transaction account

.PHONY:clean clean_store
