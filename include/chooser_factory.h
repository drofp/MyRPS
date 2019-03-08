#ifndef CHOOSER_FACTORY_H_
#define CHOOSER_FACTORY_H_

#include "chooser.h"

namespace myrps
{
class ChooserFactory
{
public:
    static Chooser *makeChooser(string choice);
};
}
#endif
