#include "GpXmlFromStruct.hpp"

#include <iostream>

namespace GPlatform {

template<typename ValGetter>
void    _ProcessContainer
(
    const GpTypeStructBase&         aStruct,
    const GpTypePropInfo&           aPropInfo,
    tinyxml2::XMLElement&           aXmlElement,
    const GpXmlMapperFlags          aFlags,
    GpTypePropInfo::C::Opt::CRef    aUnwrapKeyProp
)
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

    tinyxml2::XMLElement& valElement = *aXmlElement.InsertNewChildElement(propName.data());

    std::string elementName("e"_sv);
    auto        elementNameByFlag = aPropInfo.FlagArg(GpTypePropFlag::CONTAINER_ELEMENT_NAME);

    if (elementNameByFlag.has_value())
    {
        elementName = elementNameByFlag.value();
    }

    switch (propType)
    {
        case GpType::U_INT_8:
        {
            auto& container = ValGetter::UInt8(aStruct, aPropInfo);

            for (const u_int_8 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(u_int_64(e));

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::S_INT_8:
        {
            auto& container = ValGetter::SInt8(aStruct, aPropInfo);

            for (const s_int_8 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(s_int_64(e));

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::U_INT_16:
        {
            auto& container = ValGetter::UInt16(aStruct, aPropInfo);

            for (const u_int_16 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(u_int_64(e));

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::S_INT_16:
        {
            auto& container = ValGetter::SInt16(aStruct, aPropInfo);

            for (const s_int_16 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(s_int_64(e));

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::U_INT_32:
        {
            auto& container = ValGetter::UInt32(aStruct, aPropInfo);

            for (const u_int_32 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(u_int_64(e));

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::S_INT_32:
        {
            auto& container = ValGetter::SInt32(aStruct, aPropInfo);

            for (const s_int_32 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(s_int_64(e));

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::U_INT_64:
        {
            auto& container = ValGetter::UInt64(aStruct, aPropInfo);

            for (const u_int_64 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(u_int_64(e));

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::S_INT_64:
        {
            auto& container = ValGetter::SInt64(aStruct, aPropInfo);

            for (const s_int_64 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(s_int_64(e));

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::UNIX_TS_S:
        {
            auto& container = ValGetter::SInt64(aStruct, aPropInfo);

            for (const s_int_64 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());

                if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
                {
                    xmlE.SetText(GpDateTimeOps::SUnixTsToStr(unix_ts_s_t::SMake(e), GpDateTimeFormat::STD_DATE_TIME).data());
                } else
                {
                    xmlE.SetText(s_int_64(e));
                }

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::UNIX_TS_MS:
        {
            auto& container = ValGetter::SInt64(aStruct, aPropInfo);

            for (const s_int_64 e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());

                if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
                {
                    xmlE.SetText(GpDateTimeOps::SUnixTsToStr(unix_ts_ms_t::SMake(e), GpDateTimeFormat::STD_DATE_TIME).data());
                } else
                {
                    xmlE.SetText(s_int_64(e));
                }

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::DOUBLE:
        {
            auto& container = ValGetter::Double(aStruct, aPropInfo);

            for (const double e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(e);

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::FLOAT:
        {
            auto& container = ValGetter::Float(aStruct, aPropInfo);

            for (const float e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(e);

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::BOOLEAN:
        {
            auto& container = ValGetter::Bool(aStruct, aPropInfo);

            for (const bool e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(e);

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::UUID:
        {
            auto& container = ValGetter::UUID(aStruct, aPropInfo);

            for (const GpUUID& e: container)
            {
                const std::string       s   = e.ToString();
                tinyxml2::XMLElement&   xmlE= *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(s.data());

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::STRING:
        {
            auto& container = ValGetter::String(aStruct, aPropInfo);

            for (const std::string& e: container)
            {
                tinyxml2::XMLElement& xmlE = *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(e.data());

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::BLOB:
        {
            auto& container = ValGetter::BLOB(aStruct, aPropInfo);

            for (const GpBytesArray& e: container)
            {
                const std::string       s   = StrOps::SFromBytes(e);
                tinyxml2::XMLElement&   xmlE= *valElement.InsertNewChildElement(elementName.data());
                xmlE.SetText(s.data());

                if (aUnwrapKeyProp.has_value())
                {
                    GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                }
            }
        } break;
        case GpType::STRUCT:
        {
            THROW_GPE("Arrays of struct are not supported, use arrays of struct::SP instead"_sv);
        } break;
        case GpType::STRUCT_SP:
        {
            auto& container = ValGetter::StructSP(aStruct, aPropInfo);

            if (aPropInfo.FlagTest(GpTypePropFlag::UNWRAP_CONTAINER))
            {
                THROW_GPE_COND_CHECK_M
                (
                    aUnwrapKeyProp.has_value() == false,
                    "Sequential unwrap are unsupported"_sv
                );

                const GpTypePropInfo& unwrapKeyPropInfo = aPropInfo.UnwrapContainerKeyProp();

                aXmlElement.DeleteChild(&valElement);

                for (const GpTypeStructBase::SP& e: container)
                {
                    if (e.IsNULL())
                    {
                        //NOP
                    } else
                    {
                        const GpTypeStructBase& structBase = e.VCn();
                        GpXmlFromStruct::SWrite(structBase, aXmlElement, aFlags, unwrapKeyPropInfo);
                    }                   
                }
            } else
            {
                for (const GpTypeStructBase::SP& e: container)
                {
                    tinyxml2::XMLElement& xmlE= *valElement.InsertNewChildElement(elementName.data());

                    if (e.IsNULL())
                    {
                        //NOP
                    } else
                    {
                        const GpTypeStructBase& structBase  = e.VCn();
                        GpXmlFromStruct::SWrite(structBase, xmlE, aFlags, std::nullopt);
                    }

                    if (aUnwrapKeyProp.has_value())
                    {
                        GpXmlFromStruct::SWriteAttr(aStruct, aUnwrapKeyProp.value(), xmlE, aFlags);
                    }
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

template<typename T>
void    _ProcessMapVal
(
    tinyxml2::XMLElement&   /*aXmlElement*/,
    const T&                /*aValue*/,
    const GpXmlMapperFlags  /*aFlags*/
)
{
    /*constexpr const GpType::EnumT type = GpTypeUtils::SDetectType<T>();

    if constexpr (type == GpType::U_INT_8)
    {
        aJValOut.SetUint64(aValue);
    } else if constexpr (type == GpType::S_INT_8)
    {
        aJValOut.SetInt64(aValue);
    } else if constexpr (type == GpType::U_INT_16)
    {
        aJValOut.SetUint64(aValue);
    } else if constexpr (type == GpType::S_INT_16)
    {
        aJValOut.SetInt64(aValue);
    } else if constexpr (type == GpType::U_INT_32)
    {
        aJValOut.SetUint64(aValue);
    } else if constexpr (type == GpType::S_INT_32)
    {
        aJValOut.SetInt64(aValue);
    } else if constexpr (type == GpType::U_INT_64)
    {
        aJValOut.SetUint64(aValue);
    } else if constexpr (type == GpType::S_INT_64)
    {
        aJValOut.SetInt64(aValue);
    } else if constexpr (type == GpType::DOUBLE)
    {
        aJValOut.SetDouble(aValue);
    } else if constexpr (type == GpType::FLOAT)
    {
        aJValOut.SetDouble(double(aValue));
    } else if constexpr (type == GpType::BOOLEAN)
    {
        aJValOut.SetBool(aValue);
    } else if constexpr (type == GpType::UUID)
    {
        const std::string s = aValue.ToString();
        aJValOut.SetString(s.data(), NumOps::SConvert<tinyxml2::SizeType>(s.length()));
    } else if constexpr (type == GpType::STRING)
    {
        aJValOut.SetString(aValue.data(), NumOps::SConvert<tinyxml2::SizeType>(aValue.length()));
    } else if constexpr (type == GpType::BLOB)
    {
        const std::string s = StrOps::SFromBytes(aValue);
        aJValOut.SetString(s.data(), NumOps::SConvert<tinyxml2::SizeType>(s.length()));
    } else if constexpr (type == GpType::STRUCT)
    {
        THROW_GPE("Struct are not supported, use arrays of struct::SP instead"_sv);
    } else if constexpr (type == GpType::STRUCT_SP)
    {
        if (aValue.IsNULL())
        {
            aJValOut.SetNull();
        } else
        {
            const GpTypeStructBase& structBase  = aValue.VCn();
            tinyxml2::XMLElement&   obj         = aJValOut.SetObject();
            GpXmlFromStruct::SWrite(structBase, obj, aFlags);
        }
    } else if constexpr (type == GpType::ENUM)
    {
        THROW_GPE("Enums are not supported"_sv);
    } else if constexpr (type == GpType::ENUM_FLAGS)
    {
        THROW_GPE("Enums flags are not supported"_sv);
    } else
    {
        GpThrowCe<std::out_of_range>("Unknown type '"_sv + GpTypeUtils::STypeName<T>() + "'"_sv);
    }*/
}

template<typename KeyT,
         typename CT>
void    _ProcessMapContainer (const CT&                 /*aContainer*/,
                              tinyxml2::XMLElement&     /*aXmlMap*/,
                              const GpXmlMapperFlags    /*aFlags*/)
{
    /*const GpType::EnumT propType = aPropInfo.Type();
    std::string_view    propName = aPropInfo.Name();

    tinyxml2::XMLElement& valElement = *aXmlElement.InsertNewChildElement(propName.data());

    std::string elementName("e"_sv);
    auto        elementNameByFlag = aPropInfo.FlagArg(GpTypePropFlag::CONTAINER_ELEMENT_NAME);

    if (elementNameByFlag.has_value())
    {
        elementName = elementNameByFlag.value();
    }*/

    /*for (const auto&[k, v]: aContainer)
    {
        tinyxml2::XMLElement& xmlE = *aXmlMap.InsertNewChildElement(elementName.data());
            xmlE.SetText(e.data());
        }

        //Key
        tinyxml2::Value jMapElementKey;
        _ProcessMapVal(jMapElementKey, k, aFlags);

        //Value
        tinyxml2::Value jMapElementVal;
        _ProcessMapVal(jMapElementVal, v, aFlags);

        tinyxml2::Value jMapElement;
        aXmlMap.AddMember(jMapElementKey.Move(), jMapElementVal.Move());
    }*/
}

template<typename                       Key,
         template<typename...> class    ValGetter>
void    _ProcessMap (const GpTypeStructBase&    aStruct,
                     const GpTypePropInfo&      aPropInfo,
                     tinyxml2::XMLElement&      aXmlElement,
                     const GpXmlMapperFlags     aFlags)
{
    const GpType::EnumT propType = aPropInfo.Type();

    switch (propType)
    {
        case GpType::U_INT_8:
        {
            auto& container = ValGetter<Key>::UInt8(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::S_INT_8:
        {
            auto& container = ValGetter<Key>::SInt8(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::U_INT_16:
        {
            auto& container = ValGetter<Key>::UInt16(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::S_INT_16:
        {
            auto& container = ValGetter<Key>::SInt16(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::U_INT_32:
        {
            auto& container = ValGetter<Key>::UInt32(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::S_INT_32:
        {
            auto& container = ValGetter<Key>::SInt32(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::U_INT_64:
        {
            auto& container = ValGetter<Key>::UInt64(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::S_INT_64:   [[fallthrough]];
        case GpType::UNIX_TS_S:  [[fallthrough]];
        case GpType::UNIX_TS_MS:
        {
            auto& container = ValGetter<Key>::SInt64(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::DOUBLE:
        {
            auto& container = ValGetter<Key>::Double(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::FLOAT:
        {
            auto& container = ValGetter<Key>::Float(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::BOOLEAN:
        {
            auto& container = ValGetter<Key>::Bool(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::UUID:
        {
            auto& container = ValGetter<Key>::UUID(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::STRING:
        {
            auto& container = ValGetter<Key>::String(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::BLOB:
        {
            auto& container = ValGetter<Key>::BLOB(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::STRUCT:
        {
            THROW_GPE("struct as map value are not supported, use struct::SP instead"_sv);
        } break;
        case GpType::STRUCT_SP:
        {
            auto& container = ValGetter<Key>::StructSP(aStruct, aPropInfo);
            _ProcessMapContainer<Key>(container, aXmlElement, aFlags);
        } break;
        case GpType::ENUM:
        {
            THROW_GPE("enums are not supported"_sv);
        } break;
        case GpType::ENUM_FLAGS:
        {
            THROW_GPE("enums flags are not supported"_sv);
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

std::string GpXmlFromStruct::SToString (const tinyxml2::XMLDocument& aXmlDOM)
{
    tinyxml2::XMLPrinter printer;
    aXmlDOM.Print(&printer);

    std::string s(printer.CStr(), NumOps::SSub<size_t>(printer.CStrSize(), 1));

    // !!!!!!!!!!!!!!! bug of feature
    //If in print to memory mode, return the size
    //of the XML file in memory. (Note the size returned
    //includes the terminating null

    //int c = s.at(s.length() - 1);
    //std::cout << "[GpXmlFromStruct::SToString]: '"_sv << s << "'"_sv << std::endl;
    //std::cout << "[GpXmlFromStruct::SToString]: c = "_sv << c << std::endl;

    return s;
}

void    GpXmlFromStruct::SToString
(
    const tinyxml2::XMLDocument&    aXmlDOM,
    GpByteWriter&                   aWriter
)
{
    aWriter.Bytes(SToString(aXmlDOM));
}

void    GpXmlFromStruct::SWrite
(
    const GpTypeStructBase&         aStruct,
    tinyxml2::XMLElement&           aXmlElement,
    const GpXmlMapperFlags          aFlags,
    GpTypePropInfo::C::Opt::CRef    aUnwrapKeyProp
)
{
    const GpTypeStructInfo& typeInfo    = aStruct.TypeInfo();
    const auto&             props       = typeInfo.Props();

    if (aFlags.Test(GpXmlMapperFlag::WRITE_STRUCT_UID))
    {
        const std::string structUidStr = typeInfo.UID().ToString();
        aXmlElement.SetAttribute("@", structUidStr.data());
    }

    for (const GpTypePropInfo& propInfo: props)
    {
        const GpTypeContainer::EnumT containerType = propInfo.Container();

        try
        {
            if (containerType == GpTypeContainer::NO)
            {
                SWriteValue(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            } else if (containerType == GpTypeContainer::VECTOR)
            {
                SWriteValueVec(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            } else if (containerType == GpTypeContainer::LIST)
            {
                SWriteValueList(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            } else if (containerType == GpTypeContainer::SET)
            {
                SWriteValueSet(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            } else if (containerType == GpTypeContainer::MAP)
            {
                SWriteValueMap(aStruct, propInfo, aXmlElement, aFlags, aUnwrapKeyProp);
            }
        } catch (const std::exception& e)
        {
            THROW_GPE("Failed to write value to Xml. Struct "_sv + typeInfo.Name() + "."_sv + propInfo.Name() + "\nReason:\n"_sv + e.what());
        } catch (...)
        {
            THROW_GPE("Failed to write value to Xml. Struct "_sv + typeInfo.Name() + "."_sv + propInfo.Name() + "\nReason:\nUnknown exception"_sv);
        }
    }
}

void    GpXmlFromStruct::SWriteAttr (const GpTypeStructBase&    aStruct,
                                     const GpTypePropInfo&      aPropInfo,
                                     tinyxml2::XMLElement&      aXmlElement,
                                     const GpXmlMapperFlags     aFlags)
{
    const GpType::EnumT propType = aPropInfo.Type();
    std::string_view    propName = aPropInfo.Name();

    switch (propType)
    {
        case GpType::U_INT_8:
        {
            aXmlElement.SetAttribute(propName.data(), u_int_64(aPropInfo.Value_UInt8(aStruct)));
        } break;
        case GpType::S_INT_8:
        {
            aXmlElement.SetAttribute(propName.data(), s_int_64(aPropInfo.Value_SInt8(aStruct)));
        } break;
        case GpType::U_INT_16:
        {
            aXmlElement.SetAttribute(propName.data(), u_int_64(aPropInfo.Value_UInt16(aStruct)));
        } break;
        case GpType::S_INT_16:
        {
            aXmlElement.SetAttribute(propName.data(), s_int_64(aPropInfo.Value_SInt16(aStruct)));
        } break;
        case GpType::U_INT_32:
        {
            aXmlElement.SetAttribute(propName.data(), u_int_64(aPropInfo.Value_UInt32(aStruct)));
        } break;
        case GpType::S_INT_32:
        {
            aXmlElement.SetAttribute(propName.data(), s_int_64(aPropInfo.Value_SInt32(aStruct)));
        } break;
        case GpType::U_INT_64:
        {
            aXmlElement.SetAttribute(propName.data(), u_int_64(aPropInfo.Value_UInt64(aStruct)));
        } break;
        case GpType::S_INT_64:
        {
            aXmlElement.SetAttribute(propName.data(), s_int_64(aPropInfo.Value_SInt64(aStruct)));
        } break;
        case GpType::UNIX_TS_S:
        {
            const s_int_64 v = s_int_64(aPropInfo.Value_SInt64(aStruct));

            if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
            {
                aXmlElement.SetAttribute(propName.data(), GpDateTimeOps::SUnixTsToStr(unix_ts_s_t::SMake(v), GpDateTimeFormat::STD_DATE_TIME).data());
            } else
            {
                aXmlElement.SetAttribute(propName.data(), v);
            }
        } break;
        case GpType::UNIX_TS_MS:
        {
            const s_int_64 v = s_int_64(aPropInfo.Value_SInt64(aStruct));

            if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
            {
                aXmlElement.SetAttribute(propName.data(), GpDateTimeOps::SUnixTsToStr(unix_ts_ms_t::SMake(v), GpDateTimeFormat::STD_DATE_TIME).data());
            } else
            {
                aXmlElement.SetAttribute(propName.data(), v);
            }
        } break;
        case GpType::DOUBLE:
        {
            aXmlElement.SetAttribute(propName.data(), aPropInfo.Value_Double(aStruct));
        } break;
        case GpType::FLOAT:
        {
            aXmlElement.SetAttribute(propName.data(), aPropInfo.Value_Float(aStruct));
        } break;
        case GpType::BOOLEAN:
        {
            aXmlElement.SetAttribute(propName.data(), aPropInfo.Value_Bool(aStruct));
        } break;
        case GpType::UUID:
        {
            const std::string propVal = aPropInfo.Value_UUID(aStruct).ToString();
            aXmlElement.SetAttribute(propName.data(), propVal.data());
        } break;
        case GpType::STRING:
        {
            const std::string& propVal = aPropInfo.Value_String(aStruct);
            aXmlElement.SetAttribute(propName.data(), propVal.data());
        } break;
        case GpType::BLOB:
        {
            const std::string propVal = StrOps::SFromBytes(aPropInfo.Value_BLOB(aStruct));
            aXmlElement.SetAttribute(propName.data(), propVal.data());
        } break;
        case GpType::STRUCT:
        {
            THROW_GPE("Unsupported type "_sv + GpType::SToString(aPropInfo.Type()));
        } break;
        case GpType::STRUCT_SP:
        {
            THROW_GPE("Unsupported type "_sv + GpType::SToString(aPropInfo.Type()));
        } break;
        case GpType::ENUM:
        {
            std::string_view propVal = aPropInfo.Value_Enum(aStruct).ToString();
            aXmlElement.SetAttribute(propName.data(), propVal.data());
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

void    GpXmlFromStruct::SWriteValue (const GpTypeStructBase&       aStruct,
                                      const GpTypePropInfo&         aPropInfo,
                                      tinyxml2::XMLElement&         aXmlElement,
                                      const GpXmlMapperFlags        aFlags,
                                      GpTypePropInfo::C::Opt::CRef  aUnwrapKeyProp)
{
    const GpType::EnumT propType = aPropInfo.Type();
    std::string_view    propName = aPropInfo.Name();

    if (aUnwrapKeyProp.has_value())
    {
        if (&aPropInfo == &aUnwrapKeyProp.value().get())
        {
            return;
        }
    }

    tinyxml2::XMLElement& valElement = *aXmlElement.InsertNewChildElement(propName.data());

    if (aUnwrapKeyProp.has_value())
    {
        SWriteAttr(aStruct, aUnwrapKeyProp.value(), valElement, aFlags);
    }

    switch (propType)
    {
        case GpType::U_INT_8:
        {
            valElement.SetText(u_int_64(aPropInfo.Value_UInt8(aStruct)));
        } break;
        case GpType::S_INT_8:
        {
            valElement.SetText(s_int_64(aPropInfo.Value_SInt8(aStruct)));
        } break;
        case GpType::U_INT_16:
        {
            valElement.SetText(u_int_64(aPropInfo.Value_UInt16(aStruct)));
        } break;
        case GpType::S_INT_16:
        {
            valElement.SetText(s_int_64(aPropInfo.Value_SInt16(aStruct)));
        } break;
        case GpType::U_INT_32:
        {
            valElement.SetText(u_int_64(aPropInfo.Value_UInt32(aStruct)));
        } break;
        case GpType::S_INT_32:
        {
            valElement.SetText(s_int_64(aPropInfo.Value_SInt32(aStruct)));
        } break;
        case GpType::U_INT_64:
        {
            valElement.SetText(u_int_64(aPropInfo.Value_UInt64(aStruct)));
        } break;
        case GpType::S_INT_64:
        {
            valElement.SetText(s_int_64(aPropInfo.Value_SInt64(aStruct)));
        } break;
        case GpType::UNIX_TS_S:
        {
            const s_int_64 v = s_int_64(aPropInfo.Value_SInt64(aStruct));

            if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
            {
                valElement.SetText(GpDateTimeOps::SUnixTsToStr(unix_ts_s_t::SMake(v), GpDateTimeFormat::STD_DATE_TIME).data());
            } else
            {
                valElement.SetText(v);
            }
        } break;
        case GpType::UNIX_TS_MS:
        {
            const s_int_64 v = s_int_64(aPropInfo.Value_SInt64(aStruct));

            if (aFlags.Test(GpXmlMapperFlag::UNIX_TS_AS_STR))
            {
                valElement.SetText(GpDateTimeOps::SUnixTsToStr(unix_ts_ms_t::SMake(v), GpDateTimeFormat::STD_DATE_TIME).data());
            } else
            {
                valElement.SetText(v);
            }
        } break;
        case GpType::DOUBLE:
        {
            valElement.SetText(aPropInfo.Value_Double(aStruct));
        } break;
        case GpType::FLOAT:
        {
            valElement.SetText(aPropInfo.Value_Float(aStruct));
        } break;
        case GpType::BOOLEAN:
        {
            valElement.SetText(aPropInfo.Value_Bool(aStruct));
        } break;
        case GpType::UUID:
        {
            const std::string propVal = aPropInfo.Value_UUID(aStruct).ToString();
            valElement.SetText(propVal.data());
        } break;
        case GpType::STRING:
        {
            const std::string& propVal = aPropInfo.Value_String(aStruct);
            valElement.SetText(propVal.data());
        } break;
        case GpType::BLOB:
        {
            const std::string propVal = StrOps::SFromBytes(aPropInfo.Value_BLOB(aStruct));
            valElement.SetText(propVal.data());
        } break;
        case GpType::STRUCT:
        {
            const GpTypeStructBase& structBase = aPropInfo.Value_Struct(aStruct);
            SWrite(structBase, valElement, aFlags, std::nullopt);
        } break;
        case GpType::STRUCT_SP:
        {
            const GpTypeStructBase::SP& structBaseSP = aPropInfo.Value_StructSP(aStruct);

            if (structBaseSP.IsNULL())
            {
                //NOP
            } else
            {
                const GpTypeStructBase& structBase  = structBaseSP.VCn();
                SWrite(structBase, valElement, aFlags, std::nullopt);
            }
        } break;
        case GpType::ENUM:
        {
            std::string_view propVal = aPropInfo.Value_Enum(aStruct).ToString();
            valElement.SetText(propVal.data());
        } break;
        case GpType::ENUM_FLAGS:
        {
            const GpEnumFlags&          enumFlags       = aPropInfo.Value_EnumFlags(aStruct);
            GpVector<std::string_view>  enumFlagNames   = enumFlags.ToStringViewArray();

            for (std::string_view flagName: enumFlagNames)
            {
                tinyxml2::XMLElement& fe = *valElement.InsertNewChildElement("flag");
                fe.SetText(flagName.data());
            }
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

void    GpXmlFromStruct::SWriteValueVec (const GpTypeStructBase&        aStruct,
                                         const GpTypePropInfo&          aPropInfo,
                                         tinyxml2::XMLElement&          aXmlElement,
                                         const GpXmlMapperFlags         aFlags,
                                         GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp)
{
    _ProcessContainer<GpTypePropInfoGetter_Vec>(aStruct, aPropInfo, aXmlElement, aFlags, aUnwrapKeyProp);
}

void    GpXmlFromStruct::SWriteValueList (const GpTypeStructBase&       aStruct,
                                          const GpTypePropInfo&         aPropInfo,
                                          tinyxml2::XMLElement&         aXmlElement,
                                          const GpXmlMapperFlags        aFlags,
                                          GpTypePropInfo::C::Opt::CRef  aUnwrapKeyProp)
{
    _ProcessContainer<GpTypePropInfoGetter_List>(aStruct, aPropInfo, aXmlElement, aFlags, aUnwrapKeyProp);
}

void    GpXmlFromStruct::SWriteValueSet (const GpTypeStructBase&        aStruct,
                                         const GpTypePropInfo&          aPropInfo,
                                         tinyxml2::XMLElement&          aXmlElement,
                                         const GpXmlMapperFlags         aFlags,
                                         GpTypePropInfo::C::Opt::CRef   aUnwrapKeyProp)
{
    _ProcessContainer<GpTypePropInfoGetter_Set>(aStruct, aPropInfo, aXmlElement, aFlags, aUnwrapKeyProp);
}

void    GpXmlFromStruct::SWriteValueMap (const GpTypeStructBase&        /*aStruct*/,
                                         const GpTypePropInfo&          /*aPropInfo*/,
                                         tinyxml2::XMLElement&          /*aXmlElement*/,
                                         const GpXmlMapperFlags         /*aFlags*/,
                                         GpTypePropInfo::C::Opt::CRef   /*aUnwrapKeyProp*/)
{
    //TODO: implement
    THROW_NOT_IMPLEMENTED();

    /*const GpType::EnumT keyType       = aPropInfo.ContainerKeyType();
    std::string_view    propName    = aPropInfo.Name();

    tinyxml2::XMLElement& valElement = *aXmlElement.InsertNewChildElement(propName.data());

    switch (keyType)
    {
        case GpType::U_INT_8:
        {
            _ProcessMap<u_int_8, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::S_INT_8:
        {
            _ProcessMap<s_int_8, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::U_INT_16:
        {
            _ProcessMap<u_int_16, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::S_INT_16:
        {
            _ProcessMap<s_int_16, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::U_INT_32:
        {
            _ProcessMap<u_int_32, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::S_INT_32:
        {
            _ProcessMap<s_int_32, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::U_INT_64:
        {
            _ProcessMap<u_int_64, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::S_INT_64:
        {
            _ProcessMap<u_int_64, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::DOUBLE:
        {
            _ProcessMap<double, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::FLOAT:
        {
            _ProcessMap<float, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::BOOLEAN:
        {
            THROW_GPE("bool as map key are not supported"_sv);
        } break;
        case GpType::UUID:
        {
            _ProcessMap<GpUUID, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::STRING:
        {
            _ProcessMap<std::string, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::BLOB:
        {
            _ProcessMap<GpBytesArray, GpTypePropInfoGetter_Map>(aStruct, aPropInfo, valElement, aFlags);
        } break;
        case GpType::STRUCT:
        {
            THROW_GPE("struct as map key are not supported"_sv);
        } break;
        case GpType::STRUCT_SP:
        {
            THROW_GPE("struct::sp as map key are not supported"_sv);
        } break;
        case GpType::ENUM:
        {
            THROW_GPE("enums as map key are not supported"_sv);
        } break;
        case GpType::ENUM_FLAGS:
        {
            THROW_GPE("enum flags as map key are not supported"_sv);
        } break;
        case GpType::NOT_SET:
        {
            THROW_GPE("Type "_sv + GpType::SToString(aPropInfo.Type()));
        } break;
        default:
        {
            THROW_GPE("Unsupported type "_sv + GpType::SToString(aPropInfo.Type()));
        }
    }*/
}


}//namespace GPlatform
