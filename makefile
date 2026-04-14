# used for local build and debugging only

.PHONY: all 

all: test

test: 
	cmake -Bbuild -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
	make -C build -j
