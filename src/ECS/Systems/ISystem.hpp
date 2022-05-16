#pragma once

#include "../ecs.hpp"

namespace ecs
{
    class ISystem {
    public:
        virtual ~ISystem() {}
        virtual void update(ecs::Core &world) = 0;

    protected:
        static unsigned int _idCount;
    };

    template <typename T>
    class TemplateSystem : public ISystem {
    public:
        static unsigned int getId() {
            static unsigned int id = ecs::ISystem::_idCount++;
            return id;
        }
    };
} // namespace ecs
