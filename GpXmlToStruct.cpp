#include "GpXmlToStruct.hpp"

namespace GPlatform {

class _InserterVec
{
public:
    template<typename T, typename... Ts>
    static void SInsert(GpVector<T>& aVec, Ts&&... aArgs)
    {
        aVec.emplace_back(std::forward<Ts>(aArgs)...);
    }
};

class _InserterList
{
public:
    template<typename T, typename... Ts>
    static void SInsert(GpList<T>& aVec, Ts&&... aArgs)
    {
        aVec.emplace_back(std::forward<Ts>(aArgs)...);
    }
};

class _InserterSet
{
public:
    template<typename T, typename... Ts>
    static void SInsert(GpSet<T>& aVec, Ts&&... aArgs)
    {
        aVec.insert(std::forward<Ts>(aArgs)...);
    }
};

template<typename Inserter,
         typename ValGetter>
void    _ProcessContainer (GpTypeStructBase&            aStruct,
                           const GpTypePropInfo&        aPropInfo,
                           const tinyxml2::XMLElement&  aXmlElement,
                           const GpXmlMapperFlags       aFlags,
                           GpTypePropInfo::C::Opt::CRef aUnwrapKeyProp)
{
    if (aUnwrapKeyProp.has_value())
    {
        if (&aPropInfo == &aUnwrapKeyProp.value().get())
        {
            return;
        }
    }

    const GpType::EnumT propType = aPropInfo.Type();
    std::string_view    propName = aPropInfo.Name();

    //Element name
    std::string elementName("e"_sv);
    auto        elementNameByFlag = aPropInfo.FlagArg(GpTypePropFlag::CONTAINER_ELEMENT_NAME);

    if (elementNameByFlag.has_value())
    {
        elementName = elementNameByFlag.value();
    }

    //Find Xml member
    const tinyxml2::XMLElement* currentXmlElement = nullptr;

    if (   (aPropInfo.FlagTest(GpTypePropFlag::UNWRAP_CONTAINER))
        && (propType == GpType::STRUCT_SP))
    {
        THROW_GPE_COND
        (
            aUnwrapKeyProp.has_value() == false,
            "Sequential unwrap are unsupported"_sv
        );
    } else
    {
        const tinyxml2::XMLElement* propXmlElementPtr = aXmlElement.FirstChildElement(propName.data());

        if (propXmlElementPtr == nullptr)
        {
            return;
        }

        currentXmlElement = propXmlElementPtr->FirstChildElement(elementName.data());
    }

    switch (propType)
    {
        case GpType::U_INT_8:
        {
            auto& container = ValGetter::UInt8(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<u_int_8>(StrOps::SToUI64(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::S_INT_8:
        {
            auto& container = ValGetter::SInt8(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<s_int_8>(StrOps::SToSI64(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::U_INT_16:
        {
            auto& container = ValGetter::UInt16(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<u_int_16>(StrOps::SToUI64(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::S_INT_16:
        {
            auto& container = ValGetter::SInt16(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<s_int_16>(StrOps::SToSI64(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::U_INT_32:
        {
            auto& container = ValGetter::UInt32(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<u_int_32>(StrOps::SToUI64(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::S_INT_32:
        {
            auto& container = ValGetter::SInt32(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<s_int_32>(StrOps::SToSI64(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::U_INT_64:
        {
            auto& container = ValGetter::UInt64(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<u_int_64>(StrOps::SToUI64(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::S_INT_64:
        {
            auto& container = ValGetter::SInt64(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<s_int_64>(StrOps::SToSI64(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::UNIX_TS_S:
        {
            auto& container = ValGetter::SInt64(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
                {
                    Inserter::SInsert(container, NumOps::SConvert<s_int_64>(GpDateTimeOps::SUnixTsFromStr_s(elementText, GpDateTimeFormat::STD_DATE_TIME).Value()));
                } else
                {
                    Inserter::SInsert(container, NumOps::SConvert<s_int_64>(StrOps::SToSI64(elementText)));
                }
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::UNIX_TS_MS:
        {
            auto& container = ValGetter::SInt64(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
                {
                    Inserter::SInsert(container, NumOps::SConvert<s_int_64>(GpDateTimeOps::SUnixTsFromStr_ms(elementText, GpDateTimeFormat::STD_DATE_TIME).Value()));
                } else
                {
                    Inserter::SInsert(container, NumOps::SConvert<s_int_64>(StrOps::SToSI64(elementText)));
                }
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::DOUBLE:
        {
            auto& container = ValGetter::Double(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<double>(StrOps::SToDouble_fast(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::FLOAT:
        {
            auto& container = ValGetter::Float(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, NumOps::SConvert<float>(StrOps::SToDouble_fast(elementText)));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::BOOLEAN:
        {
            auto& container = ValGetter::Bool(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container,elementText == "true"_sv);
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::UUID:
        {
            auto& container = ValGetter::UUID(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, GpUUID::SFromString(elementText));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::STRING:
        {
            auto& container = ValGetter::String(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, std::string(elementText));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::BLOB:
        {
            auto& container = ValGetter::BLOB(aStruct, aPropInfo);

            while (currentXmlElement != nullptr)
            {
                std::string_view elementText = StrOps::SFromChar(currentXmlElement->GetText());
                Inserter::SInsert(container, StrOps::SToBytesHex(elementText));
                currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
            }
        } break;
        case GpType::STRUCT:
        {
            THROW_GPE("Arrays of struct are not supported, use arrays of struct::SP instead"_sv);
        } break;
        case GpType::STRUCT_SP:
        {
            auto& container = ValGetter::StructSP(aStruct, aPropInfo);

            const GpTypeStructInfo& typeInfoBase = GpTypeManager::S().Find(aPropInfo.TypeUID()).value();

            if (aPropInfo.FlagTest(GpTypePropFlag::UNWRAP_CONTAINER))
            {
                THROW_GPE_COND
                (
                    aUnwrapKeyProp.has_value() == false,
                    "Sequential unwrap are unsupported"_sv
                );

                const GpTypePropInfo& unwrapKeyPropInfo = aPropInfo.UnwrapContainerKeyProp();

                GpSet<std::string_view> unwrapKeyValues;
                {
                    const tinyxml2::XMLElement* xmlElementPtr = aXmlElement.FirstChildElement();

                    while (xmlElementPtr != nullptr)
                    {
                        std::string_view attrVal = StrOps::SFromChar(xmlElementPtr->Attribute(unwrapKeyPropInfo.Name().data()));
                        if (attrVal.length() > 0)
                        {
                            unwrapKeyValues.insert(attrVal);
                        }

                        xmlElementPtr = xmlElementPtr->NextSiblingElement();
                    }
                }

                for (std::string_view unwrapKeyValue: unwrapKeyValues)
                {
                    GpTypeStructBase::SP structBaseSP = typeInfoBase.NewInstance();
                    GpXmlToStruct::SReadStruct(structBaseSP.Vn(), aXmlElement, aFlags, unwrapKeyPropInfo, unwrapKeyValue);

                    unwrapKeyPropInfo.Value_String(structBaseSP.Vn()) = std::string(unwrapKeyValue);

                    Inserter::SInsert(container, std::move(structBaseSP));
                }
            } else
            {
                while (currentXmlElement != nullptr)
                {
                    const GpTypeStructInfo& typeInfoXml = GpXmlToStruct::SCheckTypeInfo
                    (
                        *currentXmlElement,
                        typeInfoBase,
                        GpXmlToStruct::CheckMode::CAN_BE_DERIVED
                    );
                    GpTypeStructBase::SP structBaseSP = typeInfoXml.NewInstance();
                    GpXmlToStruct::SReadStruct(structBaseSP.Vn(), *currentXmlElement, aFlags, std::nullopt, ""_sv);

                    Inserter::SInsert(container, std::move(structBaseSP));

                    currentXmlElement = currentXmlElement->NextSiblingElement(elementName.data());
                }
            }
        } break;
        case GpType::ENUM:
        {
            THROW_GPE("Arrays of enums are not supported"_sv);
        } break;
        case GpType::ENUM_FLAGS:
        {
            THROW_GPE("Arrays of enum flags are not supported"_sv);
        } break;
        case GpType::NOT_SET:
        {
            THROW_GPE("Type "_sv + GpType::SToString(aPropInfo.Type()));
        } break;
        default:
        {
            THROW_GPE("Unsupported type "_sv + GpType::SToString(aPropInfo.Type()));
        }
    }
}

void    GpXmlToStruct::SParseXmlDom (GpRawPtrCharR          aXmlData,
                                     tinyxml2::XMLDocument& aXmlDocOut)
{
    tinyxml2::XMLError error = aXmlDocOut.Parse(aXmlData.Ptr(), aXmlData.CountLeft().As<size_t>());

    //Check for errors
    THROW_GPE_COND
    (
        error == tinyxml2::XMLError::XML_SUCCESS,
        "Xml parse error: "_sv + aXmlDocOut.ErrorName() + ", at line "_sv + aXmlDocOut.ErrorLineNum()
    );
}

void    GpXmlToStruct::SReadStruct (GpTypeStructBase&               aStruct,
                                    const tinyxml2::XMLElement&     aXmlElement,
                                    const GpXmlMapperFlags          aFlags,
                                    GpTypePropInfo::C::Opt::CRef    aUnwrapKeyProp,
                                    std::string_view                aUnwrapKeyValue)
{
    const GpTypeStructInfo& typeInfo    = aStruct.TypeInfo();
    const auto&             props       = typeInfo.Props();

    for (const GpTypePropInfo& propInfo: props)
    {
        const GpTypeContainer::EnumT containerType = propInfo.Container();
        try
        {
            if (containerType == GpTypeContainer::NO)
            {
                SReadValue(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp, aUnwrapKeyValue);
            } else if (containerType == GpTypeContainer::VECTOR)
            {
                SReadValueVec(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            } else if (containerType == GpTypeContainer::LIST)
            {
                SReadValueList(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            } else if (containerType == GpTypeContainer::SET)
            {
                SReadValueSet(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            } else if (containerType == GpTypeContainer::MAP)
            {
                SReadValueMap(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            }
        } catch (const std::exception& e)
        {
            THROW_GPE("Failed to read value from Xml. Struct "_sv + typeInfo.Name() + "."_sv + propInfo.Name() + "\nReason:\n"_sv + e.what());
        } catch (...)
        {
            THROW_GPE("Failed to read value from Xml. Struct "_sv + typeInfo.Name() + "."_sv + propInfo.Name() + "\nReason:\nUnknown exception"_sv);
        }
    }
}

const GpTypeStructInfo& GpXmlToStruct::SCheckTypeInfo (const tinyxml2::XMLElement&  aXmlElement,
                                                       const GpTypeStructInfo&      aTypeInfoBase,
                                                       const CheckMode              aCheckMode)
{
    FindTypeInfoResT findRes = SFindTypeInfo(aXmlElement);

    if (findRes.has_value())
    {
        const GpTypeStructInfo& typeInfoXml = findRes.value().get();
        if (aTypeInfoBase.UID() != typeInfoXml.UID())
        {
            if (aCheckMode == CheckMode::MUST_BE_EQUAL)
            {
                THROW_GPE("Struct UID`s in Xml and in c++ must be equal. But c++ struct UID "_sv + aTypeInfoBase.UID().ToString()
                          + " and Xml struct UID "_sv + typeInfoXml.UID().ToString());
            } else if (GpTypeManager::S().IsBaseOf(aTypeInfoBase.UID(), typeInfoXml.UID()) == false)
            {
                THROW_GPE("Struct with UID "_sv + aTypeInfoBase.UID().ToString()
                          + " must be base of struct with UID "_sv + typeInfoXml.UID().ToString());
            }
        }

        return typeInfoXml;
    } else
    {
        return aTypeInfoBase;
    }
}

GpXmlToStruct::FindTypeInfoResT GpXmlToStruct::SFindTypeInfo (const tinyxml2::XMLElement& aXmlElement)
{
    //Detect type struct info
    const char* attrVal = aXmlElement.Attribute("@");

    if (attrVal == nullptr)
    {
        return std::nullopt;
    }

    //Get struct uid
    const GpUUID structUID = GpUUID::SFromString(std::string_view(attrVal));

    //Find struct info by uid
    const auto structUidOpt = GpTypeManager::S().Find(structUID);

    THROW_GPE_COND(structUidOpt.has_value(), "Struct info was not found by uid = '"_sv + structUID.ToString() + "'"_sv);

     return structUidOpt.value();
}

void    GpXmlToStruct::SReadValue (GpTypeStructBase&            aStruct,
                                   const GpTypePropInfo&        aPropInfo,
                                   const tinyxml2::XMLElement&  aXmlElement,
                                   const GpXmlMapperFlags       aFlags,
                                   GpTypePropInfo::C::Opt::CRef aUnwrapKeyProp,
                                   std::string_view             aUnwrapKeyValue)
{
    const GpType::EnumT propType = aPropInfo.Type();
    std::string_view    propName = aPropInfo.Name();

    //Find Xml member
    const tinyxml2::XMLElement* propXmlElementPtr = aXmlElement.FirstChildElement(propName.data());

    if (aUnwrapKeyProp.has_value())
    {
        if (&aPropInfo == &aUnwrapKeyProp.value().get())
        {
            return;
        }

        bool found = false;
        while (propXmlElementPtr != nullptr)
        {
            std::string_view attrVal = StrOps::SFromChar(propXmlElementPtr->Attribute(aUnwrapKeyProp.value().get().Name().data()));
            if (attrVal == aUnwrapKeyValue)
            {
                found = true;
                break;
            }

            propXmlElementPtr = propXmlElementPtr->NextSiblingElement(propName.data());
        }

        if (!found)
        {
            return;
        }
    } else
    {
        propXmlElementPtr = aXmlElement.FirstChildElement(propName.data());

        if (propXmlElementPtr == nullptr)
        {
            return;
        }
    }

    const tinyxml2::XMLElement& propXmlElement      = *propXmlElementPtr;
    std::string_view            propXmlElementText  = StrOps::SFromChar(propXmlElement.GetText());

    switch (propType)
    {
        case GpType::U_INT_8:
        {
            aPropInfo.Value_UInt8(aStruct) = NumOps::SConvert<u_int_8>(StrOps::SToUI64(propXmlElementText));
        } break;
        case GpType::S_INT_8:
        {
            aPropInfo.Value_UInt8(aStruct) = NumOps::SConvert<s_int_8>(StrOps::SToSI64(propXmlElementText));
        } break;
        case GpType::U_INT_16:
        {
            aPropInfo.Value_UInt16(aStruct) = NumOps::SConvert<u_int_16>(StrOps::SToUI64(propXmlElementText));
        } break;
        case GpType::S_INT_16:
        {
            aPropInfo.Value_UInt16(aStruct) = NumOps::SConvert<s_int_16>(StrOps::SToSI64(propXmlElementText));
        } break;
        case GpType::U_INT_32:
        {
            aPropInfo.Value_UInt32(aStruct) = NumOps::SConvert<u_int_32>(StrOps::SToUI64(propXmlElementText));
        } break;
        case GpType::S_INT_32:
        {
            aPropInfo.Value_UInt32(aStruct) = NumOps::SConvert<s_int_32>(StrOps::SToSI64(propXmlElementText));
        } break;
        case GpType::U_INT_64:
        {
            aPropInfo.Value_UInt64(aStruct) = NumOps::SConvert<u_int_64>(StrOps::SToUI64(propXmlElementText));
        } break;
        case GpType::S_INT_64:
        {
            aPropInfo.Value_UInt64(aStruct) = NumOps::SConvert<s_int_64>(StrOps::SToSI64(propXmlElementText));
        } break;
        case GpType::UNIX_TS_S:
        {
            if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
            {
                aPropInfo.Value_UInt64(aStruct) = NumOps::SConvert<s_int_64>(GpDateTimeOps::SUnixTsFromStr_s(propXmlElementText, GpDateTimeFormat::STD_DATE_TIME).Value());
            } else
            {
                aPropInfo.Value_UInt64(aStruct) = NumOps::SConvert<s_int_64>(StrOps::SToSI64(propXmlElementText));
            }
        } break;
        case GpType::UNIX_TS_MS:
        {
            if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
            {
                aPropInfo.Value_UInt64(aStruct) = NumOps::SConvert<s_int_64>(GpDateTimeOps::SUnixTsFromStr_ms(propXmlElementText, GpDateTimeFormat::STD_DATE_TIME).Value());
            } else
            {
                aPropInfo.Value_UInt64(aStruct) = NumOps::SConvert<s_int_64>(StrOps::SToSI64(propXmlElementText));
            }
        } break;
        case GpType::DOUBLE:
        {
            aPropInfo.Value_Double(aStruct) = NumOps::SConvert<double>(StrOps::SToDouble_fast(propXmlElementText));
        } break;
        case GpType::FLOAT:
        {
            aPropInfo.Value_Float(aStruct) = NumOps::SConvert<float>(StrOps::SToDouble_fast(propXmlElementText));
        } break;
        case GpType::BOOLEAN:
        {
            aPropInfo.Value_Bool(aStruct) = (propXmlElementText == "true"_sv);
        } break;
        case GpType::UUID:
        {
            aPropInfo.Value_UUID(aStruct) = GpUUID::SFromString(propXmlElementText);
        } break;
        case GpType::STRING:
        {
            aPropInfo.Value_String(aStruct) = std::string(propXmlElementText);
        } break;
        case GpType::BLOB:
        {
            GpRawPtrCharR strPtr(propXmlElementText);
            aPropInfo.Value_BLOB(aStruct) = StrOps::SToBytesHex(strPtr);
        } break;
        case GpType::STRUCT:
        {
            GpTypeStructBase& structBase = aPropInfo.Value_Struct(aStruct);
            SReadStruct(structBase, propXmlElement, aFlags, std::nullopt, ""_sv);
        } break;
        case GpType::STRUCT_SP:
        {
            GpTypeStructBase::SP&   structBaseSP    = aPropInfo.Value_StructSP(aStruct);
            const GpTypeStructInfo& typeInfoBase    = GpTypeManager::S().Find(aPropInfo.TypeUID()).value();
            const GpTypeStructInfo& typeInfoXml     = GpXmlToStruct::SCheckTypeInfo(propXmlElement, typeInfoBase, GpXmlToStruct::CheckMode::CAN_BE_DERIVED);
                                    structBaseSP    = typeInfoXml.NewInstance();
            GpTypeStructBase&       structBase      = structBaseSP.Vn();
            SReadStruct(structBase, propXmlElement, aFlags, std::nullopt, ""_sv);
        } break;
        case GpType::ENUM:
        {
            aPropInfo.Value_Enum(aStruct).FromString(propXmlElementText);
        } break;
        case GpType::ENUM_FLAGS:
        {
            THROW_GPE("Unsupported type "_sv + GpType::SToString(aPropInfo.Type()));
        } break;
        case GpType::NOT_SET:
        {
            THROW_GPE("Type "_sv + GpType::SToString(aPropInfo.Type()));
        } break;
        default:
        {
            THROW_GPE("Unsupported type "_sv + GpType::SToString(aPropInfo.Type()));
        }
    }
}

void    GpXmlToStruct::SReadValueVec (GpTypeStructBase&             aStruct,
                                      const GpTypePropInfo&         aPropInfo,
                                      const tinyxml2::XMLElement&   aXmlElement,
                                      const GpXmlMapperFlags        aFlags,
                                      GpTypePropInfo::C::Opt::CRef  aUnwrapKeyProp)
{
    _ProcessContainer<_InserterVec, GpTypePropInfoGetter_Vec>(aStruct, aPropInfo, aXmlElement, aFlags, aUnwrapKeyProp);
}

void    GpXmlToStruct::SReadValueList (GpTypeStructBase&            aStruct,
                                        const GpTypePropInfo&       aPropInfo,
                                       const tinyxml2::XMLElement&  aXmlElement,
                                       const GpXmlMapperFlags       aFlags,
                                       GpTypePropInfo::C::Opt::CRef aUnwrapKeyProp)
{
    _ProcessContainer<_InserterList, GpTypePropInfoGetter_List>(aStruct, aPropInfo, aXmlElement, aFlags, aUnwrapKeyProp);
}

void    GpXmlToStruct::SReadValueSet (GpTypeStructBase&             aStruct,
                                      const GpTypePropInfo&         aPropInfo,
                                      const tinyxml2::XMLElement&   aXmlElement,
                                      const GpXmlMapperFlags        aFlags,
                                      GpTypePropInfo::C::Opt::CRef  aUnwrapKeyProp)
{
    _ProcessContainer<_InserterSet, GpTypePropInfoGetter_Set>(aStruct, aPropInfo, aXmlElement, aFlags, aUnwrapKeyProp);
}

void    GpXmlToStruct::SReadValueMap (GpTypeStructBase&             /*aStruct*/,
                                      const GpTypePropInfo&         /*aPropInfo*/,
                                      const tinyxml2::XMLElement&   /*aXmlElement*/,
                                      const GpXmlMapperFlags        /*aFlags*/,
                                      GpTypePropInfo::C::Opt::CRef  /*aUnwrapKeyProp*/)
{
    //TODO: implement
    THROW_GPE_NOT_IMPLEMENTED();
}

}//namespace GPlatform
