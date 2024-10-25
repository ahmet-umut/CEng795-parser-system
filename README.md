# CEng795-parser-system
This repository may help some future CEng795 students to parse most of the scene files for homeworks.

This system solves some problems that exist in given XML files. Some XML files have missing parameters; this system puts some default parameters in those cases, infers some details from scene when missing. Also, whenever the program encounters a mesh with a plyFile name on it, the parser adds the details of the ply file to the scene: There is a new Plymesh structure.

```
struct Plymesh
{
  int material_id;
  std::string plyFile;
};
```

In the scene structure, there is a element as follows: ```std::vector<struct Plymesh> plymeshes;```. The parser puts the mesh information inside this variable and leaves the programmer to load the mesh as they wish. There are some plyreader files in this repository, the user can utilize them when extracting the file contents.

## Future Work
I plan to evolve this system into outputting the vertices, spheres, cameras, triangles and any other details about the scene into a unified binary format.
