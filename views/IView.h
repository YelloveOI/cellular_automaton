#ifndef CELLULAR_AUTOMATA_IVIEW_H
#define CELLULAR_AUTOMATA_IVIEW_H


class IView {
public:
    virtual void print(char** screen) = 0;
    virtual void println(char* string) = 0;
    virtual bool open() const = 0;
    virtual void clear() = 0;
    virtual ~IView() {};
};


#endif //CELLULAR_AUTOMATA_IVIEW_H
