TARGET := fft

OBJECT := obj/fft_comp.o obj/io.o obj/main.o

EXTERNAL_OBJECT := ../../common/obj/btr_fly.o
EXTERNAL_OBJECT += ../../common/obj/cpx_op.o
EXTERNAL_OBJECT += ../../common/obj/fft_prep_bit.o
EXTERNAL_OBJECT += ../../common/obj/fft_prep_cpx.o
EXTERNAL_HEADER := ../../common/inc/

$(TARGET): $(OBJECT)
	gcc -o $@ $(EXTERNAL_OBJECT) $^ -lm

$(OBJECT): obj/%.o: src/%.c
	gcc -std=c99 -I inc/ -I $(EXTERNAL_HEADER) -c -o $@ $^

clean:
	rm $(OBJECT) $(TARGET)
