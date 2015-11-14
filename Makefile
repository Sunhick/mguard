#
# Makefile for efence
# Author : sunil bn
#

# ================ Compilers and linkers ============= #
CC = g++
LD = g++ #ld

# ================ CC and LD flags =================== #
IDIR = ./src/
CPP_STD_FLAG = -std=c++11
DEBUG = -g
OPTIMIZATION = -O0
CCFLAGS = $(CPP_STD_FLAG) $(DEBUG) $(OPTIMIZATION) -Wall -I $(IDIR)
LDFLAGS = #-llibstd++

# ================ libraries ========================= #
LIB_LOGGER = liblogger.a
LIB_LOGGER_SRC = src/logger.cc
LIB_LOGGER_OBJS = $(LIB_LOGGER_SRC:.cc=.o)

# ================ Static libraries ================== #
STATLIBS = $(LIB_LOGGER)

# ================ Sources =========================== #
EFENCE_SRC = src/mguard.cc src/logger.cc
EFENCE_OBJS = $(EFENCE_SRC:.cc=.o)

# ================ Test sources ====================== #
TEST_SRC = src/test.cc
TEST_OBJS = $(TEST_SRC:.cc=.o)
TEST_EXE = test

# ================ Target recipies =================== #

all: $(TEST_EXE)

$(TEST_EXE): $(EFENCE_OBJS) $(TEST_OBJS)
	$(LD) $(LDFLAGS) $(EFENCE_OBJS) $(TEST_OBJS) -o $(TEST_EXE)

$(LIB_LOGGER): $(LIB_LOGGER_OBJS)
	ar ru $@ $^
	ranlib $@

%.o: %.cc
	$(CC) -c -o $@ $(CCFLAGS) $<

# ================= Clean targets ===================== #
.PHONY: clean
clean:
	@rm ./src/*.o ./src/*~ $(TEST_EXE) $(STATLIBS) *~
