#pragma once

#include "GpXmlMapperFlags.hpp"

namespace GPlatform {

class GPXML_API GpXmlMapper
{
public:
    CLASS_REMOVE_CTRS(GpXmlMapper)

public:
    static GpTypeStructBase::SP     SFromXml    (GpRawPtrCharR          aXmlData,
                                                 const GpXmlMapperFlags aFlags);
    static GpTypeStructBase::SP     SFromXml    (GpRawPtrCharR              aXmlData,
                                                 const GpTypeStructInfo&    aTypeInfo,
                                                 const GpXmlMapperFlags     aFlags);
    static void                     SFromXml    (GpRawPtrCharR          aXmlData,
                                                 GpTypeStructBase&      aOut,
                                                 const GpXmlMapperFlags aFlags);

    template <typename T> static
    typename T::SP                  SFromXml    (GpRawPtrCharR          aXmlData,
                                                 const GpXmlMapperFlags aFlags);

    static std::string              SToXml      (const GpTypeStructBase&    aStruct,
                                                 const GpXmlMapperFlags     aFlags);
    static void                     SToXml      (const GpTypeStructBase&    aStruct,
                                                 GpByteWriter&              aWriter,
                                                 const GpXmlMapperFlags     aFlags);
};

template <typename T>
typename T::SP  GpXmlMapper::SFromXml (GpRawPtrCharR            aXmlData,
                                       const GpXmlMapperFlags   aFlags)
{
    GpTypeStructBase::SP obj = SFromXml(aXmlData, T::STypeInfo(), aFlags);
    return obj.CastAs<typename T::SP>();
}

}//namespace GPlatform
