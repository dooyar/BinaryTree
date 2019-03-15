OBJ=main.o tree.o
CFLAGS+=-Wall -g -c
cc=g++
exe=run_tree
$(exe):$(OBJ)
	$(cc) $^ -o $@
%.o:%.c
	$(cc) $^ $(CFLAGS) -o $@

clean: 
	rm -rf *.o 
cle:
	rm -f $(exe)
