#Objects
OBJS = uimain.o tokenizer.o

# Compiler Flags -g Debug, -03 Optimize
CFLAGS=-g

# Main target
all: myProgram

# target dependencies
myProgram: $(OBJS)
	cc -o $@ $(CFLAGS) $(OBJS)

# File Dependencies
$(OBJS): tokenizer.h

# Clean directory
clean:
	rm -f *.o myProgram
