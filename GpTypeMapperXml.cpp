#include "GpTypeMapperXml.hpp"
#include <iostream>

namespace GPlatform {

GpTypeMapperXml::GpTypeMapperXml (void) noexcept
{
}

GpTypeMapperXml::GpTypeMapperXml (const GpXmlMapperFlags aFlags) noexcept:
iFlags(aFlags)
{
}

GpTypeMapperXml::~GpTypeMapperXml (void) noexcept
{
}

GpTypeStructBase::SP    GpTypeMapperXml::ToStruct (GpRawPtrByteR aData) const
{
    return GpXmlMapper::SFromXml(aData, iFlags);
}

GpTypeStructBase::SP    GpTypeMapperXml::ToStruct (GpRawPtrByteR            aData,
                                                   const GpTypeStructInfo&  aTypeInfo) const
{
    return GpXmlMapper::SFromXml(aData, aTypeInfo, iFlags);
}

void    GpTypeMapperXml::FromStruct (const GpTypeStructBase&    aStruct,
                                     GpByteWriter&              aWriter) const
{
    GpXmlMapper::SToXml(aStruct, aWriter, iFlags);
}

}//namespace GPlatform
