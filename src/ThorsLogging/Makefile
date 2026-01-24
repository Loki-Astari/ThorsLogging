CONFIG_NAME					= ThorsLogging
THORSANVIL_ROOT				?= $(realpath ../../)
TARGET						= ThorsLogging.lib
NAMESPACE					= ThorsAnvil::Logging


CXXFLAGS					+= -DLOGURU_WITH_STREAMS=1


#
# This is need to build on Windows
%/loguru.o:					FILE_WARNING_FLAGS += -Wno-attributes -Wno-type-limits

include $(THORSANVIL_ROOT)/build/tools/Makefile

