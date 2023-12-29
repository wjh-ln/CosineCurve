# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_cosine_curve_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED cosine_curve_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(cosine_curve_FOUND FALSE)
  elseif(NOT cosine_curve_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(cosine_curve_FOUND FALSE)
  endif()
  return()
endif()
set(_cosine_curve_CONFIG_INCLUDED TRUE)

# output package information
if(NOT cosine_curve_FIND_QUIETLY)
  message(STATUS "Found cosine_curve: 0.0.0 (${cosine_curve_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'cosine_curve' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${cosine_curve_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(cosine_curve_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${cosine_curve_DIR}/${_extra}")
endforeach()
