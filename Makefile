LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX:=g++

all:Test

%.o:%.cpp
	$(CXX) -c $< -o $@ -I /home/maxim/SFML/SFML-2.5.1/include

Test:*.o
	$(CXX) -o Test *.o $(LIBS) -L /home/maxim/SFML/SFML-2.5.1/lib
clean:
	@echo "Removing object files and executable..."
	rm -f Test
	rm -f *.o
install:
	@echo 'Installing...'
#	cp thegame /usr/bin
uninstall:
	@echo '** Uninstalling...'
#	rm Test
