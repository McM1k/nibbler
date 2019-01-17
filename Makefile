# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 20:06:05 by gboudrie          #+#    #+#              #
#    Updated: 2019/01/17 20:35:33 by gboudrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ansi chars
LOG = 	\033[2K
BLUE = 	\033[1;34m
YELLOW =\033[1;33m
GREEN =	\033[1;32m
RED =	\033[1;31m
CLEAR =	\033[0m
BOLD =	\033[1m
UNDERL =\033[4m
SHI =	\xF0\x9F\x9B\xA1
TRA =	\xF0\x9F\x97\x91
LIG =	\xE2\x9A\xA1
BR_V =	\xe2\x95\x91
BR_H =	\xe2\x95\x90
CR_UR =	\xe2\x95\x97
CR_UL =	\xe2\x95\x94
CR_DR =	\xe2\x95\x9d
CR_DL =	\xe2\x95\x9a

# comp
CC =		clang++
CFLAGS =	-Wall -Wextra -Werror -std=c++11
SFLAGS =    -shared -fPIC -undefined dynamic_lookup

# binaries
EXE =       nibbler
LIB1 =      libncurses.so
LIB2 =
LIB3 =

# dir
SRC_DIR =       sources
INC_DIR =       includes
OBJ_DIR =       obj
PROJ_DIR =      project
LIB1_DIR =      ncurses_library
LIB2_DIR =
LIB3_DIR =
LIBS_DIR =      libs

# libs

# sources
PROJ_SRC_LIST = main.cpp \
                Map.cpp \
                UI.cpp \
                Bloc.cpp \
                LibLoader.cpp \
                GameManager.cpp \
                ObstaclesFactory.cpp

LIB1_SRC_LIST = Display.cpp \
                Inputs.cpp

LIB2_SRC_LIST =
LIB3_SRC_LIST =

# objects
PROJ_OBJ_LIST = $(PROJ_SRC_LIST:.cpp=.o)
LIB1_OBJ_LIST = $(LIB1_SRC_LIST:.cpp=.o)
LIB2_OBJ_LIST = $(LIB2_SRC_LIST:.cpp=.o)
LIB3_OBJ_LIST = $(LIB3_SRC_LIST:.cpp=.o)

#paths
PROJ_SRC =	$(addprefix $(PROJ_DIR)/$(SRC_DIR)/, $(PROJ_SRC_LIST))
PROJ_OBJ =	$(addprefix $(PROJ_DIR)/$(OBJ_DIR)/, $(PROJ_OBJ_LIST))
LIB1_SRC =	$(addprefix $(LIB1_DIR)/$(SRC_DIR)/, $(LIB1_SRC_LIST))
LIB1_OBJ =	$(addprefix $(LIB1_DIR)/$(OBJ_DIR)/, $(LIB1_OBJ_LIST))
LIB2_SRC =	$(addprefix $(LIB2_DIR)/$(SRC_DIR)/, $(LIB2_SRC_LIST))
LIB2_OBJ =	$(addprefix $(LIB2_DIR)/$(OBJ_DIR)/, $(LIB2_OBJ_LIST))
LIB3_SRC =	$(addprefix $(LIB3_DIR)/$(SRC_DIR)/, $(LIB3_SRC_LIST))
LIB3_OBJ =	$(addprefix $(LIB3_DIR)/$(OBJ_DIR)/, $(LIB3_OBJ_LIST))

################################################################################

all :		    $(EXE)

$(EXE) :                    $(LIB1) $(PROJ_SRC) $(PROJ_OBJ)
	                        @$(CC) $(PROJ_OBJ) -o $@
	                        @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$(EXE) "$(CLEAR)$(LIG)"

$(PROJ_DIR)/$(OBJ_DIR)/%.o: $(PROJ_DIR)/$(SRC_DIR)/%.cpp
	                        @mkdir -p $(PROJ_DIR)/$(OBJ_DIR) 2> /dev/null || true
	                        @$(CC) $(CFLAGS) -o $@ -c $<
	                        @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$< "$(CLEAR)$(LIG)"


$(LIB1) :                   $(LIB1_SRC) $(LIB1_OBJ)
	                        @mkdir -p $(LIBS_DIR) 2> /dev/null || true
	                        @$(CC) $(SFLAGS) $(LIB1_OBJ) -o $(LIBS_DIR)/$@ -lncurses
	                        @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$(LIB1) "$(CLEAR)$(LIG)"

$(LIB1_DIR)/$(OBJ_DIR)/%.o: $(LIB1_DIR)/$(SRC_DIR)/%.cpp
	                        @mkdir -p $(LIB1_DIR)/$(OBJ_DIR) 2> /dev/null || true
	                        @$(CC) $(CFLAGS) -o $@ -c $<
	                        @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$< "$(CLEAR)$(LIG)"


$(LIB2) :                   $(LIB2_SRC) $(LIB2_OBJ)
	                        @mkdir -p $(LIBS_DIR) 2> /dev/null || true
	                        @$(CC) $(SFLAGS) $(LIB2_OBJ) -o $(LIBS_DIR)/$@
	                        @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$(LIB2) "$(CLEAR)$(LIG)"

$(LIB2_DIR)/$(OBJ_DIR)/%.o: $(LIB2_DIR)/$(SRC_DIR)/%.cpp
	                        @mkdir -p $(LIB2_DIR)/$(OBJ_DIR) 2> /dev/null || true
	                        @$(CC) $(CFLAGS) -o $@ -c $<
	                        @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$< "$(CLEAR)$(LIG)"


$(LIB3) :                   $(LIB3_SRC) $(LIB3_OBJ)
	                        @mkdir -p $(LIBS_DIR) 2> /dev/null || true
	                        @$(CC) $(SFLAGS) $(LIB3_OBJ) -o $(LIBS_DIR)/$@
	                        @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$(LIB3) "$(CLEAR)$(LIG)"

$(LIB3_DIR)/$(OBJ_DIR)/%.o: $(LIB3_DIR)/$(SRC_DIR)/%.cpp
	                        @mkdir -p $(LIB3_DIR)/$(OBJ_DIR) 2> /dev/null || true
	                        @$(CC) $(CFLAGS) -o $@ -c $<
	                        @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$< "$(CLEAR)$(LIG)"

meteo :
	            @curl http://wttr.in/Paris
	            @curl http://wttr.in/Moon

clean :
	            @echo "$(CLEAR)$(TRA)$(RED)  Cleaning Object $(CLEAR)$(TRA)"
	            @$(RM) $(PROJ_OBJ)
	            @$(RM) $(LIB1_OBJ)
	            @$(RM) $(LIB2_OBJ)
	            @$(RM) $(LIB3_OBJ)
	            @rmdir $(PROJ_DIR)/$(OBJ_DIR) 2> /dev/null || true
	            @rmdir $(LIB1_DIR)/$(OBJ_DIR) 2> /dev/null || true
	            @rmdir $(LIB2_DIR)/$(OBJ_DIR) 2> /dev/null || true
	            @rmdir $(LIB3_DIR)/$(OBJ_DIR) 2> /dev/null || true

fclean :	    clean
	            @echo "$(CLEAR)$(TRA)$(RED)  Removing Binary $(CLEAR)$(TRA)"
	            @$(RM) $(LIBS_DIR)/$(LIB1)
	            #@$(RM) $(LIBS_DIR)/$(LIB2)
	            #@$(RM) $(LIBS_DIR)/$(LIB3)
	            @rmdir $(LIBS_DIR) 2> /dev/null || true
	            @$(RM) $(EXE)

re :		    fclean all

.PHONY :	    all, clean, fclean, re

.SILENT :