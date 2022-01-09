cmake_minimum_required(VERSION 3.21)
project(LibAML)

set(CMAKE_CXX_STANDARD 20)

find_package(fmt)
link_libraries(fmt-header-only)

set(ELEMENTS
        Elements/DataContainer.cpp
        Elements/DataContainer.h
        Elements/Data.cpp
        Elements/Data.h
        Elements/DefinitionBlock.cpp
        Elements/DefinitionBlock.h
        Elements/Device.cpp
        Elements/Device.h
        Elements/Element.cpp
        Elements/Element.h
        Elements/Elements.h
        Elements/ElementTypes.h
        Elements/Method.cpp
        Elements/Method.h
        Elements/Name.cpp
        Elements/Name.h
        Elements/NameString.cpp
        Elements/NameString.h
        Elements/Return.cpp
        Elements/Return.h
        Elements/Scope.cpp
        Elements/Scope.h
        Elements/TermArg.cpp
        Elements/TermArg.h
        )


set(LIBRARY
        Library/Error.h
        Library/Result.h
        Library/Types.h
        Library/Optional.h
        Library/StringView.h
        Library/Try.h
        Library/ByteReader.cpp
        Library/ByteReader.h
        )

add_executable(LibAML ${LIBRARY} ${ELEMENTS}
        main.cpp
        DefinitionBlockHeader.h
        Parser.cpp
        Parser.h
        Opcodes.h
        Opcodes.cpp
        Debug.cpp
        )
