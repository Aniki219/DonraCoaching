class Node2D {
    public:
        int value;
        Node2D* next = nullptr;
        Node2D* prev = nullptr;
        Node2D* below = nullptr;
    Node2D(int _value);
    bool isHead();
    bool isTail();
};

class SkipList {
    public:
        int depth;
        Node2D** heads;
    SkipList(int _depth);
    SkipList* Add(int value);
    Node2D* Find(int value);
    void Print();

    private:
        bool initialized;
        void addDepth(int value, Node2D* node);
        int getFlips();
        void insertAtPlace(Node2D** nodeStack);
        Node2D** findNodeStack(int value);
};