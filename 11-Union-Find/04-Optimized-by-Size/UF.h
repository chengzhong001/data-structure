#ifndef __UF__
#define __UF__

class UF
{
public:

    virtual int getSize();
    virtual bool isConnected(int p, int q);
    virtual void unionElements(int p, int q);
};

#endif