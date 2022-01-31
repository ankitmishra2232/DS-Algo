run: hospital.o priorityq.o
	gcc -o run hospital.o priorityq.o
hospital.o: hospital.c priorityq.h
	gcc -c hospital.c
priorityq.o: priorityq.c priorityq.h
	gcc -c priorityq.c