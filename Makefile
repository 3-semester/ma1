Main:
	@echo "Creating output folder..."
	([ -d out ] && echo "out/ already exists") || mkdir out
	@echo "Compiling Shell..."
	gcc main.c -o out/Shell
