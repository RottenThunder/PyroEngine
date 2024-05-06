#pragma once
#include <string>

namespace PyroEngine
{
	class ProcessorAnalyser
	{
	private:
		static void CPU_ID(int* cpuInfo, int cpuInfoType);
		static void AnalyseF1(int* cpuInfo);
		static void AnalyseF7(int* cpuInfo);
	public:
		static std::string s_ProcessorName;
		static bool s_IsIntel;
		static bool s_IsAMD;
		static bool s_MMX;
		static bool s_SSE;
		static bool s_SSE2;
		static bool s_SSE3;
		static bool s_SSSE3;
		static bool s_SSE41;
		static bool s_SSE42;
		static bool s_AVX;
		static bool s_AVX2;
		static bool s_FMA;
		static bool s_AVX512F;
		static bool s_AVX512PF;
		static bool s_AVX512ER;
		static bool s_AVX512CD;

		static void Analyse();
	};
}