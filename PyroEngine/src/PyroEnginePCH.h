//---PYRO-ENGINE-PRECOMPILED-HEADER-FILE-----------------------------------

#pragma once

//---UTILITY---------------------------------------------------------------
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <functional>
#include <immintrin.h>
#include <iostream>
#include <memory>
#include <utility>
//-------------------------------------------------------------------------

//---DATA-STRUCTURES-------------------------------------------------------
#include <array>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//-------------------------------------------------------------------------

//---PLATFORM-SPECIFIC-----------------------------------------------------
#if defined PYRO_PLATFORM_WINDOWS
#include <Windows.h>
#endif
//-------------------------------------------------------------------------