#include "your_class.h"  // Include the header file for your_class

ClassImp(your_class)

// Default constructor - ROOT needs the default one where everything is set to 0
your_class::your_class() : TObject()
{
    // Initialize all members to appropriate default values
    // For example, if you have an integer member called someInt, you can initialize it like this:
    // someInt = 0;
}

// Another constructor
your_class::your_class(Int_t variable) : TObject()
{
    // Initialize members based on the input 'variable'
    // For example, if you have an integer member called someInt, you can initialize it like this:
    // someInt = variable;
}

// Destructor
your_class::~your_class()
{
    // Cleanup any resources if needed
    // This function can be empty if you don't need to do anything specific during destruction
}
