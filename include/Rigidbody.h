#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Component.h"

namespace eEngine
{
    namespace Components
    {
        class Rigidbody : public Component
        {
        public:
            static const std::string typeIDS;
            virtual std::string typeID();    

            Rigidbody();
        };
    }
	
}

#endif