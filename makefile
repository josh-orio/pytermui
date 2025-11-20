BUILD_DIR := build

.PHONY: all install

all: test

bind:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && \
	cmake -DCMAKE_BUILD_TYPE=Debug \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
	-DBUILD_EXAMPLES=OFF \
	-DPYBIND=ON .. && \
	$(MAKE) -j

test:
	python3 bind_test.py

install:
	@echo "not implemented!"

clean:
	@rm -rf $(BUILD_DIR) .cache
