#pragma once

#include "GpXmlMapper.hpp"

namespace GPlatform {

class GPXML_API GpTypeMapperXml final: public GpTypeMapper
{
public:
    CLASS_DECLARE_DEFAULTS(GpTypeMapperXml)

public:
                                    GpTypeMapperXml     (void) noexcept;
                                    GpTypeMapperXml     (const GpXmlMapperFlags aFlags) noexcept;

    virtual                         ~GpTypeMapperXml    (void) noexcept override final;

    virtual GpTypeStructBase::SP    ToStruct            (GpRawPtrByteR aData) const override final;
    virtual GpTypeStructBase::SP    ToStruct            (GpRawPtrByteR              aData,
                                                         const GpTypeStructInfo&    aTypeInfo) const override final;

    virtual void                    FromStruct          (const GpTypeStructBase&    aStruct,
                                                         GpByteWriter&              aWriter) const override final;

private:
    const GpXmlMapperFlags          iFlags;
};

}//namespace GPlatform
