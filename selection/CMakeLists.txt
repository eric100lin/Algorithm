# Properties->C/C++->General->Additional Include Directories
include_directories ("${PROJECT_SOURCE_DIR}/selection")

# Set Properties->General->Configuration Type to Application(.exe)
# Creates heap_sort.exe with the listed sources (main.cxx)
# Adds sources to the Solution Explorer
add_executable (selection selection.cpp)

# Creates a folder "executables" and adds target 
# project (selection.vcproj) under it
set_property(TARGET selection PROPERTY FOLDER "Search")

# Adds logic to INSTALL.vcproj to copy quick_sort.exe to destination directory
install (TARGETS selection
		 RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
