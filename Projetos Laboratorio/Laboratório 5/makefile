CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o calculo_investimento.o gerenciamento_investimento.o
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c transacoes.h calculo_investimento.h gerenciamento_investimento.h
	$(CC) $(CFLAGS) -c main.c

calculo_investimento.o: calculo_investimento.c transacoes.h calculo_investimento.h
	$(CC) $(CFLAGS) -c calculo_investimento.c

gerenciamento_investimento.o: gerenciamento_investimento.c transacoes.h gerenciamento_investimento.h
	$(CC) $(CFLAGS) -c gerenciamento_investimento.c

clean:
	rm -f $(TARGET) $(OBJ)
