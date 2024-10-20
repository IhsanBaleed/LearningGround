#include "Helper.hh"

template <typename T>
void helper_template_function(T t) {
    std::cout << "Helper Template Imp" << std::endl;
}
// template void helper_template_function<int>(int); this can fix the issue, by expanding the template, which makes it callable

void helper_function() {
    std::cout << "Helper Imp" << std::endl;
    // helper_template_function(7);
}
