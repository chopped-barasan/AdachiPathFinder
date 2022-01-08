TARGET := program

OUTPUT_DIR := ./build
SOURCE_DIR := ./src
TEMP_DIR := ./temp
DEFINES := __DEBUG__ __CLEAR_MAP__

INC_DIRS := $(shell find $(SOURCE_DIR) -type d)
SRCS := $(wildcard $(SOURCE_DIR)/*.cpp $(SOURCE_DIR)/*.c)
FILES := $(notdir $(SRCS))
OBJS := $(FILES:%=$(TEMP_DIR)/%.o)
DEPS := $(FILES:%=$(TEMP_DIR)/%.d)

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= -Wall -MMD -MP $(INC_FLAGS) $(addprefix -D,$(DEFINES))

.PHONY: all
all: $(OUTPUT_DIR)/$(TARGET)

.PHONY: clean
clean:
	rm -f $(TEMP_DIR)/*.o
	rm -f $(TEMP_DIR)/*.d

$(OUTPUT_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ 

$(TEMP_DIR)/%.cpp.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(TEMP_DIR)/%.c.o: $(SOURCE_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEPS)