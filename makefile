BUILD_DIR := build

.PHONY: all install

all: test

bind:
	@cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
	@make -C build -j

test:
	@cp build/bindings/pytermui*.so pytermui/

	@if [ ! -d "venv" ]; then python3 -m venv venv; fi; \
	. venv/bin/activate; \
	pip install --upgrade pip; \
	pip install build; \
	python3 -m build; \
	python3 bind_test.py

clean:
	@rm -rf $(BUILD_DIR) .cache venv
