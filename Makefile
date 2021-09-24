Main:
	@echo "Creating output folder..."
	@([ -d out ] && echo "out/ already exists") || mkdir out
	@echo "Compiling Shell..."
	@gcc main.c Shell/shell.c String/StringUtil.c Pipe/dualExec.c -o out/Shell
	@echo "Finished shell compilation"
	@echo "Compiling programs"
	@gcc programs/helloworld.c -o out/hw
	@gcc Pipe/testprint.c -o out/testprint
	@gcc Pipe/testread.c -o out/testread
	@echo "Finished"

run:
	./out/Shell