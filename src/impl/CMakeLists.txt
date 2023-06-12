add_library(impl STATIC
        opponentImpl.cpp
        minimax.cpp
        )
target_link_libraries(impl PUBLIC
        domain
)

target_include_directories(TicTacToe PUBLIC
        "${PROJECT_SOURCE_DIR}/src/domain"
        )