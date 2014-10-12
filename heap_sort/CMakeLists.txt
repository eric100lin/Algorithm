# Properties->C/C++->General->Additional Include Directories
include_directories ("${PROJECT_SOURCE_DIR}/heap_sort")

# Set Properties->General->Configuration Type to Application(.exe)
# Creates heap_sort.exe with the listed sources (main.cxx)
# Adds sources to the Solution Explorer
add_executable (heap_sort heap_sort.c)

# Creates a folder "executables" and adds target 
# project (heap_sort.vcproj) under it
set_property(TARGET heap_sort PROPERTY FOLDER "Sort")

# Adds logic to INSTALL.vcproj to copy heap_sort.exe to destination directory
install (TARGETS heap_sort
		 RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
