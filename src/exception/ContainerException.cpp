//
// Created by User on 015 15.02.19.
//
#include <stdexcept>

namespace ContainerSpace {
    struct ContainerException {
        std::string message;

        const std::string &getMessage() const {
            return message;
        }

        explicit ContainerException(const std::string &message) {
            this->message = message;
        }
    };
}
