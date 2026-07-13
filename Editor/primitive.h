#pragma once
#include <memory>

class BasePrimitive;
using PtrPrimitive = std::shared_ptr<BasePrimitive>; 


class IPrimitive 
{
public:
    virtual ~IPrimitive() = default;
    
    virtual int getId() const = 0;
    virtual void setId(int id) = 0;

    virtual void draw() = 0;
};

class BasePrimitive : public IPrimitive 
{

protected:
    int m_id; 
   
    //ðàçìåð, ïîçèöèÿ 

public:
    BasePrimitive() : m_id(0) {} 
    
    int getId() const override { return m_id; }
    void setId(int id) override { m_id = id; }
};

