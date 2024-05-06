#include "PyroEnginePCH.h"
#include "ProcessorAnalyser.h"
#include "Core.h"
#include <cstring>
#if defined PYRO_PLATFORM_WINDOWS
#include <intrin.h>
#endif

namespace PyroEngine
{
	std::string ProcessorAnalyser::s_ProcessorName = "";
	bool ProcessorAnalyser::s_IsIntel = false;
	bool ProcessorAnalyser::s_IsAMD = false;
	bool ProcessorAnalyser::s_MMX = false;
	bool ProcessorAnalyser::s_SSE = false;
	bool ProcessorAnalyser::s_SSE2 = false;
	bool ProcessorAnalyser::s_SSE3 = false;
	bool ProcessorAnalyser::s_SSSE3 = false;
	bool ProcessorAnalyser::s_SSE41 = false;
	bool ProcessorAnalyser::s_SSE42 = false;
	bool ProcessorAnalyser::s_AVX = false;
	bool ProcessorAnalyser::s_AVX2 = false;
	bool ProcessorAnalyser::s_FMA = false;
	bool ProcessorAnalyser::s_AVX512F = false;
	bool ProcessorAnalyser::s_AVX512PF = false;
	bool ProcessorAnalyser::s_AVX512ER = false;
	bool ProcessorAnalyser::s_AVX512CD = false;

	void ProcessorAnalyser::CPU_ID(int* cpuInfo, int cpuInfoType)
	{
#ifdef PYRO_PLATFORM_WINDOWS
		__cpuid(cpuInfo, cpuInfoType);
#else
		asm("cpuid" : "=a" (cpuInfo[0]), "=b" (cpuInfo[1]), "=c" (cpuInfo[2]), "=d" (cpuInfo[3])
				: "a" (cpuInfoType), "c" (0));
#endif
	}

	void ProcessorAnalyser::AnalyseF1(int* cpuInfo)
	{
		s_SSE3 = cpuInfo[2] & PYRO_CPU_SSE3_BIT;
		s_SSSE3 = cpuInfo[2] & PYRO_CPU_SSSE3_BIT;
		s_SSE41 = cpuInfo[2] & PYRO_CPU_SSE41_BIT;
		s_SSE42 = cpuInfo[2] & PYRO_CPU_SSE42_BIT;
		s_AVX = cpuInfo[2] & PYRO_CPU_AVX_BIT;
		s_FMA = cpuInfo[2] & PYRO_CPU_FMA_BIT;

		s_MMX = cpuInfo[3] & PYRO_CPU_MMX_BIT;
		s_SSE = cpuInfo[3] & PYRO_CPU_SSE_BIT;
		s_SSE2 = cpuInfo[3] & PYRO_CPU_SSE2_BIT;
	}

	void ProcessorAnalyser::AnalyseF7(int* cpuInfo)
	{
		s_AVX2 = cpuInfo[1] & PYRO_CPU_AVX2_BIT;
		s_AVX512F = cpuInfo[1] & PYRO_CPU_AVX512F_BIT;
		s_AVX512PF = cpuInfo[1] & PYRO_CPU_AVX512PF_BIT;
		s_AVX512ER = cpuInfo[1] & PYRO_CPU_AVX512ER_BIT;
		s_AVX512CD = cpuInfo[1] & PYRO_CPU_AVX512CD_BIT;
	}

	void ProcessorAnalyser::Analyse()
	{
		int cpuInfo[4] = { 0, 0, 0, 0 };
		int hvFuncID = 0;

		//Set highest valid function ID
		CPU_ID(cpuInfo, 0);
		hvFuncID = cpuInfo[0];

		//Capture vendor string
		char vendor[32];
		std::memset(vendor, 0, sizeof(vendor));
		*reinterpret_cast<int*>(vendor) = cpuInfo[1];
		*reinterpret_cast<int*>(vendor + 4) = cpuInfo[3];
		*reinterpret_cast<int*>(vendor + 8) = cpuInfo[2];
		s_IsIntel = !std::strcmp(vendor, "GenuineIntel");
		s_IsAMD = !std::strcmp(vendor, "AuthenticAMD");

		//Capture brand string
		char brand[64];
		std::memset(brand, 0, sizeof(brand));
		CPU_ID(cpuInfo, 0x80000000);
		if (cpuInfo[0] >= 0x80000004)
		{
			CPU_ID(cpuInfo, 0x80000002);
			std::memcpy(brand, cpuInfo, sizeof(cpuInfo));
			CPU_ID(cpuInfo, 0x80000003);
			std::memcpy(brand + 16, cpuInfo, sizeof(cpuInfo));
			CPU_ID(cpuInfo, 0x80000004);
			std::memcpy(brand + 32, cpuInfo, sizeof(cpuInfo));
			s_ProcessorName = brand;
		}

		//Analysing CPU Bits
		if (hvFuncID >= 1)
		{
			CPU_ID(cpuInfo, 1);
			AnalyseF1(cpuInfo);
		}
		if (hvFuncID >= 7)
		{
			CPU_ID(cpuInfo, 7);
			AnalyseF7(cpuInfo);
		}
	}
}