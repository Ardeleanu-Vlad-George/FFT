TARGET := fft

OBJECT := obj/fft_comp.o obj/io.o obj/main.o

PATH := ../../../common

EXTERNAL_OBJECT := $(PATH)/obj/btr_fly.o
EXTERNAL_OBJECT += $(PATH)/obj/cpx_op.o
EXTERNAL_OBJECT += $(PATH)/obj/fft_prep_bit.o
EXTERNAL_OBJECT += $(PATH)/obj/fft_prep_cpx.o
EXTERNAL_HEADER := $(PATH)/inc/

$(TARGET): $(OBJECT)
	g++ -o $@ $(EXTERNAL_OBJECT) $^ -lm -lsfml-graphics -lsfml-system 

$(OBJECT): obj/%.o: src/%.c
	g++ -std=c++98 -I inc/ -I $(EXTERNAL_HEADER) -c -o $@ $^

clean:
	rm $(OBJECT) $(TARGET)
