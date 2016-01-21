aprox: main.o splines.o points.o tryg.o
	$(CC) -o aprox  main.o splines.o points.o tryg.o -lm
tryg.o: makespl.h points.h
	$(CC) -c tryg.c
wykres1: aprox test/wykres1
	-./aprox -s spl -p test/wykres1 -g myplot -f 0.5 -t 5.5 -n 300 
	-gnuplot -e "plot 'test/wykres1','myplot';pause 5"
wykres3: aprox test/wykres3
	-./aprox -s spl -p test/wykres3 -g myplot -f 0.5 -t 5.5 -n 100 
	-gnuplot -e "plot 'test/wykres3','myplot';pause 5"
wykres2: aprox test/wykres2
	-./aprox -s spl -p test/wykres2 -g myplot -f 0.5 -t 5.5 -n 300 
	-gnuplot -e "plot 'test/wykres2','myplot';pause 5"
sin_x: aprox test/sin_x
	-./aprox -s spl -p test/sin_x -g myplot -f 0.5 -t 5.5 -n 300 
	-gnuplot -e "plot 'test/sin_x','myplot';pause 5"


oldaprox: main.o oldsplines.o points.o oldtryg.o
	$(CC) -o oldaprox  main.o oldsplines.o points.o oldtryg.o -lm
oldtryg.o: oldsplines.h points.h
	$(CC) -c oldtryg.c
oldwykres1: oldaprox test/wykres1
	-./oldaprox -s spl -p test/wykres1 -g myplot -f 0.5 -t 5.5 -n 300 
	-gnuplot -e "plot 'test/wykres1','myplot';pause 5"
oldwykres2: oldaprox test/wykres2
	-./oldaprox -s spl -p test/wykres2 -g myplot -f 0.5 -t 5.5 -n 300 
	-gnuplot -e "plot 'test/wykres2','myplot';pause 5"
oldsin_x: oldaprox test/sin_x
	-./oldaprox -s spl -p test/sin_x -g myplot -f 0.5 -t 5.5 -n 300 
	-gnuplot -e "plot 'test/sin_x','myplot';pause 5"
oldwykres3: oldaprox test/wykres3
	-./oldaprox -s spl -p test/wykres3 -g myplot -f 0.5 -t 5.5 -n 100 
	-gnuplot -e "plot 'test/wykres3','myplot';pause 5"

.PHONY: clean

clean:
	-rm *.o spl aprox oldaprox myplot 

