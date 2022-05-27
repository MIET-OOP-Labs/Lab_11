#ifndef BASE_H
#define BASE_H


class base {

    int foo = 42;
public:
    base();

    virtual int getNum(){return foo;};

    ~base();
};

#endif // BASE_H
