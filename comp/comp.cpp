#include <iostream>
#include <vector>

// Component
class Component {
public:
    virtual void operation() const = 0;
};

// Leaf
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Composite
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation" << std::endl;

        for (const auto& child : children) {
            child->operation();
        }
    }
};

int main() {
    Leaf leaf1, leaf2;
    Composite composite;

    composite.add(&leaf1);
    composite.add(&leaf2);

    composite.operation();

    return 0;
}
