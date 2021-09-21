Main:
	@echo "Creating output folder..."
	@([ -d out ] && echo "out/ already exists") || mkdir out
	@echo "Compiling Shell..."
	@gcc main.c Shell/shell.c String/StringUtil.c -o out/Shell
	@echo "Finished shell compilation"
	@echo "Compiling programs"
	@gcc programs/helloworld.c -o out/hw
	@echo "Finished"

run:
	./out/Shell