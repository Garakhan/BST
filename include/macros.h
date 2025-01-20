#ifndef __MACROS_H__
#define __MACROS_H__

#include <type_traits>
#define __assert_comparison__(T) std::is_same_v<decltype(declval<int>()<declval<int>()), bool>

#endif