add_library(domain STATIC
        baseOpponent.h
        boardConfig.cpp
        winningPositions.h
        )
target_include_directories(domain INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})