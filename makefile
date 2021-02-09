test : main.o Shader.o stb_image.o libglad.a libglfw3dll.a
	g++ -o test main.o Shader.o stb_image.o libglad.a libglfw3dll.a
main.o : main.cpp
	g++ -c main.cpp
Shader.o : Shader.cpp Shader.h
	g++ -c Shader.cpp Shader.h
stb_image.o : stb_image.cpp .\include\stb_image.h
	g++ -c stb_image.cpp .\include\stb_image.h
clean:
	del *.o

