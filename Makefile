CXX = g++
CXXFLAGS = -g -Wall -std=c++2a

OBJ_DIR = obj
SRC_DIR = src

HDRS = $(wildcard src/*.h)
SRCS = $(wildcard src/*.cc)
OBJS = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRCS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(HDRS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

sudoku: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $?

clean:
	rm -r obj/ sudoku
