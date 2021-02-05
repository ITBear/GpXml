#include "GpTypeMapperXmlFactory.hpp"

namespace GPlatform {

GpTypeMapperXmlFactory::GpTypeMapperXmlFactory (void) noexcept
{
}

GpTypeMapperXmlFactory::GpTypeMapperXmlFactory (const GpXmlMapperFlags aFlags) noexcept:
iFlags(aFlags)
{
}

GpTypeMapperXmlFactory::~GpTypeMapperXmlFactory (void) noexcept
{
}

GpTypeMapper::SP    GpTypeMapperXmlFactory::NewInstance (void) const
{
    return MakeSP<GpTypeMapperXml>(iFlags);
}

}//namespace GPlatform
