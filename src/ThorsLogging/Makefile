
THORSANVIL_ROOT				?= $(realpath ../../)

TARGET						= ThorsLogging.lib
NAMESPACE					= ThorsAnvil::Logging
TEST_IGNORE					= loguru.cpp loguru.hpp
CXXFLAGS					+= -DLOGURU_WITH_STREAMS=1
FILE_WARNING_FLAGS			+= -Wno-attributes

VERA_PROFILE_loguru.hpp		= ThorsLogging_loguru.hpp

include $(THORSANVIL_ROOT)/build/tools/Makefile




