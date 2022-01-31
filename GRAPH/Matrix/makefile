run: 2125_main.o 2125_adjMatrix.o 2125_stack.o 2125_queue.o
	gcc -o run 2125_main.o 2125_adjMatrix.o 2125_stack.o 2125_queue.o
2125_main.o: 2125_main.c 2125_adjMatrix.h
	gcc -c 2125_main.c
2125_adjMatrix.o: 2125_adjMatrix.c 2125_adjMatrix.h
	gcc -c 2125_adjMatrix.c 2125_stack.c 2125_queue.c
2125_stack.o: 2125_stack.c 2125_stack.h
	gcc -c 2125_stack.c
2125_queue.o: 2125_queue.c 2125_queue.h
	gcc -c 2125_queue.c