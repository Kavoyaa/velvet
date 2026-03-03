BUILD_DIR := build
GENERATOR := Ninja

.PHONY: configure build run clean rebuild

configure:
	cmake -S . -B $(BUILD_DIR) -G $(GENERATOR)

build:
	cmake --build $(BUILD_DIR)

run: build
	./$(BUILD_DIR)/velvet_app

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean configure build
