#include "GpXmlMapper.hpp"
#include "GpXmlToStruct.hpp"
#include "GpXmlFromStruct.hpp"

namespace GPlatform {

GpTypeStructBase::SP    GpXmlMapper::SFromXml
(
    GpRawPtrCharR           aXmlData,
    const GpXmlMapperFlags  aFlags
)
{
    tinyxml2::XMLDocument xmlDoc;
    GpXmlToStruct::SParseXmlDom(aXmlData, xmlDoc);

    const tinyxml2::XMLElement* xmlRootElement = xmlDoc.RootElement();
    THROW_GPE_COND_CHECK_M
    (
        xmlRootElement != nullptr,
        "XML root element is null"_sv
    );

    GpXmlToStruct::FindTypeInfoResT typeInfoFindRes = GpXmlToStruct::SFindTypeInfo(*xmlRootElement);

    if (!typeInfoFindRes.has_value())
    {
        THROW_GPE("Xml member '@' was not found"_sv);
    }

    const GpTypeStructInfo& typeInfo    = typeInfoFindRes.value().get();
    GpTypeStructBase::SP    resStruct   = typeInfo.NewInstance();

    GpXmlToStruct::SReadStruct(resStruct.Vn(), *xmlRootElement, aFlags, std::nullopt, ""_sv);

    return resStruct;
}

GpTypeStructBase::SP    GpXmlMapper::SFromXml
(
    GpRawPtrCharR           aXmlData,
    const GpTypeStructInfo& aTypeInfo,
    const GpXmlMapperFlags  aFlags
)
{
    tinyxml2::XMLDocument xmlDoc;
    GpXmlToStruct::SParseXmlDom(aXmlData, xmlDoc);

    const tinyxml2::XMLElement* xmlRootElement = xmlDoc.RootElement();
    THROW_GPE_COND_CHECK_M
    (
        xmlRootElement != nullptr,
        "XML root element is null"_sv
    );

    const GpTypeStructInfo& typeInfo = GpXmlToStruct::SCheckTypeInfo
    (
        *xmlRootElement,
        aTypeInfo,
        GpXmlToStruct::CheckMode::CAN_BE_DERIVED
    );

    GpTypeStructBase::SP resStruct = typeInfo.NewInstance();
    GpXmlToStruct::SReadStruct(resStruct.Vn(), *xmlRootElement, aFlags, std::nullopt, ""_sv);

    return resStruct;
}

void    GpXmlMapper::SFromXml
(
    GpRawPtrCharR           aXmlData,
    GpTypeStructBase&       aOut,
    const GpXmlMapperFlags  aFlags
)
{
    tinyxml2::XMLDocument xmlDoc;
    GpXmlToStruct::SParseXmlDom(aXmlData, xmlDoc);

    const tinyxml2::XMLElement* xmlRootElement = xmlDoc.RootElement();
    THROW_GPE_COND_CHECK_M
    (
        xmlRootElement != nullptr,
        "XML root element is null"_sv
    );

    GpXmlToStruct::SReadStruct(aOut, *xmlRootElement, aFlags, std::nullopt, ""_sv);
}

std::string GpXmlMapper::SToXml (const GpTypeStructBase&    aStruct,
                                 const GpXmlMapperFlags     aFlags)
{
    tinyxml2::XMLDocument   xmlDoc;
    tinyxml2::XMLNode*      xmlRoot = xmlDoc.NewElement("body");
    xmlDoc.InsertFirstChild(xmlRoot);

    GpXmlFromStruct::SWrite(aStruct, *xmlDoc.RootElement(), aFlags, std::nullopt);
    return GpXmlFromStruct::SToString(xmlDoc);
}

void    GpXmlMapper::SToXml
(
    const GpTypeStructBase& aStruct,
    GpByteWriter&           aWriter,
    const GpXmlMapperFlags  aFlags
)
{
    tinyxml2::XMLDocument   xmlDoc;
    tinyxml2::XMLNode*      xmlRoot = xmlDoc.NewElement("body");
    xmlDoc.InsertFirstChild(xmlRoot);

    GpXmlFromStruct::SWrite(aStruct, *xmlDoc.RootElement(), aFlags, std::nullopt);
    GpXmlFromStruct::SToString(xmlDoc, aWriter);
}

}//namespace GPlatform
