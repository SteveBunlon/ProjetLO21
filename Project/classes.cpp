#include "classes.h"

ProgrammationManager& ProgrammationManager::Instance()
{
    static ProgrammationManager Pmanager;
    return Pmanager;
}
