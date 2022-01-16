#ifndef CELLULAR_AUTOMATA_IVIEW_H
#define CELLULAR_AUTOMATA_IVIEW_H
#include "vector"

class IView {
public:
    virtual void print(std::vector<bool> screen) = 0;
    virtual void println(char* string) = 0;
    virtual bool open() const = 0;
    virtual void clear() = 0;
    virtual ~IView() {};
};


#endif //CELLULAR_AUTOMATA_IVIEW_H
