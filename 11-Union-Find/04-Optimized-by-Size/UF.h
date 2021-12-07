#ifndef __UF__
#define __UF__

class UF
{
public:
    virtual int getSize() { return 0; };
    virtual bool isConnected(int p, int q) { return false; };
    virtual void unionElements(int p, int q){};
};

#endif