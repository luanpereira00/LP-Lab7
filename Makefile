# Makefile, separando os diferentes elementos da aplicacao
# como codigo (src), cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento e alocado em uma pasta especifica, organizando melhor seu codigo fonte.
#
# Algumas variaveis sao usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC=g++ 

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
DAT_DIR=./data
TEST_DIR=./test

# Opcoes de compilacao
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all init clean doxy debug doc 

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: init q1 q2 q3 q4 q5 q6
debug: CFLAGS += -g -O0
debug: init q1 q2 q3 q4 q5 q6

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/

# Alvo (target) para a construcao do executavel
# Define o arquivo q1.o como dependencia
q1: $(OBJ_DIR)/q1.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'q1' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto q1.o
# Define os arquivos q1.cpp e templateSTL.h como dependencias.
$(OBJ_DIR)/q1.o: $(SRC_DIR)/q1.cpp $(INC_DIR)/templateSTL.h 
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do executavel
# Define o arquivo q2.o como dependencia
q2: $(OBJ_DIR)/q2.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'q2' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto q2.o
# Define os arquivos q2.cpp e templateSTL.h como dependencias.
$(OBJ_DIR)/q2.o: $(SRC_DIR)/q2.cpp $(INC_DIR)/templateSTL.h 
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do executavel
# Define o arquivo q3.o como dependencia
q3: $(OBJ_DIR)/q3.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'q3' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto q3.o
# Define os arquivos q3.cpp e templateSTL.h como dependencias.
$(OBJ_DIR)/q3.o: $(SRC_DIR)/q3.cpp $(INC_DIR)/templateSTL.h 
	$(CC) -c $(CFLAGS) -o $@ $<		

# Alvo (target) para a construcao do executavel
# Define o arquivo q4.o como dependencia
q4: $(OBJ_DIR)/q4.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'q4' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto q4.o
# Define os arquivos q3.cpp e templateSTL.h como dependencias.
$(OBJ_DIR)/q4.o: $(SRC_DIR)/q4.cpp $(INC_DIR)/templateSTL.h 
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do executavel
# Define o arquivo q5.o como dependencia
q5: $(OBJ_DIR)/q5.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'q5' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto q4.o
# Define os arquivos q3.cpp e templateSTL.h como dependencias.
$(OBJ_DIR)/q5.o: $(SRC_DIR)/q5.cpp 
	$(CC) -c $(CFLAGS) -o $@ $<		

# Alvo (target) para a construcao do executavel
# Define o arquivo q6.o como dependencia
q6: $(OBJ_DIR)/q6.o $(OBJ_DIR)/poupanca.o $(OBJ_DIR)/cc.o $(OBJ_DIR)/data.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'q6' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto q6.o
# Define os arquivos q6.cpp, conta.h, cc.h, poupanca.h e data.h como dependencias.
$(OBJ_DIR)/q6.o: $(SRC_DIR)/q6.cpp $(INC_DIR)/conta.h $(INC_DIR)/cc.h $(INC_DIR)/data.h $(INC_DIR)/poupanca.h 
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto q6.o
# Define os arquivos poupanca.cpp e poupanca.h como dependencias.
$(OBJ_DIR)/poupanca.o: $(SRC_DIR)/poupanca.cpp $(INC_DIR)/poupanca.h $(INC_DIR)/conta.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto q6.o
# Define os arquivos cc.cpp e cc.h como dependencias.
$(OBJ_DIR)/cc.o: $(SRC_DIR)/cc.cpp $(INC_DIR)/cc.h $(INC_DIR)/conta.h
	$(CC) -c $(CFLAGS) -o $@ $<		 

# Alvo (target) para a construcao do objeto q6.o
# Define os arquivos data.cpp e data.h como dependencias.
$(OBJ_DIR)/data.o: $(SRC_DIR)/data.cpp $(INC_DIR)/data.h
	$(CC) -c $(CFLAGS) -o $@ $<		

			
# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*	
	$(RM) $(DOC_DIR)/*	