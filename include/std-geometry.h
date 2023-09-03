namespace std {
typedef unsigned int uint;
struct Coordinate {
    int x, y;
};
struct Size {
    uint w, h;
};
struct Object {
    Coordinate pos;
    Size size;
};
};  // namespace std