TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=5c88961b-16bb-49f8-b8fe-4265362aa98f
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += GPXML_LIBRARY
PACKET_NAME     = GpXml
DIR_LEVEL       = ./..

include(../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V		= 2
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -ltinyxml2
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	GpXmlFromStruct.cpp \
	GpXmlMapper.cpp \
	GpXmlMapperFlags.cpp \
	GpXmlToStruct.cpp \
	GpTypeMapperXml.cpp \
	GpTypeMapperXmlFactory.cpp

HEADERS += \
	GpXmlFromStruct.hpp \
	GpXmlMapper.hpp \
	GpXmlMapperFlags.hpp \
	GpXmlToStruct.hpp \
	GpXml_global.hpp \
	GpXml.hpp \
	GpTypeMapperXml.hpp \
	GpTypeMapperXmlFactory.hpp
