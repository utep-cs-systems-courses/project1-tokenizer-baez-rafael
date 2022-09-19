# Compiler Flags -g Debug, -03 Optimize
CFLAGS=-g

all: myProgram

# File Dependencies
#tester.o: tokenizer.h

myProgram: uimain.o #tester.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o myProgram
