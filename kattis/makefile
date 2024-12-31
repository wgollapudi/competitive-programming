CXX := g++
CXXFLAGS := -Wall -std=c++23
OPT = -g

.PHONY: all clean

SOURCES := $(wildcard *.cpp)
TARGETS := $(SOURCES:.cpp=)

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $(OPT) -o $@ $<

gitignore:
	@SCRIPT=$$( \
		cd "$(CURDIR)"; \
		SEARCH_DIR="$$PWD"; \
		while [ "$$SEARCH_DIR" != "/" ]; do \
			if [ -f "$$SEARCH_DIR/generate_gitignore.sh" ]; then \
				echo "$$SEARCH_DIR/generate_gitignore.sh"; \
				break; \
			fi; \
			SEARCH_DIR=$$(dirname "$$SEARCH_DIR"); \
		done \
	); \
	if [ -n "$$SCRIPT" ]; then \
		echo "Found generate_gitignore.sh at: $$SCRIPT"; \
		chmod +x "$$SCRIPT" 2>/dev/null || true; \
		"$$SCRIPT" "$(CURDIR)"; \
	else \
		printf "\033[31mError: generate_gitignore.sh not found in any parent directory.\033[0m\n" >&2; \
		exit 1; \
	fi

clean:
	rm -f $(TARGETS) *.o
