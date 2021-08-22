#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Node.hpp>

namespace godot {

class GDExample : public Node {
    GODOT_CLASS(GDExample, Node)

public:
    static void _register_methods();

    GDExample();
    ~GDExample();

    void _init(); // our initializer called by Godot

    void _process(float delta);
};

}

#endif
