#Objects
OBJS = uimain.o tokenizer.o

# Compiler Flags -g Debug, -03 Optimize
CFLAGS=-g

all: myProgram

myProgram: $(OBJS)
	cc -o $@ $(CFLAGS) $(OBJS)

# File Dependencies
$(OBJS): tokenizer.h

clean:
	rm -f *.o myProgram
