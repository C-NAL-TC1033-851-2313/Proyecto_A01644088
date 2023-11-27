all: clean compile run

compile: proyectoA01644088.cpp
	g++ *.cpp -o build/proyectoA01644088
run: 
	clear
	build/proyectoA01644088
clean:
	rm -f build/proyectoA01644088
	rm -f build/dproyectoA01644088
debug: 
	g++ *.cpp -g -o dproyectoA01644088
	gdb dproyectoA01644088
	rm -f dproyectoA01644088
debugvs:
	g++ *.cpp -g -o build/dproyectoA01644088
