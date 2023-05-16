##
## EPITECH PROJECT, 2023
## BlueLock
## File description:
## Make
##

## PROJECT SOURCES ##
SRC_DIR 		:= src

SRC_MAIN 		:= main.c \
				   bluelock.c

SRC_HANDLERS 	:= handlers/args.c \
				   handlers/errors.c

SRC_UTILS   	:= utils/scan.c

SRC_DISPLAY		:= display/docs.c \
				   display/error.c

SRC				:= $(addprefix $(SRC_DIR)/, $(SRC_MAIN) $(SRC_HANDLERS) \
											$(SRC_DISPLAY) $(SRC_UTILS))

## PROJECT HEADERS ##
INC_DIR 		:= include

## PROJECT BUILD ##
BUILD_DIR 		:= build

## PROJECT OUTPUT ##
RELEASE_DIR 	:= ./
RELEASE_NAME 	:= bluelock

## PROJECT COMPILER ##
CC 				:= gcc

## PROJECT FLAGS ##
CFLAGS 			:= -Wall -Wextra -Wpedantic -I./$(INC_DIR)
RELEASE_FLAGS 	:= -O3 -lbluetooth

## PROJECT OBJECTS ##
RELEASE_OBJ 	:= $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

## PROJECT TESTS ##
TEST_DIR 		:= tests
TEST_FLAGS		:= --coverage -lcriterion $(CFLAGS)

SRC_TESTS		:= $(SRC_DIR)/handlers/args.c \
				   $(SRC_DIR)/handlers/errors.c \
				   $(TEST_DIR)/args.c \
				   $(TEST_DIR)/errors.c

## PROJECT RULES ##
all: 				release

release: 			$(RELEASE_NAME)
					@printf "\033[32m[OK]\033[0m Project built successfully\n"

$(RELEASE_NAME): 	CFLAGS += -O3
$(RELEASE_NAME): 	$(RELEASE_OBJ)
					@mkdir -p $(RELEASE_DIR)
					@printf "\033[32m[OK]\033[0m Linking project...\n"
					@$(CC) $(CFLAGS) $(RELEASE_FLAGS) \
					-o $(RELEASE_DIR)/$(RELEASE_NAME) $(RELEASE_OBJ)

## PROJECT OBJECTS RULES ##
$(BUILD_DIR)/%.o: 	%.c
					@mkdir -p $(dir $@)
					@printf "\033[32m[OK]\033[0m Building $<...\n"
					@$(CC) $(CFLAGS) -c $< -o $@

## PROJECT CLEAN RULES ##
clean:
					@printf "\033[32m[OK]\033[0m Cleaning project...\n"
					@rm -rf $(BUILD_DIR)

fclean: 			clean
					@printf "\033[32m[OK]\033[0m Removing project...\n"
					@rm -f $(RELEASE_NAME)

re: 				fclean all

unit_tests:
					@printf "\033[32m[OK]\033[0m Building unit tests...\n"
					@$(CC) $(CFLAGS) $(TEST_FLAGS) $(SRC_TESTS) -o unit_tests

run_tests:			unit_tests
					@printf "\033[32m[OK]\033[0m Running unit tests...\n"
					@./unit_tests

clean_tests:
					rm -f unit_tests

## PROJECT PHONY RULES ##
.PHONY: 			all clean fclean re
