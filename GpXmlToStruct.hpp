#pragma once

#include "GpXmlMapperFlags.hpp"
#include <tinyxml2/tinyxml2.h>

namespace GPlatform {

class GPXML_API GpXmlToStruct
{
public:
    CLASS_REMOVE_CTRS(GpXmlToStruct);

    enum class CheckMode
    {
        MUST_BE_EQUAL,
        CAN_BE_DERIVED
    };

    using FindTypeInfoResT = std::optional<std::reference_wrapper<const GpTypeStructInfo>>;

public:
    static void                     SParseXmlDom    (GpRawPtrCharR          aXmlData,
                                                     tinyxml2::XMLDocument& aXmlDocOut);

    static void                     SReadStruct     (GpTypeStructBase&              aStruct,
                                                     const tinyxml2::XMLElement&    aXmlElement,
                                                     const GpXmlMapperFlags         aFlags,
                                                     GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp,
                                                     std::string_view               aUnwrapKeyValue);
    static const GpTypeStructInfo&  SCheckTypeInfo  (const tinyxml2::XMLElement&    aXmlElement,
                                                     const GpTypeStructInfo&        aTypeInfoBase,
                                                     const CheckMode                aCheckMode);
    static FindTypeInfoResT         SFindTypeInfo   (const tinyxml2::XMLElement&    aXmlElement);

private:
    static void                     SReadValue      (GpTypeStructBase&              aStruct,
                                                     const GpTypePropInfo&          aPropInfo,
                                                     const tinyxml2::XMLElement&    aXmlElement,
                                                     const GpXmlMapperFlags         aFlags,
                                                     GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp,
                                                     std::string_view               aUnwrapKeyValue);

    static void                     SReadValueVec   (GpTypeStructBase&              aStruct,
                                                     const GpTypePropInfo&          aPropInfo,
                                                     const tinyxml2::XMLElement&    aXmlElement,
                                                     const GpXmlMapperFlags         aFlags,
                                                     GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

    static void                     SReadValueList  (GpTypeStructBase&              aStruct,
                                                     const GpTypePropInfo&          aPropInfo,
                                                     const tinyxml2::XMLElement&    aXmlElement,
                                                     const GpXmlMapperFlags         aFlags,
                                                     GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

    static void                     SReadValueSet   (GpTypeStructBase&              aStruct,
                                                     const GpTypePropInfo&          aPropInfo,
                                                     const tinyxml2::XMLElement&    aXmlElement,
                                                     const GpXmlMapperFlags         aFlags,
                                                     GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

    static void                     SReadValueMap   (GpTypeStructBase&              aStruct,
                                                     const GpTypePropInfo&          aPropInfo,
                                                     const tinyxml2::XMLElement&    aXmlElement,
                                                     const GpXmlMapperFlags         aFlags,
                                                     GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp);

private:
    static const std::array<std::string_view, 18>   sParseErrorCodes;
};

}//namespace GPlatform
