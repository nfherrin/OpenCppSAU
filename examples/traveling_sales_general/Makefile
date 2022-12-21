# Defining variables
FC:=g++
EXE:=TSG
EXT:=.exe

all :     TYPE :=
debug:    TYPE := _Debug
catch:    TYPE := _Catch
coverage: TYPE := _Coverage

all:      OPT := -O3 -Wall -Werror
debug:    OPT := -O0 -g -Wall -Werror
catch:    OPT := -O0 -g -Wall -W -Wsurprising -Wextra -Werror
coverage: OPT := -O0 -g --coverage -Wall -Werror

#-----------------------------------------------------------------------------------
#Directory Paths
#-----------------------------------------------------------------------------------
SIMANN := ../../src

#-----------------------------------------------------------------------------------
#Add source files as necessary
#If the files are not compiled using the generic rules, add commands under their
#rule declaration. Add these items to FILTER
#-----------------------------------------------------------------------------------

SRC := main.cpp \
	   travel_sales.cpp

OBJ := $(SRC:.cpp=.o)

#-----------------------------------------------------------------------------------
#Add simple compile SIMANN files
#-----------------------------------------------------------------------------------
SIMANN_SRC := $(SIMANN)/OpenCppSAU.cpp

SIMANN_OBJ := $(patsubst %.cpp,%.o,$(notdir $(SIMANN_SRC)))

#-----------------------------------------------------------------------------------
#Phony targets for cleaning and building
#-----------------------------------------------------------------------------------
.PHONY: all debug catch coverage clean reset

EXEC_NAME=$(EXE)
EXEC_FILE=./$(EXEC_NAME)

all: $(EXEC_FILE)

debug: $(EXEC_FILE)

catch: $(EXEC_FILE)

coverage: $(EXEC_FILE)

#Intended to clean up compilation artifacts but leave executable & coverage
clean:
	$(RM) $(OBJ) $(SIMANN_OBJ) *.mod *.gcno

#Intended to reset directory to fresh state with no exe or artifacts
reset : clean
	$(RM) *.exe

#Generics for source files
%.o : %.cpp
	$(FC) $(OPT) -I $(SIMANN) -c $<

#-----------------------------------------------------------------------------------
#Generics for contrib files
#-----------------------------------------------------------------------------------
$(SIMANN_OBJ): %.o: $(filter %.cpp, $(SIMANN_SRC))
	$(FC) -c $(OPT) $^

#Executable rule
$(EXEC_FILE): $(OBJ) $(SIMANN_OBJ)
	$(FC) -o $@$(TYPE)$(EXT) $(OPT) $^

#-----------------------------------------------------------------------------------
#Dependency List
#-----------------------------------------------------------------------------------
main.o : infuncs.o travel_sales.o OpenCppSAU.o
