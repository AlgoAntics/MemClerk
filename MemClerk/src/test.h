#ifndef TEST_H
#define TEST_H

class Test {
    private:
        int x = 5;

    public:
        Test() {}
        ~Test() {}

        int get() {
            return this->x;
        }
};

#endif // TEST_H
