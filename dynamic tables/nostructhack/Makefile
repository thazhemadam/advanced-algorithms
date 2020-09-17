dyntable_no_structhack: dyntable_impl.o dyntable_client.o
	gcc dyntable_impl.o dyntable_client.o -lm -o dyntable_no_structhack

dyntable_impl.o: dyntable_impl.c dyntable_impl.h
	gcc -c dyntable_impl.c -o dyntable_impl.o

dyntable_client.o: dyntable_client.c dyntable_impl.h
	gcc -c dyntable_client.c -lm -o dyntable_client.o

clean:
	rm *.o dyntable_no_structhack