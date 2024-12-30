bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h


bin/testListLinked: testListLinked.cpp ListLinked.h Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h Node.h

# Regla para limpiar el proyecto eliminando archivos objeto y el directorio bin
clean:
	rm -f *.o
	rm -f *.gch
	rm -rf bin

