#pragma once

#include "../GpCore2/GpCore.hpp"

#if defined(GPXML_LIBRARY)
    #define GPXML_API GP_DECL_EXPORT
#else
    #define GPXML_API GP_DECL_IMPORT
#endif
