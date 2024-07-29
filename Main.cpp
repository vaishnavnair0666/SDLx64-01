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

std::vector<Edge> edges = {
    Edge{ 0, 1 }, Edge{ 1, 2 }, Edge{ 2, 3 }, Edge{ 3, 0 },
    Edge{ 4, 5 }, Edge{ 5, 6 }, Edge{ 6, 7 }, Edge{ 7, 4 },
    Edge{ 0, 4 }, Edge{ 1, 5 }, Edge{ 2, 6 }, Edge{ 3, 7 }
};
/*
std::vector<Point3D> points = {
    // Body
    Point3D{ -1.0f,  0.0f,  0.0f },  // 0: Head
    Point3D{ -0.5f,  0.5f,  0.5f },  // 1: Top Front Left
    Point3D{ -0.5f,  0.5f,  0.5f },  // 1: Top Front Left
    Point3D{ -0.5f,  0.5f, -0.5f },  // 2: Top Front Right
    Point3D{ -0.5f, -0.5f,  0.5f },  // 3: Bottom Front Left
    Point3D{ -0.5f, -0.5f, -0.5f },  // 4: Bottom Front Right
    Point3D{  0.5f,  0.5f,  0.5f },  // 5: Top Back Left
    Point3D{  0.5f,  0.5f, -0.5f },  // 6: Top Back Right
    Point3D{  0.5f, -0.5f,  0.5f },  // 7: Bottom Back Left
    Point3D{  0.5f, -0.5f, -0.5f },  // 8: Bottom Back Right
    Point3D{  1.0f,  0.0f,  0.0f },  // 9: Tail
    
    // Dorsal Fin
    Point3D{ -0.25f,  1.0f,  0.0f },  // 10: Top Front
    Point3D{  0.25f,  1.0f,  0.0f },  // 11: Top Back

    // Side Fins
    Point3D{  0.0f,  0.0f,  0.75f },  // 12: Left Fin
    Point3D{  0.0f,  0.0f, -0.75f },  // 13: Right Fin
};

// Define the edges of the fish
std::vector<Edge> edges = {
    // Body
    Edge{ 1, 2 }, Edge{ 1, 3 }, Edge{ 2, 4 }, Edge{ 3, 4 },
    Edge{ 0, 1 }, Edge{ 0, 2 }, Edge{ 0, 3 }, Edge{ 0, 4 },
    Edge{ 1, 5 }, Edge{ 2, 6 }, Edge{ 3, 7 }, Edge{ 4, 8 },
    Edge{ 5, 6 }, Edge{ 5, 7 }, Edge{ 6, 8 }, Edge{ 7, 8 },
    Edge{ 5, 9 }, Edge{ 6, 9 }, Edge{ 7, 9 }, Edge{ 8, 9 },

    // Dorsal Fin
    Edge{ 1, 10 }, Edge{ 2, 10 }, Edge{ 10, 11 }, Edge{ 5, 11 }, Edge{ 6, 11 },

    // Side Fins
    Edge{ 3, 12 }, Edge{ 7, 12 }, Edge{ 4, 13 }, Edge{ 8, 13 },
};
*/
int main(int argc, char** argv) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    window = SDL_CreateWindow("3D Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 500, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    Renderer3D renderer3D1(window, renderer, points, edges);

    while (running) {
        if (SDL_QuitRequested()) {
            running = false; break;
        }
        renderer3D1.render();
    }
    return 0;

}