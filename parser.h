#pragma once
#include "Vector.hh"

#ifndef __HW1__PARSER__
#define __HW1__PARSER__

#include <string>
#include <vector>

namespace parser
{
    //Notice that all the structures are as simple as possible
    //so that you are not enforced to adopt any style or design.
    struct Vec3f
    {
        float x, y, z;
    };

    struct Vec3i
    {
        int x, y, z;
        operator Vector()
        {
            Vector vector = {x, y, z};
            return vector;
        }
    };

    struct Vec4f
    {
        float x, y, z, w;
    };

    struct Camera
    {
        Vector position;
        Vector gaze;
        Vector up;
        Vec4f near_plane;
        float near_distance;
        int image_width, image_height;
        std::string image_name;
    };

    struct PointLight
    {
        Vector position;
        Vector intensity;
    };

    struct Material
    {
        bool is_mirror, is_dielectric;
        Vector ambient;
        Vector diffuse;
        Vector specular;
        Vector mirror;
        Vector AbsorptionCoefficient;
        float phong_exponent, refraction_index;
    };

    struct Face
    {
        int v0_id;
        int v1_id;
        int v2_id;
    };

    struct Mesh
    {
        int material_id;
        std::vector<Face> faces;
    };

    struct Triangle
    {
        int material_id;
        Face indices;
    };

    struct Sphere
    {
        int material_id;
        int center_vertex_id;
        float radius;
    };

    struct Plymesh
    {
        int material_id;
        std::string plyFile;
    };

    struct Scene
    {
        //Data
        Vec3i background_color;
        float shadow_ray_epsilon;
        int max_recursion_depth;
        std::vector<Camera> cameras;
        Vector ambient_light;
        std::vector<PointLight> point_lights;
        std::vector<Material> materials;
        std::vector<Vector> vertex_data;
        std::vector<Mesh> meshes;
        std::vector<Triangle> triangles;
        std::vector<Sphere> spheres;

        std::vector<struct Plymesh> plymeshes;

        //Functions
        void loadFromXml(const std::string &filepath);
    };
}

#endif
