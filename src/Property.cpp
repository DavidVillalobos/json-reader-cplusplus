#include"Property.h"

Property::Property(string name, string value) : Element(name){
    this->value = value;
}

string Property::getValue(){
    return value;
}

ostream& operator << (ostream &o,const Property &p)
{
    o << p.value;
    return o;
}

Property::~Property(){ }