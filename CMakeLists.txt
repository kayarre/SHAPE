project(shape)

cmake_minimum_required(VERSION 3.14)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Instruct CMake to run moc automatically when needed.
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)

# if(POLICY CMP0020)
#   cmake_policy(SET CMP0020 NEW)
# endif()

find_package(VTK COMPONENTS REQUIRED
  CommonCore
  CommonColor
  FiltersCore
  RenderingCore
  InfovisCore
  FiltersSources
  InteractionStyle
  InteractionWidgets
  ViewsQt
  GUISupportQt
  RenderingOpenGL2
  RenderingFreeType
  RenderingContext2D
)

if(vtkGUISupportQt_LOADED OR TARGET VTK::GUISupportQt)
  # The rest should just work (sure...)
  # We have ui files, this will bring in the macro: qt5_wrap_ui
  find_package(Qt5 COMPONENTS REQUIRED Widgets Core)
  if (NOT TARGET Qt5::Widgets)
    message("Cannot find qt5 thing: ${Qt5_NOT_FOUND_MESSAGE}")
    return ()
  endif ()
else()
  message(STATUS "GuiSupportQt not found.")
  return()
endif()

# Set your files and resources here

set( shape_tools /home/krs/build/shape/shape_tools)

set( sources main.cpp shape.cpp )
set( Hdrs shape.h)
set( Uis shape.ui)

#set( MOC_Hdrs shape.h )
#qt5_wrap_cpp(MOC_Hdrs shape.h)
#qt5_wrap_ui(UIS_Hdrs shape.ui)

set( QRCs shape.qrc )


add_executable(shape 
  ${sources} # ${QRCs} ${Hdrs} ${Uis}
)


target_link_libraries(shape PRIVATE
  Qt5::Widgets
  Qt5::Core
  VTK::CommonCore
  VTK::FiltersSources
  VTK::GUISupportQt
  VTK::InteractionStyle
  VTK::RenderingCore
  VTK::CommonColor
  VTK::InteractionWidgets
  VTK::RenderingContext2D
  VTK::RenderingFreeType
  VTK::RenderingGL2PSOpenGL2
  VTK::RenderingOpenGL2
)

target_include_directories(shape SYSTEM PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${VTK_INCLUDE_DIRS}
    ${shape_tools}
    ${AUTOGEN_BUILD_DIR}
)

target_compile_definitions(shape PRIVATE
    ${VTK_DEFINITIONS}
)

set_target_properties(shape PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)