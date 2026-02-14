NAME = Identify
CC = c++
flages = -Wall -Wextra -Werror -std=c++98

src = main.cpp Fun.cpp Base.cpp 
obj = $(src:.cpp=.o)

all: $(NAME)

$(NAME): $(obj)
	$(CC) $(flages) $(obj) -o $(NAME)

%.o: %.cpp
	$(CC) $(flages) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(NAME)

re: fclean all
