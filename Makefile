libraries := -lmingw32 -lSDL2main -lSDL2

app:
	g++ *.cpp -o huntingSquares $(libraries)