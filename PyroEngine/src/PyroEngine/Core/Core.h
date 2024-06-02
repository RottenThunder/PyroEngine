#pragma once
#include "Logger.h"

#define PYRO_VERSION_MAJOR 0
#define PYRO_VERSION_MINOR 0
#define PYRO_VERSION_PATCH 0

#define PYRO_BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)
#define PYRO_BIT_FIELD(x) (1 << x)

#define PYRO_CPU_MMX_BIT PYRO_BIT_FIELD(23)
#define PYRO_CPU_SSE_BIT PYRO_BIT_FIELD(25)
#define PYRO_CPU_SSE2_BIT PYRO_BIT_FIELD(26)
#define PYRO_CPU_SSE3_BIT PYRO_BIT_FIELD(0)
#define PYRO_CPU_SSSE3_BIT PYRO_BIT_FIELD(9)
#define PYRO_CPU_SSE41_BIT PYRO_BIT_FIELD(19)
#define PYRO_CPU_SSE42_BIT PYRO_BIT_FIELD(20)
#define PYRO_CPU_AVX_BIT PYRO_BIT_FIELD(28)
#define PYRO_CPU_AVX2_BIT PYRO_BIT_FIELD(5)
#define PYRO_CPU_FMA_BIT PYRO_BIT_FIELD(12)
#define PYRO_CPU_AVX512F_BIT PYRO_BIT_FIELD(16)
#define PYRO_CPU_AVX512PF_BIT PYRO_BIT_FIELD(26)
#define PYRO_CPU_AVX512ER_BIT PYRO_BIT_FIELD(27)
#define PYRO_CPU_AVX512CD_BIT PYRO_BIT_FIELD(28)

#define PYRO_TYPE_ERROR int

#define PYRO_ERROR_0 (PYRO_TYPE_ERROR)0
#define PYRO_ERROR_1 (PYRO_TYPE_ERROR)1
#define PYRO_ERROR_2 (PYRO_TYPE_ERROR)2
#define PYRO_ERROR_3 (PYRO_TYPE_ERROR)3
#define PYRO_ERROR_4 (PYRO_TYPE_ERROR)4
#define PYRO_ERROR_5 (PYRO_TYPE_ERROR)5
#define PYRO_ERROR_6 (PYRO_TYPE_ERROR)6
#define PYRO_ERROR_7 (PYRO_TYPE_ERROR)7
#define PYRO_ERROR_8 (PYRO_TYPE_ERROR)8
#define PYRO_ERROR_9 (PYRO_TYPE_ERROR)9
#define PYRO_ERROR_10 (PYRO_TYPE_ERROR)10
#define PYRO_ERROR_11 (PYRO_TYPE_ERROR)11
#define PYRO_ERROR_12 (PYRO_TYPE_ERROR)12
#define PYRO_ERROR_13 (PYRO_TYPE_ERROR)13
#define PYRO_ERROR_14 (PYRO_TYPE_ERROR)14
#define PYRO_ERROR_15 (PYRO_TYPE_ERROR)15
#define PYRO_ERROR_16 (PYRO_TYPE_ERROR)16
#define PYRO_ERROR_17 (PYRO_TYPE_ERROR)17
#define PYRO_ERROR_18 (PYRO_TYPE_ERROR)18
#define PYRO_ERROR_19 (PYRO_TYPE_ERROR)19
#define PYRO_ERROR_20 (PYRO_TYPE_ERROR)20

#define PYRO_ERROR_0_DESC "No Errors"
#define PYRO_ERROR_1_DESC "GLFW did not initialise"
#define PYRO_ERROR_2_DESC "A value was trying to be accessed with an index of {1} in a SIMDRegister128"
#define PYRO_ERROR_3_DESC "Window Creation was unsuccessful"
#define PYRO_ERROR_4_DESC "Glad did not initialise"
#define PYRO_ERROR_5_DESC "An Index Buffer has been created with no Graphics API"
#define PYRO_ERROR_6_DESC "An Index Buffer has been created with an unknown Graphics API"
#define PYRO_ERROR_7_DESC "A Shader has been created with no Graphics API"
#define PYRO_ERROR_8_DESC "A Shader has been created with an unknown Graphics API"
#define PYRO_ERROR_9_DESC "A Texture has been created with no Graphics API"
#define PYRO_ERROR_10_DESC "A Texture has been created with an unknown Graphics API"
#define PYRO_ERROR_11_DESC "A Vertex Array has been created with no Graphics API"
#define PYRO_ERROR_12_DESC "A Vertex Array has been created with an unknown Graphics API"
#define PYRO_ERROR_13_DESC "A Vertex Buffer has been created with no Graphics API"
#define PYRO_ERROR_14_DESC "A Vertex Buffer has been created with an unknown Graphics API"
#define PYRO_ERROR_15_DESC "An Unknown ShaderDataType has been requested to process"
#define PYRO_ERROR_16_DESC "Failed to Compile Shader: {1}"
#define PYRO_ERROR_17_DESC "Failed to Link Shaders: {1}"
#define PYRO_ERROR_18_DESC "Data sent to a Texture doesn't have the same size as the Texture"
#define PYRO_ERROR_19_DESC "A Vertex Buffer has been sent to a Vertex Array with no layout"
#define PYRO_ERROR_20_DESC "An Unknown ShaderDataType has been requested to process"

#define PYRO_ERROR_NO_ERROR PYRO_ERROR_0
#define PYRO_ERROR_NO_ERROR_DESC PYRO_ERROR_0_DESC