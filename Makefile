aprox: main.o splines.o points.o tryg.o
	$(CC) -o aprox  main.o splines.o points.o tryg.o -lm

tryg.o: makespl.h points.h
	$(CC) -c tryg.c


.PHONY: clean

clean:
	-rm *.o spl myplot aprox 
