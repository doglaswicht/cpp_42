
NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Contact.cpp phonebook.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Contact.hpp phonebook.hpp


all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o :%-cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all