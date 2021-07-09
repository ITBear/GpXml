#pragma once

#include "GpXmlMapperFlags.hpp"

#include <tinyxml2/tinyxml2.h>

namespace GPlatform {

class GPXML_API GpXmlFromStruct
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpXmlFromStruct);

public:
    static std::string  SToString       (const tinyxml2::XMLDocument&   aXmlDOM);
    static void         SToString       (const tinyxml2::XMLDocument&   aXmlDOM,
                                         GpByteWriter&                  aWriter);

    static void         SWrite          (const GpTypeStructBase&        aStruct,
                                         tinyxml2::XMLElement&          aXmlElement,
                                         const GpXmlMapperFlags         aFlags,
                                         GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

    static void         SWriteAttr      (const GpTypeStructBase&    aStruct,
                                         const GpTypePropInfo&      aPropInfo,
                                         tinyxml2::XMLElement&      aXmlElement,
                                         const GpXmlMapperFlags     aFlags);

private:
    static void         SWriteValue     (const GpTypeStructBase&        aStruct,
                                         const GpTypePropInfo&          aPropInfo,
                                         tinyxml2::XMLElement&          aXmlElement,
                                         const GpXmlMapperFlags         aFlags,
                                         GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

    static void         SWriteValueVec  (const GpTypeStructBase&        aStruct,
                                         const GpTypePropInfo&          aPropInfo,
                                         tinyxml2::XMLElement&          aXmlElement,
                                         const GpXmlMapperFlags         aFlags,
                                         GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

    static void         SWriteValueList (const GpTypeStructBase&        aStruct,
                                         const GpTypePropInfo&          aPropInfo,
                                         tinyxml2::XMLElement&          aXmlElement,
                                         const GpXmlMapperFlags         aFlags,
                                         GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

    static void         SWriteValueSet  (const GpTypeStructBase&        aStruct,
                                         const GpTypePropInfo&          aPropInfo,
                                         tinyxml2::XMLElement&          aXmlElement,
                                         const GpXmlMapperFlags         aFlags,
                                         GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

    static void         SWriteValueMap  (const GpTypeStructBase&        aStruct,
                                         const GpTypePropInfo&          aPropInfo,
                                         tinyxml2::XMLElement&          aXmlElement,
                                         const GpXmlMapperFlags         aFlags,
                                         GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);
};

}//namespace GPlatform
