IDIR1 = src
IDIR2 = dep
ODIR = bin
CC = g++
FLAGS = -g -Wall -I $(IDIR1) -I $(IDIR2) -I $(ODIR)

heap.exe: $(ODIR)/main.o $(ODIR)/Pixel.o
	$(CC) $(FLAGS) $^ -o $(ODIR)/$@
$(ODIR)/main.o: $(IDIR1)/main.cpp $(IDIR2)/Heap.h
	$(CC) $(FLAGS) -c $< -o $@
$(ODIR)/Pixel.o: $(IDIR2)/Pixel.cpp
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -rf $(ODIR)/*.o $(ODIR)/heap.exe 
