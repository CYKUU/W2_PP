#include <iostream>
#include <vector>


namespace MuSoeun
{


    class Object {
    public:
        int x;
        int y;
        float scale;
        float rotation;
        std::vector<Component*> components;

        void Render(std::vector<std::vector<char>>& screenBuffer) {
            for (Component* component : components) {
                component->Render(screenBuffer);
            }
        }
    };

    class Scene {
    public:
        std::vector<Object*> objects;
        std::vector<std::vector<char>> screenBuffer;
        int screenWidth;
        int screenHeight;

        Scene(int width, int height) {
            screenWidth = width;
            screenHeight = height;
            InitScreenBuf();
        }

        void AddObject(Object* object) {
            objects.push_back(object);
        }

        void Draw() {
            ClearScreenBuf();
            for (Object* object : objects) {
                object->Render(screenBuffer);
            }
            PrintScreenBuf();
        }

        void InitScreenBuf() {
            screenBuffer.resize(screenHeight, std::vector<char>(screenWidth, ' '));
        }

        void ClearScreenBuf() {
            for (auto& row : screenBuffer) {
                std::fill(row.begin(), row.end(), ' ');
            }
        }

        void PrintScreenBuf() {
            for (const auto& row : screenBuffer) {
                for (const char pixel : row) {
                    std::cout << pixel;
                }
                std::cout << std::endl;
            }
        }
    };

    class Component {
    public:
        virtual void Render(std::vector<std::vector<char>>& screenBuffer) = 0;
        virtual void Start() {}
        virtual void Update() {}
    };

    class SnakeBody : public Object {
    public:
        // SnakeBody에 특화된 동작 구현
    };

    class RenderComponent : public Component {
    public:
        void Render(std::vector<std::vector<char>>& screenBuffer) override {
            // screenBuffer에 그리기 동작 구현
        }
    };

    class MovementComponent : public Component {
        public:
        void Update() override {
            // 위치 업데이트 동작 구현
        }
    };

    int main() {
        Scene scene(80, 24);

        Object object1;
        object1.x = 10;
        object1.y = 5;
        object1.scale = 1.0f;
        object1.rotation = 0.0f;
        object1.components.push_back(new RenderComponent());
        scene.AddObject(&object1);

        Object object2;
        object2.x = 20;
        object2.y = 8;
        object2.scale = 1.5f;
        object2.rotation = 45.0f;
        object2.components.push_back(new RenderComponent());
        scene.AddObject(&object2);

        scene.Draw();

        // 메모리 해제
        for (Object* object : scene.objects) {
            for (Component* component : object->components) {
                delete component;
            }
        }

        return 0;
    }

}
