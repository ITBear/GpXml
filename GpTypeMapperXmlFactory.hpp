#pragma once

#include "GpTypeMapperXml.hpp"

namespace GPlatform {

class GPXML_API GpTypeMapperXmlFactory final: public GpTypeMapperFactory
{
public:
    CLASS_DECLARE_DEFAULTS(GpTypeMapperXmlFactory)

public:
                                    GpTypeMapperXmlFactory  (void) noexcept;
                                    GpTypeMapperXmlFactory  (const GpXmlMapperFlags aFlags) noexcept;
    virtual                         ~GpTypeMapperXmlFactory (void) noexcept override final;

    virtual GpTypeMapper::SP        NewInstance             (void) const override final;

private:
    const GpXmlMapperFlags          iFlags;
};

}//namespace GPlatform
