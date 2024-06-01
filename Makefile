
CC = gcc
FLAG = -g

NAME_FILE = calculator
LIBRARY = -lcalc

CR_DIR = create_$(NAME_FILE)
OBJ_DIR = object_$(NAME_FILE)


SRC = $(wildcard ./$(CR_DIR)/*.c)
OBJ = $(patsubst ./$(CR_DIR)/%.c, ./$(OBJ_DIR)/%.o, $(SRC))

$(NAME_FILE) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME_FILE) -L . $(LIBRARY)

./$(OBJ_DIR)/%.o : ./$(CR_DIR)/%.c
	$(CC) $(FLAG) -c $< -o $@

clean: 
	rm $(NAME_FILE) ./$(OBJ_DIR)/*.o