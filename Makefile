	# les variables
CC = g++
CFLAG = -Wall -pg
DEBUG = -g

# optimisation
# utiliser make OPTIM='oui' pour optimisation
# ou make OPTIM='oui' -f makefile

ifeq ($(OPTIM),oui)
	MODEOPTIM = -O
else
	MODEOPTIM =
endif

# programme principal
main : main.cpp Arbre.h Arbre.o class.h class.o
	$(CC) -o main Arbre.o class.o main.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

# les librairies


Arbre.o : Arbre.h Arbre.cpp 
	$(CC) -c Arbre.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

class.o : class.h class.cpp 
	$(CC) -c class.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)


# nettoyage
clean :
	rm -f *.o

mrproper : clean
	rm -f main


  
