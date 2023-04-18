# Directories
SRC_DIR := main
OBJ_DIR := objects
THIRD_PARTHY_DIR := third-parthy
NAME := Tetris
# Files
SRC_FILES :=  $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
THIRD_PARTHY_FILES := $(wildcard $(THIRD_PARTHY_DIR)/*.c)

# Compiler and flags
CC		:= gcc
LIB		:= `sdl2-config --cflags --libs` -lSDL2 -pthread -lm
CFLAGS	:=  -Wall -Werror -Wextra 

# Targets
all: ${NAME}

${NAME} : $(OBJ_FILES)
	$(CC)  $(CFLAGS) $^ $(THIRD_PARTHY_FILES) -o $@  ${LIB}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) ${LIB}  -c $< -o $@

clean:
	rm -rf ${OBJ_FILES}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}
