# SALIDA
TARGET=libtelegram.so

# DIRECTORIOS
SRCDIR=src
INCDIR=inc
OBJDIR=obj


#ARCHIVOS
SRCS:=$(wildcard $(SRCDIR)/*.c)
OBJS:=$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


# COMPILACION1
CC=gcc
CFLAGS=-Wall -fpic -shared
#=-O2 -Wall -Wextra -std=c99
CFLAGS+=-I./$(INCDIR)

# LINKER
LINKER   = gcc
#LFLAGS   = -Wall -I. -lm
LFLAGS = -fPIC -shared -pedantic -Wall -Wextra -ggdb3
POSTLFLAGS= -lcurl


all:$(TARGET)

$(TARGET):$(OBJS)
	$(LINKER)  $(LFLAGS) $(OBJS) -o $@ $(POSTLFLAGS)
	cp $(TARGET) ../lib/
	@echo "Versión: ${MAJORV}.${MINORV}.${PATCHV}b${BUILDV}"

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
	@rm -rf $(OBJDIR)/*.o
	@echo "Clean done!!"
