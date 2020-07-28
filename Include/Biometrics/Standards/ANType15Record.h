#ifndef AN_TYPE_15_RECORD_H_INCLUDED
#define AN_TYPE_15_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANFPImageAsciiBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType15Record, ANFPImageAsciiBinaryRecord)

#define AN_TYPE_15_RECORD_FIELD_LEN  AN_RECORD_FIELD_LEN
#define AN_TYPE_15_RECORD_FIELD_IDC  AN_RECORD_FIELD_IDC
#define AN_TYPE_15_RECORD_FIELD_IMP  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_IMP
#define AN_TYPE_15_RECORD_FIELD_SRC  AN_ASCII_BINARY_RECORD_FIELD_SRC
#define AN_TYPE_15_RECORD_FIELD_PCD  AN_ASCII_BINARY_RECORD_FIELD_DAT
#define AN_TYPE_15_RECORD_FIELD_HLL  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_15_RECORD_FIELD_VLL  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_15_RECORD_FIELD_SLC  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC
#define AN_TYPE_15_RECORD_FIELD_HPS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS
#define AN_TYPE_15_RECORD_FIELD_VPS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS
#define AN_TYPE_15_RECORD_FIELD_CGA  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA
#define AN_TYPE_15_RECORD_FIELD_BPX  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX
#define AN_TYPE_15_RECORD_FIELD_PLP  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FGP
#define AN_TYPE_15_RECORD_FIELD_SHPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS
#define AN_TYPE_15_RECORD_FIELD_SVPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS
#define AN_TYPE_15_RECORD_FIELD_AMP  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_AMP
#define AN_TYPE_15_RECORD_FIELD_COM  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM
#define AN_TYPE_15_RECORD_FIELD_SEG  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_SEG
#define AN_TYPE_15_RECORD_FIELD_PQM  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM
#define AN_TYPE_15_RECORD_FIELD_DMM  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM

#define AN_TYPE_15_RECORD_FIELD_PAP 31

#define AN_TYPE_15_RECORD_FIELD_SUB AN_ASCII_BINARY_RECORD_FIELD_SUB
#define AN_TYPE_15_RECORD_FIELD_CON AN_ASCII_BINARY_RECORD_FIELD_CON

#define AN_TYPE_15_RECORD_FIELD_FCT AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FCT
#define AN_TYPE_15_RECORD_FIELD_ANN AN_ASCII_BINARY_RECORD_FIELD_ANN
#define AN_TYPE_15_RECORD_FIELD_DUI AN_ASCII_BINARY_RECORD_FIELD_DUI
#define AN_TYPE_15_RECORD_FIELD_MMS AN_ASCII_BINARY_RECORD_FIELD_MMS

#define AN_TYPE_15_RECORD_FIELD_SAN AN_ASCII_BINARY_RECORD_FIELD_SAN
#define AN_TYPE_15_RECORD_FIELD_EFR AN_ASCII_BINARY_RECORD_FIELD_EFR
#define AN_TYPE_15_RECORD_FIELD_ASC AN_ASCII_BINARY_RECORD_FIELD_ASC
#define AN_TYPE_15_RECORD_FIELD_HAS AN_ASCII_BINARY_RECORD_FIELD_HAS
#define AN_TYPE_15_RECORD_FIELD_SOR AN_ASCII_BINARY_RECORD_FIELD_SOR
#define AN_TYPE_15_RECORD_FIELD_GEO AN_ASCII_BINARY_RECORD_FIELD_GEO

#define AN_TYPE_15_RECORD_FIELD_UDF_FROM  AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#define AN_TYPE_15_RECORD_FIELD_UDF_TO    AN_ASCII_BINARY_RECORD_FIELD_UDF_TO
#define AN_TYPE_15_RECORD_FIELD_UDF_TO_V5 AN_ASCII_BINARY_RECORD_FIELD_UDF_TO_V5

#define AN_TYPE_15_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

#define AN_TYPE_15_RECORD_MAX_QUALITY_METRIC_COUNT    4
#define AN_TYPE_15_RECORD_MAX_QUALITY_METRIC_COUNT_V5 9

#define AN_TYPE_15_RECORD_MAX_AMPUTATION_COUNT 9

#define AN_TYPE_15_RECORD_MAX_SEGMENT_COUNT 17

#define AN_TYPE_15_RECORD_PAP_70  70
#define AN_TYPE_15_RECORD_PAP_80  80
#define AN_TYPE_15_RECORD_PAP_170 170
#define AN_TYPE_15_RECORD_PAP_180 180

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType15Record instead")
NResult N_API ANType15RecordCreate(NVersion_ version, NInt idc, NUInt flags, HANType15Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType15Record instead")
NResult N_API ANType15RecordCreateEx(NUInt flags, HANType15Record * phRecord);

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType15RecordFromNImageN instead")
NResult N_API ANType15RecordCreateFromNImageN(NVersion_ version, NInt idc, HNString hSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType15Record * phRecord);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType15RecordFromNImageA instead")
NResult ANType15RecordCreateFromNImageA(NVersion_ version, NInt idc, const NAChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType15Record * phRecord);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType15RecordFromNImageW instead")
NResult ANType15RecordCreateFromNImageW(NVersion_ version, NInt idc, const NWChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType15Record * phRecord);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType15RecordFromNImage instead")
NResult ANType15RecordCreateFromNImage(NVersion_ version, NInt idc, const NChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType15Record * phRecord);
#endif
#define ANType15RecordCreateFromNImage N_FUNC_AW(ANType15RecordCreateFromNImage)

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType15RecordFromNImageN instead")
NResult N_API ANType15RecordCreateFromNImageNEx(HNString hSrc, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType15Record * phRecord);

NResult N_API ANType15RecordGetSubjectAcquisitionProfile(HANType15Record hRecord, NInt * pValue);
NResult N_API ANType15RecordSetSubjectAcquisitionProfile(HANType15Record hRecord, NInt value);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_15_RECORD_H_INCLUDED
