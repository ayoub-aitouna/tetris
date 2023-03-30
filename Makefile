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
LIB		:= -I/Users/aaitouna/homebrew/opt/sdl2/include -L/Users/aaitouna/homebrew/opt/sdl2/lib -lSDL2 -pthread -lm
CFLAGS	:=  -Wall -Werror -Wextra 
# Targets
all: ${NAME}

${NAME} : $(OBJ_FILES)
	$(CC) ${LIB}  $(CFLAGS) $^ $(THIRD_PARTHY_FILES) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) ${LIB}  -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o

fclean: clean
	rm -rf ${NAME}
re: fclean ${NAME}