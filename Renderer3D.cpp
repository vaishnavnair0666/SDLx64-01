#include "Renderer3D.h"

Renderer3D::Renderer3D(SDL_Window* window, SDL_Renderer* renderer, std::vector<Point3D>& points, std::vector<Edge>& vertices)
    :  renderer(renderer), points(points), vertices(vertices)
{
    SDL_GetWindowSize(window, &WindowSizeX, &WindowSizeY);
    renderer = renderer;
    points = points;
    vertices = vertices;
}

void Renderer3D::render() {
    auto time1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration(0);

    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Set the draw color to white
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    rotation += 1 * DeltaTime;

    // Render the vertices
    for (auto& Edge : vertices) {
        Point3D rotatedStartPoint = rotateX(rotateY(points[Edge.start]));
        Point3D rotatedEndPoint = rotateX(rotateY(points[Edge.end]));

        Point2D start = projection(rotatedStartPoint);
        Point2D end = projection(rotatedEndPoint);
        SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
    }
    SDL_RenderPresent(renderer);
    auto time2 = std::chrono::high_resolution_clock::now();
    duration = time2 - time1;
    DeltaTime = duration.count();
    time1 = time2;
}
Point3D Renderer3D::rotateX(Point3D point) {
    Point3D returnPoint;
    returnPoint.x = point.x;
    returnPoint.y = cos(rotation) * point.y - sin(rotation) * point.z;
    returnPoint.z = sin(rotation) * point.y + cos(rotation) * point.z;
    return returnPoint;
}

Point3D Renderer3D::rotateY(Point3D point)
{
    Point3D returnPoint;
    returnPoint.x = cos(rotation) * point.x + sin(rotation) * point.z;
    returnPoint.y = point.y;
    returnPoint.z = -sin(rotation) * point.x + cos(rotation) * point.z;
    return returnPoint;
}

Point3D Renderer3D::rotateZ(Point3D point) {
    Point3D returnPoint;
    returnPoint.x = cos(rotation) * point.x - sin(rotation) * point.y;
    returnPoint.y = sin(rotation) * point.x + cos(rotation) * point.y;
    returnPoint.z = point.z;
    return returnPoint;
}

Point2D Renderer3D::projection(Point3D point)
{
    return Point2D{
        WindowSizeX / 2 + (FOV * point.x) / (FOV + point.z) * 100,WindowSizeY / 2 + (FOV * point.y) / (FOV + point.z) * 100
    };
}