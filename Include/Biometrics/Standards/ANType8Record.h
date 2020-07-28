#ifndef AN_TYPE_8_RECORD_H_INCLUDED
#define AN_TYPE_8_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANImageBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType8Record, ANImageBinaryRecord)

#define AN_TYPE_8_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_8_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC

#define AN_TYPE_8_RECORD_FIELD_SIG 3
#define AN_TYPE_8_RECORD_FIELD_SRT 4

#define AN_TYPE_8_RECORD_FIELD_ISR  AN_IMAGE_BINARY_RECORD_FIELD_ISR
#define AN_TYPE_8_RECORD_FIELD_HLL  AN_IMAGE_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_8_RECORD_FIELD_VLL  AN_IMAGE_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_8_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

typedef enum ANSignatureType_
{
	anstSubject = 0,
	anstOfficial = 1
} ANSignatureType;

N_DECLARE_TYPE(ANSignatureType)

typedef enum ANSignatureRepresentationType_
{
	ansrtScannedUncompressed = 0,
	ansrtScannedCompressed = 1,
	ansrtVectorData = 2
} ANSignatureRepresentationType;

N_DECLARE_TYPE(ANSignatureRepresentationType)

struct ANPenVector_
{
	NUShort X;
	NUShort Y;
	NByte Pressure;
};
#ifndef AN_TYPE_8_RECORD_HPP_INCLUDED
typedef struct ANPenVector_ ANPenVector;
#endif

N_DECLARE_TYPE(ANPenVector)

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType8Record instead")
NResult N_API ANType8RecordCreate(NVersion_ version, NInt idc, NUInt flags, HANType8Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType8Record instead")
NResult N_API ANType8RecordCreateEx(NUInt flags, HANType8Record * phRecord);

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType8RecordFromNImage instead")
NResult N_API ANType8RecordCreateFromNImage(NVersion_ version, NInt idc, ANSignatureType st, ANSignatureRepresentationType srt,
	NBool isr, HNImage hImage, NUInt flags, HANType8Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType8RecordFromNImage instead")
NResult N_API ANType8RecordCreateFromNImageEx(ANSignatureType st, ANSignatureRepresentationType srt, NBool isr, HNImage hImage, NUInt flags,
											HANType8Record * phRecord);

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType8RecordFromVectors instead")
NResult N_API ANType8RecordCreateFromVectors(NVersion_ version, NInt idc, ANSignatureType st, 
	const struct ANPenVector_ * arPenVectors, NInt penVectorCount, NUInt flags, HANType8Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType8RecordFromVectors instead")
NResult N_API ANType8RecordCreateFromVectorsEx(ANSignatureType st, const struct ANPenVector_ * arPenVectors, NInt penVectorCount,
											NUInt flags, HANType8Record * phRecord);

NResult N_API ANType8RecordGetPenVectorCount(HANType8Record hRecord, NInt * pValue);
NResult N_API ANType8RecordGetPenVector(HANType8Record hRecord, NInt index, struct ANPenVector_ * pValue);
NResult N_API ANType8RecordGetPenVectors(HANType8Record hRecord, struct ANPenVector_ * * parValues, NInt * pValueCount);
NResult N_API ANType8RecordSetPenVector(HANType8Record hRecord, NInt index, const struct ANPenVector_ * pValue);
NResult N_API ANType8RecordAddPenVectorEx(HANType8Record hRecord, const struct ANPenVector_ * pValue, NInt * pIndex);
NResult N_API ANType8RecordInsertPenVector(HANType8Record hRecord, NInt index, const struct ANPenVector_ * pValue);
NResult N_API ANType8RecordRemovePenVectorAt(HANType8Record hRecord, NInt index);
NResult N_API ANType8RecordClearPenVectors(HANType8Record hRecord);

NResult N_API ANType8RecordGetSignatureType(HANType8Record hRecord, ANSignatureType * pValue);
NResult N_API ANType8RecordSetSignatureType(HANType8Record hRecord, ANSignatureType value);
NResult N_API ANType8RecordGetSignatureRepresentationType(HANType8Record hRecord, ANSignatureRepresentationType * pValue);
NResult N_API ANType8RecordSetSignatureRepresentationType(HANType8Record hRecord, ANSignatureRepresentationType value);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_8_RECORD_H_INCLUDED
