#ifndef N_PROCESSOR_INFO_H_INCLUDED
#define N_PROCESSOR_INFO_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NProcessorVendor_
{
	npvUnknown = 0,
	npvAmd = 1,
	npvCentaur = 2,
	npvCyrix = 3,
	npvIntel = 4,
	npvNationalSemiconductor = 5,
	npvNexGen = 6,
	npvRiseTechnology = 7,
	npvSiS = 8,
	npvTransmeta = 9,
	npvUmc = 10,
	npvVia = 11
} NProcessorVendor;

N_DECLARE_TYPE(NProcessorVendor)

typedef enum NProcessorFeature_
{
	npftX86Sse = 0,
	npftX86Sse2 = 1,
	npftX86Sse3 = 2,
	npftX86Ssse3 = 3,
	npftX86LZCnt = 4,
	npftX86PopCnt = 5,
	npftX86Sse41 = 6,
	npftX86Sse42 = 7,
	npftX86Sse4a = 8,
	npftX86Avx = 9,
	npftX86Avx2 = 10,
	npftArmNeon = 1000,
	npftArmCrc32 = 1001,
} NProcessorFeature;

N_DECLARE_TYPE(NProcessorFeature)

N_DECLARE_STATIC_OBJECT_TYPE(NProcessorInfo)

NResult N_API NProcessorInfoGetCount(NInt * pValue);

NResult N_API NProcessorInfoGetVendorNameN(HNString * phValue);
NResult N_API NProcessorInfoGetVendor(NProcessorVendor * pValue);
NResult N_API NProcessorInfoGetModelInfo(NInt * pFamily, NInt * pModel, NInt * pStepping);
NResult N_API NProcessorInfoGetModelNameN(HNString * phValue);

NResult N_API NProcessorInfoIsMmxSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIs3DNowSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSseSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse2SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse3SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSsse3SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsLZCntSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsPopCntSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse41SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse42SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse4aSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse5SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsNeonSupported(NBool * pValue);

NResult N_API NProcessorInfoIsFeatureSupported(NProcessorFeature feature, NBool * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_PROCESSOR_INFO_H_INCLUDED
