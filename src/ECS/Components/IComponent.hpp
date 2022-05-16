#pragma once

namespace ecs
{
    class IComponent {
        protected:
            static unsigned int _idCount;
    };
    
    template <typename T>
    class TemplateComponent : public IComponent {
        public:
            static unsigned int getId() {
                static unsigned int id = ecs::IComponent::_idCount++;
                return id;
            }
    };
} // namespace ecs