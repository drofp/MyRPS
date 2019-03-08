#include "chooser_factory.h"

#include <iostream>

using namespace std;
using namespace myrps;

Chooser *ChooserFactory::makeChooser(string choice)
{
    if(choice == "smart")
    {
        cout << "you chose random!" << endl;
    }
    else if(choice == "smart")
    {
        cout << "you chose smart!" << endl;
    }
    else if(choice == "genius")
    {
        cout << "you chose genius!" << endl;
    }
    else
    {
        cout << "you chose none of those!" << endl;
    }

    return nullptr;
}
