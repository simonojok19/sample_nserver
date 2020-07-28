#ifndef AN_TYPE_16_RECORD_H_INCLUDED
#define AN_TYPE_16_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANImageAsciiBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType16Record, ANImageAsciiBinaryRecord)

#define AN_TYPE_16_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_16_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC

#define AN_TYPE_16_RECORD_FIELD_UDI 3

#define AN_TYPE_16_RECORD_FIELD_SRC  AN_ASCII_BINARY_RECORD_FIELD_SRC
#define AN_TYPE_16_RECORD_FIELD_UTD  AN_ASCII_BINARY_RECORD_FIELD_DAT
#define AN_TYPE_16_RECORD_FIELD_HLL  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_16_RECORD_FIELD_VLL  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_16_RECORD_FIELD_SLC  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC
#define AN_TYPE_16_RECORD_FIELD_HPS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS
#define AN_TYPE_16_RECORD_FIELD_VPS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS
#define AN_TYPE_16_RECORD_FIELD_CGA  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA
#define AN_TYPE_16_RECORD_FIELD_BPX  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX
#define AN_TYPE_16_RECORD_FIELD_CSP  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CSP
#define AN_TYPE_16_RECORD_FIELD_SHPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS
#define AN_TYPE_16_RECORD_FIELD_SVPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS
#define AN_TYPE_16_RECORD_FIELD_COM  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM
#define AN_TYPE_16_RECORD_FIELD_UQS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM
#define AN_TYPE_16_RECORD_FIELD_DMM  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM

#define AN_TYPE_16_RECORD_FIELD_ANN AN_ASCII_BINARY_RECORD_FIELD_ANN
#define AN_TYPE_16_RECORD_FIELD_DUI AN_ASCII_BINARY_RECORD_FIELD_DUI
#define AN_TYPE_16_RECORD_FIELD_MMS AN_ASCII_BINARY_RECORD_FIELD_MMS

#define AN_TYPE_16_RECORD_FIELD_SAN AN_ASCII_BINARY_RECORD_FIELD_SAN
#define AN_TYPE_16_RECORD_FIELD_EFR AN_ASCII_BINARY_RECORD_FIELD_EFR
#define AN_TYPE_16_RECORD_FIELD_ASC AN_ASCII_BINARY_RECORD_FIELD_ASC
#define AN_TYPE_16_RECORD_FIELD_HAS AN_ASCII_BINARY_RECORD_FIELD_HAS
#define AN_TYPE_16_RECORD_FIELD_SOR AN_ASCII_BINARY_RECORD_FIELD_SOR
#define AN_TYPE_16_RECORD_FIELD_GEO AN_ASCII_BINARY_RECORD_FIELD_GEO

#define AN_TYPE_16_RECORD_FIELD_UDF_FROM  AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#define AN_TYPE_16_RECORD_FIELD_UDF_TO    AN_ASCII_BINARY_RECORD_FIELD_UDF_TO
#define AN_TYPE_16_RECORD_FIELD_UDF_TO_V5 AN_ASCII_BINARY_RECORD_FIELD_UDF_TO_V5

#define AN_TYPE_16_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

#define AN_TYPE_16_RECORD_MAX_USER_DEFINED_IMAGE_LENGTH 35

#define AN_TYPE_16_RECORD_MAX_USER_DEFINED_QUALITY_SCORE_COUNT    1
#define AN_TYPE_16_RECORD_MAX_USER_DEFINED_QUALITY_SCORE_COUNT_V5 9

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType4Record instead")
NResult N_API ANType16RecordCreate(NVersion_ version, NInt idc, NUInt flags, HANType16Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType4Record instead")
NResult N_API ANType16RecordCreateEx(NUInt flags, HANType16Record * phRecord);

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType16RecordFromNImageN instead")
NResult N_API ANType16RecordCreateFromNImageN(NVersion_ version, NInt idc, HNString hUdi, HNString hSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType16Record * phRecord);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType16RecordFromNImageA instead")
NResult ANType16RecordCreateFromNImageA(NVersion_ version, NInt idc, const NAChar * szUdi, const NAChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType16Record * phRecord);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType16RecordFromNImageW instead")
NResult ANType16RecordCreateFromNImageW(NVersion_ version, NInt idc, const NWChar * szUdi, const NWChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType16Record * phRecord);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType16RecordFromNImage instead")
NResult ANType16RecordCreateFromNImage(NVersion_ version, NInt idc, const NChar * szUdi, const NChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType16Record * phRecord);
#endif
#define ANType16RecordCreateFromNImage N_FUNC_AW(ANType16RecordCreateFromNImage)

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType16RecordFromNImageN instead")
NResult N_API ANType16RecordCreateFromNImageNEx(HNString hUdi, HNString hSrc, BdifScaleUnits slc, ANImageCompressionAlgorithm cga,
	HNImage hImage, NUInt flags, HANType16Record * phRecord);

NResult N_API ANType16RecordGetUserDefinedImageN(HANType16Record hRecord, HNString * phValue);

NResult N_API ANType16RecordSetUserDefinedImageN(HANType16Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType16RecordSetUserDefinedImageA(HANType16Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType16RecordSetUserDefinedImageW(HANType16Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType16RecordSetUserDefinedImage(HANType16Record hRecord, const NChar * szValue);
#endif
#define ANType16RecordSetUserDefinedImage N_FUNC_AW(ANType16RecordSetUserDefinedImage)

NResult N_API ANType16RecordGetUserDefinedQualityScoreCount(HANType16Record hRecord, NInt * pValue);
NResult N_API ANType16RecordGetUserDefinedQualityScoreEx(HANType16Record hRecord, NInt index, struct ANQualityMetric_ * pValue);
NResult N_API ANType16RecordGetUserDefinedQualityScores(HANType16Record hRecord, struct ANQualityMetric_ * * parValues, NInt * pValueCount);
NResult N_API ANType16RecordSetUserDefinedQualityScoreEx(HANType16Record hRecord, NInt index, const struct ANQualityMetric_ * pValue);
NResult N_API ANType16RecordAddUserDefinedQualityScore(HANType16Record hRecord, const struct ANQualityMetric_ * pValue, NInt * pIndex);
NResult N_API ANType16RecordInsertUserDefinedQualityScore(HANType16Record hRecord, NInt index, const struct ANQualityMetric_ * pValue);
NResult N_API ANType16RecordRemoveUserDefinedQualityScoreAt(HANType16Record hRecord, NInt index);
NResult N_API ANType16RecordClearUserDefinedQualityScores(HANType16Record hRecord);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_16_RECORD_H_INCLUDED
