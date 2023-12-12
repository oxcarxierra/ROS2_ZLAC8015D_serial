cmake_minimum_required(VERSION 3.8)
project(ros2_ZLAC8015D_serial)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(serial REQUIRED)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter, which checks for copyrights
  # uncomment the line when copyright and license are not present in all source files
  # set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  # set(ament_cmake_cpplint_FOUND TRUE)
  find_package(ament_cmake_gtest REQUIRED)

  set(TESTFILES
      test/main.cpp
      test/zlac_test.cpp
      )
  # Add a gtest executables
  ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
  target_link_libraries(${PROJECT_NAME}_test zlac8015)

  install(TARGETS
        ${PROJECT_NAME}_test
        # Install the generated test executable file to the path after DESTINATION
        DESTINATION lib/${PROJECT_NAME})
  # uncomment to enforce lintners and static code analyzers defined in ament_lint_common package        
  # ament_lint_auto_find_test_dependencies()
endif()


include_directories(include)


add_executable(zlac8015_example src/zlac8015_example.cpp src/zlac8015.cpp)
ament_target_dependencies(zlac8015_example serial rclcpp)


add_library(zlac8015 src/zlac8015.cpp) 
ament_export_targets(zlac8015 HAS_LIBRARY_TARGET)
ament_target_dependencies(zlac8015 serial rclcpp)

install(
  DIRECTORY include/motor_driver
  DESTINATION include
)

# install the executable in the lib folder to make it detectable through setup.bash
install(TARGETS 
  zlac8015_example
  DESTINATION lib/${PROJECT_NAME}/
)

install(
  TARGETS zlac8015
  EXPORT zlac8015
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

ament_package()
