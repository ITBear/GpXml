#pragma once

#include "GpXml_global.hpp"

namespace GPlatform {

GP_ENUM(GPXML_API, GpXmlMapperFlag,
    WRITE_STRUCT_UID,
    UNIX_TS_AS_STR
);

using GpXmlMapperFlags = GpEnumFlagsST<GpXmlMapperFlag>;

}//namespace GPlatform
