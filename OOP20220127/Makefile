EXEC := rps
EXEC_FLAGS ?=
EXEC_ARGS ?=

SRC_DIR := sources
OBJ_DIR := obj

INCLUDE_DIRS = \
	$(SRC_DIR)/

CXX := g++
CXXSTD := c++17
CXXFLAGS := -std=$(CXXSTD) -Wall -Wextra -pedantic
CXXFLAGS += $(addprefix -I, $(INCLUDE_DIRS))
LDFLAGS ?=

SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp" -or -name "*.c")
SRC_FILES_WITHOUT_DIR := $(notdir $(SRC_FILES))
OBJ_FILES := $(addprefix ./$(OBJ_DIR)/,$(SRC_FILES_WITHOUT_DIR:.cpp=.o))

# Verbose flag
Q := @
ifeq ($(V),1)
Q :=
endif

.PHONY: build clean

$(EXEC): $(OBJ_FILES)
	$(Q) echo Linking program...
	$(Q) $(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^
	$(Q) echo Done

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(Q) echo Compiling $<...
	$(Q) mkdir -p $(dir $@)
	$(Q) $(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ -c $<

build:
	+$(Q) echo Build start...
	+$(Q) make 
	+$(Q) echo Done

run: $(EXEC)
	./$(EXEC) $(EXEC_FLAGS) $(EXEC_ARGS)

clean:
	+$(Q) $(RM) -rf ./$(OBJ_DIR) ./$(EXEC)

