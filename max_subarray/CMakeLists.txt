# Properties->C/C++->General->Additional Include Directories
include_directories ("${PROJECT_SOURCE_DIR}/max_subarray")

# Set Properties->General->Configuration Type to Application(.exe)
# Creates max_subarray.exe with the listed sources (main.cxx)
# Adds sources to the Solution Explorer
add_executable (max_subarray max_subarray.c)

# Creates a folder "executables" and adds target 
# project (max_subarray.vcproj) under it
set_property(TARGET max_subarray PROPERTY FOLDER "Search")

# Adds logic to INSTALL.vcproj to copy max_subarray.exe to destination directory
install (TARGETS max_subarray
		 RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
