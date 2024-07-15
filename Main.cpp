#include <SDL.h>
#include "Renderer3D.h"
//cube
std::vector<Point3D> points = {
    Point3D{ -1.0f, -1.0f, -1.0f },
    Point3D{ 1.0f, -1.0f, -1.0f },
    Point3D{ 1.0f, 1.0f, -1.0f },
    Point3D{ -1.0f, 1.0f, -1.0f },
    Point3D{ -1.0f, -1.0f, 1.0f },
    Point3D{ 1.0f, -1.0f, 1.0f },
    Point3D{ 1.0f, 1.0f, 1.0f },
    Point3D{ -1.0f, 1.0f, 1.0f }
};

std::vector<Edge> vertices = {
    Edge{ 0, 1 }, Edge{ 1, 2 }, Edge{ 2, 3 }, Edge{ 3, 0 },
    Edge{ 4, 5 }, Edge{ 5, 6 }, Edge{ 6, 7 }, Edge{ 7, 4 },
    Edge{ 0, 4 }, Edge{ 1, 5 }, Edge{ 2, 6 }, Edge{ 3, 7 }
};

int main(int argc, char** argv) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    window = SDL_CreateWindow("3D Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 500, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    Renderer3D renderer3D1(window, renderer, points, vertices);

    while (running) {
        if (SDL_QuitRequested()) {
            running = false; break;
        }
        renderer3D1.render();
    }
    return 0;

}