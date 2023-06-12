add_executable(TicTacToe
        ticTacToeWindow.cpp
        board.cpp
        drawer.cpp
        main.cpp
        )

target_link_libraries(TicTacToe PUBLIC
        domain
        impl
        Qt5::Widgets
        )

target_include_directories(TicTacToe PUBLIC
        "${PROJECT_SOURCE_DIR}/src/domain"
        "${PROJECT_SOURCE_DIR}/src/impl"
        )

set_target_properties(TicTacToe PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
        )