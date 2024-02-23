GPP = g++ -std=c++11 -g
run: output
	./output

output: main.o shortest_path.o priority_queue.o graph.o
	$(GPP) main.o shortest_path.o priority_queue.o graph.o -o output

main.o: main.cpp
	$(GPP) -c main.cpp

priority_queue.o: priority_queue.cpp priority_queue.h
	$(GPP) -c priority_queue.cpp

graph.o: graph.cpp graph.h
	$(GPP) -c graph.cpp

shortest_path.o: shortest_path.cpp shortest_path.h
	$(GPP) -c shortest_path.cpp -Wc++11-extensions

clean:
	rm -rf *.o output