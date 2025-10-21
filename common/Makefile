OBJ:= obj/btr_fly.o obj/cpx_op.o obj/fft_prep_bit.o obj/fft_prep_cpx_fn.o

all: $(OBJ)

$(OBJ): obj/%.o : src/%.c
	gcc -c -I inc/ -o $@ $^

clean:
	rm $(OBJ)
