defaultFileName:=main.cc
defaultBuildDir:=build

fileName:=$(shell if [ ! -z $(filename) ]; then echo $(filename); else echo $(defaultFileName); fi)
execName:=$(basename $(fileName))
buildDir:=$(shell if [ ! -z $(builddir) ]; then echo $(builddir); else echo $(defaultBuildDir); fi)

defaultProjectName:=$(execName)
projectName:=$(shell if [ ! -z $(projectname) ];then echo $(projectname); else echo $(defaultProjectName); fi)

export projectName
export fileName


.SILENT:
.PHONY: default all clean help

default: 
	@cd	 $(buildDir) && make
	@echo "-----------------------------"
	@cd $(buildDir) && ./$(execName)


all:
	@mkdir -p $(buildDir)
	@cd $(buildDir) && cmake ..
	@cd $(buildDir) && make
	@echo "-----------------------------"
	@cd $(buildDir) && ./$(execName)


clean:
	@rm -rf $(buildDir)

help:
	@echo @argument: projectname - creates executable with this name
	@echo @argument: filename - main file name to compile
	@echo @argument: builddir - name of the directory to build the project into
	@echo Example: projectname=AVL make all