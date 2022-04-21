.PHONY: all test run clean 
.IGNORE: clean

export CFLAGS=-c -O0 -Wall
export BUILD=$(realpath build)
export INCLUDE_DIR=$(realpath include)
export SOURCE_DIR=$(realpath src)

LIB=lib/libskrivarn.so
EXEC=test

all: $(LIB)

test: tests/test.c
	gcc -I$(INCLUDE_DIR) $< -o $(EXEC) -Llib -lskrivarn
	./$(EXEC)
	

$(LIB): lib/lib%.so: src/%.c
	mkdir -p lib
	echo $< $@
	gcc -shared -fPIC -I$(INCLUDE_DIR) $< -o $@
	cp include/skrivarn.h lib/skrivarn.h

deploy:
	sudo cp lib/libskrivarn.so /usr/local/lib/rotbjorn
	sudo cp include/skrivarn.h /usr/local/include/rotbjorn

clean:
	rm $(EXEC)
	rm $(LIB)
	rm lib/skrivarn.h
