# Makefile para el proyecto ListArray

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

# Regla para limpiar el proyecto eliminando archivos objeto y el directorio bin
clean:
	rm -f *.o
	rm -f *.gch
	rm -rf bin


