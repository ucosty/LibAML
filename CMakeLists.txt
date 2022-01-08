cmake_minimum_required(VERSION 3.21)
project(LibAML)

set(CMAKE_CXX_STANDARD 20)

find_package(fmt)
link_libraries(fmt-header-only)

set(LIBRARY Library/Error.h Library/Result.h Library/Types.h Library/Optional.h Library/StringView.h Library/Try.h Library/ByteReader.cpp Library/ByteReader.h Elements/ElementTypes.h Parser.cpp Parser.h Elements/Element.h Opcodes.h Opcodes.cpp Debug.cpp Elements/Element.cpp Elements/DefinitionBlock.cpp Elements/DefinitionBlock.h Elements/NameString.cpp Elements/NameString.h Elements/Name.cpp Elements/Name.h Elements/Data.cpp Elements/Data.h Elements/DataContainer.h Elements/DataContainer.cpp Elements/Elements.h Elements/Scope.cpp Elements/Scope.h Elements/Device.cpp Elements/Device.h Elements/Method.cpp Elements/Method.h Elements/Return.cpp Elements/Return.h Elements/TermArg.cpp Elements/TermArg.h)
add_executable(LibAML ${LIBRARY} main.cpp DefinitionBlockHeader.h)
