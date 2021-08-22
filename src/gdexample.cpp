#include "gdexample.h"
#include <iostream>

using namespace godot;

void GDExample::_register_methods() {
    register_method("_process", &GDExample::_process);
}

GDExample::GDExample() {
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_init() {
    // initialize any variables here
}

void GDExample::_process(float delta) {
    std::cout << "Hello World Nacho!";
}

