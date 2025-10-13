TARGET := fft

OBJECT := obj/fft_comp.o obj/io.o obj/main.o obj/fft_post_comp.o

COMMON := ../../../common
# choosing 'PATH' for this variable that was bad
# for 'PATH' is a system variable

EXTERNAL_OBJECT := $(COMMON)/obj/btr_fly.o
EXTERNAL_OBJECT += $(COMMON)/obj/cpx_op.o
EXTERNAL_OBJECT += $(COMMON)/obj/fft_prep_bit.o
EXTERNAL_OBJECT += $(COMMON)/obj/fft_prep_cpx.o

EXTERNAL_HEADER := $(COMMON)/inc/

$(TARGET):$(OBJECT) 
	g++ -o $@ $(EXTERNAL_OBJECT) $^ -lm -lsfml-graphics -lsfml-system 

$(OBJECT):obj/%.o:src/%.cpp 
	g++ -std=c++98 -I inc/ -I $(EXTERNAL_HEADER) -c -o $@ $^

clean:
	rm $(OBJECT) $(TARGET)
