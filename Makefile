CXX		=	clang++

NAME	=	libobjectnn.so

SRC		=	src/Network.cpp

OBJ 	=	$(SRC:.cpp=.o)

CXXFLAGS=	-c -fpic

LDFLAGS	=	-lfann

$(NAME):	$(OBJ)
	$(CXX) -shared $(OBJ) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

clean:
	rm -f	$(OBJ)

fclean:		clean
	rm -f	$(NAME)

re:			fclean all
