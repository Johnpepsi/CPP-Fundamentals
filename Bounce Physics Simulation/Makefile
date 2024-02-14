TARGET = bounce
all: $(TARGET)

srcdir  = .

CXX = clang++
CFLAGS = -O3 -pthread -std=c++17 -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL 
LIBS = -L/usr/lib/x86_64-linux-gnu -lSDL -lGL -lGLU -lm


$(TARGET): main.o SDL_GL_Helper.o
	$(CXX) -o $@ main.o SDL_GL_Helper.o $(CFLAGS) $(LIBS) 

main.o: main.cpp 
	$(CXX) -c $? $(CFLAGS)  

SDL_GL_Helper.o: SDL_GL_Helper.cpp
	$(CXX) -c $? $(CFLAGS)  

clean:
	rm -f $(TARGET) *.o

