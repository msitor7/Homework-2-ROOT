#ifndef __YOUR_CLASS_H__
#define __YOUR_CLASS_H__

#include <TObject.h>  

class your_class : public TObject {
public:
    your_class();                 
    your_class(Int_t variable);   
    virtual ~your_class();        

    // Add public member functions and data members as needed

private:
    // Add private data members

    ClassDef(your_class, 1);  
};

#endif 
